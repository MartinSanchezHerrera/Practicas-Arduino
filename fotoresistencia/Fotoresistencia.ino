int ldr= A5;
int ledPin = 13;

void setup(){
  pinMode(ledPin, OUTPUT); // Configurar LED como salida
  pinMode(ldrPin, INPUT); // Configurar LDR como entrada
  Serial.begin(9600); // Iniciar comunicación serie para depuración
  
}
void loop(){
  int lecturaLDR = analogRead(ldrPin); // Leer valor del LDR
  
  Serial.print("Valor LDR: ");
  Serial.println(lecturaLDR); // Mostrar el valor en el monitor serie
  
  // Verificar si está oscuro o hay luz
  if (lecturaLDR < umbral) {
    digitalWrite(ledPin, HIGH); // Encender LED
  } else {
    digitalWrite(ledPin, LOW); // Apagar LED
  }
  
  delay(500); // Espera de medio segundo antes de la siguiente lectura
}

