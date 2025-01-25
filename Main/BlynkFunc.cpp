#include "blynk_func.h"
#include "releu.h"
#include "data.h"
#include <BlynkSimpleEsp32.h>


void initBlynk(){
  Blynk.begin(auth, ssid, pass);
  Blynk.virtualWrite(BLYNK_WMODE, 0);    // Setare WORK MODE pe MANUAL
  Blynk.virtualWrite(BLYNK_RELAY, 0);    // Setare buton RELEU pe OPRIT
}

void runBlynk(){
  Blynk.run();
}

void showTemp(float _temperatura){
  Blynk.virtualWrite(BLYNK_TEMP, _temperatura); // Trimite temperatura la Blynk (V4)
  Serial.print("Temperatura: ");
  Serial.println(_temperatura);
}


void showOraCurenta(){
  String _ora = getOraCurenta();
  Blynk.virtualWrite(BLYNK_TIME, _ora ); // Trimite ora la Blynk (V2)
  Serial.print("Ora curentă: ");
  Serial.println(_ora);
}

void releuResponse(bool state){
 Blynk.virtualWrite(BLYNK_RELAY, state);    // Setare buton cu starea releului
}

BLYNK_WRITE(BLYNK_RELAY) {
  int valoare = param.asInt(); // Valoare primita de la butonul Blynk
  if(stareReleu != valoare){
    releuState(valoare);
    if(workMode == ON){   // Trecere automata pe mod manual
      Blynk.virtualWrite(BLYNK_WMODE, OFF);
      workMode = OFF;
      Serial.println("Work Mode is now MANUALE from AUTO");
    }
  }
}

BLYNK_WRITE(BLYNK_WMODE) {
  int valoare = param.asInt(); // Valoare primita de la butonul Blynk
  if(workMode != valoare){
    workMode = valoare;
    Serial.print("Work Mode is now ");
    Serial.println(workMode == ON ? "AUTOMATE" : "MANUALE");  
  }
}

BLYNK_WRITE(BLYNK_START_CLOCK) {
  startClock = param.asInt(); // Valoare primita de la butonul Blynk
  Serial.print("Ora de pornire a fost setata la:  ");
  Serial.println(startClock);  
}

BLYNK_WRITE(BLYNK_STOP_CLOCK) {
  stopClock = param.asInt(); // Valoare primita de la butonul Blynk
  Serial.print("Ora de oprire a fost setata la:  ");
  Serial.println(stopClock);  
}
