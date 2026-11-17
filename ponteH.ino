int pinorele = 22;

void iniciaPonteH() {

  pinMode(pinorele, OUTPUT);
  digitalWrite(pinorele, LOW);
}

// ===== LIGA ESTEIRA =====

void ligarEsteira(int espera) {

  delay(espera);

  digitalWrite(pinorele, HIGH);

  esteiraLigada = true;

  Serial.println("Esteira ligada");

}

// ===== DESLIGA ESTEIRA =====

void desligarEsteira(int espera) {

  delay(espera);

  digitalWrite(pinorele, LOW);

  esteiraLigada = false;

  Serial.println("Esteira desligada");
}