// variables
// uart / serial
int incomingByte = 0; // for incoming serial data
int incomingCMD;

// bewegingen Omzetten van 0-5V naar 0-255
int bew_min = map(MVOLT_LOW, MVOLT_0V , MVOLT_5V , 0, 255);
int bew_rust = map(MVOLT_RUST, MVOLT_0V, MVOLT_5V, 0, 255);
int bew_max = map(MVOLT_HIGH, MVOLT_0V, MVOLT_5V, 0, 255);
int bew_curva = bew_rust;  //huidige beweging
int bew_curlr = bew_rust;
int bew_tgtva = bew_rust;  //target
int bew_tgtlr = bew_rust;

// voor watchdog
unsigned long timeNow = 0;

// voor LEDs
CRGB leds[NUM_LEDS];
int  oog_fct[NUM_LEDS];   // welke functie?  AAN, PINK of FADE
CRGB oog_color[NUM_LEDS]; // tobe color
int  oog_fade[NUM_LEDS];  // status van fading
bool oog_pinkerstatus[NUM_LEDS];
unsigned long timePink[NUM_LEDS] = {0, 0};
