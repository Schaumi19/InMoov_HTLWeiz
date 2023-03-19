#include "Motor.h"

Motor::Motor(){
  
}

// DebugOutput is used to print out the current state of the motor
void Motor::DebugOutput(int n){
  Serial.println(" ");
  Serial.print(n+1);
  Serial.print(":");
  Serial.print("Angle:");
  Serial.print(angle);
  Serial.print(",Pot: ");
  Serial.print(readValue);
  Serial.print(",Goal: ");
  Serial.print(goalAngle);
  Serial.print(",Power: ");
  Serial.print(angularSpeed.GetCurrentPower());

  if(Error_Value){
    Serial.print(" Value ");
  }
  if(Error_OutOfRange){
    Serial.print(" OutOfRange ");
  }
  if(Error_Time){
    Serial.print(" Time");
  }
  if(Error_Dir){
    Serial.print(" Dir");
  }
}

// This function is used to set the pins of the motor and the potentiometer
void Motor::SetPins(int Pin_pot, int Pin_motorPWM, int Pin_motorA, int Pin_motorB){
    if(motorParameter.used){
      pinMode(Pin_motorPWM, OUTPUT);
      pinMode(Pin_motorA, OUTPUT);
      pinMode(Pin_motorB, OUTPUT);
      pinMode(Pin_pot, INPUT);
    }
    pin_pot = Pin_pot;
    pin_motorPWM = Pin_motorPWM;
    pin_motorA = Pin_motorA;
    pin_motorB = Pin_motorB;
}

void Motor::Init(){
    if(motorParameter.used && motorParameter.continuousMovement == 0){
      readSensorInput();
      goalAngle = angle; //Aktuators should not move from IC-start
    }
    if(motorParameter.continuousMovement >= 1){
      motorControl(motorParameter.continuousMovement, 1);
    }
}

// This function is used to set the goalAngle of the motor
void Motor::SetAngle(int Angle){
    if(Angle > motorParameter.max_angle)
        Angle = motorParameter.max_angle;
    else if(Angle < motorParameter.min_angle)
        Angle = motorParameter.min_angle;
    goalAngle = Angle;
    newGoal = true;
}

// Reading in data from the Potentiometers + mapping
void Motor::readSensorInput(){
  readValue = analogRead(pin_pot);
  if(motorParameter.reverse_input)
    readValue = 1024 - readValue;
  if(motorParameter.used&&(readValue > motorParameter.max_pot || readValue < motorParameter.min_pot))
    Error_OutOfRange = true;  //Value out of Range err
  angle = map(readValue, motorParameter.min_pot, motorParameter.max_pot, motorParameter.min_angle, motorParameter.max_angle);
}

// This function is used to update the motor
void Motor::motorControl(int Speed, bool Direction){
  if (Speed > 0) {
    if(motorParameter.continuousMovement == 0){
      if(!moving){  //Mech Error detection
        moving = true;
        startTime = millis();
        startDiff = abs(goalAngle-angle);
      }/*else if(((millis()-startTime)*errorMinAngularSpeed) > abs(angle - startAngle)){
        Error_Time = true; //Time Error detected
      }*/else if (startDiff - motorParameter.errorMinDiff <= abs(goalAngle-angle))
      {
        Error_Dir = true;
      }
      
    }
    
    if(!Error_OutOfRange && !Error_Time && !Error_Value){
      if(motorParameter.reverse_output)
        Direction = !Direction;
      #ifdef Debug_Motor
        Serial.print("Beweg:");
        Serial.print(_Speed);
        Serial.print(" ");
      #endif
      digitalWrite(pin_motorA, Direction);
      digitalWrite(pin_motorB, !Direction);
      analogWrite(pin_motorPWM, Speed);
      return;
    }
  }
  // If the Speed is 0 or an Error was detected, stop the motors
  digitalWrite(pin_motorA, true);  // High,High = short break
  digitalWrite(pin_motorB, true);
  moving = false;
}

void Motor::angleControl(){
  if((angle < goalAngle && angle < (goalAngle - motorParameter.goalDeadzone)) ||(angle > goalAngle &&  angle > (goalAngle + motorParameter.goalDeadzone))){ //Do we even need to move
    #ifdef Debug
    Serial.print("Move");
    #endif
    bool _dir = goalAngle > angle;
    motorControl(motorParameter.maxSpeed,_dir);
  }else{
    motorControl(0, false);
    #ifdef Debug
    Serial.print("Stop     ");
    #endif
  }
}

void Motor::angleControlWithAngularSpeedControl(){
  if((angle < goalAngle && angle < (goalAngle - motorParameter.goalDeadzone)) ||(angle > goalAngle &&  angle > (goalAngle + motorParameter.goalDeadzone))){ //Do we even need to move
    #ifdef Debug
    Serial.print("Move");
    #endif
    bool _dir = goalAngle > angle;
    if(newGoal){
      newGoal = false;
      startAngle = angle;
    }
    int diff [2] = {abs(goalAngle-angle), abs(startAngle-angle)};
    if(diff[1] < diff[0])
      diff[0] = diff[1];
    angularSpeed.SetAngularSpeed(diff[0]*3, angle); //Desto näher man an der start oder ziel pos ist desto langsamer
    motorControl(angularSpeed.GetCurrentPower(),_dir);
  }else{
    motorControl(0, false);
    #ifdef Debug
    Serial.print("Stop     ");
    #endif
  }
}

Motor::~Motor()
{
}
