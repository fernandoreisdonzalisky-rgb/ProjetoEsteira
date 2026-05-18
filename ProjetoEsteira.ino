// ===== PROTOTIPOS =====

void iniciaPonteH();

void ligarEsteira(int espera = 0);

void desligarEsteira(int espera = 0);

void iniciaServo();

void abrirFunil(int espera = 0);

void fecharFunil(int espera = 0);

bool servoAtivo();

void iniciaSensores();

void verificarSensor1();

void verificarSensor2();

void iniciaBotao();

void botaoLiga();

void botaoDesliga();

// ===== SETUP =====

void setup() {

  Serial.begin(9600);

  iniciaPonteH();

  iniciaServo();

  iniciaSensores();

  iniciaBotao();

}

// ===== LOOP =====

void loop() {

  botaoLiga();

  botaoDesliga();

  verificarSensor1();

  verificarSensor2();
}