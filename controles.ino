void verificarTeclado() {

  if (Serial.available() > 0) {

    char tecla = Serial.read();

    if (tecla == 'L' || tecla == 'l') {
      sistemaLigado = true;
      Serial.println(">>> COMANDO TECLADO: Sistema Ligado");
    }
    else if (tecla == 'D' || tecla == 'd') {
      Serial.println(">>> COMANDO TECLADO: Sistema Desligado");
      desligarEsteira();
      sistemaLigado = false;
    }
  }
}

void atualizarSistema() {

  // durante o retorno de emergencia nao atualiza nada
  // (evita chamar o botao desliga de novo dentro do proprio retorno)
  if (retornoEmergencia == true) return;

  botaoLiga();
  botaoDesliga();

  verificarSensor1();
  verificarSensor2();
  verificarTeclado();
}
