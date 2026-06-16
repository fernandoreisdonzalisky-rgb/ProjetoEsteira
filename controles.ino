
void verificarTeclado() {
  if (Serial.available() > 0) {
    char tecla = Serial.read(); // Lê o caractere digitado

    if (tecla == 'L' || tecla == 'l') { // Se digitar 'L'
      sistemaLigado = true;
      ligarEsteira();
      Serial.println(">>> COMANDO TECLADO: Sistema LIGADO");
    } 
    else if (tecla == 'D' || tecla == 'd') { // Se digitar 'D'
      sistemaLigado = false;
      desligarEsteira();
      Serial.println(">>> COMANDO TECLADO: Sistema DESLIGADO");
    }
  }
}