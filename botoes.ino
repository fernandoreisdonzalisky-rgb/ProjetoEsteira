int botaoLiga = 5;
int botaoDesliga = 6;


void iniciaBotao() {

  pinMode(botaoLiga, INPUT_PULLUP);
  pinMode(botaoDesliga, INPUT_PULLUP);
}

void botaoLiga() {

  int estadoliga = digitalRead(botaoLiga);

  if (estadoliga == LOW) {

    sistemaLigado = true;

    Serial.println("Sistema LIGADO");

    delay(500);
  }
}


void botaoDesliga() {

  int estadodesliga = digitalRead(botaoDesliga);

  if (estadodesliga == LOW) {

    sistemaLigado = false;

    desligarEsteira();

    Serial.println("Sistema DESLIGADO");

    delay(1000);
  }
}