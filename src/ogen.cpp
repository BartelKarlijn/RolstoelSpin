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
  // //blend
  // leds[0] = CRGB::Red;
  // leds[1] = CRGB::White;
  // for (int i = 0; i < 255; i++)
  // {
  //   leds[0] = blend( leds[0], CRGB::Blue, 1 );
  //   leds[1] = blend( leds[1], CRGB::Blue, 2 );
  //   FastLED.show();
  // }
  
  // check if data is available
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
      break;
    case 'Z': 
      Serial.println("Vooruit");
      break;
    case 'E': 
      Serial.println("RechtsVoor");
      break;
    case 'Q': 
      Serial.println("Links");
      break;
    case 'S': 
      Serial.println("Stop");
      break;
    case 'D': 
      Serial.println("Rechts");
      break;
    case 'W': 
      Serial.println("LinksAchter");
      break;
    case 'X': 
      Serial.println("Achteruit");
      break;
    case 'C': 
      Serial.println("RechtsAchter");
      break; 
    case 'O': 
      Serial.println("Tik Links");
      break; 
    case 'P': 
      Serial.println("Tik Rechts");
      break; 
    case ' ': 
      Serial.println("NoodStop");
      oog_kleuren(FCT_AAN, CRGB::Black, FCT_AAN, CRGB::Black );
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
      led_wakeup();
      break;
    case '5':
      Serial.println("MODE");
      oog_kleuren(FCT_FADE, CRGB::Yellow, FCT_FADE, CRGB::YellowGreen );
      break; 
    case '6':
      Serial.println("PROFILE");
      oog_kleuren(FCT_FADE, CRGB::Red, FCT_FADE, CRGB::Red );
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

    timeNow = millis();
  }
  ogen_process();  

}