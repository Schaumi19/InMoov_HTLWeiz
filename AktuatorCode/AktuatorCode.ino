// Includes
#include "config.h"
#include <Servo.h>


// Initialization of the In/Output Ports
const byte Pot[4] = {A1,A3,A4,A6};
const byte Pot2[4] = {A0,A2,A5,A7};
const byte MotorPWM[4] = {3,6,9,11};
const byte MotorA[4] = {2,5,8,12};
const byte MotorB[4] = {4,7,10,13};

// Initialization of the state Arrays
int AktuatorStates[4] = {0, 0, 0, 0};
int GoalAngle[4] = {0, 0, 0, 0};
int MotorSteps[4][2];
bool dir[4] = {true, true, true, true};

byte Speed[4] = {0, 0, 0, 0};
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
  delay(500);
  for (byte i = 0; i < 4; i++)
  {
    AktuatorStates[i] = map(analogRead(Pot[i]), min_pot[i], max_pot[i], min[i], max[i]);
    GoalAngle[i] = AktuatorStates[i];
    GoalAngle[i] = 170; //Testing
  }
  
}


void loop() {
  //readSerial();

  Serial.println(";");  //?????? Hot des an sinn?

  for(byte i = 0; i < 4; i++){
    if(isServo[i]){
      if(AktuatorStates[i] != GoalAngle[i]){
        servos[i].write(GoalAngle[i]);
        AktuatorStates[i] = GoalAngle[i];
      }
    }
    else{
      // Reading in data from the Potentiometers + mapping
      AktuatorStates[i] = map(analogRead(Pot[i]), min_pot[i], max_pot[i], min[i], max[i]);
      Serial.print(AktuatorStates[i]);
      Serial.print(" ");
      normalControl(i);
    }
    
    Serial.print("   ");
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
  if(Serial.available() >= 2){
    byte AkIndex = Serial.parseInt();
    byte Angle = Serial.parseInt();
    if (AkIndex == 0){    //All
      for (byte i = 0; i < 4; i++){
        if(isServo[i])
          servos[i].write(HardStopSave(Angle,i));
        else{
          GoalAngle[i] = HardStopSave(Angle,i);
        }
      }
    }
    else if (AkIndex <= 4){
      if(isServo[AkIndex-1])
        servos[AkIndex-1].write(HardStopSave(Angle,AkIndex-1));
      else{
        GoalAngle[AkIndex-1] = HardStopSave(Angle,AkIndex-1);
      }
    }
    else{
      //Error Value out of Range
    }
  }
}


void normalControl(int i){
  int Spx = 0;
  if((AktuatorStates[i] < GoalAngle[i] && AktuatorStates[i] < (GoalAngle[i] - goalDeadzone)) ||(AktuatorStates[i] > GoalAngle[i] &&  AktuatorStates[i] > (GoalAngle[i] + goalDeadzone))){ //Do we even need to move
    Serial.print("Move");
    if(AktuatorStates[i] < GoalAngle[i]){
      Serial.print("1Dir");
      if(AktuatorStates[i] <= GoalAngle[i] - Speed1Zone){
        Speed[i]=150;
      }else if(AktuatorStates[i] <= GoalAngle[i] - Speed2Zone){
        Speed[i]=200;
      }else{
        Speed[i]=255;
      }
      MotorControl(i, Speed[i], true);
    }else{
      Serial.print("2Dir");
      if(AktuatorStates[i] <= GoalAngle[i] + Speed1Zone){
        Speed[i]=150;
        Spx = 151;
      }else if(AktuatorStates[i] <= GoalAngle[i] + Speed2Zone){
        Speed[i]=200;
        Spx = 201;
      }else{
        Spx = 255;
        Speed[i]=255;
      }
      MotorControl(i, Speed[i], false);
      
    }
  }else{
    MotorControl(i, 0, false);
    Speed[i] = 0;
    Serial.print("Stop");
  }
  Serial.print(Speed[i]);
}


/*void schmufControl(int i){
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
*/

//Hardware Output
void MotorControl(byte Motor, byte Speed, bool Direction){

  if (Speed > 0) {
    analogWrite(MotorPWM[Motor], Speed);
    if(reversed[Motor])
      Direction != Direction;
    digitalWrite(MotorA[Motor], Direction);
    digitalWrite(MotorB[Motor], !Direction);
    return;
  }
  // If the Speed is 0, stop the motors
  digitalWrite(MotorA[Motor], true);  // High,High = short break
  digitalWrite(MotorB[Motor], true);
}
