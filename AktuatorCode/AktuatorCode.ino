// Includes
#include "config.h"
#include <Servo.h>


// Initialization of the In/Output Ports
;const byte Pot[4] = {6,4,3,1};
;const byte Pot2[4] = {7,5,2,0};
;const byte MotorPWM[4] = {3,6,9,11};
;const byte MotorA[4] = {2,5,8,12};
;const byte MotorB[4] = {4,7,10,13};

// Initialization of the state Arrays
int AktuatorStates[4] = {0, 0, 0, 0};
int GoalAngle[4] = {0, 0, 0, 0};
int MotorSteps[4][2];
bool dir[4] = {true, true, true, true};

double Speed[4] = {0, 0, 0, 0};
bool driving[4] = {false, false, false, false};

Servo servos[4] = {Servo(), Servo(), Servo(), Servo()};


void setup() {

  // Setting up the serial
  Serial.begin(115200);
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
  for (size_t i = 0; i < 4; i++)
  {
    AktuatorStates[i] = map(analogRead(Pot[i]), min_pot[i], max_pot[i], min[i], max[i]);
    checkDir(i);
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
  
  if(invert)
    Serial.println("ERROR NOT CONNECTED CORRECTLY");

  MotorControl(motor, 0, dir[motor]);
}


void loop() {

  readSerial();

  Serial.write(",");
  for(int i = 0; i < 4; i++){

    if(isServo[i])
      AktuatorStates[i] = servos[i].read();

    else{
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
    }

    if(!isServo[i])
      control(i);

    Serial.println(AktuatorStates[i]);

  }

}


int getAktuator(byte i){
  return map(analogRead(Pot[i]), min_pot[i], max_pot[i], min[i], max[i]);
}


void control(byte i){ 
  if(schmuf[i])
    schmufControl(i);
  else
    normalControl(i);
}


void checkDir(byte i){
  dir[i] = (AktuatorStates[i] < GoalAngle[i]);
}


// Reading in a string from Serial and computing it
void readSerial(){
  if(Serial.available()){
    byte b = Serial.read();
    if (b == 0){
      byte Angle = Serial.read();
      
      if(isServo[0])
        servos[0].write(map(Angle, min[0], max[0], min_pot[0], max_pot[0]));
      else{
        setAngleSpeed(0, map(Angle, min[0], max[0], min_pot[0], max_pot[0]), 0);}
        
      if(isServo[1])
        servos[1].write(map(Angle, min[1], max[1], min_pot[1], max_pot[1]));
      else{
        setAngleSpeed(1, map(Angle, min[1], max[1], min_pot[1], max_pot[1]), 0);}
        
      if(isServo[2])
        servos[2].write(map(Angle, min[2], max[2], min_pot[2], max_pot[2]));
      else{
        setAngleSpeed(2, map(Angle, min[2], max[2], min_pot[2], max_pot[2]), 0);}
        
      if(isServo[3])
        servos[3].write(map(Angle, min[3], max[3], min_pot[3], max_pot[3]));
      else{
        setAngleSpeed(3, map(Angle, min[3], max[3], min_pot[3], max_pot[3]), 0);}
    }
    else if (b == 1){
      if(isServo[0])
        servos[0].write(map(Serial.read(), min[0], max[0], min_pot[0], max_pot[0]));
      else{
        setAngleSpeed(0, map(Serial.read(), min[0], max[0], min_pot[0], max_pot[0]), 0);}
    }
    else if (b == 2){
      if(isServo[1])
        servos[1].write(map(Serial.read(), min[1], max[1], min_pot[1], max_pot[1]));
      else{
        setAngleSpeed(1, map(Serial.read(), min[1], max[1], min_pot[1], max_pot[1]), 0);}
    }
    else if (b == 3){
      if(isServo[2])
        servos[2].write(map(Serial.read(), min[2], max[2], min_pot[2], max_pot[2]));
      else{
        setAngleSpeed(2, map(Serial.read(), min[2], max[2], min_pot[2], max_pot[2]), 0);}
    }
    else if (b == 4){
      if(isServo[3])
        servos[3].write(map(Serial.read(), min[3], max[3], min_pot[3], max_pot[3]));
      else{
        setAngleSpeed(3, map(Serial.read(), min[3], max[3], min_pot[3], max_pot[3]), 0);}
    }
    Serial.read();
  }
  delay(200);
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
