  
int servoBasepin = 10;
int servoDireitapin = 11;
int servoEsquerdapin = 12;
int servoGarrapin = 13;

void iniciaRobo() {

  servoB.attach(servoBasepin);
  servoD.attach(servoDireitapin); 
  servoE.attach(servoEsquerdapin);
  servoG.attach(servoGarrapin); 

  servoB.write(90); //limite min Base
  servoD.write(90); //limite min Altura
  servoE.write(100); //limite min Avanço
  servoG.write(0); //limite min Garra
}


// --- FUNÇÕES DE MOVIMENTO BÁSICO (Músculos) ---
// Estas funções garantem o movimento suave para qualquer ângulo

void moverBase(int anguloDestino) {

  int atual = servoB.read();

  if (atual < anguloDestino) {

    for (int i = atual; i <= anguloDestino; i++) {

      if (!sistemaLigado) return;
      servoB.write(i);
      atualizarSistema();
      delay(15);
    }
  } else {

    for (int i = atual; i >= anguloDestino; i--) {
      
      if (!sistemaLigado) return;
      servoB.write(i);
      atualizarSistema();
      delay(15);
    }
  }
}

void controlarGarra(int anguloDestino) {

  int atual = servoG.read();

  if (atual < anguloDestino) {

    for (int i = atual; i <= anguloDestino; i++) {

      if (!sistemaLigado) return;
      servoG.write(i);
      atualizarSistema();
      delay(15);
    }
  } else {

    for (int i = atual; i >= anguloDestino; i--) {
      servoG.write(i);
      atualizarSistema();
      delay(15);
    }
  }
}

void controlarDireita(int anguloDestino) {

  int atual = servoD.read();

  if (atual < anguloDestino) {

    for (int e = atual; e <= anguloDestino; e++) {

      if (!sistemaLigado) return;
      servoD.write(e);
      atualizarSistema();
      delay(15);
    }
  } else {
    for (int e = atual; e >= anguloDestino; e--) {

      if (!sistemaLigado) return;
      servoD.write(e);
      atualizarSistema();
      delay(15);
    }
  }
}

void controlarEsquerda(int anguloDestino) {

  int atual = servoE.read();

  if (atual < anguloDestino) {

    for (int d = atual; d <= anguloDestino; d++) {

      if (!sistemaLigado) return;
      servoE.write(d);
      atualizarSistema();
      delay(15);
    }
 } else {

    for (int d = atual; d >= anguloDestino; d--) {

      if (!sistemaLigado) return;
      servoE.write(d);
      atualizarSistema();
      delay(15);
    }
  }
}

// --- FUNÇÕES DE AÇÃO COMPOSTA (Tarefas) ---

void executarCicloRobo() {

  if (sistemaLigado == false) return;

  // --- PARTE 1: ESTOQUE -> ESTEIRA ---
  Serial.println("Iniciando: Estoque para Esteira");
  bracoAtivo = true;
  
  moverBase(180);           // Vai no Estoque
  controlarEsquerda(140);   // Avança
  controlarDireita(160);   // Abaixa
  controlarGarra(90);     // PEGA
  controlarEsquerda(100);   // Recolhe
  controlarDireita(90);    // Sobe
  
  moverBase(135);         // Vai para o início da Esteira
  controlarDireita(180); 
  controlarEsquerda(70); 
  controlarEsquerda(90); 
  desligarEsteira();
  controlarGarra(0);      // SOLTA na esteira
  bracoAtivo = false;     // Libera o sensor para parar a esteira e abrir funil
  controlarDireita(90);
  controlarEsquerda(120);   // Recolhe

  verificarSensor1(); //verificação do sensor 1 para a ação do funil
  
  bracoAtivo = false;     // Libera a esteira para levar a caixa
  moverBase(90);          // Fica em posição de espera no meio


  // --- PARTE 2: ESPERAR CHEGAR NO SENSOR 2 ---
  Serial.println("Aguardando caixa chegar no Sensor 2...");

  while (sensor2Ativado == false) {

    //Serial.print("sistemaLigado=");
    //Serial.println(sistemaLigado);

    if (!sistemaLigado) return;

    atualizarSistema();

    delay(100);
}


  // --- PARTE 3: ESTEIRA (SENSOR 2) -> CAMINHÃO ---
  Serial.println("Caixa detectada no Sensor 2! Levando para o caminhão...");

  bracoAtivo = true;      // Para a esteira para o braço agir com segurança
  
  moverBase(45);         // Vai até o final da esteira (Sensor 2) 
  controlarDireita(180);
  controlarEsquerda(70);   
  controlarEsquerda(90); 
  controlarGarra(90);     // PEGA a caixa da esteira
  controlarDireita(90);
  controlarEsquerda(120);   // Recolhe
  moverBase(0);          // Gira até o Caminhão
       
  controlarEsquerda(150);   // Avança     
  controlarDireita(160);   // Recolhe
  controlarGarra(0);   // SOLTA no caminhão
  controlarDireita(90);  
  controlarEsquerda(100);
  
  moverBase(180);      
  bracoAtivo = false;   // Ciclo finalizado
   // Volta para o início para a próxima caixa
  Serial.println("Ciclo completo concluído!");

}
