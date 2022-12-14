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
    void SetAngularSpeed(int AngularSpeed, int CurrentAngle);
    int GetCurrentPower(){return currentPower;}
    void Update(int CurrentAngle);
    ~AngularSpeed();
};

void AngularSpeed::SetAngularSpeed(int AngularSpeed, int CurrentAngle){
    if(AngularSpeed < maxAngularSpeed && AngularSpeed >= 0)
        goalAngularSpeed = AngularSpeed;
    if(millis() - lastTime >= updateTime){
        lastTime = millis();
        lastAngle = CurrentAngle;
    }
}

void AngularSpeed::Update(int CurrentAngle){
    if(goalAngularSpeed > 0 && millis() - lastTime >= updateTime){
        bool toHigh = calcAngularSpeed(CurrentAngle) > goalAngularSpeed;
        currentPower += PowerIntegrationCoefficient * !toHigh - PowerIntegrationCoefficient * toHigh;
        if(currentPower < minPower)
            currentPower = minPower;
        if(currentPower > maxPower)
            currentPower = maxPower;
        lastTime = millis();
        lastAngle = CurrentAngle;
    }
}

//returns °/s
int AngularSpeed::calcAngularSpeed(int CurrentAngle){
    long timeDif = millis() - lastTime;
    int angleDif = abs(lastAngle - CurrentAngle);
    return (angleDif*1000)/timeDif;
}

AngularSpeed::AngularSpeed(/* args */)
{
}

AngularSpeed::~AngularSpeed()
{
}
