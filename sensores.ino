int sensor1 = 5;

int sensor2 = 11;

bool sensor1Ativado = false;

void iniciaSensores() {

  pinMode(sensor1, INPUT_PULLUP);

  pinMode(sensor2, INPUT_PULLUP);
}

void verificarSensor1() {

  int estadoSensor1 = digitalRead(sensor1);

  // executa apenas uma vez
  if (estadoSensor1 == LOW && sensor1Ativado == false) {

    Serial.println("Objeto detectado no sensor 1");
    sensor1Ativado = true;

    desligarEsteira();
    abrirFunil(1000);
    fecharFunil(200);
    ligarEsteira(2000);

  }

  // reseta quando objeto sair
  if (estadoSensor1 == HIGH) {

    sensor1Ativado = false;
  }
}

void verificarSensor2() {

  int estadoSensor2 = digitalRead(sensor2);

  if (estadoSensor2 == LOW) {

    Serial.println("Objeto detectado no sensor 2");

    desligarEsteira();
  }
}