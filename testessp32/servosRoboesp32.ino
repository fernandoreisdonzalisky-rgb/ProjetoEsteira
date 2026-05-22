#include <ESP32Servo.h>

Servo servoB;
Servo servoD;
Servo servoE;
Servo servoG;

const int pinoServoBase = 33;
const int pinoServoDireita = 25;
const int pinoServoEsquerda = 32;
const int pinoServoGarra = 26;

const int pinoPot = 34;

int anguloBase = 0;
int anguloDireita = 0;
int anguloEsquerda = 0;
int anguloGarra = 0;

void iniciaServos_esp() {
  servoB.attach(pinoServoBase, 500, 2500);
  servoD.attach(pinoServoDireita, 500, 2500);
  servoE.attach(pinoServoEsquerda, 500, 2500);
  servoG.attach(pinoServoGarra, 500, 2500);

  Serial.println("Teste de servos com potenciometro");
}

void testaServos_esp() {
  int leituraPot = analogRead(pinoPot);

  anguloBase = map(leituraPot, 0, 4095, 0, 180);
  anguloDireita = map(leituraPot, 0, 4095, 0, 180);
  anguloEsquerda = map(leituraPot, 0, 4095, 0, 180);
  anguloGarra = map(leituraPot, 0, 4095, 0, 180);

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
