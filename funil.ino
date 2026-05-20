// ===== FUNIL =====

int servoPin = 13;

Servo Fservo;

//ESTADO DO FUNIL

bool funilAberto = false;

void iniciaFunil() {
  Fservo.attach(servoPin, 500, 2400);

  Fservo.write(0);
}

void abrirFunil(int espera) {

  if (sistemaLigado == false){

    Fservo.write(0);

    return;
  }

  Serial.print("Posicao atual servo: ");
  Serial.println(Fservo.read());

  if (funilAberto == false) {
    
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

  if (funilAberto == true) {

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

  if (funilAberto == true) {
    Serial.println("Funil ATIVO");
    return true;
  }

  if (funilAberto == false){

  Serial.println("Funil DESATIVADO");
  return false;
 }
}