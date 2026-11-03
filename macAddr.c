// Obtener la MAC adress

#include <WiFi.h>

void setup() {
  Serial.begin(115200);
  delay(1000); // Pequeña pausa para inicializar el monitor serie

  // Configura el WiFi en modo estación
  WiFi.mode(WIFI_STA); 
  delay(100);  // Pausa corta para que el chip procese el modo

  // Imprime directamente la dirección MAC
  Serial.print("Mi MAC Address es: ");
  Serial.println(WiFi.macAddress());
}

void loop() {
}
