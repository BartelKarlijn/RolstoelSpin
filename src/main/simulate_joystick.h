void simulate_joystick(int vooruit, int zijwaarts) {
    analogWrite( PIN_VOORACHT, vooruit);
    analogWrite( PIN_LINKRECH, zijwaarts);
}

void smooth_joystick(int vooruit, int zijwaarts) {
    // in 2 sec opschalen
    for (int i=0; i<10; i++) {
      bew_curva = 0.95 * bew_curva + 0.05 * vooruit;
      bew_curlr = 0.95 * bew_curlr + 0.05 * zijwaarts;
      simulate_joystick( bew_curva, bew_curlr);
      delay(200);
    }
    // 5sec houden
    simulate_joystick (vooruit, zijwaarts);
    delay(5000);

    // in 2 sec afschalen
    for (int i=0; i<10; i++) {
      bew_curva = 0.95 * bew_curva + 0.05 * bew_rust;
      bew_curlr = 0.95 * bew_curlr + 0.05 * bew_rust;
      simulate_joystick( bew_curva, bew_curlr);
      delay(200);
    }
    simulate_joystick (bew_rust, bew_rust);
}