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

  bool leitura = digitalRead(pinBotaoDesliga);

  // Detectou uma mudança
  if (leitura != estadoDesliga) {
    ultimoDebounce = millis();
    estadoDesliga = leitura;
  }

  // Espera a leitura ficar estável
  if ((millis() - ultimoDebounce) > tempoDebounce) {

    // Detecta o clique: HIGH -> LOW
    if (estadoDesliga == LOW && ultimoEstadoDesliga == HIGH) {

      contadorDesliga++;

      Serial.print("Clique DESLIGA: ");
      Serial.println(contadorDesliga);

      sistemaLigado = false;
      desligarEsteira();

      if (contadorDesliga >= 3) {

        contadorDesliga = 0;

        retornoEmergencia = true;

        Serial.println(">>> RETORNO DE EMERGENCIA ATIVADO <<<");

        retornaBraco();

        retornoEmergencia = false;

        Serial.println(">>> BRACO RETORNOU AO SETUP <<<");
      }
    }

    ultimoEstadoDesliga = estadoDesliga;
  }
}
