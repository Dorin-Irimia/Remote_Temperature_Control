#include "connection.h"

float temperatura = 0.0;
int switchRelayState = 0;
int switchModeState = 0;
int relayState = 0;

DHT dht(DHTPIN, DHTTYPE);

char* ntpServer = "pool.ntp.org";
long gmtOffset_sec = 7200;    // Fus orar România (+2 ore)
int daylightOffset_sec = 3600; // Ora de vară (1 oră)
String oraCurenta;
int ore, minute;

// Datele rețelei Wi-Fi
const char* ssid = "MERCUSYS_1EDC";
const char* password = "39689597";

// Datele serverului MQTT
const char* mqtt_server = "test.mosquitto.org";
const char* mqtt_client_id = "ESP32Dorin";

// Topic-urile MQTT
const char* topic_control = "topic/control";
const char* topic_date = "topic/date";
const char* topic_data_work_mode = "topic/date_work_mode";
const char* topic_data_clock_stored = "topic/date_clock_stored";
const char* topic_temperatura = "topic/temperatura";
const char* topic_clock_start = "topic/clock_start";
const char* topic_clock_stop = "topic/clock_stop";
const char* topic_work_mode = "topic/work_mode";


String startTime = "07:00"; // Initialize with default values
String stopTime = "8:20";
// Pinul releului (modifică dacă este necesar)



WiFiClient espClient;
PubSubClient client(espClient);

void setup() {
  Serial.begin(115200);
  pinMode(RELAY_PIN, OUTPUT);
  digitalWrite(RELAY_PIN, LOW); 

  pinMode(SWITCH_RELAY_PIN, INPUT);
  pinMode(SWITCH_MODE_PIN, INPUT);

  pinMode(LED_ORANGE, OUTPUT);
  digitalWrite(LED_ORANGE, LOW); 
  pinMode(LED_GREEN, OUTPUT);
  digitalWrite(LED_GREEN, LOW); 


  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Conectare la Wi-Fi...");
  }

  client.setServer(mqtt_server, 1883);
  client.setCallback(callback);
 
  dht.begin();
  
  configTime(gmtOffset_sec, daylightOffset_sec, ntpServer);
}

void loop() {
  tempRead();
  switchModeState = digitalRead(SWITCH_MODE_PIN);
  if(switchModeState == Low){
    static unsigned long startManualTime = 0;
    switchRelayState = digitalRead(SWITCH_RELAY_PIN);
    if((switchRelayState == Low) && (millis() - startManualTime < 1800000)){
      digitalWrite(RELAY_PIN, HIGH); 
      digitalWrite(LED_ORANGE, HIGH);
      startManualTime = millis();
      if(temperatura > 18){
        digitalWrite(RELAY_PIN, LOW); 
      }
    }
    else if(switchRelayState == HIGH){
      digitalWrite(RELAY_PIN, LOW); 
      digitalWrite(LED_ORANGE, LOW);
      startManualTime = 0;
    }
    else{
      digitalWrite(RELAY_PIN, LOW);
      digitalWrite(LED_ORANGE, !digitalRead(LED_ORANGE));
      delay(100);
    }
  }

  if(temperatura < 3)
  {
    while(temperatura < 5){
      digitalWrite(RELAY_PIN, HIGH); 
      digitalWrite(LED_ORANGE, !digitalRead(LED_GREEN));
      digitalWrite(LED_GREEN, !digitalRead(LED_ORANGE));
    }
    
  }

  if (!client.connected()) {
    reconnect();
  }
  client.loop();

  static unsigned long lastPublishTime = 0;
  if (millis() - lastPublishTime > 500) {
    publishData();
    lastPublishTime = millis();
  }

}





void tempRead() {
  temperatura = dht.readTemperature();
  if (isnan(temperatura) || temperatura < 0 || temperatura > 40) {
    Serial.println("Eroare la citirea senzorului DHT sau temperatură in afara intervalului!");
    temperatura = 999; // Marcaj pentru eroare
    return;
  }
  Serial.print(temperatura);
  Serial.println(" ^C");
}

String getOraCurenta() {
  struct tm timeinfo;
  if (!getLocalTime(&timeinfo)) {
    Serial.println("Nu pot obține ora!        ERROR");
    oraCurenta = "0000      ERROR";
    return oraCurenta;
  }
  char buffer[6];
  strftime(buffer, sizeof(buffer), "%H:%M", &timeinfo); // Format HH:MM
  oraCurenta = String(buffer);
  Serial.println(oraCurenta);
  return oraCurenta;
}

  // bool auto_state = Fals
autoRun(){
  String _ora = getOraCurenta();
  int _h = _ora.substring(0,2).toInt();
  int difference = abs(_h - startClock);
  if(auto_state == True){
    if((temperatura < 3))

  }
}


void tempAutoControl(){
  String _ora = getOraCurenta();
  int _h = _ora.substring(0,2).toInt();
  int difference = abs(_h - startClock);
  Serial.print("diferenta de ore este = ");
  Serial.println(difference);
  if((temperatura < 24) && (0 <=  difference <= (stopClock - startClock))){
    releuState(ON);
  }
  else if(25 < temperatura < 50){
    releuState(OFF);
  }
  else{
    releuState(OFF);
  }
}