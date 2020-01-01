#include "LED_Button_Relay.h"

void relays::button(){

if (digitalRead(tactile)){

  Serial.println("Tactile has been pressed");
  delay(1000);
  }

  
}
