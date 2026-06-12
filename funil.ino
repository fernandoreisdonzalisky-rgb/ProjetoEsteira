int servoPin = 9;

//ESTADO DO FUNIL

bool funilAberto = false;

void iniciaFunil() {

  Fservo.attach(servoPin);

  Fservo.write(0);
}

void abrirFunil(int destino,int espera) {

  if (funilAberto == false) {
    Serial.println("Abrindo funil...");
    
    int atual = Fservo.read();

    // Movimento suave de abertura
    if (atual < destino) {
      for (int i = atual; i <= destino; i++) {

        if (!sistemaLigado) return;

        delay(espera); //espera o robo colocar a caixa
        Fservo.write(i);

        delay(15); // Ajusta a velocidade da abertura
      }      
    }

    funilAberto = true;
    Serial.println("Funil aberto.");
  }
}

void fecharFunil(int destino,int espera) {
  
  if (funilAberto == true) {
    Serial.println("Fechando funil...");

    int atual = Fservo.read();

    // Movimento suave de fechamento
    if (atual > destino) {
      for (int i = atual; i >= destino; i--) {

        if (!sistemaLigado) return;
        Fservo.write(i);
        delay(15); // Ajusta a velocidade do fechamento
      }
    }

    funilAberto = false;
    Serial.println("Funil fechado.");
    delay(espera); // Espera após fechar
  }
}

bool funilAtivo() {

  Serial.print("Verificando funil: ");
  Serial.println(Fservo.read());

  if (funilAberto == true) {

    Serial.println("Funil ATIVO");

    return true;
  }

  if (funilAberto == false){

  Serial.println("Funil DESATIVADO");

  return false;
  }
 

}