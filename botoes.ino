int pinBotaoLiga= 5;
int pinBotaoDesliga = 6;


void iniciaBotao() {

  pinMode(pinBotaoLiga, INPUT_PULLUP);
  pinMode(pinBotaoDesliga, INPUT_PULLUP);
}

void botaoLiga() {

  int estadoliga = digitalRead(pinBotaoLiga);

  if (estadoliga == LOW) {

    sistemaLigado = true;

    Serial.println("Sistema LIGADO");
    exibirMensagem("Sistema LIGADO", "Iniciando...");

    delay(500);
  }
}


void botaoDesliga() {

  int estadodesliga = digitalRead(pinBotaoDesliga);

  if (estadodesliga == LOW) {

    sistemaLigado = false;

    desligarEsteira();

    Serial.println("Sistema DESLIGADO");
    exibirMensagem("Sistema OFF", "Aguardando...");

    delay(1000);
  }
}