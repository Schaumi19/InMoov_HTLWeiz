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
bool inverted[4] = {false, false, false, false};


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
  Serial.println(ACP_B1 + "\n" + ACP_B2);

  // Reading in data from the Potentiometers + mapping
  for (size_t i = 0; i < 4; i++)
  {
    AktuatorStates[i] = map(analogRead(Pot[i]), min_pot[i], max_pot[i], min, max);
    checkDir(i);

    setupMotor(i);
  }

}


// This function is used to check if the motor is correctly connected or needs to be inverted
void setupMotor(byte motor){
  int setupPos[2];
  bool invert = false;

  MotorControl(motor, 255, dir[motor]);

  for (size_t i = 0; i < 2; i++){
    setupPos[i] = getAktuator(motor);
    delay(100);
  }

  if(dir[motor])
      invert = (setupPos[0] < setupPos[1]);
  else
      invert = (setupPos[0] > setupPos[1]);

  inverted[motor] = !invert;

  MotorControl(motor, 0, dir[motor]);
}


void loop() {

  readSerial();

  for(int i = 0; i < 4; i++){
    
    // Reading in data from the Potentiometers + mapping
    AktuatorStates[i] = getAktuator(i);

    if(!(AktuatorStates[i] <= (GoalAngle[i] + goalDeadzone) && 
         AktuatorStates[i] >= (GoalAngle[i] - goalDeadzone))){

      // Initialization of the direction, depending on the current position relative to the goal position
      checkDir(i);
      driving[i] = true;
    }
    else
      MotorSteps[i][0] = GoalAngle[i];
        
    // Calculating the Steps required to reach the goal angle
    CalculateSteps(GoalAngle[i], i);

    control(i);

    Serial.println(AktuatorStates[i]);

  }

}


int getAktuator(byte i){
    return map(analogRead(Pot[i]), min_pot[i], max_pot[i], min, max);
}


void control(byte i){
  if(schmuf[i])
    schmufControl(i);
  else
    normalControl(i);
}


void checkDir(byte i){
  dir[i] = (AktuatorStates[i] < GoalAngle[i]);
  invertDir(i);
}


void invertDir(byte i){
  if(inverted[i])
    dir[i] != dir[i];
}


// Reading in a string from Serial and computing it
void readSerial(){
  while(!Serial.available());
  char b = Serial.read();
  if (b == '0'){
    int Angle = Serial.parseInt();
    setAngleSpeed(0, Angle, 0);
    setAngleSpeed(1, Angle, 0);
    setAngleSpeed(2, Angle, 0);
    setAngleSpeed(3, Angle, 0);
  }
  else if (b == '1')
    setAngleSpeed(0, Serial.parseInt(), 0);
  else if (b == '2') 
    setAngleSpeed(1, Serial.parseInt(), 0);
  else if (b == '3')
    setAngleSpeed(2, Serial.parseInt(), 0);
  else if (b == '4')
    setAngleSpeed(3, Serial.parseInt(), 0);
}


void setAngleSpeed(byte motor, int goalAngle, int speed){
  GoalAngle[motor] = goalAngle;
  Speed[motor] = speed;
}


void normalControl(int i){
  if(dir[i]){  
    if(AktuatorStates[i] >= MotorSteps[i][1] && 
       !(AktuatorStates[i] >= (MotorSteps[i][1])) && 
       driving[i]){

      MotorControl(i, Speed[i], dir[i]);
      Speed[i]=150;
    }
    else if(AktuatorStates[i] <= MotorSteps[i][0] && 
            !(AktuatorStates[i] >= (MotorSteps[i][1])) && 
            driving[i]){

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
    if(AktuatorStates[i] <= MotorSteps[i][1] && 
       !(AktuatorStates[i] <= (MotorSteps[i][1])) && 
       driving[i]){

      MotorControl(i, (int) Speed[i], dir[i]);
      Speed[i]=150;
    }
    else if(AktuatorStates[i] >= MotorSteps[i][0] && 
            !(AktuatorStates[i] <= (MotorSteps[i][1])) && 
            driving[i]){

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
  Serial.println(Speed[i]);
  Serial.println(driving[i]);
}


// Waypoints get Calculated depending on the driving direction
void CalculateSteps(int GoalAngle, byte Motor){

  int diff;
  if(dir[Motor]){
    diff = GoalAngle - AktuatorStates[Motor];
    MotorSteps[Motor][0] = AktuatorStates[Motor] + (diff / 2);
    MotorSteps[Motor][1] = GoalAngle;
  }

  else{
    diff = GoalAngle + AktuatorStates[Motor];
    MotorSteps[Motor][0] = AktuatorStates[Motor] - (diff / 2);
    MotorSteps[Motor][1] = GoalAngle;
  }

}


// Motor driving code
void MotorControl(byte Motor, byte Speed, bool Direction){

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