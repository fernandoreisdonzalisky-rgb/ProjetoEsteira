
int sensor1 = 18;

 void iniciaSensor(){

  Serial.begin(115200);

  pinMode(sensor1,INPUT);
}

 void testaSensor(){

 int estado = digitalRead (sensor1);

 Serial.println(estado);

 delay(200);


}