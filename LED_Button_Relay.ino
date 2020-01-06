#include "LED_Button_Relay.h"



relays relay;

void setup() {
  Serial.begin(9600);
  
  pinMode(tactile, INPUT);
  pinMode(relay1, OUTPUT);
  pinMode(relay2, OUTPUT);
  digitalWrite(tactile, LOW);
  digitalWrite(relay1, HIGH); //The initial state of the relay1 is OFF
  digitalWrite(relay2, HIGH); //The initial state of the relay2 is OFF

}

void loop() {

  relay.button();

}
