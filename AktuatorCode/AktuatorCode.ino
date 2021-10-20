#include "config.h"


const byte Pot[4] = {7,5,3,1};
const byte MotorPWM[4] = {3,6,9,11};
const byte MotorA[4] = {2,5,8,12};
const byte MotorB[4] = {4,7,10,13};

int AktuatorStates[4];

uint16_t Anfahren = 0;
uint16_t DG1 = 0;
uint16_t DG2 = 0;

uint16_t cPTDT = 0;

bool angefahren = false;
bool dg1 = false;
bool dg2 = false;
bool stopped = false;

uint16_t P3_std = P3;
uint16_t P4_std = P4;


void setup() {

  for(int i = 0; i < 4;i++){
    pinMode(Pot[i], INPUT);
    pinMode(MotorPWM[i], OUTPUT);
    pinMode(MotorA[i], OUTPUT);
    pinMode(MotorB[i], OUTPUT);
  }
 
  Serial.begin(115200);
  
  AktuatorStates[0] = map(analogRead(Pot[0]), 0, 1023, 0, 275);

  if(AktuatorStates[0] < PTDT){
    Anfahren = AktuatorStates[0] + 100;
    DG1 = PTDT - 20;
    DG2 = PTDT - 10;
  }

  else if(AktuatorStates[0] > PTDT){
    Anfahren = AktuatorStates[0] - 10;
    DG1 = PTDT + 20;
    DG2 = PTDT + 10;
  }

}


void loop() {

  if (Serial.available() && Serial.read() == FirstPos) { //R = Right; L = Left; M = Middle
    while(!Serial.available());
    char b = Serial.read();
    if (b == SecondPos) { //h = hand/head; s = shoulder; t = torso;
      while(!Serial.available());
      char b = Serial.read();
      if (b == 'a') {
        PTDT = Serial.parseInt();
      }
    }
  }
  
  AktuatorStates[0] = map(analogRead(Pot[0]), 0, 1023, 0, 275);

  if(AktuatorStates[0] > PTDT){
    P3 = P2;
    P4 = P2;
  }

  else{
    P3 = P3_std;
    P4 = P4_std;
  }

  if(AktuatorStates[0] < PTDT){
    if(AktuatorStates[0] < PTDT - deadzone){
      Anfahren = AktuatorStates[0] + deadzone;
      DG1 = PTDT - 20;
      DG2 = PTDT - 10;

      angefahren = false;
      dg1 = false;
      dg2 = false;
      stopped = false;
    }
    
  }

  else if(AktuatorStates[0] > PTDT){
    if(AktuatorStates[0] > PTDT + deadzone){
      Anfahren = AktuatorStates[0] - deadzone;
      DG1 = PTDT + 20;
      DG2 = PTDT + 10;

      angefahren = false;
      dg1 = false;
      dg2 = false;
      stopped = false;
    }
  }

  if(AktuatorStates[0] != PTDT && !stopped){
    
    if(AktuatorStates[0] < PTDT){

      if(!angefahren && !dg1 && !dg2 && !stopped){

        cPTDT = Anfahren;

        while(AktuatorStates[0] < cPTDT){

          AktuatorStates[0] = map(analogRead(Pot[0]), 0, 1023, 0, 275);
          MotorControl(0, P1, true);

        }

        angefahren = true;

      }

      if(angefahren && !dg1 && !dg2 && !stopped){

        cPTDT = DG1;

        while(AktuatorStates[0] < cPTDT){

          AktuatorStates[0] = map(analogRead(Pot[0]), 0, 1023, 0, 275);
          MotorControl(0, P2, true);

        }
      
        dg1 = true;

      }

      if(angefahren && dg1 && !dg2 && !stopped){

        cPTDT = DG2;

        while(AktuatorStates[0] < cPTDT){

          AktuatorStates[0] = map(analogRead(Pot[0]), 0, 1023, 0, 275);
          MotorControl(0, P3, true);

        }

        dg2 = true;
      
      }

      if(angefahren && dg1 && dg2 && !stopped){

        cPTDT = PTDT;

        while(AktuatorStates[0] < cPTDT){

          AktuatorStates[0] = map(analogRead(Pot[0]), 0, 1023, 0, 275);
          MotorControl(0, P4, true);

        }
      
        stopped = true;

      }

      if(stopped){

        MotorControl(0, 0, true);

      }

    }


    else if(AktuatorStates[0] > PTDT){

      if(!angefahren && !dg1 && !dg2 && !stopped){

        cPTDT = Anfahren;

        while(AktuatorStates[0] > cPTDT){

          AktuatorStates[0] = map(analogRead(Pot[0]), 0, 1023, 0, 275);
          MotorControl(0, P1, false);

        }

        angefahren = true;

      }

      if(angefahren && !dg1 && !dg2 && !stopped){

        cPTDT = DG1;

        while(AktuatorStates[0] > cPTDT){

          AktuatorStates[0] = map(analogRead(Pot[0]), 0, 1023, 0, 275);
          MotorControl(0, P2, false);

        }
      
        dg1 = true;

      }

      if(angefahren && dg1 && !dg2 && !stopped){

        cPTDT = DG2;

        while(AktuatorStates[0] > cPTDT){

          AktuatorStates[0] = map(analogRead(Pot[0]), 0, 1023, 0, 275);
          MotorControl(0, P3, false);

        }

        dg2 = true;
      
      }

      if(angefahren && dg1 && dg2 && !stopped){

        cPTDT = PTDT;

        while(AktuatorStates[0] > cPTDT){

          AktuatorStates[0] = map(analogRead(Pot[0]), 0, 1023, 0, 275);
          MotorControl(0, P4, false);

        }
      
        stopped = true;

      }

      if(stopped){

        MotorControl(0, 0, false);

      }

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
