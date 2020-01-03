#include "LED_Button_Relay.h"

void relays::startMillisFunc() {

  startMillis = millis();
}


void relays::button() {

  //If the switch is pressed
  if (digitalRead(tactile)) {

    while (currentMillis - startMillis < Relay1_period)  //test whether the period (Relay1) has elapsed
    {
      digitalWrite(relay1, HIGH); //Activate instantly the first relay
      Serial.print("Relay 1 is ON ");
      Serial.println(currentMillis);
      delay(1000);
      currentMillis = millis();

      if (currentMillis - startMillis >= Relay2_Start) {

        while (currentMillis - startMillis <= Relay2_period + Relay2_Start) {
          digitalWrite(relay2, HIGH); //Activate instantly the first relay
          Serial.print("Relay 2 is ON ");
          Serial.println(currentMillis);
          currentMillis = millis();
        }
        digitalWrite(relay2, LOW);
        Serial.print("Relay 2 is OFF ");
        Serial.println(currentMillis);
      }

    }
    digitalWrite(relay1, LOW);
    Serial.println("Relay 1 is OFF");


  }
}
