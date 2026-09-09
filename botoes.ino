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

    delay(500);
  }
}


void botaoDesliga() {

  int estadoDesliga = digitalRead(pinBotaoDesliga);

  if (estadoDesliga == LOW) {

    contadorDesliga++;

    Serial.print("Clique no DESLIGA: ");
    Serial.println(contadorDesliga);

    // Desliga o sistema normalmente
    sistemaLigado = false;
    desligarEsteira();

    // Só ativa o retorno no terceiro clique
    if (contadorDesliga >= 3) {
      contadorDesliga = 0;

      retornoEmergencia = true;

      Serial.println(">>> RETORNO DE EMERGENCIA ATIVADO <<<");

      retornaBraco();

      retornoEmergencia = false;

      Serial.println(">>> BRACO RETORNOU AO SETUP <<<");
    }

    delay(500);
  }
}