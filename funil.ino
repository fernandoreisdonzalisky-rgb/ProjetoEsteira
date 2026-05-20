// ===== FUNIL =====

int servoPin = 13;

Servo Fservo;

//ESSTADO DO FUNIL

bool funilAberto = false;

void iniciaFunil() {
  Fservo.attach(servoPin, 500, 2400);

  Fservo.write(0);
}

void abrirFunil(int espera) {

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

void fecharFunil(int espera) {
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

  Serial.println("Funil DESATIVADO");
  return false;
}