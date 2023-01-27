void move_smooth(int vooruit, int zijwaarts) {
  bew_curva = 0.95 * bew_curva + 0.05 * bew_tgtva;
  bew_curlr = 0.95 * bew_curlr + 0.05 * bew_tgtlr;
}
