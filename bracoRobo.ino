 
int servoBasepin = 10;

int servoDireitapin = 11;

int servoEsquerdapin = 12;

int servoGarrapin = 13;

void iniciaRobo() {

  servoB.attach(servoBasepin);

  servoD.attach(servoDireitapin); 

  servoE.attach(servoEsquerdapin);

  servoG.attach(servoGarrapin); 

  servoB.write(0);
  
  servoD.write(0);

  servoE.write(0);

  servoG.write(0);
}


void ligaRobo() {
  
  if (sistemaLigado == false) {
    Serial.println("Braço Desativado");
    return;
  }
  
  base(3000);
}

void base(int espera) {

  for (int primeiroAngulobase = 0; primeiroAngulobase <= 180; primeiroAngulobase++) {

    if (sistemaLigado == false) {
      Serial.println("Base parada");
      return;
    }

    servoB.write(primeiroAngulobase);
    delay(15);

    if (primeiroAngulobase == 65) {

      delay(espera);

      for (int segundoAnguloBase = 65; segundoAnguloBase <= 165; segundoAnguloBase++) {

        if (sistemaLigado == false) {
          Serial.println("Base parada");
          return;
        }

        servoB.write(segundoAnguloBase);
        delay(15);
      }
        
        delay(espera);

      for (int voltaBase = 165; voltaBase >= 0; voltaBase--) {

        if (sistemaLigado == false) {
          Serial.println("Base parada");
          return;
        }

        servoB.write(voltaBase);
        delay(15);
      }

      break;
    }
  }
}