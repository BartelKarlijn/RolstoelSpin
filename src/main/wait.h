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
        bew_tgtva = bew_max;
        bew_tgtlr = bew_min;
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