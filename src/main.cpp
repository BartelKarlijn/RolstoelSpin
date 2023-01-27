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
  Serial.print("bew_min: ");
  Serial.print(bew_min);
  Serial.print(" rust: ");
  Serial.print(bew_rust);
  Serial.print(" max: ");
  Serial.print(bew_max);
  Serial.println();
  Serial.println("Setup gedaan");
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
    //Serial.print("I received: ");
    //Serial.println((char)incomingByte);
    incomingCMD = toupper( incomingByte );
    switch (incomingCMD) {
    case 'A': //Achteruit
      Serial.println("Achteruit");
      bew_tgtva = bew_min;
      bew_tgtlr = bew_rust;
      break;
    case 'L': //Links
      Serial.println("Links");
      bew_tgtva = bew_rust;
      bew_tgtlr = bew_min;
      break;
    case 'R': //Rechts
      Serial.println("Rechts");
      bew_tgtva = bew_rust;
      bew_tgtlr = bew_max;
      break;
    case 'V': //Vooruit
      Serial.println("Vooruit");
      bew_tgtva = bew_max;
      bew_tgtlr = bew_rust;
      break;
    default:
      Serial.print("Ongeldige letter: ");
      Serial.println((char)incomingByte);
      break;
    }
    // reset watchdog
    timeNow = millis();
  }

  // smooth movements
  bew_curva = 0.95 * bew_curva + 0.05 * bew_tgtva;
  bew_curlr = 0.95 * bew_curlr + 0.05 * bew_tgtlr;

  simulate_joystick(bew_curva, bew_curlr);

  // watchdog
  if (millis() - timeNow >= TIMEOUT) {
    Serial.print("Input te traag, time= ");
    Serial.println(timeNow);
    bew_tgtva = bew_rust;
    bew_tgtlr = bew_rust;
    bew_curva = bew_rust;
    bew_curlr = bew_rust;
    timeNow = millis();
  }
}