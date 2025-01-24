
#include "main.h"

// Configurare Wi-Fi
char ssid[] = "TP-Link_F6B8";      // Numele rețelei Wi-Fi
char pass[] = "21580260";    // Parola rețelei Wi-Fi
char auth[] = "HdYxokz-8EgYdvi-BKrlZyaOgi1jkr27";    // Tokenul primit de la Blynk

// Configurații NTP
char* ntpServer = "pool.ntp.org";
long gmtOffset_sec = 7200;    // Fus orar România (+2 ore)
int daylightOffset_sec = 3600; // Ora de vară (1 oră)
String oraCurenta;


// Funcția pentru obținerea timpului curent de la NTP
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


void setup() {
  Serial.begin(115200);
  
  WiFi.begin(ssid, pass);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Conectare la Wi-Fi...");
  }
  Serial.println("Conectat la Wi-Fi!");
  
  configTime(gmtOffset_sec, daylightOffset_sec, ntpServer);
  
  initBlynk();                  // Configurare Blynk
  initDHT11();         
  initReleu();                  // Configurare Releu
}

void loop() {
  
  static unsigned long lastTempUpdate = 0;
  
  runBlynk();                  
  if(workMode){
    tempAutoControl();
  }
  if (millis() - lastTempUpdate > 5000) { // Actualizare la fiecare 5 min
    lastTempUpdate = millis();
    tempRead();
  }
  delay(200);
 
}
