void tickleft(){
  //tikje links
  bew_curva = bew_rust;
  bew_curlr = bew_min;
  simulate_joystick(bew_curva, bew_curlr);
  wait(TIME_TICK);
  
  //terug in midden
  bew_curva = bew_rust;
  bew_curlr = bew_rust;
  simulate_joystick(bew_curva, bew_curlr);
  wait(TIME_PRESS);
}

void tickright(){
  //tikje rechts
  bew_curva = bew_rust;
  bew_curlr = bew_max;
  simulate_joystick(bew_curva, bew_curlr);
  wait(TIME_TICK);
  
  //terug in midden
  bew_curva = bew_rust;
  bew_curlr = bew_rust;
  simulate_joystick(bew_curva, bew_curlr);
  wait(TIME_PRESS);
}
