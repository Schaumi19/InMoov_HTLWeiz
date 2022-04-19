// Includes
#include "config.h"
#include <Servo.h>


// Initialization of the In/Output Ports
const byte Pot[4] = {6,4,3,1};
const byte Pot2[4] = {7,5,2,0};
const byte MotorPWM[4] = {3,6,9,11};
const byte MotorA[4] = {2,5,8,12};
const byte MotorB[4] = {4,7,10,13};

// Initialization of the state Arrays
int AktuatorStates[4] = {0, 0, 0, 0};
int GoalAngle[4] = {0, 0, 0, 0};
int MotorSteps[4][2];
bool dir[4] = {true, true, true, true};

double Speed[4] = {0, 0, 0, 0};
bool driving[4] = {false, false, false, false};

Servo servos[4] = {Servo(), Servo(), Servo(), Servo()};


void setup() {

  // Setting up the serial
  Serial.begin(115200);
  while(!Serial);
  Serial.write(ACP_B1);
  Serial.write(ACP_B2);

  delay(500);

  // Change pins to IN/OUTPUT - mode
  for(int i = 0; i < 4;i++){
    pinMode(Pot[i], INPUT);
    pinMode(MotorPWM[i], OUTPUT);
    pinMode(MotorA[i], OUTPUT);
    pinMode(MotorB[i], OUTPUT);
    if(isServo[i]){
      servos[i].attach(servoPins[i]);
      digitalWrite(MotorPWM[i], HIGH);
      digitalWrite(MotorA[i], HIGH);
      digitalWrite(MotorB[i], LOW);
    }
  }

  // Reading in data from the Potentiometers + mapping
  for (size_t i = 0; i < 4; i++)
  {
    AktuatorStates[i] = map(analogRead(Pot[i]), min_pot[i], max_pot[i], min[i], max[i]);
    GoalAngle[i] = AktuatorStates[i];
    checkDir(i);
  }

}


void loop() {

  readSerial();

  Serial.print(";");
  for(int i = 0; i < 4; i++){

    if(isServo[i])
      AktuatorStates[i] = servos[i].read();

    else{
      // Reading in data from the Potentiometers + mapping
      AktuatorStates[i] = getAktuator(i);
      if(!(AktuatorStates[i] <= (GoalAngle[i] + goalDeadzone) && 
           AktuatorStates[i] >= (GoalAngle[i] - goalDeadzone))){
      }else{
        MotorSteps[i][0] = GoalAngle[i];
      }
      normalControl(i);
    }
    Serial.write(AktuatorStates[i]);
  }
}

int getAktuator(byte i){
  return map(analogRead(Pot[i]), min_pot[i], max_pot[i], min[i], max[i]);
}

// Reading in a string from Serial and computing it
void readSerial(){
  if(Serial.available()){
    byte AkIndex = Serial.parseInt();
    byte Angle = Serial.parseInt();
    if (AkIndex == 0){    //All
      for (byte i = 0; i < 4; i++)
      {
        if(isServo[i])
          servos[i].write(map(Angle, min[i], max[i], min_pot[i], max_pot[i]));
        else{
          setAngleSpeed(i, map(Angle, min[i], max[i], min_pot[i], max_pot[i]), 0);
        }
      }
    }
    else if (AkIndex <= 4){
      if(isServo[AkIndex-1])
        servos[AkIndex-1].write(map(Serial.parseInt(), min[AkIndex-1], max[AkIndex-1], min_pot[AkIndex-1], max_pot[AkIndex-1]));
      else{
        setAngleSpeed(AkIndex-1, map(Serial.parseInt(), min[AkIndex-1], max[AkIndex-1], min_pot[AkIndex-1], max_pot[AkIndex-1]), 0);}
    }
    else{
      //Error Value out of Range
    }
  }
}


void setAngleSpeed(byte motor, int goalAngle, int speed){
  GoalAngle[motor] = goalAngle;
  Speed[motor] = speed;
}


void normalControl(int i){
  if(AktuatorStates[i] == GoalAngle[i]){
    MotorControl(i, 0, true);
    Speed[i] = 0;
  }else{
    if(AktuatorStates < GoalAngle){
      if(AktuatorStates[i] <= GoalAngle[i] - Speed1Zone){
        Speed[i]=150;
        MotorControl(i, Speed[i], true);
      }else if(AktuatorStates[i] <= GoalAngle[i] - Speed2Zone){
        Speed[i]=200;
        MotorControl(i, Speed[i], true);
      }else if(AktuatorStates[i] <= GoalAngle[i]){
        Speed[i]=255;
        MotorControl(i, Speed[i], true);
      }
    }else{
      if(AktuatorStates[i] <= GoalAngle[i] - Speed1Zone){
        Speed[i]=150;
        MotorControl(i, Speed[i], true);
      }else if(AktuatorStates[i] <= GoalAngle[i] - Speed2Zone){
        Speed[i]=200;
        MotorControl(i, Speed[i], true);
      }else if(AktuatorStates[i] <= GoalAngle[i]){
        Speed[i]=255;
        MotorControl(i, Speed[i], true);
      }
    }
    
  }
}


void schmufControl(int i){
  if(dir[i]){  
    if(AktuatorStates[i] > MotorSteps[i][0] && 
       !(AktuatorStates[i] < (MotorSteps[i][1])) && driving[i]){

      MotorControl(i, Speed[i], dir[i]);
      Speed[i]-=SpeedModifier[i];
    }
    else if(AktuatorStates[i] <= MotorSteps[i][0] && 
            !(AktuatorStates[i] >= (MotorSteps[i][1])) && driving[i]){

      MotorControl(i, Speed[i], dir[i]);
      Speed[i]+=SpeedModifier[i]; 
    }
    else{

      MotorControl(i, 0, dir[i]);
      Speed[i] = 0;
      driving[i] = false;
    }
  }
  else{  
    if(AktuatorStates[i] < MotorSteps[i][0] && 
       !(AktuatorStates[i] > (MotorSteps[i][1])) && driving[i]){

      MotorControl(i, (int) Speed[i], dir[i]);
      Speed[i]-=SpeedModifier[i];
    }
    else if(AktuatorStates[i] >= MotorSteps[i][0] && 
            !(AktuatorStates[i] <= (MotorSteps[i][1])) && driving[i]){

      MotorControl(i, (int) Speed[i], dir[i]);
      Speed[i]+=SpeedModifier[i]; 
    }
    else{

      MotorControl(i, 0, dir[i]);
      Speed[i] = 0;
      driving[i] = false;
    }
  }
}


// Motor driving code
void MotorControl(byte Motor, byte Speed, bool Direction){

  if (Speed > 0) {
    analogWrite(MotorPWM[Motor], Speed);

    digitalWrite(MotorA[Motor], !(Direction*reversed[Motor]));
    digitalWrite(MotorB[Motor], +(Direction*reversed[Motor]));

    return;
  }

  // If the Speed is 0, stop the motors

  digitalWrite(MotorA[Motor], false);
  digitalWrite(MotorB[Motor], false);

}
