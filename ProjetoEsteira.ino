#include <Servo.h>

#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2); 

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

void moverBase(int anguloDestino);

void controlarGarra(int anguloDestino);

void controlarAltura(int anguloDestino);

void controlarAvanco(int anguloDestino);

void executarCicloRobo();

void verificarTeclado();

void exibirMensagem(const char* linha1, const char* linha2);

void exibirLinha1(const char* texto);

void exibirLinha2(const char* texto);

// ===== SETUP =====

void setup() {

  Serial.begin(9600);

  iniciaPonteH();

  iniciaFunil();

  iniciaSensores();

  iniciaBotao();

  iniciaRobo();

  iniciaDisplay();
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
