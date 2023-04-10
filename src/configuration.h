// Configuration file

///////////////// Serial  ///////////////////////////
#define SERIALSPEED 9600

///////////////// Pins  //////////////////////////////
#define PIN_JOYVOORACHT     5    //pins 5&6 are capable of PWM up to 980Hz
#define PIN_JOYLINKRECH     6
#define PIN_ONOFF           14
#define PIN_HAZARDS         12   //PIN 13 + INTERNAL LED
#define PIN_HORN            10
#define PIN_LIGHTS          8
#define PIN_MODE            11
#define PIN_PROFILE         9
#define PIN_LEFTTURN        4
#define PIN_SPEEDDOWN       7
#define PIN_SPEEDUP         3
#define PIN_RIGHTTURN       2
#define PIN_LEDSTRIP        19

///////////////// Spanning  //////////////////////////////
// in mV omdat map functie enkel met gehele getallen werkt
#define MVOLT_0V      0
#define MVOLT_RUST 2600
#define MVOLT_HIGH 3900
#define MVOLT_LOW  1300
#define MVOLT_5V   5000

///////////////// Watchdog  //////////////////////////////
// Timeout in ms
#define TIMEOUT 5000

///////////////// Tijd om op knop te drukken  //////////////////////////////
#define TIME_PRESS 100  //knop indrukken
#define TIME_TICK 1000  //Joystick tick links/rechts
  
///////////////// LEDS ogen  //////////////////////////////
#define NUM_LEDS       2
#define LED_BRIGHTNESS 150
#define LED_TYPE       WS2811
#define LED_COLORORDER RGB
#define FCT_AAN        1
#define FCT_PINK       2
#define FCT_FADE       3
#define FCT_RAND       4
#define TIME_PINK      1000 //pinker knipper tijd
#define FADE_DELAY     10   //maakt fade functie trager
#define RAND_DELAYMAX  20   //Traagste
#define RAND_COLOR     CRGB::DarkRed
