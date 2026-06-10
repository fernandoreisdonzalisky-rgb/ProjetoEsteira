 
int servoBasepin = 10;
int servoDireitapin = 11;
int servoEsquerdapin = 12;
int servoGarrapin = 13;

void iniciaRobo() {

  servoB.attach(servoBasepin);
  servoD.attach(servoDireitapin); 
  servoE.attach(servoEsquerdapin);
  servoG.attach(servoGarrapin); 

  servoB.write(0); //limite min base
  servoD.write(105); //limite min avanço
  servoE.write(60); //limite min altura
  servoG.write(0); //limite min garra
}

void ligaRobo() {
  
  if (sistemaLigado == false) {
    Serial.println("Braço Desativado");
    return;
  }
  
  base(2000);
}

void base(int espera) {

  // Vai de 0 até 65
  for (int primeiroAnguloBase = 0; primeiroAnguloBase <= 45; primeiroAnguloBase++) {

    if (sistemaLigado == false) {
      Serial.println("Base interrompida"); 
      return;
    }

    servoB.write(primeiroAnguloBase);
    delay(15);

    Serial.println("robo indo...");
  }

  delay(espera); // espera em 65 graus

  // Vai de 65 até 90
  for (int segundoAnguloBase = 45; segundoAnguloBase <= 90; segundoAnguloBase++) {

    if (sistemaLigado == false) {
      Serial.println("Base interrompida");
      return;
    }

    servoB.write(segundoAnguloBase);
    delay(15);

    
  }
  Serial.println("robo parado");
  
  delay(5000); // fica parado em 90 graus por 5 segundos


  if (sensor2Ativado == true) { //condição para o robo ir até a caixa

  // Vai de 90 até 165
  for (int terceiroAnguloBase = 90; terceiroAnguloBase <= 135; terceiroAnguloBase++) {

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

  // vai de 165 até 180
  for (int quartoAngulobase = 135; quartoAngulobase >= 180; quartoAngulobase++) {

    if (sistemaLigado == false) {
      Serial.println("Base interrompida");
      return;
    }

    servoB.write(quartoAngulobase);
    delay(15);

    Serial.println("robo indo...");
  }

  // vai de 180 até 0
  for (int voltaBase = 180; voltaBase >= 0; voltaBase--) {

    if (sistemaLigado == false) {
      Serial.println("Base interrompida");
      return;
    }

    servoB.write(voltaBase);
    delay(15);

    Serial.println("robo voltando...");
  }
}