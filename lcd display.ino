// ====== DISPLAY LCD I2C ======
// Utiliza apenas 2 pinos: A4 (SDA) e A5 (SCL)

void iniciaDisplay() {
  lcd.init();
  lcd.backlight();
  exibirMensagem("Sistema Pronto", "Aguardando...");
}

// Função auxiliar para exibir mensagens no LCD (2 linhas)
void exibirMensagem(const char* linha1, const char* linha2) {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print(linha1);
  lcd.setCursor(0, 1);
  lcd.print(linha2);
}

// Função auxiliar para exibir apenas a linha 1 (sem limpar a linha 2)
void exibirLinha1(const char* texto) {
  lcd.setCursor(0, 0);
  lcd.print("                "); // Limpa a linha 1
  lcd.setCursor(0, 0);
  lcd.print(texto);
}

// Função auxiliar para exibir apenas a linha 2 (sem limpar a linha 1)
void exibirLinha2(const char* texto) {
  lcd.setCursor(0, 1);
  lcd.print("                "); // Limpa a linha 2
  lcd.setCursor(0, 1);
  lcd.print(texto);
}