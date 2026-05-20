Servo servo1;

const int pinoServo = 13;
const int pinoPot = 34;

void  iniciaServos(){

 Serial.begin(115200);

  servo1.attach(pinoServo, 500, 2500);

  Serial.println("Teste de servo com potenciometro");

}

void testaServos(){

  int leituraPot = analogRead(pinoPot);

  int angulo = map(leituraPot, 0, 4095, 0, 180);

  servo1.write(angulo);

  Serial.print("Pot: ");
  Serial.print(leituraPot);

  Serial.print(" | Angulo: ");
  Serial.println(angulo);

  delay(20);


}
