// Atividade 02 - Exercício 1
// Pisca dois LEDs alternadamente a cada segundo.

const int LED_A = 12;
const int LED_B = 6;
const unsigned long INTERVALO_MS = 1000;

void setup() {
  pinMode(LED_A, OUTPUT);
  pinMode(LED_B, OUTPUT);
}

void loop() {
  digitalWrite(LED_A, HIGH);
  digitalWrite(LED_B, LOW);
  delay(INTERVALO_MS);

  digitalWrite(LED_A, LOW);
  digitalWrite(LED_B, HIGH);
  delay(INTERVALO_MS);
}
