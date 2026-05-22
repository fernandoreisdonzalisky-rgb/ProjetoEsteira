int IN1 = 6;
int IN2 = 7;

void iniciaPonteH() {

  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
}

void ligarEsteira(int espera = 0) {
  delay(espera);
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);

  Serial.print("Esteira Ligada");
}

void desligarEsteira(int espera = 0) {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);

  Serial.print("Esteira Desligada");
}