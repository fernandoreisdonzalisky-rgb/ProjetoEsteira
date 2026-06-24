void verificarTeclado() {

  if (Serial.available() > 0) {

    char tecla = Serial.read();

    Serial.print("ASCII recebido: ");
    Serial.println((int)tecla);

    Serial.print("Caractere recebido: ");
    Serial.println(tecla);

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