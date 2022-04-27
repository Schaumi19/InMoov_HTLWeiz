// Includes
#include "config.h"
#include <Servo.h>

//for hardcoded testing states
int state = 0;
unsigned long statetime = 0;

// Initialization of the In/Output Ports
const byte Pot[4] = {A1,A3,A4,A6};
const byte Pot2[4] = {A0,A2,A5,A7};
const byte MotorPWM[4] = {11,9,6,3};
const byte MotorA[4] = {12,10,5,4};
const byte MotorB[4] = {13,8,7,2};
const int servoPins[4] = {A0, 0, 0, 0};

// Initialization of the state Arrays
int AktuatorStates[4] = {0, 0, 0, 0};
int GoalAngle[4] = {0, 0, 0, 0};

//Mechanical Error Detection
bool moving[4] = {false,false,false,false};
int startDiff[4] = {0,0,0,0};
unsigned long StartTime[4] = {0,0,0,0};

Servo servos[4] = {Servo(), Servo(), Servo(), Servo()};
bool error[4] = {false,false,false,false};

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
      pinMode(MotorPWM[i], OUTPUT);
      pinMode(MotorA[i], OUTPUT);
      pinMode(MotorB[i], OUTPUT);
      if(isServo[i]){
        servos[i].attach(servoPins[i]);
        digitalWrite(MotorPWM[i], HIGH);
        digitalWrite(MotorA[i], HIGH);
        digitalWrite(MotorB[i], LOW);
      }else{
        pinMode(Pot[i], INPUT);
        pinMode(Pot2[i],INPUT);
      }
    }
  }

  // Reading in data from the Potentiometers
  delay(500);
  for (byte i = 0; i < 4; i++)
  {
    if(!isServo[i]){
      int readValue = analogRead(Pot[i]);
      if(used[i]&&(readValue-5 > max_pot[i] || readValue+5 < min_pot[i]))
        error[i] = true;
      AktuatorStates[i] = map(readValue, min_pot[i], max_pot[i], min[i], max[i]);
      GoalAngle[i] = AktuatorStates[i]; //Aktuators should not move from IC-start
    }
  }
  
}

void loop() {

  //hardcoded();

  readSerial();

  #ifdef Debug
    Serial.println(";");  //Line ending
  #endif

  if(error){
    //Serial.print("Error");
  }

  for(byte i = 0; i < 4; i++){
    if(isServo[i]){
      if(AktuatorStates[i] != GoalAngle[i]){
        servos[i].write(map(GoalAngle[i],min[i],max[i],min_pot[i],max_pot[i]));
        AktuatorStates[i] = GoalAngle[i];
      }
      #ifdef Debug
        Serial.print(" ");
        Serial.print(AktuatorStates[i]);
        Serial.print(" ");
      #endif
    }
    else if(ContinuousMovement[i] == 0){
      // Reading in data from the Potentiometers + mapping
      int _readValue = analogRead(Pot[i]);
      if(used[i]&&(_readValue-5 > max_pot[i] || _readValue+5 < min_pot[i]))
        error[i] = true;
      AktuatorStates[i] = map(_readValue, min_pot[i], max_pot[i], min[i], max[i]);
      #ifdef Debug
        Serial.print(" ");
        Serial.print(analogRead(Pot[i]));
        Serial.print("/");
        Serial.print(GoalAngle[i]);
        Serial.print("/");
        Serial.print(AktuatorStates[i]);
        Serial.print(" ");
      #endif
      normalControl(i);
    }else{
      MotorControl(i, ContinuousMovement[i], true);
    }
  }
}

int HardStopSave(int Angle, int MotorIndex){
  if(Angle > max[MotorIndex])
    Angle = max[MotorIndex];
  else if(Angle < min[MotorIndex])
    Angle = min[MotorIndex];
  return Angle;
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
      byte AkIndex = Serial.parseInt();
      Serial.readStringUntil(',');
      byte Angle = Serial.parseInt();
      #ifdef Debug_Serial
      Serial.print(' ' +String(AkIndex)+ ':' +String(Angle) + ' ');
      #endif
      if (AkIndex == 0){    //All
        for (byte i = 0; i < 4; i++){
            GoalAngle[i] = HardStopSave(Angle,i);
        }
      }
      else if (AkIndex <= 4){
          GoalAngle[AkIndex-1] = HardStopSave(Angle,AkIndex-1);
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
  if((AktuatorStates[i] < GoalAngle[i] && AktuatorStates[i] < (GoalAngle[i] - goalDeadzone)) ||(AktuatorStates[i] > GoalAngle[i] &&  AktuatorStates[i] > (GoalAngle[i] + goalDeadzone))){ //Do we even need to move
    #ifdef Debug
    Serial.print("Move");
    #endif
    bool _dir = GoalAngle[i] > AktuatorStates[i];
    if((_dir&&AktuatorStates[i]+SlowSpeedZone[i]>GoalAngle[i])||(!_dir&&AktuatorStates[i]-SlowSpeedZone[i]<GoalAngle[i]))
      MotorControl(i,SlowSpeed[i],_dir);
    else
      MotorControl(i,255,_dir);

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
    if(!moving[_Motor]){  //Mech Error detection
      moving[_Motor] = true;
      StartTime[_Motor] = millis();
      startDiff[_Motor] = abs(GoalAngle[_Motor]-AktuatorStates[_Motor]);
    }else if(millis()-StartTime[_Motor] > 500 && startDiff[_Motor] - 2 > abs(GoalAngle[_Motor]-AktuatorStates[_Motor])){
      error[_Motor] = true;
    }
    if(!error[_Motor]){
      if(reversed[_Motor])
      _Direction = !_Direction;
    #ifdef Debug_Motor
    Serial.print("Beweg:");
    Serial.print(_Speed);
    Serial.print(" ");
    #endif
    digitalWrite(MotorA[_Motor], _Direction);
    digitalWrite(MotorB[_Motor], !_Direction);
    analogWrite(MotorPWM[_Motor], _Speed);
    return;
    }
  }
  // If the Speed is 0, stop the motors
  digitalWrite(MotorA[_Motor], true);  // High,High = short break
  digitalWrite(MotorB[_Motor], true);
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
      GoalAngle[0] = 50;
      GoalAngle[1] = 70;
      GoalAngle[2] = 70;
      GoalAngle[3] = 70;
    break;
  case 1:
      GoalAngle[0] = 60;
      GoalAngle[1] = 100;
      GoalAngle[2] = 100;
      GoalAngle[3] = 100;
    break;
  case 2:
      GoalAngle[0] = 90;
      GoalAngle[1] = 120;
      GoalAngle[2] = 120;
      GoalAngle[3] = 120;
    break;
  case 3:
      GoalAngle[0] = 115;
      GoalAngle[1] = 150;
      GoalAngle[2] = 150;
      GoalAngle[3] = 150;
    break;
  case 4:
      GoalAngle[0] = 115;
      GoalAngle[1] = 180;
      GoalAngle[2] = 180;
      GoalAngle[3] = 180;
    break;
  default:
    break;
  }
}