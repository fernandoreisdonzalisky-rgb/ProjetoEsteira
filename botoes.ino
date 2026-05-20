// ===== BOTÕES =====

int botaoliga = 18;
int botaodesliga = 19;


void iniciaBotao() {
  pinMode(botaoliga, INPUT_PULLUP);
  pinMode(botaodesliga, INPUT_PULLUP);
}

void botaoLiga() {
  int estadoliga = digitalRead(botaoliga);

  if (estadoliga == LOW) {
    sistemaLigado = true;

    Serial.println("Sistema LIGADO");

    ligarEsteira();

    delay(300);
  }
}

void botaoDesliga() {
  int estadodesliga = digitalRead(botaodesliga);

  if (estadodesliga == LOW) {
    sistemaLigado = false;

    Serial.println("Sistema DESLIGADO");

    desligarEsteira();

    delay(300);
  }
}
