int IN1 = 6;
int IN2 = 4;

void iniciaPonteH() {

  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
}

void ligarEsteira(int espera = 0) {
  delay(espera);
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
}

void desligarEsteira() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
}