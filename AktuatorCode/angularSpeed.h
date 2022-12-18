#include <Arduino.h>
class AngularSpeed
{
private:
    unsigned long lastTime;
    int lastAngle;
    int currentPower;

    unsigned int goalAngularSpeed = 0; // °/s should be under 300

    //Presets
    int updateTime = 10; // 1/Frequency
    int maxAngularSpeed = 300;
    int PowerIntegrationCoefficient = 10;
    int minPower = 50;
    int maxPower = 255;

    int calcAngularSpeed(int CurrentAngle); 

public:
    AngularSpeed(/* args */);
    void SetMaxAngularSpeed(int MaxAngularSpeed){maxAngularSpeed = MaxAngularSpeed;}
    void SetAngularSpeed(int AngularSpeed, int CurrentAngle);
    int GetCurrentPower(){return currentPower;}
    void Update(int CurrentAngle);
    ~AngularSpeed();
};
