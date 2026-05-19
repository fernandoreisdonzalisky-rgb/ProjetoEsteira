// ===== MÓDULOS =====

void ligarEsteira(int espera = 0);

void desligarEsteira(int espera = 0);

void abrirFunil(int espera = 0);

void fecharFunil(int espera = 0);

void verificarSensor1();

void verificarSensor2();

void botaoLiga();

void botaoDesliga();

void verificaBotaodesliga ();

bool funilAtivo();

void ligaBraco(int espera = 0);

// ===== INICIALIZAÇÃO =====

void iniciaPonteH();

void iniciaFunil();

void iniciaSensores();

void iniciaBotao();

void iniciaBraco();

// ===== SETUP =====

void setup() {

  Serial.begin(9600);

  iniciaPonteH();

  iniciaFunil();

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

  verificaBotaodesliga ();
}