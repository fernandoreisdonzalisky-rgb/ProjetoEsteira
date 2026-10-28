int sensor1 = A1;

int sensor2 = A3;


void iniciaSensores() {

  pinMode(sensor1, INPUT_PULLUP);

  pinMode(sensor2, INPUT_PULLUP);
}

void verificarSensor1() {

  // BLOQUEIA TODO O SENSOR
  if (sistemaLigado == false || sensor2Ativado == true || bracoAtivo == true || esteiraLigada == true) {

    //Serial.println("Sensor1 Desativado");

    return;
  }

  int estadoSensor1 = analogRead(sensor1);

  if (estadoSensor1 <= 250 && sensor1Ativado == false) {

    sensor1Ativado = true;

    Serial.println("Objeto detectado no sensor 1");

    desligarEsteira();

    abrirFunil(90,2000); //ângulo e delay

    fecharFunil(0,1000); //ângulo e delay

    ligarEsteira(0); //delay

    //Serial.println("Leitura1 realizada");
  }

  if (estadoSensor1 >= 750) {

    sensor1Ativado = false;
  }
}
void verificarSensor2() {
  int estadoSensor2 = analogRead(sensor2);

  if (estadoSensor2 <= 250 && sensor2Ativado == false) {
    sensor2Ativado = true;

    Serial.println("Objeto detectado no sensor 2");
    desligarEsteira();
  }

  if (estadoSensor2 >= 750) {
    sensor2Ativado = false;
  }
}