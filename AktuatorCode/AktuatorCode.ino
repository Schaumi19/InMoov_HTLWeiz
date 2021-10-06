#include "config.h"


const byte Pot[4] = {1,3,5,7};
const byte MotorPWM[4] = {3,6,9,11};
const byte MotorA[4] = {2,5,8,12};
const byte MotorB[4] = {4,7,10,13};

int AktuatorStates[4];


void setup() {
  for(int i = 0; i < 4;i++){
    pinMode(Pot[i], INPUT);
    pinMode(MotorPWM[i], OUTPUT);
    pinMode(MotorA[i], OUTPUT);
    pinMode(MotorB[i], OUTPUT);
  }
 
  Serial.begin(115200);
  Serial.print(FirstPos+SecondPos);

  for(int i = 0; i < 4; i++){
    MotorControl(i, 255, true);
    Serial.print("Carl");
  }

  while (true);
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
    }

    else if(AktuatorStates[i] > 130){
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
