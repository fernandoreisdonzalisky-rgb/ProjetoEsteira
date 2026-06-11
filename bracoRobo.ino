  
  int servoBasepin = 10;
  int servoDireitapin = 11;
  int servoEsquerdapin = 12;
  int servoGarrapin = 13;

void iniciaRobo() {

    servoB.attach(servoBasepin);
    servoD.attach(servoDireitapin); 
    servoE.attach(servoEsquerdapin);
    servoG.attach(servoGarrapin); 

    servoB.write(0); //limite min Base (0 - estoque ; 45 esteira ; 90 parado ; 135 esteira; 180 caminhão)
    servoD.write(105); //limite min Avanço (105 - recolhido ; 160 avançado)
    servoE.write(60); //limite min Altura (60 -baixo ; 170 -alto )
    servoG.write(0); //limite min Garra (0 - aberto ; 40 - fechado)
  }

void ligaRobo() {
    
    if (sistemaLigado == false) {
      Serial.println("Braço Desativado");
      return;
    }
    
    base(2000);
    avanca();
    garra();
  }

void base(int espera) {

  // Vai de 0 até 65

  if (servoG.read() == 40) {

    for (int primeiroAnguloBase = 0; primeiroAnguloBase <= 45; primeiroAnguloBase++) { //robo vai até a esteira

      if (sistemaLigado == false) {
       Serial.println("Base interrompida"); 
       return;
      }

     servoB.write(primeiroAnguloBase);
     delay(15);

     Serial.println("robo indo...");

     bracoAtivo = true;

    }
  }

 delay(espera); // espera em 65 graus

    // Vai de 65 até 90

  if (servoG.read() == 0){

    for (int segundoAnguloBase = 45; segundoAnguloBase <= 90; segundoAnguloBase++) { //robo espera o sensor 2 ATIVAR

      if (sistemaLigado == false) {
       Serial.println("Base interrompida");
       return;
      }

     servoB.write(segundoAnguloBase);
     delay(15);

      
    }
    
    Serial.println("robo parado");
  }

  if (sensor2Ativado == true) { //condição para o robo ir até a esteira para pegar a caixa

    // Vai de 90 até 165
   for (int terceiroAnguloBase = 90; terceiroAnguloBase <= 135; terceiroAnguloBase++) { //robo vai até o estoque

      if (sistemaLigado == false) {
       Serial.println("Base interrompida");
       return;
      }

     servoB.write(terceiroAnguloBase);
     delay(15);

     Serial.print("robo indo...");
    }
  }

  delay(espera); // espera em 165 graus

  // vai de 135 até 180

  if(servoG.read() == 40) {

    for (int quartoAnguloBase = 135; quartoAnguloBase >= 180; quartoAnguloBase++) { //robo vai até o caminhão

      if (sistemaLigado == false) {
       Serial.println("Base interrompida");
       return;
      }

     servoB.write(quartoAnguloBase);
     delay(15);

     Serial.println("robo indo...");

     bracoAtivo = true;
    }
  }

  // vai de 180 até 0

  if (servoG.read() == 0){

    for (int voltaBase = 180; voltaBase >= 0; voltaBase--) { //robo volta para o estoque

      if (sistemaLigado == false) {
        Serial.println("Base interrompida");
        return;
      }

     servoB.write(voltaBase);
     delay(15);

     Serial.println("robo voltando...");

     bracoAtivo = true;
    }
  } 
}


  

void altura() {

  if (servoB.read() == 45) {

    for (int segundoAnguloAltura = 170; segundoAnguloAltura <= 60; segundoAnguloAltura++) { //robo sobe para a esteira

      if (sistemaLigado == false) {
        Serial.println("Base interrompida");
        return;
      }

      servoE.write(segundoAnguloAltura);
      delay(15);

      Serial.println("Robo levantando....");
    }
  }
} 

void avanca() {

  if( servoG.read() == 0 || servoE.read() == 60) { //robo avanca para a esteira

    for (int primeiroAnguloAvanca = 105; primeiroAnguloAvanca <= 160; primeiroAnguloAvanca++) {

     if (sistemaLigado == false) {
        Serial.println("Base interrompida");
        return;
      }

      servoD.write(primeiroAnguloAvanca);
      delay(15);

      Serial.println("Garra avançando....");
    }
  }


  if (servoG.read() == 0) {
    
    for (int primeiroAnguloRetorna = 0; primeiroAnguloRetorna <= 105; primeiroAnguloRetorna++) { //braço retorna garra

      if (sistemaLigado == false) {
       Serial.println("Base interrompida");
        return;
     }

      servoD.write(primeiroAnguloRetorna);
      delay(15);

      Serial.println("Garra retornando....");
    }
  }
}

void garra() {

  if ( servoE.read() == 170 || servoB.read() == 0) { //pegar a caixa do estoque

    for (int primeiroAnguloGarra = 0; primeiroAnguloGarra <= 40; primeiroAnguloGarra++) {

      if (sistemaLigado == false) {
        Serial.println("Base interrompida");
        return;
     }
 
     servoG.write(primeiroAnguloGarra);
     delay(15);
      
     Serial.println("Garra pegando....");
   }

    bracoAtivo = false;
 }

  if ( servoE.read() == 60 || servoB.read() == 45) {

    for (int primeiroAnguloGarra = 40; primeiroAnguloGarra <= 0; primeiroAnguloGarra++) { //soltar a caixa na esteira

      if (sistemaLigado == false) {
        Serial.println("Base interrompida");
        return;
      }

      servoG.write(primeiroAnguloGarra);
      delay(15);
      
      Serial.println("Garra soltando....");
   }
   bracoAtivo = false;
  }
}

