#include <Arduino.h>
class AngularSpeed
{
private:
    unsigned long lastTime;
    byte lastAngle;
    byte currentPower;

    unsigned int goalAngularSpeed = 0; // °/s should be under 300

    //Presets
    byte updateTime = 10; // 1/Frequency
    byte maxAngularSpeed = 255;
    byte PowerIntegrationCoefficient = 10;
    byte minPower = 50;
    byte maxPower = 255;

    int calcAngularSpeed(int CurrentAngle); 

public:
    AngularSpeed(/* args */);
    void SetMaxAngularSpeed(int MaxAngularSpeed){maxAngularSpeed = MaxAngularSpeed;}
    void SetAngularSpeed(int AngularSpeed, int CurrentAngle);
    int GetCurrentPower(){return currentPower;}
    void Update(int CurrentAngle);
    ~AngularSpeed();
};
