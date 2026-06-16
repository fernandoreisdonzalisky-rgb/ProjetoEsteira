
void iniciacontrole(){
  Serial.begin(9600); // Inicia a comunicação serial a 9600 bps

  // Anexa os servos aos seus respectivos pinos
  servoB.attach(pinoServoBase);
  servoD.attach(pinoServoDireita);
  servoE.attach(pinoServoEsquerda);
  servoG.attach(pinoServoGarra);

  // Define as posições iniciais dos servos
  servoB.write(posBase);
  servoD.write(posDireita);
  servoE.write(posEsquerda);
  servoG.write(posGarra);

  Serial.println("Controle de 4 Servos via Serial");
  Serial.println("Comandos:");
  Serial.println("  Base: 'q' (aumenta), 'a' (diminui)");
  Serial.println("  Direita: 'w' (aumenta), 's' (diminui)");
  Serial.println("  Esquerda: 'e' (aumenta), 'd' (diminui)");
  Serial.println("  Garra: 'r' (aumenta), 'f' (diminui)");
  Serial.println("-----------------------------------");
  Serial.println("Posições Iniciais:");
  Serial.println("  Base: " + String(posBase));
  Serial.println("  Direita: " + String(posDireita));
  Serial.println("  Esquerda: " + String(posEsquerda));
  Serial.println("  Garra: " + String(posGarra));
  }

    void controle(){

  if (Serial.available() > 0) { // Verifica se há dados disponíveis na serial
    char comando = Serial.read(); // Lê o caractere recebido

    switch (comando) {
      // --- Controle do Servo da Base ---
      case 'q':
        posBase += incremento;
        if (posBase > 180) posBase = 180;
        servoB.write(posBase);
        Serial.println("Base: " + String(posBase));
        break;
      case 'a':
        posBase -= incremento;
        if (posBase < 0) posBase = 0;
        servoB.write(posBase);
        Serial.println("Base: " + String(posBase));
        break;

      // --- Controle do Servo da Direita ---
      case 'w':
        posDireita += incremento;
        if (posDireita > 180) posDireita = 180;
        servoD.write(posDireita);
        Serial.println("Direita: " + String(posDireita));
        break;
      case 's':
        posDireita -= incremento;
        if (posDireita < 0) posDireita = 0;
        servoD.write(posDireita);
        Serial.println("Direita: " + String(posDireita));
        break;

      // --- Controle do Servo da Esquerda ---
      case 'e':
        posEsquerda += incremento;
        if (posEsquerda > 180) posEsquerda = 180;
        servoE.write(posEsquerda);
        Serial.println("Esquerda: " + String(posEsquerda));
        break;
      case 'd':
        posEsquerda -= incremento;
        if (posEsquerda < 0) posEsquerda = 0;
        servoE.write(posEsquerda);
        Serial.println("Esquerda: " + String(posEsquerda));
        break;

      // --- Controle do Servo da Garra ---
      case 'r':
        posGarra += incremento;
        if (posGarra > 180) posGarra = 180;
        servoG.write(posGarra);
        Serial.println("Garra: " + String(posGarra));
        break;
      case 'f':
        posGarra -= incremento;
        if (posGarra < 0) posGarra = 0;
        servoG.write(posGarra);
        Serial.println("Garra: " + String(posGarra));
        break;

      case '\n': // Ignora quebras de linha
      case '\r': // Ignora retornos de carro
        break;

      default:
        Serial.println("Comando inválido. Verifique a lista de comandos.");
        break;
    }
  }
  delay(10); // Pequeno atraso para estabilidade
 }