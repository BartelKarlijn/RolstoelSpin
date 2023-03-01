void noodstop() {
  bew_tgtva = bew_max;
  bew_tgtlr = bew_min;
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

  Serial.println("Noodstop uitgevoerd");
}