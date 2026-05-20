#include <ESP32Servo.h>

Servo servo1;

const int pinoServo = 13;     // sinal do servo
const int pinoPot = 35;       // pino analógico do potenciômetro

void setup() {

  Serial.begin(115200);

  servo1.attach(pinoServo, 500, 2500); 
  // 500 a 2500 us é uma faixa comum para servos

  Serial.println("Teste de servo com potenciometro");
}

void loop() {

  int leituraPot = analogRead(pinoPot);      // ESP32 lê de 0 a 4095
  int angulo = map(leituraPot, 0, 4095, 0, 180);

  servo1.write(angulo);

  Serial.print("Potenciometro: ");
  Serial.print(leituraPot);
  Serial.print(" | Angulo: ");
  Serial.println(angulo);

  delay(20);
}