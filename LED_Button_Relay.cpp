#include "LED_Button_Relay.h"

void relays::startMillisFunc() {

  startMillis = millis();
}


void relays::button() {

  //If the switch is pressed
  if (digitalRead(tactile)) {

    currentMillis = millis();

    //Stay in the loop for 15sec
    while (currentMillis - startMillis < 3000) {

      digitalWrite(relay1, HIGH); //Activate instantly the first relay
      startMillis = currentMillis;
      Serial.println("HIGH");
      //delay(1000);
    }

    digitalWrite(relay1, LOW);
    
  }
}
