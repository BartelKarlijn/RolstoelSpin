#include <main\include.h>

// Created by Bodmer 17/3/20 as an example to the TFT_eSPI library:
// https://github.com/Bodmer/TFT_eSPI

// =======================================================================================
// Setup
// =======================================================================================
void setup()   {
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(PIN_VOORACHT, OUTPUT);
  pinMode(PIN_LINKRECH, OUTPUT);

  Serial.begin( SERIALSPEED );

  simulate_joystick(bew_rust, bew_rust);
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
    case 'A': //Achteruit
      Serial.println("Achteruit");
      blink();
      smooth_joystick(bew_min, bew_rust);
      break;
    case 'L': //Links
      Serial.println("Links");
      blink();
      smooth_joystick(bew_rust, bew_min);
      break;
    case 'R': //Rechts
      Serial.println("Rechts");
      blink();
      smooth_joystick(bew_rust, bew_max);
      break;
    case 'V': //Vooruit
      Serial.println("Vooruit");
      blink();
      smooth_joystick(bew_max, bew_rust);
      break;
    
    default:
      break;
    }


  }
}