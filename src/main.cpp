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

  blink();
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
    incomingCMD = toupper( incomingByte );
    switch (incomingCMD) {
    case 'A': //Vooruit
      Serial.print("Vooruit");
      blink();
      break;
    
    default:
      break;
    }


  }
}