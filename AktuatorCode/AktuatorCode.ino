// Includes
#include "config.h"


// Initialization of the In/Output Ports
const byte Pot[4] = {7,5,3,1}; 
const byte MotorPWM[4] = {3,6,9,11};
const byte MotorA[4] = {2,5,8,12};
const byte MotorB[4] = {4,7,10,13};

// Initialization of the state Arrays
int AktuatorStates[4];
int GoalAngle[4] = {0, 0, 0, 0};
int MotorSteps[4][2];
bool dir[4] = {true, true, true, true};

double Speed[4] = {0, 0, 0, 0};
bool driving[4] = {false, false, false, false};


void setup() {

  // Change pins to IN/OUTPUT - mode
  for(int i = 0; i < 4;i++){
    pinMode(Pot[i], INPUT);
    pinMode(MotorPWM[i], OUTPUT);
    pinMode(MotorA[i], OUTPUT);
    pinMode(MotorB[i], OUTPUT);
  }

  // Setting up the serial
  Serial.begin(115200);

  // Reading in data from the Potentiometers + mapping
  for (size_t i = 0; i < 4; i++)
  {
    AktuatorStates[i] = map(analogRead(Pot[i]), min_pot[i], max_pot[i], min, max);
  }

}


void loop() {

  // Reading in a string from Serial and computing it
  if (Serial.available() && Serial.read() == FirstPos) {
    while(!Serial.available());
    char b = Serial.read();
    if (b == SecondPos) {
      while(!Serial.available());
      char b = Serial.read();
      if (b == '1') {
        GoalAngle[0] = Serial.parseInt();
        Speed[0] = 0;
      }
      else if (b == '2') {
        GoalAngle[1] = Serial.parseInt();
        Speed[1] = 0;
      }
      else if (b == '3') {
        GoalAngle[2] = Serial.parseInt();
        Speed[2] = 0;
      }
      else if (b == '4') {
        GoalAngle[3] = Serial.parseInt();
        Speed[3] = 0;
      }
    }
  }

  for(int i = 0; i < 2; i++){
    
    // Reading in data from the Potentiometers + mapping
    AktuatorStates[i] = map(analogRead(Pot[i]), min_pot[i], max_pot[i], min, max);

    if(!(AktuatorStates[i] <= (GoalAngle[i] + goalDeadzone) && AktuatorStates[i] >= (GoalAngle[i] - goalDeadzone))){
      // Initialization of the direction, depending on the current position relative to the goal position
      if(AktuatorStates[i] > GoalAngle[i])
        dir[i] = false;
      if(AktuatorStates[i] < GoalAngle[i])
        dir[i] = true;
      driving[i] = true;
    }
    else{
      MotorSteps[i][0] = GoalAngle[i];
    }
        
    // Calculating the Steps required to reach the goal angle
    CalculateSteps(GoalAngle[i], i);

    // Couple of debug outputs
    Serial.print(analogRead(Pot[i]));
    Serial.print(", ");
    Serial.print(AktuatorStates[i]);
    Serial.print(", ");
    Serial.print(GoalAngle[i]);
    Serial.print(", ");
    Serial.print(dir[i]);
    Serial.print(", ");
    Serial.print((int) Speed[i]);
    Serial.println();

    if(schmuf[i]){
      if(dir[i]){  
        if(AktuatorStates[i] >= MotorSteps[i][1] && !(AktuatorStates[i] >= (MotorSteps[i][1])) && driving[i]){
          MotorControl(i, Speed[i], dir[i]);
          Speed[i]-=SpeedModifier[i];
        }
        else if(AktuatorStates[i] <= MotorSteps[i][0] && !(AktuatorStates[i] >= (MotorSteps[i][1])) && driving[i]){
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
        if(AktuatorStates[i] <= MotorSteps[i][1] && !(AktuatorStates[i] <= (MotorSteps[i][1])) && driving[i]){
          MotorControl(i, (int) Speed[i], dir[i]);
          Speed[i]-=SpeedModifier[i];
        }
        else if(AktuatorStates[i] >= MotorSteps[i][0] && !(AktuatorStates[i] <= (MotorSteps[i][1])) && driving[i]){
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
    else{
      if(dir[i]){  
        if(AktuatorStates[i] >= MotorSteps[i][1] && !(AktuatorStates[i] >= (MotorSteps[i][1])) && driving[i]){
          MotorControl(i, Speed[i], dir[i]);
          Speed[i]=150;
        }
        else if(AktuatorStates[i] <= MotorSteps[i][0] && !(AktuatorStates[i] >= (MotorSteps[i][1])) && driving[i]){
          MotorControl(i, Speed[i], dir[i]);
          Speed[i]=250; 
        }
        else{
          MotorControl(i, 0, dir[i]);
          Speed[i] = 0;
          driving[i] = false;
        }
      }
      else{  
        if(AktuatorStates[i] <= MotorSteps[i][1] && !(AktuatorStates[i] <= (MotorSteps[i][1])) && driving[i]){
          MotorControl(i, (int) Speed[i], dir[i]);
          Speed[i]=150;
        }
        else if(AktuatorStates[i] >= MotorSteps[i][0] && !(AktuatorStates[i] <= (MotorSteps[i][1])) && driving[i]){
          MotorControl(i, (int) Speed[i], dir[i]);
          Speed[i]=250; 
        }
        else{
          MotorControl(i, 0, dir[i]);
          Speed[i] = 0;
          driving[i] = false;
        }
      }
    }
  }
  Serial.println();
}


void CalculateSteps(int GoalAngle, byte Motor){

  // Waypoints get Calculated depending on the driving direction
  int diff;
  if(dir[Motor]){
    diff = GoalAngle - AktuatorStates[Motor];
    MotorSteps[Motor][0] = AktuatorStates[Motor] + diff;
    MotorSteps[Motor][1] = GoalAngle;
  }

  else{
    diff = GoalAngle + AktuatorStates[Motor];
    MotorSteps[Motor][0] = AktuatorStates[Motor] - diff;
    MotorSteps[Motor][1] = GoalAngle;
  }

}


void MotorControl(byte Motor, byte Speed, bool Direction){

  // Motor driving code

  if (Speed > 0) {
    analogWrite(MotorPWM[Motor], Speed);

    digitalWrite(MotorA[Motor], Direction);
    digitalWrite(MotorB[Motor], !Direction);

    return;
  }

  // If the Speed is 0, stop the motors

  digitalWrite(MotorA[Motor], false);
  digitalWrite(MotorB[Motor], false);

}
