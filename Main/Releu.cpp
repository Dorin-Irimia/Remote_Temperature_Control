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
    Serial.print("Releul este: ");
    Serial.println(state == 1 ? "PORNIT" : "OPRIT");
    stareReleu = state;
    releuResponse(stareReleu);
  }
  else{
    Serial.print("Releul este: ");
    Serial.println(state);
  }
}
