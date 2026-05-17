void setup() {

  Serial.begin(9600);

  iniciaPonteH();

  iniciaServo();

  iniciaSensores();

  ligarEsteira();
  
  iniciaBotao();
}

void loop() {

  botaoLiga();
  
  botaoDesliga();

  verificarSensor1();

  verificarSensor2();
}