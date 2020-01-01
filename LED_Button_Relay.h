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
  
};




#endif
