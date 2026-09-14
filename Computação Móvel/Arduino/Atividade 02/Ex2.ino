// Atividade 02 - Exercício 2
// Acende os LEDs dos pinos 1 a 10 em sequência e depois os apaga na ordem inversa.

const int PRIMEIRO_LED = 1;
const int ULTIMO_LED = 10;
const unsigned long INTERVALO_MS = 1000;

void setup() {
  for (int pino = PRIMEIRO_LED; pino <= ULTIMO_LED; pino++) {
    pinMode(pino, OUTPUT);
  }
}

void loop() {
  for (int pino = PRIMEIRO_LED; pino <= ULTIMO_LED; pino++) {
    digitalWrite(pino, HIGH);
    delay(INTERVALO_MS);
  }

  for (int pino = ULTIMO_LED; pino >= PRIMEIRO_LED; pino--) {
    digitalWrite(pino, LOW);
    delay(INTERVALO_MS);
  }
}
