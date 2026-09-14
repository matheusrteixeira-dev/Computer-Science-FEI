// Atividade 03 - Semáforo com botão de pedestre
// Ao pressionar o botão, o semáforo dos carros passa para amarelo e depois vermelho,
// liberando os pedestres por um tempo ajustável no potenciômetro (0 a ~1 s).

const int CARRO_VERDE = 6;
const int CARRO_AMARELO = 5;
const int CARRO_VERMELHO = 4;

const int PEDESTRE_VERDE = 10;
const int PEDESTRE_VERMELHO = 11;

const int BOTAO = 7;
const int POTENCIOMETRO = A1;

const unsigned long TEMPO_AMARELO_MS = 2000;
const unsigned long TEMPO_PISCA_MS = 500;

void setup() {
  Serial.begin(9600);

  pinMode(CARRO_VERDE, OUTPUT);
  pinMode(CARRO_AMARELO, OUTPUT);
  pinMode(CARRO_VERMELHO, OUTPUT);

  pinMode(PEDESTRE_VERDE, OUTPUT);
  pinMode(PEDESTRE_VERMELHO, OUTPUT);

  pinMode(BOTAO, INPUT);
}

void loop() {
  // Estado padrão: carros no verde e pedestres no vermelho.
  digitalWrite(CARRO_VERDE, HIGH);
  digitalWrite(PEDESTRE_VERMELHO, HIGH);

  if (digitalRead(BOTAO) == HIGH) {
    Serial.println("Botao de pedestre pressionado");
    int tempoTravessia = analogRead(POTENCIOMETRO);

    // Carros no amarelo; pedestres continuam no vermelho.
    digitalWrite(CARRO_VERDE, LOW);
    digitalWrite(CARRO_AMARELO, HIGH);
    delay(TEMPO_AMARELO_MS);

    // Carros no vermelho; pedestres no verde.
    digitalWrite(CARRO_AMARELO, LOW);
    digitalWrite(CARRO_VERMELHO, HIGH);
    digitalWrite(PEDESTRE_VERMELHO, LOW);
    digitalWrite(PEDESTRE_VERDE, HIGH);
    delay(tempoTravessia);

    // Fim da travessia: vermelho dos pedestres pisca antes de liberar os carros.
    digitalWrite(PEDESTRE_VERDE, LOW);
    for (int i = 0; i < 2; i++) {
      digitalWrite(PEDESTRE_VERMELHO, HIGH);
      delay(TEMPO_PISCA_MS);
      digitalWrite(PEDESTRE_VERMELHO, LOW);
      delay(TEMPO_PISCA_MS);
    }

    // Volta ao estado padrão no próximo loop.
    digitalWrite(CARRO_VERMELHO, LOW);
  }
}
