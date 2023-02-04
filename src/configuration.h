// Configuration file

///////////////// Serial  ///////////////////////////
#define SERIALSPEED 9600

///////////////// Pins  //////////////////////////////
#define PIN_JOYVOORACHT     5    //pins 5&6 are capable of PWM up to 980Hz
#define PIN_JOYLINKRECH     6
#define PIN_ONOFF           2
#define PIN_HAZARDS         3
#define PIN_HORN            4
#define PIN_LIGHTS          7
#define PIN_MODE            8
#define PIN_PROFILE         9
#define PIN_LEFTTURN        10
#define PIN_SPEEDDOWN       11
#define PIN_SPEEDUP         12   //PIN 13 + INTERNAL LED
#define PIN_RIGHTTURN       14

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
#define TIME_PRESS 100
  