// Coded by Manuel Schaumberger and Thomas Baumkircher

#include <Servo.h>
#include "config.h"

Servo servo1;
Servo servo2;
Servo servo3;
Servo servo4;
Servo servo5;
Servo servo6;
int a;
int Speed;
unsigned long Time;
int o = 0;
int i = 0;


void attach_detach_Servos(bool a){
  if(a == true){
    servo1.attach(7);
    servo2.attach(8);
    servo3.attach(9);
    servo4.attach(10);
    servo5.attach(11);
    servo6.attach(12);
  }
  else{
    servo1.detach();
    servo2.detach();
    servo3.detach();
    servo4.detach();
    servo5.detach();
    servo6.detach();
    digitalWrite(7,LOW);
    digitalWrite(8,LOW);
    digitalWrite(9,LOW);
    digitalWrite(10,LOW);
    digitalWrite(11,LOW);
    digitalWrite(12,LOW);
  }
}


void setup() {
  Serial.begin(Baudrate);//Seriel Baud-rate 
  Serial.write(ACP_B1);
  Serial.write(ACP_B2);

  attach_detach_Servos(true); //attach all Servos
  a = 0;//Standard Servo setting
  
  servo1.write(a);
  delay(400);
  servo2.write(a);
  delay(400);
  servo3.write(a);
  delay(400);
  servo4.write(a);
  delay(400);
  servo5.write(a);
  delay(400);
  servo6.write(a);
  delay(1000);

  a = 70;//Standard Servo setting
  
  servo1.write(a);
  delay(400);
  servo2.write(a);
  delay(400);
  servo3.write(a);
  delay(400);
  servo4.write(a);
  delay(400);
  servo5.write(a);
  delay(400);
  servo6.write(a);
  delay(1000);
}



void loop() {

  attach_detach_Servos(true);
  char b = Serial.read();
  if (b == 0) { //everything
    //Serial.println("gesamt");
    a = Serial.read();

    servo1.write(a);
    servo2.write(a);
    servo3.write(a);
    servo4.write(a);
    servo5.write(a);
    servo6.write(a);

  }
  else if (b == 1) { //Servo1
    a = Serial.read();
    servo1.write(a);
  }
  else if (b == 2) { //Servo2
    a = Serial.read();
    servo2.write(a);
  }
  else if (b == 3) { //Servo3
    a = Serial.read();
    servo3.write(a);
  }
  else if (b == 4) { //Servo4
    a = Serial.read();
    servo4.write(a);
  }
  else if (b == 5) { //Servo5
    a = Serial.read();
    servo5.write(a);
  }
  else if (b == 6) { //Servo6
    a = Serial.read();
    servo6.write(a);
  }
  Serial.read();
  Time = millis();


  if(Time + 10000 <= millis() && servo1.attached() == true){
    attach_detach_Servos(false);
  }
  
  if(i == 180 && o == -1){
    o = 1;
    delay(5000);
  }else if(i == 0 && o == 1){
    o = -1;
    delay(5000);
  }else{
    i+=o;
  }
  servo1.write(i);
  servo2.write(i);
  servo3.write(i);
  servo4.write(i);
  servo5.write(i);
  servo6.write(i);  

  Serial.write(",");
  Serial.write(1);
  Serial.write(0);
  Serial.write(2);
  Serial.write(0);
  Serial.write(3);
  Serial.write(0);
  Serial.write(4);
  Serial.write(0);
  Serial.write(5);
  Serial.write(0);
  Serial.write(6);
  delay(1);
}
