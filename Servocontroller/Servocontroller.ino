// Coded by Manuel Schaumberger
// To deside the arduino location change config.h

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


void setup() {
  Serial.begin(Baudrate);//Seriel Baud-rate 

  attach_detach_Servos(true); //attach all Servos
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
  Serial.println("Power");//Debuging information
  delay(1000);

  while(!Serial.available())
    Serial.write("0");
}



void loop() {
  if (Serial.available()){
    if (Serial.read() == FirstPos) { //R = Right; L = Left; M = Middle
      //delay(1);
      while(!Serial.available());
      char b = Serial.read();
      //delay(1);
      if (b == SecondPos) { //h = hand/head; s = shoulder; t = torso;
        while(!Serial.available());
        char b = Serial.read();
        attach_detach_Servos(true);
        if (b == 'a') { //everything
          //Serial.println("gesamt");
          a = Serial.parseInt();


          servo1.write(a);
          servo2.write(a);
          servo3.write(a);
          servo4.write(a);
          servo5.write(a);
          servo6.write(a);
          Serial.write("A:");
          Serial.println(a);

        }
        else if (b == 'b') { //Servo1
          Serial.println("b");
          a = Serial.parseInt();
          servo1.write(a);
        }
        else if (b == 'c') { //Servo2
          Serial.println("c");
          a = Serial.parseInt();
          servo2.write(a);
        }
        else if (b == 'd') { //Servo3
          Serial.println("d");
          a = Serial.parseInt();
          servo3.write(a);
        }
        else if (b == 'e') { //Servo4
          Serial.println("e");
          a = Serial.parseInt();
          servo4.write(a);
        }
        else if (b == 'f') { //Servo5
          Serial.println("f");
          a = Serial.parseInt();
          servo5.write(a);
        }
        else if (b == 'g') { //Servo6
          Serial.println("g");
          a = Serial.parseInt();
          servo6.write(a);
        }
        Time = millis();
      }
    }
  }
  if(Time + 10000 <= millis() && servo1.attached() == true){
    attach_detach_Servos(false);
  }
  
}
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
  Serial.print(a);
}
