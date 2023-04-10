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

  Serial.begin( SERIALSPEED );

  noodstop();
 
  Serial.print("bew_min: ");
  Serial.print(bew_min);
  Serial.print(" rust: ");
  Serial.print(bew_rust);
  Serial.print(" max: ");
  Serial.print(bew_max);
  Serial.println();
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
    case 'A': 
      Serial.println("LinksVoor");
      bew_tgtva = bew_max;
      bew_tgtlr = bew_min;
      break;
    case 'Z': 
      Serial.println("Vooruit");
      bew_tgtva = bew_max;
      bew_tgtlr = bew_rust;
      break;
    case 'E': 
      Serial.println("RechtsVoor");
      bew_tgtva = bew_max;
      bew_tgtlr = bew_max;
      break;
    case 'Q': 
      Serial.println("Links");
      bew_tgtva = bew_rust;
      bew_tgtlr = bew_min;
      break;
    case 'S': 
      Serial.println("Stop");
      bew_tgtva = bew_rust;
      bew_tgtlr = bew_rust;
      break;
    case 'D': 
      Serial.println("Rechts");
      bew_tgtva = bew_rust;
      bew_tgtlr = bew_max;
      break;
    case 'W': 
      Serial.println("LinksAchter");
      bew_tgtva = bew_min;
      bew_tgtlr = bew_min;
      break;
    case 'X': 
      Serial.println("Achteruit");
      bew_tgtva = bew_min;
      bew_tgtlr = bew_rust;
      break;
    case 'C': 
      Serial.println("RechtsAchter");
      bew_tgtva = bew_min;
      bew_tgtlr = bew_max;
      break; 
    case 'O': 
      Serial.println("Tik Links");
      tickleft();
      break; 
    case 'P': 
      Serial.println("Tik Rechts");
      tickleft();
      break; 
    case ' ': 
      Serial.println("NoodStop");
      noodstop();
      break;
    case '1':
      Serial.println("ON/OFF");
      buttonpress(PIN_ONOFF);
      break; 
    case '2':
      Serial.println("HAZARDS");
      buttonpress(PIN_HAZARDS);
      break; 
    case '3':
      Serial.println("HORN");
      buttonpress(PIN_HORN);
      break; 
    case '4':
      Serial.println("LIGHTS");
      buttonpress(PIN_LIGHTS);
      break; 
    case '5':
      Serial.println("MODE");
      buttonpress(PIN_MODE);
      break; 
    case '6':
      Serial.println("PROFILE");
      buttonpress(PIN_PROFILE);
      break; 
    case '7':
      Serial.println("LEFT TURN");
      buttonpress(PIN_LEFTTURN);
      break; 
    case '8':
      Serial.println("SPEED DOWN");
      buttonpress(PIN_SPEEDDOWN);
      break; 
    case '9':
      Serial.println("SPEED UP");
      buttonpress(PIN_SPEEDUP);
      break; 
    case '0':
      Serial.println("RIGHT TURN");
      buttonpress(PIN_RIGHTTURN);
      break; 
    default:
      Serial.print("Ongeldige letter: ");
      Serial.println((char)incomingByte);
      break;
    }
    // reset watchdog
    timeNow = millis();
  }

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