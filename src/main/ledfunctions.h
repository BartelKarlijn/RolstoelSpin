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

void led_Black(){
  leds[0] = CRGB::Black;
  leds[1] = CRGB::Black;
  FastLED.show();
}

void led_Red(){
  leds[0] = CRGB::Red;
  leds[1] = CRGB::Red;
  FastLED.show();
}

void led_Green(){
  leds[0] = CRGB::Green;
  leds[1] = CRGB::Green;
  FastLED.show();
}

void led_Blue(){
  leds[0] = CRGB::Blue;
  leds[1] = CRGB::Blue;
  FastLED.show();
}
