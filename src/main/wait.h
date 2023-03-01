void wait( unsigned long time){
  timeNow = millis();

  while (millis() - timeNow >= time) {
    // check if data is available
    if (Serial.available() > 0) {
      // read the incoming byte:
      incomingByte = Serial.read();

      incomingCMD = toupper( incomingByte );
      switch (incomingCMD) {
      case ' ': //Noodstop
        Serial.println("Noodstop");
        noodstop();
        break;
      default:
        Serial.print("Negeren: ");
        Serial.println((char)incomingByte);
        break;
      }
    }
  delay( 1 );
  }
}