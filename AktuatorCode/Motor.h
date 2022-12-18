#include <Arduino.h>
#include "AngularSpeed.h"

class Motor
{
private:
//presets
    int pin_pot;
    int pin_motorPWM;
    int pin_motorA;
    int pin_motorB;

    int id;
    bool used;
    int min_angle;
    int max_angle;
    int min_pot;
    int max_pot;
    bool reverse_output;
    bool reverse_input;
    int continuousMovement = 0;
    int goalDeadzone = 6;

    int maxSpeed = 255;
    bool useAngularSpeed = false;

    //error Detection Settings
    const int errorMinDiff = 2;
    const int errorMinAngularSpeed = 20; // °/s
    const int errorDiff = 20;

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
    bool Error_Value = 0;
    bool Error_OutOfRange = 0;
    bool Error_Time = 0;
    bool Error_Dir = 0;

    Motor();
    void SetParameter(int ID,bool Used, int Min_angle, int Max_angle, int Min_pot, int Max_pot, 
        bool Reverse_output, bool Reverse_input, int ContinuousMovement, int GoalDeadzone, int Max_Speed);
    void SetPins(int pin_pot, int pin_motorPWM, int pin_motorA, int pin_motorB);
    void UseAngularSpeed(int MaxAngularSpeed){useAngularSpeed = true; angularSpeed.SetMaxAngularSpeed(MaxAngularSpeed);}
    void Init();
    void SetAngle(int Angle);
    int GetAngle(){return angle;}
    void DebugOutput();
    void Update(){
        if(used && continuousMovement == 0){
            readSensorInput();
            angularSpeed.Update(angle);
            if(useAngularSpeed)
                angleControlWithAngularSpeedControl();
            else
                angleControl();
            DebugOutput();
        }
    }
    ~Motor();
};  
