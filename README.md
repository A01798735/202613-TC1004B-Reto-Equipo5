# 202613-TC1004B-Reto-Equipo5

Repositorio correspondiente al reto de TC1004B del equipo 5, semestre 202613.

## Introducción

El reto consiste en desarrollar un wearable biomédico capaz de medir signos vitales. Los datos obtenidos se utilizarán para actualizar una base de datos, con el propósito de facilitar su almacenamiento y análisis.

## Avance 1

- **Prueba del sensor de temperatura con LEDs:** se realizó una prueba del sensor de temperatura y se utilizaron LEDs para representar visualmente la lectura o el comportamiento del sensor.
- **Obtención de la dirección MAC:** se logró obtener la dirección MAC del dispositivo, avance necesario para identificarlo en las comunicaciones.

## Avance 2

- **Servidor HTTP en el ESP32 con conexión WiFi:** se implementó un servidor HTTP para el dispositivo. [Ver commit](https://github.com/A01798735/202613-TC1004B-Reto-Equipo5/commit/ec618d30092fff783a96f3127ed321161dcedab1)
- **Configuración de conectividad WiFi:** se agregó la configuración de conexión WiFi en `connectivity.c`. [Ver commit](https://github.com/A01798735/202613-TC1004B-Reto-Equipo5/commit/6f6b7c85643f78628f93a3efa940246fae3048f2)
- **Lectura de sensores y salida por Serial:** se agregó `sensor2csv.c` para leer datos del MAX30102 y del LM35 y mostrarlos en el monitor Serial. [Ver commit](https://github.com/A01798735/202613-TC1004B-Reto-Equipo5/commit/e925fa1ac6e0544745086c79417a1fce31fe2b69)
- **Lectura del sensor de temperatura LM35:** se agregó código para obtener lecturas de temperatura. [Ver commit](https://github.com/A01798735/202613-TC1004B-Reto-Equipo5/commit/466c66f941fc4fe089fd5b3c93ed8b4ff750cb6a)
- **Sensor de ritmo cardíaco MAX30102:** se agregó funcionalidad para inicializar el sensor, leer sus datos y mostrar mediciones por Serial. [Ver commit](https://github.com/A01798735/202613-TC1004B-Reto-Equipo5/commit/5e8b6c35d5245725a844e3a55127e9d1bca1f24c)
