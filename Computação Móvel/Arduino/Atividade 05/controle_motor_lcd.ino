// Atividade 05 - Controle de velocidade de motor DC com potenciômetro e display LCD
// O potenciômetro define o duty cycle do PWM no pino 9; o LCD exibe a rotação estimada.

#include <LiquidCrystal.h>

const int PINO_MOTOR = 9;
const int PINO_POTENCIOMETRO = A0;
const long RPM_MAXIMO = 8481; // rotação do motor com duty cycle de 100%

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup() {
  pinMode(PINO_MOTOR, OUTPUT);
  pinMode(PINO_POTENCIOMETRO, INPUT);

  lcd.begin(16, 2);
  lcd.print("Rotacao (RPM):");
}

void loop() {
  int leitura = analogRead(PINO_POTENCIOMETRO);
  int pwm = map(leitura, 0, 1023, 0, 255);
  analogWrite(PINO_MOTOR, pwm);

  long rpm = map(pwm, 0, 255, 0, RPM_MAXIMO);

  lcd.setCursor(0, 1);
  lcd.print(rpm);
  lcd.print("    "); // apaga dígitos remanescentes de valores maiores
}
