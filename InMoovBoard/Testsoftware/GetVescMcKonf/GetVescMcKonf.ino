#include <VescUart.h>


VescUart UART;



void setup() {
  Serial.begin(115200);
  Serial1.begin(115200);

    

  UART.setSerialPort(&Serial1);
  
    Serial.println();
   Serial.print("Started");

}

void loop() {
  Serial.print("New");
  // put your main code here, to run repeatedly:
    if(UART.getMCCONF()){
      
      Serial.print("Current:");
      
    Serial.println(UART.mcconf.l_current_max);
    }else{
      Serial.print("Fail");
    }
    
    
  
  
    
  
}
