#include <Servo.h>

Servo Fservo;

int servoPin = 13;

void iniciaServo() {

  Fservo.attach(servoPin);

  Fservo.write(0);
}

void abrirFunil() {

  Fservo.write(90);

  delay(5000);

  Fservo.write(0);
}