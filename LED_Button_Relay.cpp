#include "LED_Button_Relay.h"


void relays::button() {

  currentMillis = millis();

//Check if the tactile has been pressed
  if (digitalRead(tactile) == HIGH) {
    buttonPressedAt = currentMillis; // store the time that the button been pressed
    buttonPressed = true; //change the flag into true if the button has been pressed
    Serial.println("Button Pressed");
  }

  //Check if the button pressed and configure the flags
  if (buttonPressed) {
    Serial.println("Relay 1 turned ON instantly"); //Turn ON Relay1
    digitalWrite(relay1, LOW);

    // Check if the time delay for turning ON Relay 2 has been passed
    while (Relay2State == false) {
      currentMillis = millis();
      if ((currentMillis - buttonPressedAt) >= Relay2_Start) {
        Serial.print("Relay 2 turned ON at: "); Serial.println(currentMillis - buttonPressedAt);
        digitalWrite(relay2, LOW);
        Relay2State = true;
        Relay2TurnOn = currentMillis;
      }
    }

    Relay1State = true;
    buttonPressed = false;
    Relay1TurnOn = currentMillis;
  }

  //Turn OFF Relay2
  if (Relay2State) {
    if ((currentMillis - Relay2TurnOn ) >= (Relay2_period)) {
      Serial.print("Relay 2 turned OFF at: "); Serial.println(currentMillis - buttonPressedAt);
      digitalWrite(relay2, HIGH);
      Relay2State = false;
    }
  }

  //Turn OFF Relay1
  if (Relay1State) {
    if ((currentMillis - Relay1TurnOn) >= Relay1_period ) {
      Serial.print("Relay 1 turned OFF at "); Serial.println(currentMillis - Relay1TurnOn);
      digitalWrite(relay1, HIGH);
      Relay1State = false;
    }
  } 
}
