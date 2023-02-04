void buttonpress(int pin) {
  // Een knop indrukken is indrukken en weer loslaten
  digitalWrite(pin, LOW);
  delay(TIME_PRESS);
  digitalWrite(pin, HIGH);
  delay(TIME_PRESS);
}