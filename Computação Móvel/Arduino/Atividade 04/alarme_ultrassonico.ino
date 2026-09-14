// Atividade 04 - Alarme de proximidade com dois sensores ultrassônicos (HC-SR04)
// Se algum objeto estiver a até 10 cm de qualquer sensor, aciona o buzzer e o LED vermelho;
// caso contrário, mantém o LED verde aceso.

const int ECHO_1 = 2;
const int TRIGGER_1 = 3;

const int ECHO_2 = 11;
const int TRIGGER_2 = 12;

const int BUZZER = 6;
const int VOLUME_BUZZER = 100;

const int LED_VERDE = 9;
const int LED_VERMELHO = 10;

const long DISTANCIA_ALARME_CM = 10;
const unsigned long DURACAO_ALARME_MS = 5000;

void setup() {
  pinMode(TRIGGER_1, OUTPUT);
  pinMode(ECHO_1, INPUT);

  pinMode(TRIGGER_2, OUTPUT);
  pinMode(ECHO_2, INPUT);

  pinMode(LED_VERDE, OUTPUT);
  pinMode(LED_VERMELHO, OUTPUT);
  pinMode(BUZZER, OUTPUT);

  Serial.begin(9600);
}

/**
 * Dispara um pulso no sensor e retorna a distância medida em centímetros.
 * O som percorre ~0,034 cm/us; como o eco faz ida e volta, distância = tempo * 0,017.
 */
long medeDistanciaCm(int trigger, int echo) {
  digitalWrite(trigger, LOW);
  delayMicroseconds(2);
  digitalWrite(trigger, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigger, LOW);

  unsigned long duracaoUs = pulseIn(echo, HIGH);
  long distanciaCm = duracaoUs * 17 / 1000;

  Serial.println(distanciaCm);
  return distanciaCm;
}

void loop() {
  long distancia1 = medeDistanciaCm(TRIGGER_1, ECHO_1);
  long distancia2 = medeDistanciaCm(TRIGGER_2, ECHO_2);

  if (distancia1 <= DISTANCIA_ALARME_CM || distancia2 <= DISTANCIA_ALARME_CM) {
    digitalWrite(LED_VERDE, LOW);
    digitalWrite(LED_VERMELHO, HIGH);
    analogWrite(BUZZER, VOLUME_BUZZER);
    delay(DURACAO_ALARME_MS);
    analogWrite(BUZZER, 0);
  } else {
    digitalWrite(LED_VERDE, HIGH);
    digitalWrite(LED_VERMELHO, LOW);
  }
}
