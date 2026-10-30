int IN1 = 22;

void iniciaPonteH() {

  pinMode(IN1, OUTPUT);
  digitalWrite(IN1, LOW);
}

// ===== LIGA ESTEIRA =====

void ligarEsteira(int espera) {

  delay(espera);

  digitalWrite(IN1, HIGH);

  esteiraLigada = true;

  Serial.println("Esteira ligada");

}

// ===== DESLIGA ESTEIRA =====

void desligarEsteira(int espera) {

  delay(espera);

  digitalWrite(IN1, LOW);

  esteiraLigada = false;

  Serial.println("Esteira desligada");
}