#include <ESP32Servo.h>

// Cria os objetos Servo
Servo servoB;
Servo servoD;
Servo servoE;
Servo servoG;

// Pinos de cada servo
const int pinoServoBase = 5;      // verde
const int pinoServoDireita = 15;   // azul
const int pinoServoEsquerda = 16;  // amarelo
const int pinoServoGarra = 4;     // roxo

// Posicoes atuais
int posBase = 90;
int posDireita = 90;
int posEsquerda = 90;
int posGarra = 90;

int incremento = 5;         // quanto o servo anda por tecla
int velocidadeServo = 15;  // ms por grau (maior = mais lento)


// ===== PROTOTIPOS =====
void moveServoSmoothly(Servo &servo, int targetPos, int &currentPos, int delayTime);
void iniciaServos();
void handleKeyboardControl(char comando);
void limitaEIncrementa(Servo &servo, int &posicao, int passo, const char *nome);


// ===== SETUP =====
void setup() {

  Serial.begin(115200);

  iniciaServos();

  Serial.println("-----------------------------------");
  Serial.println("Controle de 4 Servos - ESP32 (teclado)");
  Serial.println("-----------------------------------");
  Serial.println("  Base:     'a' aumenta | 'd' diminui");
  Serial.println("  Direita:  'w' aumenta | 's' diminui");
  Serial.println("  Esquerda: 'q' aumenta | 'e' diminui");
  Serial.println("  Garra:    'r' aumenta | 'f' diminui");
  Serial.println("-----------------------------------");
}


// ===== LOOP =====
void loop() {

  if (Serial.available() > 0) {

    char comando = Serial.read();

    // ignora quebra de linha / retorno de carro
    if (comando == '\n' || comando == '\r' || comando == ' ') {
      return;
    }

    handleKeyboardControl(comando);
  }
}


// ===== FUNCOES =====

// Move o servo de 1 em 1 grau ate a posicao alvo
void moveServoSmoothly(Servo &servo, int targetPos, int &currentPos, int delayTime) {

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

  currentPos = targetPos;
}

// Inicializa os servos na posicao do meio
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

// Soma ou subtrai o passo, sem passar de 0 nem de 180, e mostra no serial
void limitaEIncrementa(Servo &servo, int &posicao, int passo, const char *nome) {

  int novaPosicao = posicao + passo;

  if (novaPosicao > 180) novaPosicao = 180;
  if (novaPosicao < 0)   novaPosicao = 0;

  moveServoSmoothly(servo, novaPosicao, posicao, velocidadeServo);

  Serial.print(nome);
  Serial.print(": ");
  Serial.println(posicao);
}

void handleKeyboardControl(char comando) {

  switch (comando) {

    // --- Base ---
    case 'a': limitaEIncrementa(servoB, posBase,     +incremento, "Base");     break;
    case 'd': limitaEIncrementa(servoB, posBase,     -incremento, "Base");     break;

    // --- Direita ---
    case 'w': limitaEIncrementa(servoD, posDireita,  +incremento, "Direita");  break;
    case 's': limitaEIncrementa(servoD, posDireita,  -incremento, "Direita");  break;

    // --- Esquerda ---
    case 'q': limitaEIncrementa(servoE, posEsquerda, +incremento, "Esquerda"); break;
    case 'e': limitaEIncrementa(servoE, posEsquerda, -incremento, "Esquerda"); break;

    // --- Garra ---
    case 'r': limitaEIncrementa(servoG, posGarra,    +incremento, "Garra");    break;
    case 'f': limitaEIncrementa(servoG, posGarra,    -incremento, "Garra");    break;

    default:
      Serial.println("Comando invalido. Use: a d w s q e r f");
      break;
  }
}
