int sensor1 = 35;

int sensor2 = 34;

const int SENSOR_ATIVO = 1000;  // era 250  (objeto detectado abaixo disso)
const int SENSOR_LIVRE = 3000;  // era 750  (sensor livre acima disso)


void iniciaSensores() {

  pinMode(sensor1, INPUT_PULLUP);

  pinMode(sensor2, INPUT_PULLUP);
}

void verificarSensor1() {

  // BLOQUEIA TODO O SENSOR
  if (sistemaLigado == false || sensor2Ativado == true || bracoAtivo == true || esteiraLigada == true) {

    return;
  }

  int estadoSensor1 = analogRead(sensor1);

  if (estadoSensor1 <= SENSOR_ATIVO && sensor1Ativado == false) {

    sensor1Ativado = true;

    Serial.println("Objeto detectado no sensor 1");

    desligarEsteira();

    abrirFunil(90, 2000); //ângulo e delay

    fecharFunil(0, 1000); //ângulo e delay

    ligarEsteira(0); //delay

    sensor1Ativado = false;
  }

  if (estadoSensor1 >= SENSOR_LIVRE) {

    sensor1Ativado = false;
  }
}

void verificarSensor2() {

  int estadoSensor2 = analogRead(sensor2);

  // Rearma mesmo quando existe intertravamento
  if (estadoSensor2 >= SENSOR_LIVRE) {
    sensor2Ativado = false;
  }

  // Bloqueia durante o ciclo do sensor 1 e do braço
  if (!sistemaLigado || sensor1Ativado || bracoAtivo) {
    return;
  }

  if (estadoSensor2 <= SENSOR_ATIVO && !sensor2Ativado) {
    sensor2Ativado = true;

    Serial.println("Objeto detectado no sensor 2");
    desligarEsteira();
  }
}
