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
    pinMode(MotorPWM[i], OUTPUT);
    pinMode(MotorA[i], OUTPUT);
    pinMode(MotorB[i], OUTPUT);
    if(isServo[i]){
      servos[i].attach(servoPins[i]);
      digitalWrite(MotorPWM[i], HIGH);
      digitalWrite(MotorA[i], HIGH);
      digitalWrite(MotorB[i], LOW);
    }else
      pinMode(Pot[i], INPUT);
  }

  // Reading in data from the Potentiometers + mapping
  delay(500);
  for (byte i = 0; i < 4; i++)
  {
    if(!isServo[i]){
      AktuatorStates[i] = map(analogRead(Pot[i]), min_pot[i], max_pot[i], min[i], max[i]);
      GoalAngle[i] = AktuatorStates[i];
    }
    //GoalAngle[i] = 170; //Testing
  }
  
}

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

void loop() {

  //hardcoded();

  readSerial();

  #ifdef Debug
    Serial.println(";");  //?????? Hot des an sinn?
  #endif

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
    else{
      // Reading in data from the Potentiometers + mapping
      AktuatorStates[i] = map(analogRead(Pot[i]), min_pot[i], max_pot[i], min[i], max[i]);
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
    }
    #ifdef Debug
      Serial.print("   ");
    #endif
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
<<<<<<< HEAD
    Serial.print("Move");
    if(AktuatorStates[i] < GoalAngle[i]){
      Serial.print("1Dir");
=======
    #ifdef Debug
    Serial.print("Move");
    #endif
    if(AktuatorStates[i] < GoalAngle[i]){
      #ifdef Debug
      Serial.print("1Dir");
      #endif
>>>>>>> 383c42698f3cdaf0e4b549dc01f936ecd61d43db
      if(AktuatorStates[i] <= GoalAngle[i] - Speed1Zone){
        Speed[i]=255;
      }else if(AktuatorStates[i] <= GoalAngle[i] - Speed2Zone){
        Speed[i]=255;
      }else{
        Speed[i]=255;
      }
      MotorControl(i, Speed[i], true);
    }else{
      #ifdef Debug
      Serial.print("2Dir");
      #endif
      if(AktuatorStates[i] <= GoalAngle[i] + Speed1Zone){
        Speed[i]=150;
      }else if(AktuatorStates[i] <= GoalAngle[i] + Speed2Zone){
        Speed[i]=200;
      }else{
        Speed[i]=255;
      }
      MotorControl(i, Speed[i], false);
      
    }
  }else{
    MotorControl(i, 0, false);
    Speed[i] = 0;
    #ifdef Debug
    Serial.print("Stop     ");
    #endif
  }
  #ifdef Debug
  Serial.print(Speed[i]);
  #endif
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
      Direction = !Direction;
<<<<<<< HEAD
    Serial.print("Beweg");
    Serial.print(Speed);
=======
    #ifdef Debug_Motor
    Serial.print("Beweg:");
    Serial.print(Speed);
    Serial.print(" ");
    #endif
>>>>>>> 383c42698f3cdaf0e4b549dc01f936ecd61d43db
    digitalWrite(MotorA[Motor], Direction);
    digitalWrite(MotorB[Motor], !Direction);
    return;
  }
  // If the Speed is 0, stop the motors
  digitalWrite(MotorA[Motor], true);  // High,High = short break
  digitalWrite(MotorB[Motor], true);
}
