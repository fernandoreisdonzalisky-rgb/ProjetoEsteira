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
    exibirLinha2("Funil: ABRINDO");
    
    delay(espera);
    
    int atual = Fservo.read();

    // Movimento suave de abertura
    if (atual < destino) {

      for (int i = atual; i <= destino; i++) {

        if (!sistemaLigado) return;
        Fservo.write(i);

        delay(15); // Ajusta a velocidade da abertura
      }      
    }

    funilAberto = true;
    Serial.println("Funil aberto.");
    exibirLinha2("Funil: ABERTO");
  }
}

void fecharFunil(int destino,int espera) {
  
  if (funilAberto == true) {
    Serial.println("Fechando funil...");
    exibirLinha2("Funil: FECHANDO");

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
    exibirLinha2("Funil: FECHADO");
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