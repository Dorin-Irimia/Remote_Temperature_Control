#ifndef DATA_H
#define DATA_H

#include "common.h"

extern char ssid[];     
extern char pass[];   
extern char auth[];  

void initWIFI();
void initTIME();

String getOraCurenta();

extern int startClock;
extern int stopClock;


#endif
