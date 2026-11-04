#include <WiFi.h>

const char* ssid = "iPhone de Alex";
const char* password = "TU_CONTRASENA";

WiFiServer server(80);

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

  server.begin();
  Serial.println("Servidor HTTP iniciado");
}

void loop() {
  WiFiClient client = server.available();

  if (!client) {
    return;
  }

  while (client.connected() && !client.available()) {
    delay(1);
  }

  while (client.available()) {
    client.read();
  }

  client.println("HTTP/1.1 200 OK");
  client.println("Content-Type: text/plain; charset=utf-8");
  client.println("Connection: close");
  client.println();
  client.println("ESP32 conectado correctamente");

  delay(1);
  client.stop();
}
