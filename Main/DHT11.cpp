#include "DHT11.h"



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
    releuState(false);
  }
}


void tempAutoControl(){
  String _ora = getOraCurenta();
  int _h = _ora.substring(0,2).toInt();
  int difference = abs( _h - startClock);
  if((temperatura < 6) && (difference <= 20)){
    releuState(true);
  }
  if(temperatura > 17){
    releuState(false);
  }
}
