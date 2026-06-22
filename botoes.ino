int pinoBotaoLiga = 5;
int pinoBotaoDesliga = 6;


void iniciaBotao() {

  pinMode(pinoBotaoLiga, INPUT_PULLUP);
  pinMode(pinoBotaoDesliga, INPUT_PULLUP);
}

void botaoLiga() {

  int estadoliga = digitalRead(pinoBotaoLiga);

  if (estadoliga == LOW) {

    sistemaLigado = true;

    Serial.println("Sistema LIGADO");

    delay(500);
  }
}


void botaoDesliga() {

  int estadodesliga = digitalRead(pinoBotaoDesliga);

  if (estadodesliga == LOW) {

    sistemaLigado = false;

    desligarEsteira();

    Serial.println("Sistema DESLIGADO");

    delay(1000);
  }
}