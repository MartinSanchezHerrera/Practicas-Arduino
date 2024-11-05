// Definir los pines de los LEDs
int ledRojo = 13;
int ledAmarillo = 12;
int ledVerde = 11;

void setup() {
  // Configurar los LEDs
  pinMode(ledRojo, OUTPUT);
  pinMode(ledAmarillo, OUTPUT);
  pinMode(ledVerde, OUTPUT);
}

void loop() {
  // semáforo
  
  //  LED verde 
  digitalWrite(ledVerde, HIGH);
  delay(5000);  // Esperar 5 segundos
  digitalWrite(ledVerde, LOW);

  // LED amarillo 
  for (int i = 0; i < 3; i++) {  
    digitalWrite(ledAmarillo, HIGH);  
    delay(500);        // Espera dos segundos                
    digitalWrite(ledAmarillo, LOW);
    delay(500);                      
  }

  // LED rojo
  digitalWrite(ledRojo, HIGH);
  delay(5000);  // 
  digitalWrite(ledRojo, LOW);

  // Repetir la secuencia
}

