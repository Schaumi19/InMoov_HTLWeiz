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

    bool used;
    int min_angle;
    int max_angle;
    int min_pot;
    int max_pot;
    bool reverse_output;
    bool reverse_input;
    int continuousMovement;
    int goalDeadzone = 6;

    int rampUpTime; //Slowspeed currently not implemented (max speed ca. 3,5ms/°)
    int maxSpeed = 255;

    //error Detection Settings
    const int errorTime = 600;
    const int errorMinDiff = 2;
    const int errorDiff = 20;

    AngularSpeed angularSpeed;

//Runtime Variables
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

    Motor();
    void SetParameter(bool Used, int Min_angle, int Max_angle, int Min_pot, int Max_pot, 
        bool Reverse_output, bool Reverse_input, int ContinuousMovement, int GoalDeadzone, int Max_Speed);
    void SetPins(int pin_pot, int pin_motorPWM, int pin_motorA, int pin_motorB);
    void Init();
    void SetAngle(int Angle);
    int GetAngle(){return angle;}
    void Update(){
        readSensorInput();
        angularSpeed.Update(angle);
        angleControlWithAngularSpeedControl();
        //angleControl();
        }
    ~Motor();
};  
