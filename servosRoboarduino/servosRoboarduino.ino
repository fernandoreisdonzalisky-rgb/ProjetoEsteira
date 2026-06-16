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

const int pinoPot = A1;        // Pino Analógico do Arduino
int incremento = 1;    
int velocidadeServo = 15;       

int posBase= 90;
int posDireita = 90;
int posEsquerda = 90;
int posGarra = 90;

void setup() {
  Serial.begin(9600); // Inicializa a comunicação serial obrigatória para o monitor
  iniciaServos();
  iniciacontrole();
  
}

void loop() {
  testaServos();
 controle();   
  
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
  posBase= map(leituraPot, 0, 1023, 0, 180);
  posDireita = map(leituraPot, 0, 1023, 105, 180);
  posEsquerda = map(leituraPot, 0, 1023, 60, 180);
  posGarra = map(leituraPot, 0, 1023, 0, 40);

  servoB.write(posBase);
  servoD.write(posDireita);
  servoE.write(posEsquerda);
  servoG.write(posGarra);

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

  delay(20);

}
