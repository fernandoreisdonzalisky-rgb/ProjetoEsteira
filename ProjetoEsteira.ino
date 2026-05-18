// ===== MÓDULOS =====

void ligarEsteira(int espera = 0);

void desligarEsteira(int espera = 0);

void abrirFunil(int espera = 0);

void fecharFunil(int espera = 0);

void verificarSensor1();

void verificarSensor2();

void botaoLiga();

void botaoDesliga();

bool servoAtivo();

void ligaBraco();

// ===== INICIALIZAÇÃO =====

void iniciaPonteH();

void iniciaServo();

void iniciaSensores();

void iniciaBotao();

void iniciaBraco();

// ===== SETUP =====

void setup() {

  Serial.begin(9600);

  iniciaPonteH();

  iniciaServo();

  iniciaSensores();

  iniciaBotao();

  iniciaBraco();
}

// ===== LOOP =====

void loop() {

  botaoLiga();

  botaoDesliga();

  verificarSensor1();

  verificarSensor2();
}