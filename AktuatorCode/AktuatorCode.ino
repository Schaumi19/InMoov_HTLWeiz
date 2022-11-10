// Includes
#include "config.h"
#include <Servo.h>

// Initialization of the In/Output Pins
const byte Pin_pot[4] = {A0,A1,A2,A6};
const byte Pin_motorPWM[4] = {10,9,6,3};
const byte Pin_motorA[4] = {12,11,5,4};
const byte Pin_motorB[4] = {13,8,7,2};
const byte Pin_errorLed = A3;

// Initialization of the state Arrays
int actuatorStates[4] = {0, 0, 0, 0};
int goalAngle[4] = {0, 0, 0, 0};

//Error Detection
bool moving[4] = {false,false,false,false};
int startDiff[4] = {0,0,0,0};                 //start difference of goal angle and current angle
unsigned long startTime[4] = {0,0,0,0};       //when Actuator started moving
bool error[4] = {false,false,false,false};    //Poti value out of normal range
bool errorT[4] = {false,false,false,false};   //Actuator didn't reach checkpoint in Time
bool Last_Direction[4] = {false,false,false,false};

void setup() {
  // Setting up the serial
  Serial.begin(115200);
  while(!Serial);

  Serial.write(ACP_B1); //for Actuator identification
  Serial.write(ACP_B2);

  delay(500);

  // Change pins to IN/OUTPUT - mode
  for(int i = 0; i < 4;i++){
    if(used[i]){
      pinMode(Pin_motorPWM[i], OUTPUT);
      pinMode(Pin_motorA[i], OUTPUT);
      pinMode(Pin_motorB[i], OUTPUT);
      pinMode(Pin_pot[i], INPUT);
    }
  }

  delay(100);
  // Reading in data from the Potentiometers
  for (byte i = 0; i < 4; i++)
  {
    if(used[i] && ContinuousMovement[i] == 0){
      ReadSensorInput(i);
      goalAngle[i] = actuatorStates[i]; //Aktuators should not move from IC-start
    }
  }
}

void loop() {
  //Error LED
  bool anyError = false;
  for (int i = 0; i < 4; i++)
    anyError = anyError || error[i] || errorT[i];
  digitalWrite(Pin_errorLed, anyError);

  readSerial();

  #ifdef Debug
    Serial.println(";");  //Line ending for prev. Line
    for (int i = 0; i < 4; i++)
    {
      if(error[i]){
        Serial.print(i+1);
        Serial.print("-Error");
      }
      if(errorT[i]){
        Serial.print(i+1);
        Serial.print("-TError");
      }
    }
  #endif

  for(byte i = 0; i < 4; i++){
    if(used[i]){
      if(ContinuousMovement[i] == 0){
        
        ReadSensorInput(i);

        #ifdef Debug
          Serial.print(" ");
          Serial.print(i+1);
          Serial.print("-P:");
          Serial.print(analogRead(Pin_pot[i]));
          Serial.print(" G:");
          Serial.print(goalAngle[i]);
          Serial.print(" I:");
          Serial.print(actuatorStates[i]);
          Serial.print(" ");
        #endif

        normalControl(i);
      }else{
        MotorControl(i, ContinuousMovement[i], true);
      }
    }
  }
}

void ReadSensorInput(int i){
  // Reading in data from the Potentiometers + mapping
  int _readValue = analogRead(Pin_pot[i]);
  if(reversed_input)
    _readValue = 1024 - _readValue;
  
  if(used[i]&&(_readValue > max_pot[i] + errorDiff|| _readValue + errorDiff < min_pot[i]))
    error[i] = true;  //Value out of Range err
  actuatorStates[i] = map(_readValue, min_pot[i], max_pot[i], min_angle[i], max_angle[i]);
}

int AngleInputLimiter(int _angle, int _motorIndex){
  if(_angle > max_angle[_motorIndex])
    _angle = max_angle[_motorIndex];
  else if(_angle < min_angle[_motorIndex])
    _angle = min_angle[_motorIndex];
  return _angle;
}


// Reading in a string from Serial and computing it
void readSerial(){
  if(Serial.available() >= 4){
    #ifdef Debug_Serial
    Serial.print("Reading");
    #endif
    if(Serial.read() == ';'){
      #ifdef Debug_Serial
      Serial.print("SymFound");
      #endif
      byte _AkIndex = Serial.parseInt();
      Serial.readStringUntil(',');
      byte _angle = Serial.parseInt();
      #ifdef Debug_Serial
      Serial.print(' ' +String(_AkIndex)+ ':' +String(_angle) + ' ');
      #endif
      if (_AkIndex == 0){    //All Aktuators to the same Value
        for (byte i = 0; i < 4; i++){
            goalAngle[i] = AngleInputLimiter(_angle,i);
        }
      }
      else if (_AkIndex <= 4){
          goalAngle[_AkIndex-1] = AngleInputLimiter(_angle,_AkIndex-1);
      }
      else{
        //Error Actuator Index out of Range
      }
    }
  }else{
    //Serial.print("no Serial data avalible");
  }
}

//For all normal Actuators(not Servo or ContinuousMovement)
void normalControl(int i){
  if((actuatorStates[i] < goalAngle[i] && actuatorStates[i] < (goalAngle[i] - goalDeadzone)) ||(actuatorStates[i] > goalAngle[i] &&  actuatorStates[i] > (goalAngle[i] + goalDeadzone))){ //Do we even need to move
    #ifdef Debug
    Serial.print("Move");
    #endif
    bool _dir = goalAngle[i] > actuatorStates[i];
    if((_dir&&actuatorStates[i]+SlowSpeedZone[i]>goalAngle[i])||(!_dir&&actuatorStates[i]-SlowSpeedZone[i]<goalAngle[i]))
      MotorControl(i,SlowSpeed[i],_dir);
    else
      MotorControl(i,maxSpeed[i],_dir);

  }else{
    MotorControl(i, 0, false);
    #ifdef Debug
    Serial.print("Stop     ");
    #endif
  }
}

//Hardware Output
void MotorControl(byte _Motor, byte _Speed, bool _Direction){
  if (_Speed > 0) {
    if(ContinuousMovement == 0){
      if(!moving[_Motor] || _Direction != Last_Direction[_Motor]){  //Mech Error detection
        Last_Direction[_Motor] = _Direction;
        moving[_Motor] = true;
        startTime[_Motor] = millis();
        startDiff[_Motor] = abs(goalAngle[_Motor]-actuatorStates[_Motor]);
      }else if(millis()-startTime[_Motor] > errorTime && startDiff[_Motor] - errorMinDiff <= abs(goalAngle[_Motor]-actuatorStates[_Motor])){
        errorT[_Motor] = true; //Time Error dedected
      }
    }
    

    if(!error[_Motor] && !errorT[_Motor]){
      if(reversed_output[_Motor])
        _Direction = !_Direction;
      #ifdef Debug_Motor
        Serial.print("Beweg:");
        Serial.print(_Speed);
        Serial.print(" ");
      #endif
      digitalWrite(Pin_motorA[_Motor], _Direction);
      digitalWrite(Pin_motorB[_Motor], !_Direction);
      analogWrite(Pin_motorPWM[_Motor], _Speed);
      return;
    }
  }
  // If the Speed is 0, stop the motors
  digitalWrite(Pin_motorA[_Motor], true);  // High,High = short break
  digitalWrite(Pin_motorB[_Motor], true);
  moving[_Motor] = false;
}