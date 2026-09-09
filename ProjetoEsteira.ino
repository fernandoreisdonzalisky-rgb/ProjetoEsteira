
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
bool funilAberto = false;
bool esteiraLigada = false;
int etapaBraco = 0;


// ===== MÓDULOS =====

void ligarEsteira(int espera = 0);

void desligarEsteira(int espera = 0);

void abrirFunil(int destino,int espera = 0);

bool funilAtivo();

void fecharFunil(int destino,int espera = 0);

void verificarSensor1();

void verificarSensor2();

void botaoLiga();

void botaoDesliga();

void retornaBraco();

void moverBase(int anguloDestino);

void controlarGarra(int anguloDestino);

void controlarEsquerdo(int anguloDestino);

void controlarDireita(int anguloDestino);

void executarCicloRobo();

void verificarTeclado();



// ===== SETUP =====

void setup() {

  Serial.begin(9600);

  iniciaPonteH();

  iniciaFunil();

  iniciaSensores();

  iniciaBotao();

  iniciaRobo();
}

// ===== LOOP =====

void loop() {

  verificarTeclado();
   
  botaoLiga();

  botaoDesliga();

  verificarSensor1();

  verificarSensor2();

  executarCicloRobo();

}
