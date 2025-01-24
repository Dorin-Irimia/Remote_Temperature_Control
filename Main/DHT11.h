#ifndef DHT11_H
#define DHT11_H
#include "main.h"
#include <DHT.h>

extern DHT dht;           // Obiect DHT
#define DHTPIN 4                
#define DHTTYPE DHT11          

extern float temperatura;

void initDHT11();    
void tempRead();
void tempAutoControl();


#endif
