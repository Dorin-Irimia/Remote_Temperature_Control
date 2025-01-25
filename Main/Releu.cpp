#include "releu.h"

bool stareReleu = false;
bool workMode = false;

void initReleu(){
  pinMode(RELAYPIN, OUTPUT);
  digitalWrite(RELAYPIN, LOW);
}

void releuState(bool state){
  if (state != stareReleu){
    digitalWrite(RELAYPIN, state);
    releuResponse(state);
    Serial.print("Releul este: ");
    Serial.println(state == ON ? "PORNIT" : "OPRIT");
    stareReleu = state;
    
  }
}
