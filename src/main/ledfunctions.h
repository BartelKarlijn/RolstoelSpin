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
    case FCT_FADE: 
      fade_counter[lednr]++;
      if ( fade_counter[lednr] >= FADE_DELAY ){
        fade_counter[lednr] = 0;
        leds[lednr] = blend( leds[lednr], oog_color[lednr], 1 );
      }
      break;     
    case FCT_RAND: 
      fade_counter[lednr]++;
      if ( fade_counter[lednr] >= rand_delay[lednr] ){
        fade_counter[lednr] = 0;
        rand_counter[lednr]++;
        if ( rand_counter[lednr] >= 255 ){
          rand_counter[lednr] = 0;
          if (oog_randomstatus[lednr] ){
            // ga naar 2e kleur
            Serial.print( "naar 2e kleur: ");
            Serial.println(oog_color2[lednr]);
            rand_delay[lednr] = random (0,RAND_DELAYMAX);
            oog_color[lednr] = oog_color2[lednr];
            oog_randomstatus[lednr] = not(oog_randomstatus[lednr]);
          } 
          else {
            //ga naar random kleur
            Serial.print( "naar random kleur: ");
            Serial.println(oog_color2[lednr]);
            rand_delay[lednr] = random (0,RAND_DELAYMAX);
            oog_color[lednr]  = RAND_COLOR;
            oog_randomstatus[lednr] = not(oog_randomstatus[lednr]);
          }
        }
        leds[lednr] = blend( leds[lednr], oog_color[lednr], 1 );
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
  oog_color2[0] = kleurL;  //kleur bijhouden voor random
  oog_color2[1] = kleurR;
}