// ===== BRAÇO ROBÓTICO =====

Servo servoBase;
Servo servoDireita;
Servo servoEsquerda;
Servo servoPulso;
Servo servoGarra;
Servo servoArtgarra;

int pinoBase = 25;
int pinoDireita = 26;
int pinoEsquerda = 27;
int pinoPulso = 14;
int pinoGarra = 12; 
int pinoArtgarra = 33;

void iniciaBraco() {
  servoBase.attach(pinoBase ); //500 = 0 graus
  servoDireita.attach(pinoDireita ); //2400 = 180 graus
  servoEsquerda.attach(pinoEsquerda );
  servoPulso.attach(pinoPulso );
  servoGarra.attach(pinoGarra );
  servoArtgarra.attach(pinoArtgarra );

  Serial.println("Braco iniciado");
}

void verificaBotaodesliga() {
  if (sistemaLigado == false) {
    desligaBraco();
    return;
  }
}

void ligaBraco(int espera) {
  delay(espera);

  bracoAtivo = true;

  Serial.println("Braço Ativado");

  // Aqui depois você coloca os movimentos do braço
}

void desligaBraco() {
  bracoAtivo = false;

  Serial.println("Braco DESATIVADO");

  // colocar os comandos
}