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
void startMillisFunc();

private:

unsigned long currentMillis;
unsigned long startMillis;
int timer1;
int timer2;
const unsigned long Relay1_period = 15000;  //Relay 1 stay active for 15s
const unsigned long Relay2_Start = 2000;  //Relay 2 starts 2 sec after the button is pressed
const unsigned long Relay2_period = 2000;  //Relay 2 stay active for 2sec
  
};




#endif
