#include <Arduino.h>
#include <Arduino_RouterBridge.h>
#include <Arduino_Modulino.h>


ModulinoLight light;
ModulinoThermo thermo;
ModulinoDistance distance;

const int SEUIL_MM = 800;                 // presence si < 80 cm
const unsigned long COOLDOWN_MS = 10000;  // 1 notif max toutes les 10 s
unsigned long lastSendMs = 0;

void setup() {
  Bridge.begin();
  Monitor.begin();
  Modulino.begin();

  light.begin();
  thermo.begin();
  distance.begin();

  //delay(5000); // laisser Python demarrer
}

void loop() {
  // 1) Capteurs periodiques (1 Hz)
  static unsigned long lastSensorsMs = 0;
  unsigned long now = millis();

  if (now - lastSensorsMs >= 1000) {
    lastSensorsMs = now;

    light.update();
    int lux = light.getAL();
    float temp = thermo.getTemperature();
    float hum  = thermo.getHumidity();

    Bridge.call("update_sensors", lux, temp, hum);

    Monitor.print("lux="); Monitor.print(lux);
    Monitor.print(" temp="); Monitor.print(temp, 2);
    Monitor.print(" hum="); Monitor.println(hum, 2);
  }

  // 2) Detection presence via distance (20 ms)
  if (distance.available()) {
    int mm = (int)distance.get();
    bool presence = (mm > 0 && mm < SEUIL_MM);

    if (presence && (now - lastSendMs >= COOLDOWN_MS)) {
      lastSendMs = now;
      Bridge.call("presence_mm", mm);

      Monitor.print("PRESENCE mm="); Monitor.println(mm);
    }
  }

  delay(20);
}
