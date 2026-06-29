int IN1 = 2;

int ENA = 3;

int velocidade = 180; // 0 a 255

void iniciaPonteH() {

  pinMode(IN1, OUTPUT);
  pinMode(ENA, OUTPUT);
}

// ===== LIGA ESTEIRA =====


void ligarEsteira(int espera) {

  delay(espera);

  digitalWrite(IN1, HIGH);

  analogWrite(ENA, velocidade);

  Serial.println("Esteira ligada");
  
}

// ===== DESLIGA ESTEIRA =====

void desligarEsteira(int espera) {

  delay(espera);

  analogWrite(ENA, 0);

  digitalWrite(IN1, LOW);

  Serial.println("Esteira desligada");
}