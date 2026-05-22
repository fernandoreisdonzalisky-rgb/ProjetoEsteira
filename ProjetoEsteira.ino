#include <Servo.h>

Servo Fservo;


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


// ===== INICIALIZAÇÃO =====

void iniciaPonteH();

void iniciaServo();

void iniciaSensores();

void iniciaBotao();


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