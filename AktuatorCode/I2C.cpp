#include <Wire.h>

class I2C
{
private:
    int I2CAddress;
    
public:
    I2C(/* args */);
    ~I2C();
    void init(int i2cAddress, void (*function)(int));
    void sendAsMaster(byte externalI2CAddress, byte akIndex, byte angle);
};

I2C::I2C(/* args */)
{
}

I2C::~I2C()
{
}

void I2C::init(int i2cAddress, void (*function)(int)){
    I2CAddress = i2cAddress;
    Wire.begin(I2CAddress);
    Wire.onReceive(function);
}

void I2C::sendAsMaster(byte externalI2CAddress, byte akIndex, byte angle){
    Wire.end();
    Wire.begin();
    Wire.beginTransmission(externalI2CAddress);
    Wire.write(akIndex);
    Wire.write(angle);
    Wire.endTransmission();
    Wire.end();
    Wire.begin(I2CAddress);
}

void receiveEvent2(int howMany){
  if(howMany == 2){ //If two bytes were received
     = Wire.read();
    byte _angle = Wire.read();

    /*
    if (_AkIndex == 0){    //Set all Aktuators to the same Value
      for (byte i = 0; i < 4; i++){
          goalAngle[i] = AngleInputLimiter(_angle,i);
      }
    }
    else if (_AkIndex <= 4){
        goalAngle[_AkIndex-1] = AngleInputLimiter(_angle,_AkIndex-1);
    }
    */
  }
}