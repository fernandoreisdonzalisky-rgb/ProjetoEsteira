  
int servoBasepin = A3;
int servoDireitapin = A1;
int servoEsquerdapin = A2;
int servoGarrapin = A0;

void iniciaRobo() {

  servoB.attach(servoBasepin);
  servoD.attach(servoDireitapin); 
  servoE.attach(servoEsquerdapin);
  servoG.attach(servoGarrapin); 

  servoB.write(90); //meio da base
  servoD.write(120); //ângulo mais alto da altura
  servoE.write(110); //ângulo min do avanço
  servoG.write(0); //limite min Garra
}

void retornaBraco() {

  bracoAtivo = true;

  moverBase(180);
  controlarEsquerda(90);
  controlarDireita(105);
  controlarGarra(0);

  bracoAtivo = false;

  sistemaLigado = false;

  Serial.println("Braco no SETUP.");
  Serial.println("Sistema DESLIGADO.");
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

void controlarDireitaEsquerda(int anguloDestino) {

  int atualD = servoD.read();
  int atualE = servoE.read();

 
  while (atualD != anguloDestino || atualE != anguloDestino) {

    if (!sistemaLigado) return;

    // Servo direita
    if (atualD < anguloDestino) {
      atualD++;
    } 
    else if (atualD > anguloDestino) {
      atualD--;
    }

    // Servo esquerda
    if (atualE < anguloDestino) {
      atualE++;
    } 
    else if (atualE > anguloDestino) {
      atualE--;
    }

    servoD.write(atualD);
    servoE.write(atualE);

    atualizarSistema();

    delay(15);
  }
}
// --- FUNÇÕES DE AÇÃO COMPOSTA (Tarefas) ---

void executarCicloRobo() {

  if (sistemaLigado == false) return;

  // --- PARTE 1: ESTOQUE -> ESTEIRA ---
  Serial.println("Iniciando: Estoque para Esteira");
  bracoAtivo = true;
  
  moverBase(180);  // Vai no Estoque        
  controlarEsquerda(160);   // Avança
  controlarDireita(180);
  controlarEsquerda(120);
  controlarGarra(90);     // PEGA
  controlarDireita(90);    // Sobe
  controlarEsquerda(100); //recolhe
  
  moverBase(135);         // Vai para o início da Esteira
  controlarEsquerda(160); 
  controlarEsquerda(180); 
  controlarDireita(120); 
  desligarEsteira();
  controlarGarra(0);      // SOLTA na esteira
  bracoAtivo = false;     // Libera o sensor para parar a esteira e abrir funil
  controlarDireita(120);
  controlarGarra(90);
  controlarEsquerda(90);   // Recolhe

  verificarSensor1(); //verificação do sensor 1 para a ação do funil
  
  bracoAtivo = false;     // Libera a esteira para levar a caixa
  moverBase(90);          // Fica em posição de espera no meio


  // --- PARTE 2: ESPERAR CHEGAR NO SENSOR 2 ---

  if (funilAberto == true) {
  Serial.println("Aguardando caixa chegar no Sensor 2...");
  }
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
