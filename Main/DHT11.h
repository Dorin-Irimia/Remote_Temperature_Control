#ifndef DHT11_H
#define DHT11_H

#include "common.h"

extern float temperatura;
//extern DHT dht;           // Obiect DHT

#define DHTPIN 4                
#define DHTTYPE DHT11          



void initDHT11();    
void tempRead();
void tempAutoControl();


#endif
