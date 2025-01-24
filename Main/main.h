#ifndef MAIN_H
#define MAIN_H

#define BLYNK_TEMPLATE_ID "TMPL4uIOwLDC2"
#define BLYNK_TEMPLATE_NAME "Quickstart Template"
#define BLYNK_AUTH_TOKEN "HdYxokz-8EgYdvi-BKrlZyaOgi1jkr27"

extern char ssid[];
extern char pass[];
extern char auth[];

#include <WiFi.h>
#include <time.h>
#include <Arduino.h>



#include "blynk_func.h"
#include "releu.h"
#include "DHT11.h"


#define LIGHT 6                 // Pinul cinectat la lumina din incapere


String getOraCurenta();



#endif
