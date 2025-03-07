#ifndef CONNECTION_H
#define CONNECTION_H

#include <WiFi.h>
#include <PubSubClient.h>
#include <DHT.h>
#include <time.h>
#include <ArduinoJson.h>
#include <Arduino.h>

#define DHTPIN 4
#define DHTTYPE DHT11
#define RELAY_PIN 5
#define SWITCH_RELAY_PIN 2
#define SWITCH_MODE_PIN 3
#define LED_ORANGE  6
#define LED_GREEN  7

extern WiFiClient espClient;
extern PubSubClient client;

extern int relayState;
extern int remoteWorkMode;
extern float temperatura;

extern char* ntpServer;
extern long gmtOffset_sec;    
extern int daylightOffset_sec; 
extern String oraCurenta;
extern int ore, minute;

extern const char* ssid;
extern const char* password;


extern const char* mqtt_server;
extern const char* mqtt_client_id;


extern const char* topic_control;
extern const char* topic_date;
extern const char* topic_data_work_mode;
extern const char* topic_data_clock_stored;
extern const char* topic_temperatura;
extern const char* topic_clock_start;
extern const char* topic_clock_stop;
extern const char* topic_work_mode;


extern String startTime; 
extern String stopTime;
// Pinul releului (modifică dacă este necesar)


void reconnect();
void callback(char* topic, byte* payload, unsigned int length);
void publishData(); 

#endif
