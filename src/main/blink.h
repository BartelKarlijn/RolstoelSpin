void blink() {
    for (int i=0; i<10; i++) {
        digitalWrite(LED_BUILTIN, HIGH);  // turn the LED on (HIGH is the voltage level)
        delay(100);
        digitalWrite(LED_BUILTIN, LOW);   // turn the LED off by making the voltage LOW
        delay(100);
    }
    Serial.println("Setup gedaan");
}