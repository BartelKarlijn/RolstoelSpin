void led_process(int lednr){
    switch (oog_fct[lednr]) {
    case FCT_AAN: 
      leds[lednr] = oog_color[lednr];
      break;
    case FCT_PINK: 
      if (millis() - timePink[lednr] >= TIME_PINK) {
        if (oog_pinkerstatus[lednr]) {
          // pinker is aan: zet uit
          leds[lednr] = oog_color[lednr];
          oog_pinkerstatus[lednr] = not( oog_pinkerstatus[lednr]);
        }
        else {
          // pinker is uit: zet aan
          leds[lednr] = CRGB::Black;
          oog_pinkerstatus[lednr] = not( oog_pinkerstatus[lednr]);
        }          
        timePink[lednr] = millis();
      }
      break;
    default:
      break;
    }
}

void ogen_process(){
  led_process(0);
  led_process(1);
  FastLED.show();
}

void oog_kleuren(int fctL, CRGB kleurL, int fctR, CRGB kleurR){
  oog_fct[0] = fctL;
  oog_fct[1] = fctR;
  oog_color[0] = kleurL;
  oog_color[1] = kleurR;
}

void led_wakeup(){
  leds[0] = CRGB::Black;
  leds[1] = CRGB::Black;
  FastLED.show();

  for (int i = 0; i < 50; i++)
  {
    leds[0] = blend( leds[0], CRGB::Red, 1 );
    FastLED.show();
    delay(10);
  }
  leds[0] = CRGB::Black;
  FastLED.show();
  delay(1000);

  for (int i = 0; i < 255; i++)
  {
    leds[0] = blend( leds[0], CRGB::Red, 2 );
    leds[1] = blend( leds[1], CRGB::Red, 1 );
    FastLED.show();
  }
  delay(500);
}