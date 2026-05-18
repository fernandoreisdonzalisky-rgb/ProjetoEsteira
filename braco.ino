  #include <Servo.h>

  Servo servoBase;

  Servo servoDireita;

  Servo servoEsquerda;

  Servo servoPulso;

  Servo servoGarra;

  Servo servoArtgarra;

  int pinoBase = A0;
  int pinoDireita = A1;
  int pinoEsquerda = A2 ;
  int pinoPulso = A3 ;
  int pinoGarra = A4 ;
  int pinoArtgarra = A5;

  void iniciaBraco() {

    servoBase.attach(pinoBase);

    servoDireita.attach(pinoDireita);

    servoEsquerda.attach(pinoEsquerda);

    servoPulso.attach(pinoPulso);

    servoGarra.attach(pinoGarra);

    servoArtgarra.attach(pinoArtgarra);

    Serial.println("Braco iniciado");
  }

  void ligaBraco() {


    



  }