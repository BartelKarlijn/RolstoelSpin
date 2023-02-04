void simulate_joystick(int vooruit, int zijwaarts) {
    analogWrite( PIN_JOYVOORACHT, vooruit);
    analogWrite( PIN_JOYLINKRECH, zijwaarts);
}
