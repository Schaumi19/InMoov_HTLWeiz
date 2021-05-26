#include "config.h"


const byte Pot[4] = {0,1,2,3};
const byte MotorPWM[4] = {5,6,9,10};
const byte MotorA[4] = {2,7,8,12};
const byte MotorB[4] = {3,4,11,13};

int AktuatorStates[4];

void setup() {
  for(int i = 0; i < 4;i++){
    pinMode(Pot[i], INPUT);
    pinMode(MotorPWM[i], OUTPUT);
    pinMode(MotorA[i], OUTPUT);
    pinMode(MotorB[i], OUTPUT);
  }
 
  Serial.begin(Baudrate);
  Serial.print(FirstPos+SecondPos);
}

void loop() {

  for (int i = 0; i < 4; i++) {
    AktuatorStates[i] = map(analogRead(Pot[i]), 0, 1023, 0, 180);
  }
  for(int i = 0; i < 4; i++){
    if(AktuatorStates[i] < 80){
      MotorControl(i,255,true);
    }else if(AktuatorStates[i] > 100){
      MotorControl(i,255,false);
    }
    else{
      MotorControl(i,0,true);
    }
  }

}

void MotorControl(byte Motor, byte Speed, bool Direction){
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
