#ifndef DATA_H
#define DATA_H

#include "common.h"

extern char ssid[];     
extern char pass[];   
extern char auth[];  

extern char startClock;
extern char stopClock;

void initWIFI();
void initTIME();

String getOraCurenta();





#endif
