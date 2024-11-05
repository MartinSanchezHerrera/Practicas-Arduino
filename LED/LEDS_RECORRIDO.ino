// Definimos los pines de los LEDs
const int ledPins[] = {2, 3, 4, 5, 6}; // Pines donde conectamos los LEDs
const int numLeds = 5; // Número total de LEDs
const int delayTime = 200; // Tiempo de retardo en milisegundos

void setup() {
  // Configuramos los pines como salida
  for (int i = 0; i < numLeds; i++) {
    pinMode(ledPins[i], OUTPUT);
  }
}

void loop() {
  // Encender LEDs de ida (de 0 a 4)
  for (int i = 0; i < numLeds; i++) {
    digitalWrite(ledPins[i], HIGH); // Enciende el LED
    delay(delayTime); // Espera un momento
    digitalWrite(ledPins[i], LOW); // Apaga el LED
  }

  // Encender LEDs de vuelta (de 4 a 0)
  for (int i = numLeds - 1; i >= 0; i--) {
    digitalWrite(ledPins[i], HIGH); // Enciende el LED
    delay(delayTime); // Espera un momento
    digitalWrite(ledPins[i], LOW); // Apaga el LED
  }
}

