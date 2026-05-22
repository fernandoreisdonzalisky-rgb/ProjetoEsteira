#include <Servo.h>

Servo Fservo;


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