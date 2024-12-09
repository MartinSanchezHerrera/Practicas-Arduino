#include <LiquidCrystal.h>

int ldr = A5;
int valor;
int led = 2;
int dt = 100; // delay
int limite = 200;

LiquidCrystal lcd(7, 6, 5, 4, 3, 2);

void setup() {
  Serial.begin(9600);
  pinMode(ldr, INPUT);
  pinMode(led, OUTPUT);
  
  lcd.begin(16, 2);
}

void loop() {
  valor = analogRead(ldr);  // Se usa la variable global valor
  Serial.println(valor);
  delay(dt);

  lcd.setCursor(2, 0);
  lcd.print(valor);
  delay(800);

  if(valor <= limite){
    digitalWrite(led, LOW);
    delay(100);
  } else {
    digitalWrite(led, HIGH);
    delay(100);
  }

  delay(dt);
}

