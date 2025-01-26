#include "common.h"
#include "blynk_func.h"
#include "data.h"
#include "DHT11.h"
#include "releu.h"

void setup() {
  Serial.begin(115200);
  InitWIFI();
  InitTIME();
  InitBlynk();                  // Configurare Blynk
  InitDHT11();         
  InitReleu();                  // Configurare Releu
}

void loop() {
  static unsigned long lastTempUpdate = 0;
  
  RunBlynk();                  
  if(workMode){
    TempAutoControl();
  }
  if (millis() - lastTempUpdate > TEMP_DELAY) {
    lastTempUpdate = millis();
    TempRead();
  }
  delay(RUN_DELAY);
 
}
