void verificarTeclado() {

  if (Serial.available() > 0) {

    char tecla = Serial.read();

    if (tecla == 'L' || tecla == 'l') {
      sistemaLigado = true;
      Serial.println(">>> COMANDO TECLADO: Sistema Ligado");
      ligarEsteira();
    }
    else if (tecla == 'D' || tecla == 'd') {
      Serial.println(">>> COMANDO TECLADO: Sistema Desligado");
      sistemaLigado = false;
      desligarEsteira();
    }
  }
}
  void atualizarSistema() {

   botaoLiga();
   botaoDesliga();

   verificarSensor1();
   verificarSensor2();
   verificarTeclado();
}