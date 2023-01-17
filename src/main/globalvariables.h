// variables
// uart / serial
int incomingByte = 0; // for incoming serial data
int incomingCMD;

// bewegingen Omzetten van 0-5V naar 0-255
int bew_min = map(VOLT_LOW, 0, 5, 0, 255);
int bew_rust = map(VOLT_RUST, 0, 5, 0, 255);
int bew_max = map(VOLT_HIGH, 0, 5, 0, 255);
int bew_curva = bew_rust;  //huidige beweging
int bew_curlr = bew_rust;
