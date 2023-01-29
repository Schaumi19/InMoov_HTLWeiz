#include <EEPROM.h>

struct AktuatorParameter
{
    bool used[4];
    byte min_angle[4];
    byte max_angle[4];
    unsigned int min_pot[4];
    unsigned int max_pot[4];
    bool reversed_output[4];
    bool reversed_input[4];
    byte goalDeadzone[4];
    byte maxSpeed[4];
    byte maxAngularSpeed[4];  //kleiner 255
    byte ContinuousMovement[4];
};
AktuatorParameter Aktuator = {0,0,0,0,0,0,0,0,0,0,0};
bool Configured = false;

void setup(){
    Serial.begin(115200);
    if(Serial){
        EEPROM.get(1,Configured);
        if(Configured){
           Serial.println("Configured");
           EEPROM.get(2,Aktuator);
           Configured = false;
           EEPROM.put(1,Configured);
           for (byte i = 0; i < 4; i++)
           {
            Serial.print(Aktuator.used[i]);
           }
        }else{
            Serial.println("New");
            Configured = true;
            Aktuator.used[0] = 1;
            Aktuator.used[1] = 0;
            Aktuator.used[2] = 1;
            Aktuator.used[3] = 0;
            EEPROM.put(1,Configured);
            EEPROM.put(2,Aktuator);
        }
    }
    
 
}

void loop(){

}