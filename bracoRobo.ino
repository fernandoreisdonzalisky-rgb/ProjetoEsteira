  
int servoBasepin = 12;
int servoDireitapin = 11;
int servoEsquerdapin = 10;
int servoGarrapin = 9;

int rapidez = 20;

void iniciaRobo() {

  servoB.attach(servoBasepin);
  servoD.attach(servoDireitapin); 
  servoE.attach(servoEsquerdapin);
  servoG.attach(servoGarrapin); 

  servoB.write(90); //meio da base
  servoD.write(90); //ângulo mais alto da altura
  servoE.write(130); //ângulo min do avanço
  servoG.write(90); //limite min Garra
}

void retornaBraco() {

  bracoAtivo = true;

  moverBase(0);
  controlarDireitaEsquerda(120);
  controlarGarra(90);

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

void controlarDireitaEsquerda(int anguloDestino) {

  int atualD = servoD.read();
  int atualE = servoE.read();

 
  while (atualD != anguloDestino || atualE != anguloDestino) {

    if (!sistemaLigado && !retornoEmergencia) return;

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

    delay(rapidez);
  }
}
// --- FUNÇÕES DE AÇÃO COMPOSTA (Tarefas) ---

void executarCicloRobo() {

  if (sistemaLigado == false && !retornoEmergencia) return;

  // --- PARTE 1: ESTOQUE -> ESTEIRA ---
  Serial.println("Iniciando: Estoque para Esteira");
  bracoAtivo = true;
  
  moverBase(180);  // Vai no Estoque        
  controlarDireitaEsquerda(180); //avança
  controlarGarra(0);     // PEGA
  controlarGarra(90);  
  controlarDireitaEsquerda(120);//recolhe
  
  moverBase(135);         // Vai para o início da Esteira
  controlarEsquerda(180);
  controlarDireitaEsquerda(160);
  controlarEsquerda(180);
  desligarEsteira();
  controlarGarra(0);      // SOLTA na esteira
  bracoAtivo = false;     // Libera o sensor para parar a esteira e abrir funil
  verificarSensor1(); //verificação do sensor 1 para a ação do funil
  controlarDireitaEsquerda(120);
  controlarGarra(90);
  
  bracoAtivo = false;     // Libera a esteira para levar a caixa
  moverBase(90);          // Fica em posição de espera no meio


  // --- PARTE 2: ESPERAR CHEGAR NO SENSOR 2 ---

  if (funilAberto == true) {
  Serial.println("Aguardando caixa chegar no Sensor 2...");
  }
  while (sensor2Ativado == false) {

    //Serial.print("sistemaLigado=");
    //Serial.println(sistemaLigado);

    if (!sistemaLigado && !retornoEmergencia) return;

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
