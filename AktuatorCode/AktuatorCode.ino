// Includes
#include "config.h"


// Initialization of the In/Output Ports
const byte Pot[4] = {7,5,3,1};
const byte MotorPWM[4] = {3,6,9,11};
const byte MotorA[4] = {2,5,8,12};
const byte MotorB[4] = {4,7,10,13};

// Initialization of the state Arrays
int AktuatorStates[4];
int GoalAngle[4];
int CurrentStep[4] = {0, 0, 0, 0};
int MotorSteps[4][5];
bool dir[4] = {true, true, true, true};


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
    AktuatorStates[i] = map(analogRead(Pot[i]), min_pot, max_pot, min, max);
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
        CurrentStep[0] = 0;
      }
      else if (b == '2') {
        GoalAngle[1] = Serial.parseInt();
        CurrentStep[1] = 0;
      }
      else if (b == '3') {
        GoalAngle[2] = Serial.parseInt();
        CurrentStep[2] = 0;
      }
      else if (b == '4') {
        GoalAngle[3] = Serial.parseInt();
        CurrentStep[3] = 0;
      }
    }
  }

  for(int i = 0; i < 1; i++){
    
    // Reading in data from the Potentiometers + mapping
    AktuatorStates[i] = map(analogRead(Pot[i]), min_pot, max_pot, min, max);

    if(CurrentStep[i] == 1){
      // Initialization of the direction, depending on the current position relative to the goal position
      if(AktuatorStates[i] > GoalAngle[i])
        dir[i] = false;
      if(AktuatorStates[i] < GoalAngle[i])
        dir[i] = true;
        
      // Calculating the Steps required to reach the goal angle
      CalculateSteps(GoalAngle[i], i);
    }

    // Couple of debug outputs
    Serial.print(analogRead(Pot[i]));
    Serial.print(", ");
    Serial.print(AktuatorStates[i]);
    Serial.print(", ");
    Serial.print(GoalAngle[i]);
    Serial.print(", ");
    Serial.print(MotorSteps[i][0]);
    Serial.print(" ");
    Serial.print(MotorSteps[i][1]);
    Serial.print(" ");
    Serial.print(MotorSteps[i][2]);
    Serial.print(" ");
    Serial.print(MotorSteps[i][3]);
    Serial.print(", ");
    Serial.print(CurrentStep[i]);
    Serial.print(", ");
    Serial.print(dir[i]);
    Serial.println();

    // Check if the current step has been reached according to the deadzone and direction
    if(dir[i]){  
      if(AktuatorStates[i] >= (MotorSteps[i][CurrentStep[i]]) - (deadzone * (upwards - 1)) || CurrentStep[i] == 1){
        // Check if the motor should currently be driving
        if(CurrentStep[i] == 4)
          MotorControl(i, 0, dir[i]);
        else{
          // Update the current step and drive until the next point is reached
          CurrentStep[i] = CalculatedControl(i, CurrentStep[i], dir[i]);
        }
      }
    }
    else{  
      if(AktuatorStates[i] <= (MotorSteps[i][CurrentStep[i]]) + (deadzone * (upwards + 1)) || CurrentStep[i] == 1){
        // Check if the motor should currently be driving
        if(CurrentStep[i] == 4)
          MotorControl(i, 0, dir[i]);
        else{
          // Update the current step and drive until the next point is reached
          CurrentStep[i] = CalculatedControl(i, CurrentStep[i], dir[i]);
        }
      }
    }

  }

}


void CalculateSteps(int GoalAngle, byte Motor){

  // Waypoints get Calculated depending on the driving direction

  MotorSteps[Motor][3] = GoalAngle;
  MotorSteps[Motor][4] = GoalAngle;

  if(dir[Motor]){
    MotorSteps[Motor][0] = AktuatorStates[Motor] + deadzone;
    MotorSteps[Motor][1] = GoalAngle - 20;
    MotorSteps[Motor][2] = GoalAngle - 10;
  }

  else{
    MotorSteps[Motor][0] = AktuatorStates[Motor] - deadzone;
    MotorSteps[Motor][1] = GoalAngle + 20;
    MotorSteps[Motor][2] = GoalAngle + 10;
  }

}


int CalculatedControl(byte Motor, int CurrentState, bool dir){

  // Motor drives until the next waypoint is reached and returns the index of the next waypoint

  if(CurrentState == 0){
    MotorControl(Motor, Speed1, dir);
    return 1;
  }

  else if(CurrentState == 1){
    MotorControl(Motor, Speed2, dir);
    return 2;
  }

  else if(CurrentState == 2){
    MotorControl(Motor, Speed3, dir);
    return 3;
  }

  else if(CurrentState == 3){
    MotorControl(Motor, Speed4, dir);
    return 4;
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

  // If the speed is 0, stop the motors

  digitalWrite(MotorA[Motor], false);
  digitalWrite(MotorB[Motor], false);

}
