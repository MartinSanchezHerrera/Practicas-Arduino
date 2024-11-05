#include <LiquidCrystal.h> 


int trig = 10;
int eco = 9;
int led = 13;
int duracion;
int distancia;

// Configuración de pines para la pantalla LCD
const int rs = 7, en = 8, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7); // Crear objeto LCD

void setup() {
  // Configurar los pines del sensor y del LED
  pinMode(trig, OUTPUT);
  pinMode(eco, INPUT);
  pinMode(led, OUTPUT);

  // Inicializar la comunicación serial
  Serial.begin(9600);
  
  // Iniciar la pantalla LCD
  lcd.begin(16, 2); // Pantalla LCD de 16 columnas y 2 filas
  
  // Imprimir "Hola Mundo" en la pantalla LCD
  lcd.setCursor(0, 0); // Colocar el cursor en la primera línea
  lcd.print("Hola Mundo"); // Imprimir "Hola Mundo"
  
  // Esperar 2 segundos antes de empezar a medir
  delay(2000);
  lcd.clear(); // Limpiar la pantalla
}

void loop() {
  // Enviar señal de ultrasonido
  digitalWrite(trig, HIGH);
  delay(1);
  digitalWrite(trig, LOW);
  
  duracion = pulseIn(eco, HIGH); // Recibir la duración del eco
  distancia = duracion / 58.2; // Calcular la distancia en cm

  // Imprimir la distancia en la consola serial
  Serial.print(distancia);
  Serial.print(" centimetros");
  Serial.println();
  delay(200);

  // Encender o apagar el LED dependiendo de la distancia
  if (duracion <= distancia) {
    digitalWrite(led, LOW);
    delay(100);
  } else {
    digitalWrite(led, HIGH);
    delay(100);
  }

  // Controlar el LED basado en la distancia
  if (distancia <= 20) {
    digitalWrite(led, HIGH);
    delay(100);
  } else {
    digitalWrite(led, LOW);
    delay(100);
  }
}

