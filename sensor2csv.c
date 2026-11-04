#include <Wire.h>
#include "MAX30105.h"

MAX30105 sensor;

const int PIN_LM35 = 4;

void setup() {
  Serial.begin(115200);
  while (!Serial) delay(10);
  delay(1000);

  Wire.begin(5, 6);

  if (!sensor.begin(Wire, I2C_SPEED_FAST)) {
    Serial.println("MAX30102 no detectado.");
    while (1) delay(100);
  }

  sensor.setup();
  sensor.setPulseAmplitudeRed(0x0A);
  sensor.setPulseAmplitudeIR(0x0A);
  sensor.setPulseAmplitudeGreen(0);

  Serial.println("MAX30102 listo.");
  Serial.println("IR,Rojo,ADC_LM35,Voltaje_V,Temperatura_C");
}

void loop() {
  long ir = sensor.getIR();
  long rojo = sensor.getRed();

  int adc = analogRead(PIN_LM35);
  float voltaje = adc * (3.3 / 4095.0);
  float temperatura = voltaje * 100.0;

  Serial.print(ir);
  Serial.print(",");
  Serial.print(rojo);
  Serial.print(",");
  Serial.print(adc);
  Serial.print(",");
  Serial.print(voltaje, 3);
  Serial.print(",");
  Serial.println(temperatura, 1);

  delay(500);
}
