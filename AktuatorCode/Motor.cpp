#include "Motor.h"

Motor::Motor(){
  
}

void Motor::SetParameter(bool Used, int Min_angle, int Max_angle, int Min_pot, int Max_pot, bool Reverse_output, bool Reverse_input, int ContinuousMovement, int GoalDeadzone, int Max_Speed){
    used = Used;
    reverse_input = Reverse_input;
    reverse_output = Reverse_output;
    continuousMovement = ContinuousMovement;
    goalDeadzone = GoalDeadzone;
    maxSpeed = Max_Speed;
    if(Min_angle < Max_angle){
        min_angle = Min_angle;
        max_angle = Max_angle;
    }else
        Error_Value = true;
    if(Min_pot < Max_pot){
        min_pot = Min_pot;
        max_pot = Max_pot;
    }else
        Error_Value = true;
}

void Motor::SetPins(int Pin_pot, int Pin_motorPWM, int Pin_motorA, int Pin_motorB){
    if(used){
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
    if(used && continuousMovement == 0){
      readSensorInput();
      goalAngle = angle; //Aktuators should not move from IC-start
    }
}

void Motor::SetAngle(int Angle){
    if(Angle > max_angle)
        Angle = max_angle;
    else if(Angle < min_angle)
        Angle = min_angle;
    goalAngle = Angle;
    newGoal = true;
}

void Motor::readSensorInput(){
  // Reading in data from the Potentiometers + mapping
  int _readValue = analogRead(pin_pot);
  if(reverse_input)
    _readValue = 1024 - _readValue;
  
  if(used&&(_readValue - errorDiff > max_pot || _readValue + errorDiff < min_pot))
    Error_OutOfRange = true;  //Value out of Range err
  angle = map(_readValue, min_pot, max_pot, min_angle, max_angle);
}

void Motor::motorControl(int Speed, bool Direction){
  if (Speed > 0) {
    if(continuousMovement == 0){
      if(!moving){  //Mech Error detection
        moving = true;
        startTime = millis();
        startDiff = abs(goalAngle-angle);
      }/*else if(millis()-startTime > errorTime && startDiff - errorMinDiff <= abs(goalAngle-angle)){
        Error_Time = true; //Time Error detected
      }*/
    }
    
    if(!Error_OutOfRange && !Error_Time && !Error_Value){
      if(reverse_output)
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
  
  if((angle < goalAngle && angle < (goalAngle - goalDeadzone)) ||(angle > goalAngle &&  angle > (goalAngle + goalDeadzone))){ //Do we even need to move
    #ifdef Debug
    Serial.print("Move");
    #endif
    bool _dir = goalAngle > angle;
    /*
    if((_dir&&angle+SlowSpeedZone>goalAngle[i])||(!_dir&&actuatorStates[i]-SlowSpeedZone[i]<goalAngle[i]))
      MotorControl(i,SlowSpeed[i],_dir);
    else
    */
    motorControl(maxSpeed,_dir);
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
