#ifndef BLYNK_FUNC_H
#define BLYNK_FUNC_H
#include "common.h"

#define BLYNK_TEMPLATE_ID "TMPL4uIOwLDC2"
#define BLYNK_TEMPLATE_NAME "Quickstart Template"
#define BLYNK_AUTH_TOKEN "HdYxokz-8EgYdvi-BKrlZyaOgi1jkr27"

void initBlynk();
void runBlynk();

void showTemp(float);
void showOraCurenta();
void releuResponse(bool);

#define BLYNK_RELAY V1
#define BLYNK_WMODE V0
#define BLYNK_TEMP V4
#define BLYNK_TIME V5
#define BLYNK_START_CLOCK V6


#endif
