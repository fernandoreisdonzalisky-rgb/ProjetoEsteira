int sensor1 = 5;
int sensor2 = 11;

void iniciaSensores() {

  pinMode(sensor1, INPUT_PULLUP);

  pinMode(sensor2, INPUT_PULLUP);
}

void verificarSensor1() {

  int estadoSensor1 = digitalRead(sensor1);

  if (estadoSensor1 == LOW) {

    Serial.println("Objeto detectado no sensor 1");

    desligarEsteira();

    delay(1000);

    abrirFunil();

    delay(1000);

    ligarEsteira();

    delay(3000);
  }
}

void verificarSensor2() {

  int estadoSensor2 = digitalRead(sensor2);

  if (estadoSensor2 == LOW) {

    Serial.println("Objeto detectado no sensor 2");

    desligarEsteira();
  }
}