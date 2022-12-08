#include <Wire.h>

class I2C
{
private:
    void (*receiveEvent)(byte,byte);
    int I2CAddress;
    
    
public:
    
    I2C(/* args */);
    ~I2C();
    void init(int _i2cAddress, void (*_receiveEvent)(byte,byte));
    void sendAsMaster(byte externalI2CAddress, byte akIndex, byte angle);
};

I2C::I2C(/* args */)
{
}

I2C::~I2C()
{
}

void I2C::init(int _i2cAddress, void (*_receiveEvent)(byte,byte)){
    receiveEvent = _receiveEvent;
    I2CAddress = _i2cAddress;
    Wire.begin(I2CAddress);
    Wire.onReceive(i2cReceiveEvent);
}

void i2cReceiveEvent(int howMany){
  if(howMany == 2){ //If two bytes were received
    byte _akIndex = Wire.read();
    byte _angle = Wire.read();
    receiveEvent(_akIndex,_angle);
  }
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