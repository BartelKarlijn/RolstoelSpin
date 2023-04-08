#include <main\include.h>
CRGB leds[NUM_LEDS];
#define BRIGHTNESS 150

// =======================================================================================
// Setup
// =======================================================================================
void setup()   {

  Serial.begin( SERIALSPEED );
  //FastLED.addLeds<NEOPIXEL, PIN_LEDSTRIP>(leds, NUM_LEDS);  // GRB ordering is assumed
  FastLED.addLeds<WS2811, PIN_LEDSTRIP, RGB>(leds, NUM_LEDS);
  FastLED.setBrightness(BRIGHTNESS);
  blink();
}

// =======================================================================================
// Loop
// =======================================================================================
void loop() {
  // Turn the LED on, then pause
  leds[0] = CRGB::Red;
  leds[1] = CRGB::Green;
  FastLED.show();
  Serial.println("RedGreen");
  delay(500);
  leds[0] = CRGB::Blue;
  leds[1] = CRGB::HotPink;
  FastLED.show();
  Serial.println("BluePink");
  delay(500);
  // Now turn the LED off, then pause
  leds[0] = CRGB::Black;
  leds[1] = CRGB::Black;
  FastLED.show();
  Serial.println("Uit");
  delay(1500);

  // // check if data is available
  // if (Serial.available() > 0) {
  //   // read the incoming byte:
  //   incomingByte = Serial.read();

  //   // prints the received data
  //   //Serial.print("I received: ");
  //   //Serial.println((char)incomingByte);
  //   incomingCMD = toupper( incomingByte );
  //   switch (incomingCMD) {
  //   case 'A': 
  //     Serial.println("LinksVoor");
  //     bew_tgtva = bew_max;
  //     bew_tgtlr = bew_min;
  //     break;
  //   case 'Z': 
  //     Serial.println("Vooruit");
  //     bew_tgtva = bew_max;
  //     bew_tgtlr = bew_rust;
  //     break;
  //   case 'E': 
  //     Serial.println("RechtsVoor");
  //     bew_tgtva = bew_max;
  //     bew_tgtlr = bew_max;
  //     break;
  //   case 'Q': 
  //     Serial.println("Links");
  //     bew_tgtva = bew_rust;
  //     bew_tgtlr = bew_min;
  //     break;
  //   case 'S': 
  //     Serial.println("Stop");
  //     bew_tgtva = bew_rust;
  //     bew_tgtlr = bew_rust;
  //     break;
  //   case 'D': 
  //     Serial.println("Rechts");
  //     bew_tgtva = bew_rust;
  //     bew_tgtlr = bew_max;
  //     break;
  //   case 'W': 
  //     Serial.println("LinksAchter");
  //     bew_tgtva = bew_min;
  //     bew_tgtlr = bew_min;
  //     break;
  //   case 'X': 
  //     Serial.println("Achteruit");
  //     bew_tgtva = bew_min;
  //     bew_tgtlr = bew_rust;
  //     break;
  //   case 'C': 
  //     Serial.println("RechtsAchter");
  //     bew_tgtva = bew_min;
  //     bew_tgtlr = bew_max;
  //     break; 
  //   case 'O': 
  //     Serial.println("Tik Links");
  //     tickleft();
  //     break; 
  //   case 'P': 
  //     Serial.println("Tik Rechts");
  //     tickleft();
  //     break; 
  //   case ' ': 
  //     Serial.println("NoodStop");
  //     noodstop();
  //     break;
  //   case '1':
  //     Serial.println("ON/OFF");
  //     buttonpress(PIN_ONOFF);
  //     break; 
  //   case '2':
  //     Serial.println("HAZARDS");
  //     buttonpress(PIN_HAZARDS);
  //     break; 
  //   case '3':
  //     Serial.println("HORN");
  //     buttonpress(PIN_HORN);
  //     break; 
  //   case '4':
  //     Serial.println("LIGHTS");
  //     buttonpress(PIN_LIGHTS);
  //     break; 
  //   case '5':
  //     Serial.println("MODE");
  //     buttonpress(PIN_MODE);
  //     break; 
  //   case '6':
  //     Serial.println("PROFILE");
  //     buttonpress(PIN_PROFILE);
  //     break; 
  //   case '7':
  //     Serial.println("LEFT TURN");
  //     buttonpress(PIN_LEFTTURN);
  //     break; 
  //   case '8':
  //     Serial.println("SPEED DOWN");
  //     buttonpress(PIN_SPEEDDOWN);
  //     break; 
  //   case '9':
  //     Serial.println("SPEED UP");
  //     buttonpress(PIN_SPEEDUP);
  //     break; 
  //   case '0':
  //     Serial.println("RIGHT TURN");
  //     buttonpress(PIN_RIGHTTURN);
  //     break; 
  //   default:
  //     Serial.print("Ongeldige letter: ");
  //     Serial.println((char)incomingByte);
  //     break;
  //   }
  //   // reset watchdog
  //   timeNow = millis();
  // }

}