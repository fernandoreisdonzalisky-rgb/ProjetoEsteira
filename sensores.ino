#include <Servo.h>

Servo Fservo //denomina o servo do funil

//postivo da ponte
int IN1 = 7;
//negativo da ponte
int IN2 = 9

//pino do servo
int servo = 13;

//pino do sensor1
int sensor1 = 5;
// Pino do sensor2
int sensor2 = 11;

 void reinicia(){

      //liga a esteira 
       digitalWrite(IN1, HIGH); //reinicia a esteira
  digitalWrite(IN2, LOW);  //reinicia a esteira
    }

void setup() {
  Serial.begin(9600);
  
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);

   Fservo.attach(servo);
   Fservo.write(0);

  pinMode(sensor1, INPUT);
  pinMode(sensor2,INPUT);

   //liga a esteira
   digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  
}

void loop() {

  //começo da esteira
  
int estadoSensor1 = digitalRead(sensor1);
  
   if (estadoSensor1 == LOW) {

    Serial.println("objeto detectado");
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, LOW);

    delay(1000);

    cservo.write(90);

    delay(5000);

    cservo.write (0);

    delay(1000);
    
    reinicia();

    delay(3000);

   }

   //final da esteira
   
  int estadoSensor2 = digitalRead(sensor2);

  // sensor ativado
  if (estadoSensor2 == LOW) {

    // desliga a esteira
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, LOW);

  }

  //braço robo
}
