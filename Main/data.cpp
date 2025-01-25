#include "data.h"
#include <WiFi.h>
#include <time.h>

char ssid[] = "TP-Link_F6B8";      // Numele rețelei Wi-Fi
char pass[] = "21580260";    // Parola rețelei Wi-Fi
char auth[] = "HdYxokz-8EgYdvi-BKrlZyaOgi1jkr27";    // Tokenul primit de la Blynk

char* ntpServer = "pool.ntp.org";
long gmtOffset_sec = 7200;    // Fus orar România (+2 ore)
int daylightOffset_sec = 3600; // Ora de vară (1 oră)
String oraCurenta;


char startClock = 0;
char stopClock = 0;


void initWIFI(){
    WiFi.begin(ssid, pass);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Conectare la Wi-Fi...");
  }
  Serial.println("Conectat la Wi-Fi!");
}


void initTIME(){
   configTime(gmtOffset_sec, daylightOffset_sec, ntpServer);
}

String getOraCurenta() {
  struct tm timeinfo;
  if (!getLocalTime(&timeinfo)) {
    Serial.println("Nu pot obține ora!");
    oraCurenta = "Eroare";
    return oraCurenta;
  }
  char buffer[6];
  strftime(buffer, sizeof(buffer), "%H:%M", &timeinfo); // Format HH:MM
  oraCurenta = String(buffer);
   return oraCurenta;
}
