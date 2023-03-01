void buttonpress(int pin) {
  // Een knop indrukken is indrukken en weer loslaten
  digitalWrite(pin, LOW);
  wait(TIME_PRESS);
  digitalWrite(pin, HIGH);
  wait(TIME_PRESS);
}