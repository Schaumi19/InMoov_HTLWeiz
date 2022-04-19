
#define baudrate 115200

void setup(){
  Serial.begin(baudrate);
  Serial.flush();
  while(!Serial.available());
  int b1 = Serial.parseInt();
  int b2 = Serial.parseInt();
  Serial.print(b1);
  Serial.print(b2);
}

void loop(){
  
}
