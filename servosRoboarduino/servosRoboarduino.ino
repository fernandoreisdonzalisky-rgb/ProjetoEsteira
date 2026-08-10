#include <Servo.h>

// Cria os objetos Servo
Servo servoB;
Servo servoD;
Servo servoE;
Servo servoG;

// Define os pinos para cada servo
const int pinoServoBase = 10;
const int pinoServoDireita = 12;
const int pinoServoEsquerda = 4;
const int pinoServoGarra = 13;

const int pinoPot = A1; // Pino Analógico do Arduino para o potenciômetro

// Posições atuais e incremento para cada servo
int posBase = 90;
int posDireita = 90;
int posEsquerda = 90;
int posGarra = 90;
int incremento = 5; // Incremento/decremento do ângulo ao pressionar tecla
int velocidadeServo = 15; // Atraso em ms entre cada grau para movimento suave (maior = mais lento)

// Variáveis de controle de modo
// 0 = Modo Potenciômetro
// 1 = Modo Teclado
int controlMode = 0; 
bool printPotValues = false; // Flag para controlar a impressão dos valores do potenciômetro

// Função para mover o servo suavemente
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

// Função para inicializar os servos
void iniciaServos() {
  servoB.attach(pinoServoBase);
  servoD.attach(pinoServoDireita);
  servoE.attach(pinoServoEsquerda);
  servoG.attach(pinoServoGarra);

  servoB.write(posBase);
  servoD.write(posDireita);
  servoE.write(posEsquerda);
  servoG.write(posGarra);
}

void setup() {
  Serial.begin(9600); // Inicia a comunicação serial a 9600 bps (apenas uma vez)
  iniciaServos(); // Inicializa os servos

  Serial.println("-----------------------------------");
  Serial.println("Controle de 4 Servos: Potenciômetro ou Teclado");
  Serial.println("-----------------------------------");
  Serial.println("Comandos Gerais:");
  Serial.println("  \"m\": Alternar modo (0=Potenciômetro, 1=Teclado)");
  Serial.println("  \"p\": Ligar/Desligar impressão de valores do Potenciômetro");
  Serial.println("-----------------------------------");
  Serial.println("Modo Atual: Potenciômetro (0)");
  Serial.println("-----------------------------------");
}

void loop() {
  // Verifica se há dados disponíveis na serial para comandos gerais ou de teclado
  if (Serial.available() > 0) {
    char comando = Serial.read(); // Lê o caractere recebido

    // Ignora quebras de linha e retornos de carro para evitar processamento indesejado
    if (comando == '\n' || comando == '\r') {
      return; 
    }

    // Comandos de controle de modo
    if (comando == 'm') {
      controlMode = 1 - controlMode; // Alterna entre 0 e 1
      Serial.print("Modo alterado para: ");
      if (controlMode == 0) {
        Serial.println("Potenciômetro (0)");
      } else {
        Serial.println("Teclado (1)");
        Serial.println("  Base: 'q' (aumenta), 'a' (diminui)");
        Serial.println("  Direita: 'w' (aumenta), 's' (diminui)");
        Serial.println("  Esquerda: 'e' (aumenta), 'd' (diminui)");
        Serial.println("  Garra: 'r' (aumenta), 'f' (diminui)");
      }
      return; // Já processou o comando de modo, sai para evitar processar como comando de servo
    } else if (comando == 'p') {
      printPotValues = !printPotValues; // Alterna a flag
      Serial.print("Impressão de valores do Potenciômetro: ");
      Serial.println(printPotValues ? "LIGADA" : "DESLIGADA");
      return; // Já processou o comando, sai
    }

    // Se estiver no modo teclado, processa os comandos de servo
    if (controlMode == 1) {
      handleKeyboardControl(comando);
    } else {
      Serial.println("Comando de teclado ignorado no Modo Potenciômetro. Pressione 'm' para alternar.");
    }
  }

  // Se estiver no modo potenciômetro, lê e controla os servos
  if (controlMode == 0) {
    handlePotentiometerControl();
  }

  delay(10); // Pequeno atraso para estabilidade geral do loop
}

void handlePotentiometerControl() {
  int leituraPot = analogRead(pinoPot);

  // Mapeia a leitura do potenciômetro (0-1023) para o ângulo do servo (0-180)
  int targetPosBase = map(leituraPot, 0, 1023, 0, 180);
  int targetPosDireita = map(leituraPot, 0, 1023, 0, 180);
  int targetPosEsquerda = map(leituraPot, 0, 1023, 0, 180);
  int targetPosGarra = map(leituraPot, 0, 1023, 0, 110);

  // Move os servos suavemente para as novas posições
  moveServoSmoothly(servoB, targetPosBase, posBase, velocidadeServo);
  moveServoSmoothly(servoD, targetPosDireita, posDireita, velocidadeServo);
  moveServoSmoothly(servoE, targetPosEsquerda, posEsquerda, velocidadeServo);
  moveServoSmoothly(servoG, targetPosGarra, posGarra, velocidadeServo);

  if (printPotValues) {
    Serial.print("Pot: ");
    Serial.print(leituraPot);
    Serial.print(" | Base: ");
    Serial.print(posBase);
    Serial.print(" | Direita: ");
    Serial.print(posDireita);
    Serial.print(" | Esquerda: ");
    Serial.print(posEsquerda);
    Serial.print(" | Garra: ");
    Serial.println(posGarra);
  }
}

void handleKeyboardControl(char comando) {
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

    // --- Controle do Servo da Garra ---
    case 'r':
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

    default:
      Serial.println("Comando inválido. Verifique a lista de comandos.");
      break;
  }
}
