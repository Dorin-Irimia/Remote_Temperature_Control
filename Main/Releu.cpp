#include "releu.h"

bool stareReleu = false;
bool workMode = false;

void InitReleu(){
  pinMode(RELAYPIN, OUTPUT);
  digitalWrite(RELAYPIN, OFF);
}

void ReleuState(bool state){
  if (state != stareReleu){
    digitalWrite(RELAYPIN, state);
    ReleuResponse(state);
    Serial.print("Releul este: ");
    Serial.println(state == ON ? "PORNIT" : "OPRIT");
    stareReleu = state;
  }
}
