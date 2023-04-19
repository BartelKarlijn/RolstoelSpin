#include <main\include.h>

// =======================================================================================
// Setup
// =======================================================================================
void setup()   {

  Serial.begin( SERIALSPEED );
  //FastLED.addLeds<NEOPIXEL, PIN_LEDSTRIP>(leds, NUM_LEDS);  // GRB ordering is assumed
  FastLED.addLeds<LED_TYPE, PIN_LEDSTRIP, LED_COLORORDER>(leds, NUM_LEDS);
  FastLED.setBrightness(LED_BRIGHTNESS);
  blink();
}

// =======================================================================================
// Loop
// =======================================================================================
void loop() {
  if (Serial.available() > 0) {
   // read the incoming byte:
   incomingByte = Serial.read();

   // prints the received data
   //Serial.print("I received: ");
   //Serial.println((char)incomingByte);
   incomingCMD = toupper( incomingByte );
   switch (incomingCMD) {
   case 'A': 
      Serial.println("LinksVoor");
      oog_kleuren(FCT_PINK, CRGB::OrangeRed, FCT_AAN, CRGB::Purple );
      break;
    case 'Z': 
      Serial.println("Vooruit");
      oog_kleuren(FCT_AAN, CRGB::Purple, FCT_AAN, CRGB::Purple );
      break;
    case 'E': 
      Serial.println("RechtsVoor");
      oog_kleuren(FCT_AAN, CRGB::Purple, FCT_PINK, CRGB::OrangeRed );
      break;
    case 'Q': 
      Serial.println("Links");
      oog_kleuren(FCT_PINK, CRGB::OrangeRed, FCT_AAN, CRGB::Red );
      break;
    case 'S': 
      Serial.println("Stop");
      oog_kleuren(FCT_AAN, CRGB::Red, FCT_AAN, CRGB::Red );
      break;
    case 'D': 
      Serial.println("Rechts");
      oog_kleuren(FCT_AAN, CRGB::Red, FCT_PINK, CRGB::OrangeRed );
      break;
    case 'W': 
      Serial.println("LinksAchter");
      oog_kleuren(FCT_PINK, CRGB::OrangeRed, FCT_AAN, CRGB::Blue);
      break;
    case 'X': 
      Serial.println("Achteruit");
      oog_kleuren(FCT_AAN, CRGB::Blue, FCT_AAN, CRGB::Blue);
      break;
    case 'C': 
      Serial.println("RechtsAchter");
      oog_kleuren(FCT_AAN, CRGB::Blue, FCT_PINK, CRGB::OrangeRed);
      break; 
    case 'O': 
      Serial.println("Tik Links");
      break; 
    case 'P': 
      Serial.println("Tik Rechts");
      break; 
    case ' ': 
      Serial.println("NoodStop");
      oog_kleuren(FCT_PINK, CRGB::Purple, FCT_PINK, CRGB::Purple );
      break;
    case '1':
      Serial.println("ON/OFF");
      oog_kleuren(FCT_AAN, CRGB::Red, FCT_AAN, CRGB::Red );
      break; 
     case '2':
      Serial.println("HAZARDS");
      oog_kleuren(FCT_PINK, CRGB::OrangeRed, FCT_PINK, CRGB::OrangeRed );
      break; 
    case '3':
      Serial.println("HORN");
      oog_kleuren(FCT_AAN, CRGB::Blue, FCT_AAN, CRGB::Blue );
      break; 
    case '4':
      Serial.println("LIGHTS");
      oog_kleuren(FCT_RAND, CRGB::Red, FCT_RAND, CRGB::White);
      break;
    case '5':
      Serial.println("MODE");
      oog_kleuren(FCT_FADE, CRGB::Yellow, FCT_FADE, CRGB::YellowGreen );
      break; 
    case '6':
      Serial.println("PROFILE");
      oog_kleuren(FCT_RAND, CRGB::Red, FCT_RAND, CRGB::Red );
      break;
    case '7':
      Serial.println("LEFT TURN");
      break; 
    case '8':
      Serial.println("SPEED DOWN");
      break; 
    case '9':
      Serial.println("SPEED UP");
      break; 
    case '0':
      Serial.println("RIGHT TURN");
      break; 
    default:
      Serial.print("Ongeldige letter: ");
      Serial.println((char)incomingByte);
      break;
    }
    // reset watchdog
    timeNow = millis();
  }
  // watchdog
  if (millis() - timeNow >= TIMEOUT) {
    Serial.print("Input te traag, time= ");
    Serial.println(timeNow);
    oog_kleuren(FCT_PINK, CRGB::Purple, FCT_PINK, CRGB::Purple );

    timeNow = millis();
  }
  ogen_process();  

}