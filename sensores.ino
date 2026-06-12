int sensor1 = 7;

int sensor2 = 8;


void iniciaSensores() {

  pinMode(sensor1, INPUT_PULLUP);

  pinMode(sensor2, INPUT_PULLUP);
}

void verificarSensor1() {

  // BLOQUEIA TODO O SENSOR
  if (sistemaLigado == false || sensor2Ativado == true || bracoAtivo == true) {

    Serial.println("Sensor1 Desativado");

    return;
  }

  int estadoSensor1 = digitalRead(sensor1);

  if (estadoSensor1 == LOW && sensor1Ativado == false) {

    sensor1Ativado = true;

    Serial.println("Objeto detectado no sensor 1");

    desligarEsteira();

    abrirFunil(3000);

    fecharFunil(1000);

    ligarEsteira(1000);

    Serial.println("Leitura1 realizada");
  }

  if (estadoSensor1 == HIGH) {

    sensor1Ativado = false;
  }
}
void verificarSensor2() {

  // BLOQUEIA TODO O SENSOR
  if (sistemaLigado == false || sensor1Ativado == true ) {

    Serial.println("Sensor2 Desativado");

    return;
  }

  int estadoSensor2 = digitalRead(sensor2);

  if (estadoSensor2 == LOW && sensor2Ativado == false) {

    sensor2Ativado = true;

    Serial.println("Objeto detectado no sensor 2");

    desligarEsteira();

    Serial.println("leitura2 realizada");

  }

  if (estadoSensor2 == HIGH) {

    sensor2Ativado = false;
  }
}