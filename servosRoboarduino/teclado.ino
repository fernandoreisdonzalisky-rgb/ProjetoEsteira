
void moveServoSmoothly(Servo& servo, int targetPos, int& currentPos, int delayTime) {
  if (targetPos > currentPos) {
    for (int i = currentPos; i <= targetPos; i++) {
      servo.write(i);
      delay(delayTime);
    }
  } else if (targetPos < currentPos) {
    for (int i = currentPos; i >= targetPos; i--) {
      servo.write(i);
      delay(delayTime);
    }
  }
  currentPos = targetPos; // Atualiza a posição atual para a alvo
}


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

    int novaPosicao;

    switch (comando) {
      // --- Controle do Servo da Base ---
      case 'q':
        novaPosicao = posBase + incremento;
        if (novaPosicao > 180) novaPosicao = 180;
        moveServoSmoothly(servoB, novaPosicao, posBase, velocidadeServo);
        Serial.println("Base: " + String(posBase));
        break;
      case 'a':
        novaPosicao = posBase - incremento;
        if (novaPosicao < 0) novaPosicao = 0;
        moveServoSmoothly(servoB, novaPosicao, posBase, velocidadeServo);
        Serial.println("Base: " + String(posBase));
        break;

      // --- Controle do Servo da Direita ---
      case 'w':
        novaPosicao = posDireita + incremento;
        if (novaPosicao > 180) novaPosicao = 180;
        moveServoSmoothly(servoD, novaPosicao, posDireita, velocidadeServo);
        Serial.println("Direita: " + String(posDireita));
        break;
      case 's':
        novaPosicao = posDireita - incremento;
        if (novaPosicao < 0) novaPosicao = 0;
        moveServoSmoothly(servoD, novaPosicao, posDireita, velocidadeServo);
        Serial.println("Direita: " + String(posDireita));
        break;

      // --- Controle do Servo da Esquerda ---
      case 'e':
        novaPosicao = posEsquerda + incremento;
        if (novaPosicao > 180) novaPosicao = 180;
        moveServoSmoothly(servoE, novaPosicao, posEsquerda, velocidadeServo);
        Serial.println("Esquerda: " + String(posEsquerda));
        break;
      case 'd':
        novaPosicao = posEsquerda - incremento;
        if (novaPosicao < 0) novaPosicao = 0;
        moveServoSmoothly(servoE, novaPosicao, posEsquerda, velocidadeServo);
        Serial.println("Esquerda: " + String(posEsquerda));
        break;

      // --- Controle do Servo da Garra ---\n      case 'r':
        novaPosicao = posGarra + incremento;
        if (novaPosicao > 180) novaPosicao = 180;
        moveServoSmoothly(servoG, novaPosicao, posGarra, velocidadeServo);
        Serial.println("Garra: " + String(posGarra));
        break;
      case 'f':
        novaPosicao = posGarra - incremento;
        if (novaPosicao < 0) novaPosicao = 0;
        moveServoSmoothly(servoG, novaPosicao, posGarra, velocidadeServo);
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
 }