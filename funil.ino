#include <Servo.h>

Servo Fservo;

int servoPin = 8;

void iniciaFunil() {

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

    Serial.print("Nova posicao servo: ");
    Serial.println(Fservo.read());

     delay(espera);
  }
}

bool funilAtivo() {

  Serial.print("Verificando funil: ");
  Serial.println(Fservo.read());

  if (Fservo.read() == 90) {

    Serial.println("Funil ATIVO");

    return true;
  }

  if (Fservo.read() == 0){

  Serial.println("Funil DESATIVADO");

  return false;
  }
 

}