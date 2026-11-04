#include <WiFi.h>

const char* ssid = "iPhone de Alex";
const char* password = "TU_CONTRASENA";

void setup() {
  Serial.begin(115200);
  delay(1000);

  Serial.println("Conectando a WiFi...");
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("\nWiFi conectado");
  Serial.print("Direccion IP: ");
  Serial.println(WiFi.localIP());
}

void loop() {}
