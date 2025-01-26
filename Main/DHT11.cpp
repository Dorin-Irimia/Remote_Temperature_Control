#include "DHT11.h"
#include "releu.h"
#include "data.h"
#include <DHT.h>

float temperatura = 0.0; 

DHT dht(DHTPIN, DHTTYPE);

void InitDHT11(){
  dht.begin();
}


void TempRead() {
  temperatura = dht.readTemperature();
  if (isnan(temperatura) || temperatura < 0 || temperatura > 40) {
    Serial.println("Eroare la citirea senzorului DHT sau temperatură in afara intervalului!");
    temperatura = 255; // Marcaj pentru eroare
    ReleuState(OFF);
    return;
  }
  Serial.print(temperatura);
  Serial.println(" ^C");
}


void TempAutoControl(){
  String _ora = GetOraCurenta();
  int _h = _ora.substring(0,2).toInt();
  int _difference = abs(_h - startClock);
  Serial.print("diferenta de ore este = ");
  Serial.println(_difference);
  if((temperatura < START_TEMP) && (0 <=  _difference <= (stopClock - startClock))){
    ReleuState(ON);
  }
  else if(STOP_TEMP < temperatura < ERROR_TEMP){
    ReleuState(OFF);
  }
  else{
    ReleuState(OFF);
  }
}
