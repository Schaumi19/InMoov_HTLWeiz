int x;
int y;
void setup() {
 Serial.begin(115200);
 Serial.setTimeout(1);
}
void loop() {
 while (!Serial.available());
 x = Serial.readString().toInt();
 Serial.readStringUntil(",");
 y = Serial.readString().toInt();
 Serial.print(String(x)+String(y));
}
