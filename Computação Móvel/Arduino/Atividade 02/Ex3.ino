// Atividade 02 - Exercício 3
// Luz "vai e volta" nos LEDs dos pinos 1 a 10: a cada ciclo, o ponto de retorno
// superior desce uma posição e os LEDs que chegam ao pino 1 permanecem acesos.

const int PRIMEIRO_LED = 1;
const int ULTIMO_LED = 10;
const unsigned long INTERVALO_MS = 100;

void setup() {
  for (int pino = PRIMEIRO_LED; pino <= ULTIMO_LED; pino++) {
    pinMode(pino, OUTPUT);
  }
}

void loop() {
  int pino = ULTIMO_LED;

  for (int ciclo = 1; ciclo < ULTIMO_LED; ciclo++) {
    // Descida: do pino atual até o primeiro LED.
    for (; pino >= PRIMEIRO_LED; pino--) {
      digitalWrite(pino, HIGH);
      delay(INTERVALO_MS);
      if (pino != PRIMEIRO_LED) {
        digitalWrite(pino, LOW);
      }
    }

    // Subida: do primeiro LED até o novo ponto de retorno.
    for (pino = PRIMEIRO_LED; pino <= ULTIMO_LED - ciclo; pino++) {
      digitalWrite(pino, HIGH);
      delay(INTERVALO_MS);
      digitalWrite(pino, LOW);
    }
  }
}
