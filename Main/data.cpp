#include "data.h"
#include <WiFi.h>
#include <time.h>

char ssid[] = NAME_WIFI;        // Numele rețelei Wi-Fi
char pass[] = PASSWORD_WIFI;   // Parola rețelei Wi-Fi
char auth[] = TOKEN;          // Tokenul primit de la Blynk

char* ntpServer = "pool.ntp.org";
long gmtOffset_sec = 7200;    // Fus orar România (+2 ore)
int daylightOffset_sec = 3600; // Ora de vară (1 oră)

int startClock = START_TIME;
int stopClock = STOP_TIME;


void InitWIFI(){
    WiFi.begin(ssid, pass);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Conectare la Wi-Fi...");
  }
  Serial.println("Conectat la Wi-Fi!");
}

void InitTIME(){
   configTime(gmtOffset_sec, daylightOffset_sec, ntpServer);
}


String GetOraCurenta() {
  struct tm timeinfo;
  String _oraCurenta = "";
  if (!getLocalTime(&timeinfo)) {
    Serial.println("Nu pot obține ora!        ERROR");
    _oraCurenta = "00:00";
    return _oraCurenta;
  }
  char buffer[6];
  strftime(buffer, sizeof(buffer), "%H:%M", &timeinfo); // Format HH:MM
  _oraCurenta = String(buffer);
  Serial.println(_oraCurenta);
  return _oraCurenta;
}
