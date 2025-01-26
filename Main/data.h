#ifndef DATA_H
#define DATA_H

#include "common.h"

extern char ssid[];     
extern char pass[];   
extern char auth[];  

void InitWIFI();
void InitTIME();
String GetOraCurenta();

extern int startClock;
extern int stopClock;


#endif
