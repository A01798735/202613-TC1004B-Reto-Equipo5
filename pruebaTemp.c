const int LM35_PIN = A0;
// Pines de los LEDs (ajústalos según tu conexión)
const int LED1_PIN = 8;   // Amarillo
const int LED2_PIN = 9;   // Verde
const int LED3_PIN = 10;  // Rojo
void setup() {
  Serial.begin(9600);
  pinMode(LED1_PIN, OUTPUT);
  pinMode(LED2_PIN, OUTPUT);
  pinMode(LED3_PIN, OUTPUT);
}
void loop() {
  // Leer el valor analógico del sensor LM35
  int sensorValue = analogRead(LM35_PIN);
  // Convertir el valor analógico a temperatura en grados Celsius
  float temperature = (sensorValue * 5.0 / 1024.0) * 100.0;
// Apagar todos los LEDs antes de evaluar
  digitalWrite(LED1_PIN, LOW);
  digitalWrite(LED2_PIN, LOW);
  digitalWrite(LED3_PIN, LOW);
  if (temperature <= 20) {		  	  // Control de LEDs según la temperatura
    digitalWrite(LED1_PIN, HIGH);                 // Amarillo
  } else if (temperature >= 21 && temperature <= 25) {
    digitalWrite(LED2_PIN, HIGH);                 // Verde
  } else if (temperature >= 26 && temperature <= 30) {
    digitalWrite(LED3_PIN, HIGH);                 // Rojo
  } else if (temperature >= 31) {
    digitalWrite(LED1_PIN, HIGH);                 // Todos encendidos
    digitalWrite(LED2_PIN, HIGH);
    digitalWrite(LED3_PIN, HIGH);
  }
  Serial.print("{");		// Imprimir los datos en formato JSON
  Serial.print("\"temperature\":");
  Serial.print(temperature);
  Serial.println("}");
  delay(5000); // Esperar 5 segundos antes de la siguiente lectura
}
