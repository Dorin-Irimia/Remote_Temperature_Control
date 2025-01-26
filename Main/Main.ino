#include "common.h"
#include "blynk_func.h"
#include "data.h"
#include "DHT11.h"
#include "releu.h"

void setup() {
  Serial.begin(115200);
  initWIFI();
  initTIME();
  initBlynk();                  // Configurare Blynk
  initDHT11();         
  initReleu();                  // Configurare Releu
}

void loop() {
  static unsigned long lastTempUpdate = 0;
  
  runBlynk();                  
  if(workMode){
    tempAutoControl();
  }
  if (millis() - lastTempUpdate > TEMP_DELAY) {
    lastTempUpdate = millis();
    tempRead();
  }
  delay(RUN_DELAY);
 
}
