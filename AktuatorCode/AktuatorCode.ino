#include "config.h"


const byte Pot[4] = {7,5,3,1};
const byte MotorPWM[4] = {3,6,9,11};
const byte MotorA[4] = {2,5,8,12};
const byte MotorB[4] = {4,7,10,13};

int AktuatorStates[4];
int GoalAngle[4];
int CurrentStep[4] = {0, 0, 0, 0};
int MotorSteps[4][4];

bool dir = true;


void setup() {

  for(int i = 0; i < 4;i++){
    pinMode(Pot[i], INPUT);
    pinMode(MotorPWM[i], OUTPUT);
    pinMode(MotorA[i], OUTPUT);
    pinMode(MotorB[i], OUTPUT);
  }

  Serial.begin(115200);

  AktuatorStates[0] = map(analogRead(Pot[0]), min_pot, max_pot, min, max);

}


void loop() {

  if (Serial.available() && Serial.read() == FirstPos) {
    while(!Serial.available());
    char b = Serial.read();
    if (b == SecondPos) {
      while(!Serial.available());
      char b = Serial.read();
      if (b == '1') {
        GoalAngle[0] = Serial.parseInt();
        CurrentStep[0] = 1;
      }
      else if (b == '2') {
        GoalAngle[1] = Serial.parseInt();
        CurrentStep[1] = 1;
      }
      else if (b == '3') {
        GoalAngle[2] = Serial.parseInt();
        CurrentStep[2] = 1;
      }
      else if (b == '4') {
        GoalAngle[3] = Serial.parseInt();
        CurrentStep[3] = 1;
      }
    }
  }


  for(int i = 0; i < 4; i++){

    AktuatorStates[i] = map(analogRead(Pot[i]), min_pot, max_pot, min, max);

    if(AktuatorStates[i] > GoalAngle[i])
      dir = false;

    if(AktuatorStates[i] < GoalAngle[i])
      dir = true;

    CalculateSteps(GoalAngle[i], i);

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
    Serial.println();

    if(AktuatorStates[i] == MotorSteps[CurrentStep[i] - 1] || CurrentStep[i] == 1){
      if(CurrentStep[i] == 0)
        MotorControl(i, 0, dir);
      else{
        CurrentStep[i] = CalculatedControl(i, CurrentStep[i]);
      }
    }

  }

}


void CalculateSteps(int GoalAngle, byte Motor){

  // Einzelne Stufen des Weges werden berechnet

  MotorSteps[Motor][3] = GoalAngle;

  if(dir){
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


int CalculatedControl(byte Motor, int CurrentState){

  // Motor fährt zu gewählter Position -> nächste Position wird zurückgegeben

  if(CurrentState == 1){
    MotorControl(Motor, Speed1, dir);
    return 2;
  }

  else if(CurrentState == 2){
    MotorControl(Motor, Speed2, dir);
    return 3;
  }

  else if(CurrentState == 3){
    MotorControl(Motor, Speed3, dir);
    return 4;
  }

  else if(CurrentState == 4){
    MotorControl(Motor, Speed4, dir);
    return 0;
  }

}


void MotorControl(byte Motor, byte Speed, bool Direction){

  // Ansteuerung des Motors

  if (Speed > 0) {
    analogWrite(MotorPWM[Motor], Speed);

    if(Direction){
      digitalWrite(MotorA[Motor], true);
      digitalWrite(MotorB[Motor], false);
    }

    else {
      digitalWrite(MotorA[Motor], false);
      digitalWrite(MotorB[Motor], true);
    }

    return;
  }

  digitalWrite(MotorA[Motor], false);
  digitalWrite(MotorB[Motor], false);

}
