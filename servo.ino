#include <Servo.h>

Servo Fservo;

int servoPin = 13;

void iniciaServo() {

  Fservo.attach(servoPin);

  Fservo.write(0);
}

void abrirFunil(int espera = 0) {

  Serial.print("Posicao atual servo: ");
  Serial.println(Fservo.read());

  if (Fservo.read() == 0) {

    Serial.println("Abrindo funil...");

    delay(espera);

    Fservo.write(90);

    delay(espera);

    Serial.print("Nova posicao servo: ");
    Serial.println(Fservo.read());
  }
}

void fecharFunil(int espera = 0) {

  Serial.print("Posicao atual servo: ");
  Serial.println(Fservo.read());

  if (Fservo.read() == 90) {

    Serial.println("Fechando funil...");

    Fservo.write(0);

    delay(espera);

    Serial.print("Nova posicao servo: ");
    Serial.println(Fservo.read());
  }
}

bool servoAtivo() {

  Serial.print("Verificando servo: ");
  Serial.println(Fservo.read());

  if (Fservo.read() == 90) {

    Serial.println("Servo ATIVO");

    return true;
  }

  Serial.println("Servo DESATIVADO");

  return false;
}