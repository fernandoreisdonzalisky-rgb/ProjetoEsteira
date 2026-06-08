#include <Servo.h> // Biblioteca padrão para Arduino

Servo servoB;
Servo servoD;
Servo servoE;
Servo servoG;

// Pinos adaptados para o Arduino Uno (Servos em pinos PWM, Potenciômetro em pino Analógico)
const int pinoServoBase = 3;     // Pino PWM
const int pinoServoDireita = 5;  // Pino PWM
const int pinoServoEsquerda = 6; // Pino PWM
const int pinoServoGarra = 9;    // Pino PWM

const int pinoPot = A0;          // Pino Analógico do Arduino

int anguloBase = 0;
int anguloDireita = 0;
int anguloEsquerda = 0;
int anguloGarra = 0;

void setup() {
  Serial.begin(9600); // Inicializa a comunicação serial obrigatória para o monitor
  iniciaServos();
}

void loop() {
  testaServos();
}

void iniciaServos() {
  // O Arduino gerencia os pulsos de 500 a 2500us automaticamente, 
  // mas você pode mantê-los se seus servos específicos exigirem essa calibração.
  servoB.attach(pinoServoBase, 500, 2500);
  servoD.attach(pinoServoDireita, 500, 2500);
  servoE.attach(pinoServoEsquerda, 500, 2500);
  servoG.attach(pinoServoGarra, 500, 2500);

  Serial.println("Teste de servos com potenciometro no Arduino");
}

void testaServos() {
  int leituraPot = analogRead(pinoPot);

  // Ajustado de 4095 (ESP32) para 1023 (Arduino)
  anguloBase = map(leituraPot, 0, 1023, 0, 180);
  anguloDireita = map(leituraPot, 0, 1023, 0, 180);
  anguloEsquerda = map(leituraPot, 0, 1023, 0, 180);
  anguloGarra = map(leituraPot, 0, 1023, 0, 180);

  servoB.write(anguloBase);
  servoD.write(anguloDireita);
  servoE.write(anguloEsquerda);
  servoG.write(anguloGarra);

  Serial.print("Pot: ");
  Serial.print(leituraPot);

  Serial.print(" | Base: ");
  Serial.print(anguloBase);

  Serial.print(" | Direita: ");
  Serial.print(anguloDireita);

  Serial.print(" | Esquerda: ");
  Serial.print(anguloEsquerda);

  Serial.print(" | Garra: ");
  Serial.println(anguloGarra);

  delay(20);




}
