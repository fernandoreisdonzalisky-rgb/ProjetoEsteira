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

   botaoLiga();
   botaoDesliga();

   verificarSensor1();
   verificarSensor2();
   verificarTeclado();
}