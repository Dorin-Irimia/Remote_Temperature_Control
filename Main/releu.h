#ifndef RELEU_H
#define RELEU_H

#include "common.h"
#include "blynk_func.h"

#define RELAYPIN 5

extern bool stareReleu;
extern bool workMode;

void InitReleu();       
void ReleuState(bool state);


#endif
