#include <Arduino.h>
#include "AngularSpeed.h"

struct MotorParameter
{
    bool used;
    byte min_angle;
    byte max_angle;
    unsigned int min_pot;
    unsigned int max_pot;
    bool reverse_output;
    bool reverse_input;
    byte continuousMovement = 0;
    byte goalDeadzone = 6;

    byte maxSpeed = 255;
    bool useAngularSpeed = false;

    //error Detection Settings
    byte errorMinDiff = 2;
    byte errorMinAngularSpeed = 20; // °/s
};


class Motor
{
private:
//presets
    int pin_pot;
    int pin_motorPWM;
    int pin_motorA;
    int pin_motorB;

    int debug_count = 0;

    AngularSpeed angularSpeed;

//Runtime Variables
    int readValue;
    int angle;
    int goalAngle;
    int startAngle;
    bool newGoal;
    bool moving;
    int startDiff;
    int startTime;

    void readSensorInput();
    void motorControl(int Speed, bool Direction);
    void angleControl();
    void angleControlWithAngularSpeedControl();
    

public:
    MotorParameter motorParameter;

    bool Error_Value = 0;
    bool Error_OutOfRange = 0;
    bool Error_Time = 0;
    bool Error_Dir = 0;

    Motor();
    void SetPins(int pin_pot, int pin_motorPWM, int pin_motorA, int pin_motorB);
    void Init();
    void SetAngle(int Angle);
    int GetAngle(){return angle;}
    void DebugOutput(int n);
    void Update(int n){
        if(motorParameter.used && motorParameter.continuousMovement == 0){
            readSensorInput();
            angularSpeed.Update(angle);
            if(motorParameter.useAngularSpeed)
                angleControlWithAngularSpeedControl();
            else
                angleControl();
            
        }
        if(debug_count >= 10000){ //Without that the serial monitor is to slow
            DebugOutput(n);
            debug_count = 0;
        }else
            debug_count++;
        
    }
    void ManualMotorControl(int Speed, bool Direction){
        digitalWrite(pin_motorA, Direction);
        digitalWrite(pin_motorB, !Direction);
        analogWrite(pin_motorPWM, Speed);
    }
    ~Motor();
};  
