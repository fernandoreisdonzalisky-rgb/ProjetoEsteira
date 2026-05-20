// ===== SENSORES =====

int sensor1 = 4;
int sensor2 = 5;


void iniciaSensores() {
  pinMode(sensor1, INPUT_PULLUP);
  pinMode(sensor2, INPUT_PULLUP);
}

void verificarSensor1() {

//BLOQUEIA TODO O SENSOR
  
  if (sistemaLigado == false || sensor2Ativado == true || bracoAtivo == true) {
    return;
  }

  int estadoSensor1 = digitalRead(sensor1);

  if (estadoSensor1 == LOW && sensor1Ativado == false) {
    sensor1Ativado = true;

    Serial.println("Objeto detectado no sensor 1");

    desligarEsteira(1000);

    abrirFunil(1000);

    fecharFunil(200);

    ligarEsteira(2000);
  }

  if (estadoSensor1 == HIGH) {
    sensor1Ativado = false;
  }
}

void verificarSensor2() {

  //BLOQUEIA TODO O SENSOR
  
  if (sistemaLigado == false || sensor1Ativado == true || bracoAtivo == true) {
    return;
  }

  int estadoSensor2 = digitalRead(sensor2);

  if (estadoSensor2 == LOW && sensor2Ativado == false) {
    sensor2Ativado = true;

    Serial.println("Objeto detectado no sensor 2");

    desligarEsteira();

    ligaBraco(2000);
  }

  if (estadoSensor2 == HIGH) {
    sensor2Ativado = false;
  }
}