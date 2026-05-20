#include <Servo.h>

Servo Fservo;

int servoPin = 8;

//ESSTADO DO FUNIL

bool funilAberto = false;

void iniciaFunil() {

  Fservo.attach(servoPin);

  Fservo.write(0);
}

void abrirFunil(int espera = 0) {

  Serial.print("Posicao atual servo: ");
  Serial.println(Fservo.read());

  if (funilAberto == false) {

    Serial.println("Abrindo funil...");

    delay(espera);

    Fservo.write(90);

    Serial.print("Nova posicao servo: ");
    Serial.println(Fservo.read());

    funilAberto = true;

    delay(espera);
  }
}

void fecharFunil(int espera = 0) {

  Serial.print("Posicao atual servo: ");
  Serial.println(Fservo.read());

  if (funilAberto == true) {

    Serial.println("Fechando funil...");

    Fservo.write(0);

    Serial.print("Nova posicao servo: ");
    Serial.println(Fservo.read());

    funilAberto = false;

     delay(espera);
  }
}

bool funilAtivo() {

  Serial.print("Verificando funil: ");
  Serial.println(Fservo.read());

  if (funilAberto == true) {

    Serial.println("Funil ATIVO");

    return true;
  }

  if (funilAberto == false){

  Serial.println("Funil DESATIVADO");

  return false;
  }
 

}