#include <DHT.h>

#define DHTPIN 2      
#define DHTTYPE DHT11  
DHT dht(DHTPIN, DHTTYPE);

#define LEDPIN 13
const float TEMPERATURA_ALTA = 30;

void setup() {
  Serial.begin(9600);
  dht.begin();
  pinMode(LEDPIN, OUTPUT);
}

void loop() {
  // datos del sensor 
  float temperatura = dht.readTemperature();
  float humedad = dht.readHumidity();

  // Verificamos si hay errores de lectura
  if (isnan(temperatura) || isnan(humedad)) {
    Serial.println("Error al leer del sensor DHT");
    return;
  }

  // Imprimir los datos
  Serial.print("Temperatura: ");
  Serial.print(temperatura);
  Serial.print(" °C\tHumedad: ");
  Serial.print(humedad);
  Serial.println(" %");

  // Encendemos el LED si la temperatura es mayor que el umbral
  if (temperatura > TEMPERATURA_ALTA) {
    digitalWrite(LEDPIN, HIGH);  // Enciende el LED
  } else {
    digitalWrite(LEDPIN, LOW);   // Apaga el LED
  }

  // Esperamos un segundo antes de la siguiente lectura
  delay(1000);
}
