  
  int servoBasepin = 10;
  int servoDireitapin = 11;
  int servoEsquerdapin = 12;
  int servoGarrapin = 13;

void iniciaRobo() {

  servoB.attach(servoBasepin);
  servoD.attach(servoDireitapin); 
  servoE.attach(servoEsquerdapin);
  servoG.attach(servoGarrapin); 

  servoB.write(0); //limite min Base
  servoD.write(105); //limite min Avanço
  servoE.write(60); //limite min Altura
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
      delay(15);
    }
  } else {

    for (int i = atual; i >= anguloDestino; i--) {
      
      if (!sistemaLigado) return;

      servoB.write(i);
      delay(15);
    }
  }
}

void controlarGarra(int anguloDestino) {

  int atual = servoG.read();

  if (atual < anguloDestino) {

    for (int i = atual; i <= anguloDestino; i++) {
      servoG.write(i);
      delay(15);
    }
  } else {

    for (int i = atual; i >= anguloDestino; i--) {

      servoG.write(i);
      delay(15);
    }
  }
}

// Funções para Altura (E) e Avanço (D) seguindo o mesmo padrão suave
void controlarAltura(int anguloDestino) {

  int atual = servoE.read();

  if (atual < anguloDestino) {

    for (int e = atual; e <= anguloDestino; e++) {

      if (!sistemaLigado) return;
      servoE.write(e);
      delay(15);
    }
  } else {
    for (int e = atual; e >= anguloDestino; e--) {

      if (!sistemaLigado) return;
      servoE.write(e);
      delay(15);
    }
  }
}

void controlarAvanco(int anguloDestino) {

  int atual = servoD.read();

  if (atual < anguloDestino) {

    for (int d = atual; d <= anguloDestino; d++) {

      if (!sistemaLigado) return;
      servoD.write(d);
      delay(15);
    }
 } else {

    for (int d = atual; d >= anguloDestino; d--) {

      if (!sistemaLigado) return;

      servoD.write(d);
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
  
  moverBase(0);           // Vai no Estoque
  controlarAltura(170);   // Abaixa
  controlarAvanco(160);   // Avança
  controlarGarra(40);     // PEGA
  controlarAvanco(105);   // Recolhe
  controlarAltura(60);    // Sobe
  
  moverBase(45);          // Vai para o início da Esteira
  controlarAvanco(160);   // Avança
  bracoAtivo = false;     // Libera o sensor para parar a esteira e abrir funil
  controlarGarra(0);      // SOLTA na esteira
  controlarAvanco(105);   // Recolhe
  
  bracoAtivo = false;     // Libera a esteira para levar a caixa
  moverBase(90);          // Fica em posição de espera no meio

  // --- PARTE 2: ESPERAR CHEGAR NO SENSOR 2 ---
  Serial.println("Aguardando caixa chegar no Sensor 2...");

  while (sensor2Ativado == false) { // Enquanto NÃO chegar no sensor 2
    if (!sistemaLigado) return;

    delay(100); 
  }

  // --- PARTE 3: ESTEIRA (SENSOR 2) -> CAMINHÃO ---
  Serial.println("Caixa detectada no Sensor 2! Levando para o caminhão...");

  bracoAtivo = true;      // Para a esteira para o braço agir com segurança
  
  moverBase(135);         // Vai até o final da esteira (Sensor 2)
  controlarAvanco(160);   // Avança
  controlarGarra(40);     // PEGA a caixa da esteira
  controlarAvanco(105);   // Recolhe
  moverBase(180);          // Gira até o Caminhão
  controlarAltura(170);   // desce
       
  controlarAvanco(160);   // Avança
  controlarGarra(0);      // SOLTA no caminhão
  controlarAvanco(105);   // Recolhe
  controlarAltura(60);    // Sobe
  
  bracoAtivo = false;     // Ciclo finalizado
  moverBase(0);           // Volta para o início para a próxima caixa
  Serial.println("Ciclo completo concluído!");
}
