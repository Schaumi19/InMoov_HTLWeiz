#include "config.h"

class Motors
{
private:
    int goalAngle[4] = {0, 0, 0, 0};

    int AngleInputLimiter(int _angle, int _motorIndex);
public:
    Motors(/* args */);
    ~Motors();
    void ReceiveEvent(byte aktuatorID, byte angle);
};

Motors::Motors(/* args */)
{
}

Motors::~Motors()
{
}

void Motors::ReceiveEvent(byte aktuatorID, byte angle){
  if (aktuatorID == 0){    //Set all Aktuators to the same Value
    for (byte i = 0; i < 4; i++){
        goalAngle[i] = AngleInputLimiter(angle,i);
    }
  }
  else if (aktuatorID <= 4){
      goalAngle[aktuatorID-1] = AngleInputLimiter(angle,aktuatorID-1);
  }
}

int Motors::AngleInputLimiter(int _angle, int _motorIndex){
  if(_angle > max_angle[_motorIndex])
    _angle = max_angle[_motorIndex];
  else if(_angle < min_angle[_motorIndex])
    _angle = min_angle[_motorIndex];
  return _angle;
}