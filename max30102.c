#include <Wire.h>
#include "MAX30105.h"
#include "heartRate.h"

MAX30105 sensor;

const byte RATE_SIZE = 4;
byte rates[RATE_SIZE];
byte rateSpot = 0;

long lastBeat = 0;
float bpm;
int promedioBPM;

void setup() {
  Serial.begin(115200);
  while (!Serial) delay(10);
  delay(1000);

  Wire.begin(5, 6);

  Serial.println("Inicializando MAX30102...");

  if (!sensor.begin(Wire, I2C_SPEED_FAST)) {
    Serial.println("MAX30102 no detectado.");
    while (1) delay(100);
  }

  sensor.setup();
  sensor.setPulseAmplitudeRed(0x0A);
  sensor.setPulseAmplitudeIR(0x0A);
  sensor.setPulseAmplitudeGreen(0);

  Serial.println("MAX30102 listo.");
  Serial.println("Coloca el dedo sobre el sensor.");
}

void loop() {
  long irValue = sensor.getIR();

  if (checkForBeat(irValue)) {
    long delta = millis() - lastBeat;
    lastBeat = millis();

    bpm = 60.0 / (delta / 1000.0);

    if (bpm > 20 && bpm < 255) {
      rates[rateSpot++] = (byte)bpm;
      rateSpot %= RATE_SIZE;

      promedioBPM = 0;

      for (byte i = 0; i < RATE_SIZE; i++) {
        promedioBPM += rates[i];
      }

      promedioBPM /= RATE_SIZE;
    }
  }

  Serial.print("IR=");
  Serial.print(irValue);
  Serial.print(", BPM=");
  Serial.print(bpm);
  Serial.print(", Promedio BPM=");
  Serial.print(promedioBPM);

  if (irValue < 50000) {
    Serial.print(" Sin dedo");
  }

  Serial.println();
  delay(100);
}
