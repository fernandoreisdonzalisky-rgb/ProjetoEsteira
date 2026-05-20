// ===== PONTE H =====

int ENA = 23;
int IN1 = 16;
int IN2 = 17;

int velocidade = 180; // 0 a 255


void iniciaPonteH()  {

  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);

  ledcAttach(ENA, 5000, 8); // pino, frequência, resolução
}

void ligarEsteira(int espera) {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);

  ledcWrite(ENA, velocidade);

  Serial.println("Esteira LIGADA");

}

void desligarEsteira(int espera) {
  ledcWrite(ENA, 0);

  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);

  Serial.println("Esteira DESLIGADA");

}