#include <Servo.h>

Servo Fservo;

Servo servoB;

Servo servoD;

Servo servoE;

Servo servoG;

//====== VARIÁVEIS =======

bool sistemaLigado = false;
bool sensor1Ativado = false;
bool sensor2Ativado = false;
bool bracoAtivo = false;
int anguloAtualBase = servoB.read();


// ===== MÓDULOS =====

void ligarEsteira(int espera = 0);

void desligarEsteira(int espera = 0);

void abrirFunil(int espera = 0);

bool funilAtivo();

void fecharFunil(int espera = 0);

void verificarSensor1();

void verificarSensor2();

void botaoLiga();

void botaoDesliga();

void ligaRobo();

void base(int espera = 0);



// ===== INICIALIZAÇÃO =====

void iniciaPonteH();

void iniciaFunil();

void iniciaSensores();

void iniciaBotao();



// ===== SETUP =====

void setup() {

  Serial.begin(9600);

  iniciaPonteH();

  iniciaFunil();

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