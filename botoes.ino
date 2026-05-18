int botaoliga = 9;
int botaodesliga = 7;

bool sistemaLigado = true;

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
  }
}


void botaoDesliga() {

  int estadodesliga = digitalRead(botaodesliga);

  if (estadodesliga == LOW) {

    sistemaLigado = false;

    Serial.println("Sistema DESLIGADO");

    desligarEsteira();
  }
}