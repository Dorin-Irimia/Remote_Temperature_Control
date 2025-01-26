#ifndef BLYNK_FUNC_H
#define BLYNK_FUNC_H
#include "common.h"


void InitBlynk();
void RunBlynk();

void ReleuResponse(bool);

#define BLYNK_RELAY V1
#define BLYNK_WMODE V0
#define BLYNK_TEMP V4
#define BLYNK_TIME V5
#define BLYNK_START_CLOCK V6
#define BLYNK_STOP_CLOCK V7
#define BLYNK_INFO V8


#endif
