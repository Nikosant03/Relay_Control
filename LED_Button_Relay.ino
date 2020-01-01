#include "LED_Button_Relay.h"

relays relay;

void setup() {
  Serial.begin(9600);
  
  pinMode(relay1, OUTPUT);
  pinMode(relay2, OUTPUT);
  pinMode(tactile, INPUT);
  digitalWrite(tactile,LOW);

}

void loop() {

  relay.button();

}
