int servoBasepin = 5; // verde
int servoDireitapin = 17; // branco
int servoEsquerdapin = 16; // laranja
int servoGarrapin = 4; // vermelho

int rapidez = 20;

void iniciaRobo() {

  servoB.attach(servoBasepin);
  servoD.attach(servoDireitapin);
  servoE.attach(servoEsquerdapin);
  servoG.attach(servoGarrapin);

  servoB.write(90); //meio da base
  servoD.write(34); //ângulo mais alto da altura
  servoE.write(84); //ângulo min do avanço
  servoG.write(90); //limite min Garra
}

void retornaBraco() {

  bracoAtivo = true;

  servoB.write(90);
  servoD.write(34); 
  servoE.write(84); 
  servoG.write(90);

  bracoAtivo = false;

  sistemaLigado = false;

  Serial.println("Braco no SETUP.");
  Serial.println("Sistema DESLIGADO.");
}

// --- FUNÇÕES DE MOVIMENTO BÁSICO (Músculos) ---

void moverBase(int anguloDestino) {

  int atual = servoB.read();

  if (atual < anguloDestino) {

    for (int i = atual; i <= anguloDestino; i++) {

      if (!sistemaLigado && !retornoEmergencia) return;
      servoB.write(i);
      atualizarSistema();
      delay(rapidez);
    }
  } else {

    for (int i = atual; i >= anguloDestino; i--) {

      if (!sistemaLigado && !retornoEmergencia) return;
      servoB.write(i);
      atualizarSistema();
      delay(rapidez);
    }
  }
}

void controlarGarra(int anguloDestino) {

  int atual = servoG.read();

  if (atual < anguloDestino) {

    for (int i = atual; i <= anguloDestino; i++) {

      if (!sistemaLigado  && !retornoEmergencia) return;
      servoG.write(i);
      atualizarSistema();
      delay(rapidez);
    }
  } else {

    for (int i = atual; i >= anguloDestino; i--) {

      if (!sistemaLigado && !retornoEmergencia) return;

      servoG.write(i);
      atualizarSistema();
      delay(rapidez);
    }
  }
}

void controlarDireita(int anguloDestino) {

  int atual = servoD.read();

  if (atual < anguloDestino) {

    for (int e = atual; e <= anguloDestino; e++) {

      if (!sistemaLigado && !retornoEmergencia) return;
      servoD.write(e);
      atualizarSistema();
      delay(rapidez);
    }
  } else {
    for (int e = atual; e >= anguloDestino; e--) {

      if (!sistemaLigado && !retornoEmergencia) return;
      servoD.write(e);
      atualizarSistema();
      delay(rapidez);
    }
  }
}

void controlarEsquerda(int anguloDestino) {

  int atual = servoE.read();

  if (atual < anguloDestino) {

    for (int d = atual; d <= anguloDestino; d++) {

      if (!sistemaLigado && !retornoEmergencia) return;
      servoE.write(d);
      atualizarSistema();
      delay(rapidez);
    }
  } else {

    for (int d = atual; d >= anguloDestino; d--) {

      if (!sistemaLigado && !retornoEmergencia) return;
      servoE.write(d);
      atualizarSistema();
      delay(rapidez);
    }
  }
}


// --- FUNÇÕES DE AÇÃO COMPOSTA (Tarefas) ---

void executarCicloRobo() {

  if (sistemaLigado == false && !retornoEmergencia) return;

  // --- PARTE 1: ESTOQUE -> ESTEIRA ---
  Serial.println("Iniciando: Estoque para Esteira");
  bracoAtivo = true;

  moverBase(180);  // Vai no Estoque
  controlarGarra(130);
  controlarEsquerda(20); //avança
  controlarDireita(82);     // PEGA
  controlarEsquerda(9);
  controlarDireita(164);
  controlarGarra(108);
  controlarDireita(100);//recolhe

  moverBase(159);         // Vai para o início da Esteira
  controlarEsquerda(60);
  controlarDireita(147);
  desligarEsteira();
  controlarGarra(130);      // SOLTA na esteira
  controlarDireita(34);
  controlarEsquerda(84);
  controlarGarra(90);
  moverBase(90);          // Fica em posição de espera no meio
  bracoAtivo = false;
  verificarSensor1(); //verificação do sensor 1 para a ação do funil


  // --- PARTE 2: ESPERAR CHEGAR NO SENSOR 2 ---

  if (funilAberto == true) {
    Serial.println("Aguardando caixa chegar no Sensor 2...");
  }
  while (sensor2Ativado == false) {

    if (!sistemaLigado && !retornoEmergencia) return;

    atualizarSistema();

    delay(10);
  }


  // --- PARTE 3: SENSOR 2 -> CAMINHÃO ---

  bracoAtivo = true;

  moverBase(34);
  controlarGarra(150);
  controlarEsquerda(49);
  controlarDireita(150);
  controlarGarra(90);       // Pega a caixa

  controlarDireita(100);
  moverBase(0);     //gira até o caminhão
  controlarEsquerda(14);
  controlarDireita(130);
  controlarGarra(130);  //solta a caixa
  controlarDireita(90);


// volta para o setup

  moverBase(180);

  bracoAtivo = false;

  Serial.println("Ciclo completo concluído!");
}
