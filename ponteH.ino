int IN1 = 3;

int ENA = 2;

int velocidade = 200; // 0 a 255

void iniciaPonteH() {

  pinMode(IN1, OUTPUT);
  pinMode(ENA, OUTPUT);
}

// ===== LIGA ESTEIRA =====


void ligarEsteira(int espera) {

  delay(espera);

  digitalWrite(IN1, HIGH);

  analogWrite(ENA, velocidade);

  esteiraLigada = true;

  Serial.println("Esteira ligada");
  
}

// ===== DESLIGA ESTEIRA =====

void desligarEsteira(int espera) {

  delay(espera);

  analogWrite(ENA, 0);

  digitalWrite(IN1, LOW);

  esteiraLigada = false;

  Serial.println("Esteira desligada");
}