#include <main\include.h>

// Created by Bodmer 17/3/20 as an example to the TFT_eSPI library:
// https://github.com/Bodmer/TFT_eSPI

// =======================================================================================
// Setup
// =======================================================================================
void setup()   {
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(LED_BUILTIN, OUTPUT);
  Serial.begin( SERIALSPEED );

  for (int i=0; i<5; i++) {
    digitalWrite(LED_BUILTIN, HIGH);  // turn the LED on (HIGH is the voltage level)
    delay(200);
    digitalWrite(LED_BUILTIN, LOW);   // turn the LED off by making the voltage LOW
    delay(200);
  }
}

// =======================================================================================
// Loop
// =======================================================================================
void loop() {
  // check if data is available
  if (Serial.available() > 0) {
    // read the incoming byte:
    incomingByte = Serial.read();

    // prints the received data
    Serial.print("I received: ");
    Serial.println((char)incomingByte);
  }
}