// Includes
#include "config.h"
#include <Servo.h>

//error Detection Settings
const int errorTime = 500;
const int errorMinDiff = 2;

//for hardcoded testing states
int state = 0;
unsigned long statetime = 0;

// Initialization of the In/Output Ports
const byte pot[4] = {A1,A3,A4,A6};
const byte pot2[4] = {A0,A2,A5,A7};
const byte motorPWM[4] = {11,9,6,3};
const byte motorA[4] = {12,10,5,4};
const byte motorB[4] = {13,8,7,2};
const int servoPins[4] = {A0, 0, 0, 0};

// Initialization of the state Arrays
int aktuatorStates[4] = {0, 0, 0, 0};
int goalAngle[4] = {0, 0, 0, 0};

//Mechanical Error Detection
bool moving[4] = {false,false,false,false};
int startDiff[4] = {0,0,0,0};
unsigned long startTime[4] = {0,0,0,0};

Servo servos[4] = {Servo(), Servo(), Servo(), Servo()};
bool error[4] = {false,false,false,false};
bool errorT[4] = {false,false,false,false};

void setup() {

  // Setting up the serial
  Serial.begin(115200);
  while(!Serial);
  Serial.write(ACP_B1);
  Serial.write(ACP_B2);

  delay(500);

  // Change pins to IN/OUTPUT - mode
  for(int i = 0; i < 4;i++){
    if(used[i]){
      pinMode(motorPWM[i], OUTPUT);
      pinMode(motorA[i], OUTPUT);
      pinMode(motorB[i], OUTPUT);
      if(isServo[i]){
        servos[i].attach(servoPins[i]);
        digitalWrite(motorPWM[i], HIGH);
        digitalWrite(motorA[i], HIGH);
        digitalWrite(motorB[i], LOW);
      }else{
        pinMode(pot[i], INPUT);
        pinMode(pot2[i],INPUT);
      }
    }
  }

  // Reading in data from the Potentiometers
  delay(500);
  for (byte i = 0; i < 4; i++)
  {
    if(used[i] && !isServo[i] && ContinuousMovement[i] == 0){
      int readValue = analogRead(pot[i]);
      if(used[i]&&(readValue > max_pot[i] || readValue < min_pot[i])){
        error[i] = true;
        Serial.print("New Error");
      }
      aktuatorStates[i] = map(readValue, min_pot[i], max_pot[i], min[i], max[i]);
      goalAngle[i] = aktuatorStates[i]; //Aktuators should not move from IC-start
    }
  }
  
}

void loop() {

  //hardcoded();

  readSerial();

  #ifdef Debug
    Serial.println(";");  //Line ending
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
    if(isServo[i]){
      if(aktuatorStates[i] != goalAngle[i]){
        servos[i].write(map(goalAngle[i],min[i],max[i],min_pot[i],max_pot[i]));
        aktuatorStates[i] = goalAngle[i];
      }
      #ifdef Debug
        Serial.print(" ServoState:");
        Serial.print(aktuatorStates[i]);
        Serial.print(" ");
      #endif
    }
    else if(ContinuousMovement[i] == 0){
      // Reading in data from the Potentiometers + mapping
      int _readValue = analogRead(pot[i]);

      if(used[i]&&(_readValue-5 > max_pot[i] || _readValue+5 < min_pot[i]))
        error[i] = true;

      aktuatorStates[i] = map(_readValue, min_pot[i], max_pot[i], min[i], max[i]);

      #ifdef Debug
        Serial.print(" ");
        Serial.print(i);
        Serial.print(" P:");
        Serial.print(analogRead(pot[i]));
        Serial.print(" G:");
        Serial.print(goalAngle[i]);
        Serial.print(" I:");
        Serial.print(aktuatorStates[i]);
        Serial.print(" ");
      #endif

      normalControl(i);
    }else{
      MotorControl(i, ContinuousMovement[i], true);
    }
  }
}

int HardStopSave(int _angle, int _motorIndex){
  if(_angle > max[_motorIndex])
    _angle = max[_motorIndex];
  else if(_angle < min[_motorIndex])
    _angle = min[_motorIndex];
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
      if (_AkIndex == 0){    //All
        for (byte i = 0; i < 4; i++){
            goalAngle[i] = HardStopSave(_angle,i);
        }
      }
      else if (_AkIndex <= 4){
          goalAngle[_AkIndex-1] = HardStopSave(_angle,_AkIndex-1);
      }
      else{
        //Error Value out of Range
      }
    }
  }else{
    //Serial.print("not avalible");
  }
}


void normalControl(int i){
  if((aktuatorStates[i] < goalAngle[i] && aktuatorStates[i] < (goalAngle[i] - goalDeadzone)) ||(aktuatorStates[i] > goalAngle[i] &&  aktuatorStates[i] > (goalAngle[i] + goalDeadzone))){ //Do we even need to move
    #ifdef Debug
    Serial.print("Move");
    #endif
    bool _dir = goalAngle[i] > aktuatorStates[i];
    if((_dir&&aktuatorStates[i]+SlowSpeedZone[i]>goalAngle[i])||(!_dir&&aktuatorStates[i]-SlowSpeedZone[i]<goalAngle[i]))
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
    Serial.print("E1");
    if(!moving[_Motor]){  //Mech Error detection
      Serial.print("E2");
      moving[_Motor] = true;
      startTime[_Motor] = millis();
      startDiff[_Motor] = abs(goalAngle[_Motor]-aktuatorStates[_Motor]);
    }else if(millis()-startTime[_Motor] > errorTime && startDiff[_Motor] - errorMinDiff <= abs(goalAngle[_Motor]-aktuatorStates[_Motor])){
      Serial.print("EDEC");
      errorT[_Motor] = true;
      
    }
    if(!error[_Motor] && !errorT[_Motor]){
        if(reversed[_Motor])
          _Direction = !_Direction;
      #ifdef Debug_Motor
        Serial.print("Beweg:");
        Serial.print(_Speed);
        Serial.print(" ");
      #endif
      digitalWrite(motorA[_Motor], _Direction);
      digitalWrite(motorB[_Motor], !_Direction);
      analogWrite(motorPWM[_Motor], _Speed);
      return;
    }
  }
  // If the Speed is 0, stop the motors
  digitalWrite(motorA[_Motor], true);  // High,High = short break
  digitalWrite(motorB[_Motor], true);
  moving[_Motor] = false;
}

//For testing without serial connection
void hardcoded(){
  if(millis() - statetime >= 2500){
    state++;
    statetime = millis();
    if(state > 4){
      state = 0;
    }
  }
  switch (state)
  {
  case 0:
      goalAngle[0] = 50;
      goalAngle[1] = 70;
      goalAngle[2] = 70;
      goalAngle[3] = 70;
    break;
  case 1:
      goalAngle[0] = 60;
      goalAngle[1] = 100;
      goalAngle[2] = 100;
      goalAngle[3] = 100;
    break;
  case 2:
      goalAngle[0] = 90;
      goalAngle[1] = 120;
      goalAngle[2] = 120;
      goalAngle[3] = 120;
    break;
  case 3:
      goalAngle[0] = 115;
      goalAngle[1] = 150;
      goalAngle[2] = 150;
      goalAngle[3] = 150;
    break;
  case 4:
      goalAngle[0] = 115;
      goalAngle[1] = 180;
      goalAngle[2] = 180;
      goalAngle[3] = 180;
    break;
  default:
    break;
  }
}
