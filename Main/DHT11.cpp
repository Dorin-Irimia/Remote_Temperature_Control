#include "DHT11.h"
#include "releu.h"
#include "data.h"
#include <DHT.h>

float temperatura = 0.0; 

DHT dht(DHTPIN, DHTTYPE);

void initDHT11(){
  dht.begin();
}


void tempRead() {
  temperatura = dht.readTemperature();
  if (isnan(temperatura) || temperatura < 0 || temperatura > 40) {
    Serial.println("Eroare la citirea senzorului DHT sau temperatură in afara intervalului!");
    temperatura = -999; // Marcaj pentru eroare
    releuState(OFF);
    return;
  }
  Serial.print(temperatura);
  Serial.println(" ^C");
}


void tempAutoControl(){
  String _ora = getOraCurenta();
  char _h = _ora.substring(0,2).toInt();
  char difference = (_h - startClock);
  Serial.print("diferenta de ore este = ");
  Serial.println(difference);
  if((temperatura < 24) && (0 <=  difference <= 3)){
    releuState(ON);

  }
  if(temperatura > 25){
    releuState(OFF);
  }
}
