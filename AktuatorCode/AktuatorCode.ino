#include "config.h"


const byte Pot[4] = {1,3,5,7};
const byte MotorPWM[4] = {3,6,9,11};
const byte MotorA[4] = {2,4,8,10};
const byte MotorB[4] = {5,7,12,13};

int AktuatorStates[4];

void setup() {
  for(int i = 0; i < 4;i++){
    pinMode(Pot[i], INPUT);
    pinMode(MotorPWM[i], OUTPUT);
    pinMode(MotorA[i], OUTPUT);
    pinMode(MotorB[i], OUTPUT);
  }
 
  Serial.begin(9600);
  Serial.print(FirstPos+SecondPos);
}

void loop() {

  for (int i = 0; i < 4; i++) {
    AktuatorStates[i] = map(analogRead(Pot[i]), 0, 1023, 0, 255);
    Serial.print(AktuatorStates[i]);
    Serial.print(" ");
  }
  Serial.println();
  for(int i = 0; i < 4; i++){
    if(AktuatorStates[i] < 110){
      MotorControl(i,AktuatorStates[i],true);
    }else if(AktuatorStates[i] > 130){
      MotorControl(i,AktuatorStates[i],false);
    }
    else{
      MotorControl(i,0,true);
    }
  }

  delay(100);

}

void MotorControl(byte Motor, byte Speed, bool Direction){
  if (Speed > 0) {
    analogWrite(MotorPWM[0], Speed);
    analogWrite(MotorPWM[1], Speed);
    analogWrite(MotorPWM[2], Speed);
    analogWrite(MotorPWM[3], Speed);
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
