#include <Servo.h>

Servo servoB;
Servo servoD;
Servo servoE;
Servo servoG;

const int pinoServoBase = 3;
const int pinoServoDireita = 5;
const int pinoServoEsquerda = 6;
const int pinoServoGarra = 9;

const int pinoPot = A0;

int anguloBase = 0;
int anguloDireita = 0;
int anguloEsquerda = 0;
int anguloGarra = 0;

void iniciaServos_ard() {

  servoB.attach(pinoServoBase);
  servoD.attach(pinoServoDireita);
  servoE.attach(pinoServoEsquerda);
  servoG.attach(pinoServoGarra);

  Serial.println("Teste de servos com potenciometro");
}

void testaServos_ard() {

  int leituraPot = analogRead(pinoPot);

  // Arduino UNO usa 0 a 1023
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
