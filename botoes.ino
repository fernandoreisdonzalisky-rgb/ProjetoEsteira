int botaoliga = 9;
int botaodesliga = 7;

void iniciaBotao() {

  pinMode(botaoliga, INPUT_PULLUP);
  pinMode(botaodesliga, INPUT_PULLUP);
}

void botaoLiga(){

  int estadoliga = digitalRead(botaoliga);

  if (estadoliga == LOW) {
    
    ligarEsteira();

    delay(200);
}

}

void botaoDesliga() {

  int estadodesliga = digitalRead(botaodesliga);
  if (estadodesliga == LOW) {

    desligarEsteira();

    delay(200);
  }
}