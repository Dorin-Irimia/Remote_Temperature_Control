#ifndef DHT11_H
#define DHT11_H

#include "common.h"

extern float temperatura;
//extern DHT dht;           // Obiect DHT

#define DHTPIN 4                
#define DHTTYPE DHT11          

void InitDHT11();    
void TempRead();
void TempAutoControl();


#endif
