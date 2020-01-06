#ifndef led_button_relay
#define led_button_relay

#if (ARDUINO>=100)
  #include "Arduino.h"
#else
  #include "WProgram.h"
#endif

#define relay1 8
#define relay2 7
#define tactile 3


class relays {

public:

void button();

private:

bool buttonPressed = false; //Flag for button
bool Relay1State = false; // Flag for Relay 1 state
bool Relay2State = false; // Flag for Relay 1 state
bool Relay2DelayON = false; //Flag for Relay 2 delay ON

unsigned long currentMillis;
unsigned long buttonPressedAt;
unsigned long Relay1TurnOn;
unsigned long Relay2TurnOn;

const unsigned long Relay1_period = 15000;  //Relay 1 stay active for 15s
const unsigned long Relay2_Start = 5000;  //Relay 2 starts 2 sec after the button is pressed
const unsigned long Relay2_period = 2000;  //Relay 2 stay active for 2sec
  
};




#endif
