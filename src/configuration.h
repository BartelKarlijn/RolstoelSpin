// Configuration file

///////////////// Serial  ///////////////////////////
#define SERIALSPEED 9600

///////////////// Pins  //////////////////////////////
#define PIN_JOYMIDDEN       9   //pin13 = PB1=D9
#define PIN_JOYVOORACHT     10   //pin14 = PB1=D10  
#define PIN_JOYLINKRECH     11   //pin15 = PB3=D11
#define PIN_RIGHTTURN       12
#define PIN_SPEEDUP         17
#define PIN_LEFTTURN        18
#define PIN_SPEEDDOWN       8
#define PIN_LIGHTS          7
#define PIN_PROFILE         6
#define PIN_HORN            5
#define PIN_MODE            4
#define PIN_HAZARDS         3   //PIN 13 + INTERNAL LED
#define PIN_ONOFF           2   //gaat naar 5 of 6?
#define PIN_LEDSTRIP        19

///////////////// Spanning  //////////////////////////////
// in mV omdat map functie enkel met gehele getallen werkt
#define MVOLT_RUST 2478 //gemeten op joystick
#define MVOLT_TROW 1300 //zowel in + als -
#define MVOLT_HIGH MVOLT_RUST + MVOLT_TROW
#define MVOLT_LOW  MVOLT_RUST - MVOLT_TROW
#define MVOLT_5V   4580 //gemeten aan uitgang PC

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
