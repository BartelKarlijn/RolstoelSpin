#include <main\include.h>

// Created by Bodmer 17/3/20 as an example to the TFT_eSPI library:
// https://github.com/Bodmer/TFT_eSPI

// =======================================================================================
// Setup
// =======================================================================================
void setup()   {
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(PIN_JOYVOORACHT, OUTPUT);
  pinMode(PIN_JOYLINKRECH, OUTPUT);
  pinMode(PIN_ONOFF, OUTPUT);
  pinMode(PIN_HAZARDS, OUTPUT);
  pinMode(PIN_HORN, OUTPUT);
  pinMode(PIN_LIGHTS, OUTPUT);
  pinMode(PIN_MODE, OUTPUT);
  pinMode(PIN_PROFILE, OUTPUT);
  pinMode(PIN_LEFTTURN, OUTPUT);
  pinMode(PIN_SPEEDDOWN, OUTPUT);
  pinMode(PIN_SPEEDUP, OUTPUT);
  pinMode(PIN_RIGHTTURN, OUTPUT);
  digitalWrite(PIN_ONOFF, HIGH);
  digitalWrite(PIN_HAZARDS, HIGH);
  digitalWrite(PIN_HORN, HIGH);
  digitalWrite(PIN_LIGHTS, HIGH);
  digitalWrite(PIN_MODE, HIGH);
  digitalWrite(PIN_PROFILE, HIGH);
  digitalWrite(PIN_LEFTTURN, HIGH);
  digitalWrite(PIN_SPEEDDOWN, HIGH);
  digitalWrite(PIN_SPEEDUP, HIGH);
  digitalWrite(PIN_RIGHTTURN, HIGH);

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
    case 'A': //LinksVoor
      Serial.println("LinksVoor");
      bew_tgtva = bew_max;
      bew_tgtlr = bew_min;
      break;
    case 'Z': //Vooruit
      Serial.println("Vooruit");
      bew_tgtva = bew_max;
      bew_tgtlr = bew_rust;
      break;
    case 'E': //RechtsVoor
      Serial.println("RechtsVoor");
      bew_tgtva = bew_max;
      bew_tgtlr = bew_max;
      break;
    case 'Q': //Links
      Serial.println("Links");
      bew_tgtva = bew_rust;
      bew_tgtlr = bew_min;
      break;
    case 'S': //Stop
    case ' ':
      Serial.println("Stop");
      bew_tgtva = bew_rust;
      bew_tgtlr = bew_rust;
      break;
    case 'D': //Rechts
      Serial.println("Rechts");
      bew_tgtva = bew_rust;
      bew_tgtlr = bew_max;
      break;
    case 'W': //LinksAchter
      Serial.println("LinksAchter");
      bew_tgtva = bew_min;
      bew_tgtlr = bew_min;
      break;
    case 'X': //Achteruit
      Serial.println("Achteruit");
      bew_tgtva = bew_min;
      bew_tgtlr = bew_rust;
      break;
    case 'C': //RechtsAchter
      Serial.println("RechtsAchter");
      bew_tgtva = bew_min;
      bew_tgtlr = bew_max;
      buttonpress(PIN_HAZARDS);
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
  //bew_curva = 0.95 * bew_curva + 0.05 * bew_tgtva;
  //bew_curlr = 0.95 * bew_curlr + 0.05 * bew_tgtlr;
  bew_curva = bew_tgtva;
  bew_curlr = bew_tgtlr;

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