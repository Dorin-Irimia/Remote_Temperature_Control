#ifndef BLYNK_FUNC_H
#define BLYNK_FUNC_H
#include "main.h"


extern char startClock;
extern char stopClock;

void initBlynk();
void runBlynk();

void showTemp(float);
void showOraCurenta(String);
void releuResponse(bool);

#define BLYNK_RELAY V1
#define BLYNK_WMODE V3
#define BLYNK_TEMP V4
#define BLYNK_TIME V5
#define BLYNK_START_CLOCK V6


#endif
