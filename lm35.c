const int PIN_LM35 = 4;

void setup() {
  Serial.begin(115200);
  delay(1000);
}

void loop() {
  int lectura = analogRead(PIN_LM35);

  float voltaje = lectura * (3.3 / 4095.0);
  float temperatura = voltaje * 100.0;

  Serial.print("ADC=");
  Serial.print(lectura);
  Serial.print(" Voltaje=");
  Serial.print(voltaje, 3);
  Serial.print(" V Temperatura=");
  Serial.print(temperatura, 1);
  Serial.println(" °C");

  delay(1000);
}
