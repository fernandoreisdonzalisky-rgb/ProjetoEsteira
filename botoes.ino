int botaoliga = 5;
int botaodesliga = 6;


void iniciaBotao() {

  pinMode(botaoliga, INPUT_PULLUP);
  pinMode(botaodesliga, INPUT_PULLUP);
}

void botaoLiga() {

  int estadoliga = digitalRead(botaoliga);

  if (estadoliga == LOW) {

    sistemaLigado = true;

    Serial.println("Sistema LIGADO");

    delay(500);
  }
}


void botaoDesliga() {

  int estadodesliga = digitalRead(botaodesliga);

  if (estadodesliga == LOW) {

    sistemaLigado = false;

    desligarEsteira();

    Serial.println("Sistema DESLIGADO");

    delay(1000);
  }
}