#include "angularSpeed.h"

void AngularSpeed::SetAngularSpeed(int AngularSpeed, int CurrentAngle){
    if(AngularSpeed < maxAngularSpeed && AngularSpeed >= 0)
        goalAngularSpeed = AngularSpeed;
    else if(AngularSpeed >= 0)
        goalAngularSpeed = maxAngularSpeed;
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
