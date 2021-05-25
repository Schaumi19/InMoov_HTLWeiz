#include "config.h"

const byte Pot1 = 0;
const byte Pot2 = 1;
const byte Pot3 = 2;
const byte Pot4 = 3;

const byte Motor1PWM = 5;
const byte Motor1A = 2;
const byte Motor1B = 3;

const byte Motor2PWM = 6;
const byte Motor2A = 7;
const byte Motor2B = 4;

const byte Motor3PWM = 9;
const byte Motor3A = 8;
const byte Motor3B = 11;

const byte Motor4PWM = 10;
const byte Motor4A = 12;
const byte Motor4B = 13;

int AktuatorStates[4];

void setup() {
  Serial.begin(Baudrate);
  Serial.print(FirstPos+SecondPos);
}

void loop() {



AktuatorStates[0] = map(analogRead(Pot1), 0, 1023, 0, 180);

}
