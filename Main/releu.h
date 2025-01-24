#ifndef RELEU_H
#define RELEU_H

#define RELAYPIN 5 
#include "main.h"

void initReleu();       // Funcție pentru inițializarea releului
void releuState(bool state);

extern bool stareReleu;
extern bool workMode;

 

#endif
