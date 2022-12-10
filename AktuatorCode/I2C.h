#include <Wire.h>
int i2cAddress;

void init(int _i2cAddress){
  i2cAddress = _i2cAddress;
    Wire.begin(i2cAddress);
    Wire.onReceive(i2cReceiveEvent);
}

void sendAsMaster(byte externalI2CAddress, byte akIndex, byte angle){
  Wire.end();
  Wire.begin();
  Wire.beginTransmission(externalI2CAddress);
  Wire.write(akIndex);
  Wire.write(angle);
  Wire.endTransmission();
  Wire.end();
  Wire.begin(i2cAddress);
}

void i2cReceiveEvent(int howMany){
  if(howMany == 2){ //If two bytes were received
    byte _akIndex = Wire.read();
    byte _angle = Wire.read();
    
  }
}

