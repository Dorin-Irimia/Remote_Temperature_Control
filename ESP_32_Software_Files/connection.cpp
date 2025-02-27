#include "connection.h"

void reconnect() {
  while (!client.connected()) {
    Serial.print("Încercare de conectare la MQTT...");
    if (client.connect(mqtt_client_id)) {
      Serial.println("Conectat la MQTT!");
      client.subscribe(topic_control);
      client.subscribe(topic_work_mode);
      client.subscribe(topic_clock_start);
      client.subscribe(topic_clock_stop);
    } else {
      Serial.print("Eșec, cod de eroare = ");
      Serial.print(client.state());
      Serial.println(" Încercare din nou în 5 secunde...");
      delay(2000);
    }
  }
}


void callback(char* topic, byte* payload, unsigned int length) {
  Serial.print("Mesaj primit pe topicul: ");
  Serial.println(topic);
  Serial.print("Mesaj: ");
  for (int i = 0; i < length; i++) {
    Serial.print((char)payload[i]);
  }
  Serial.println();

  if (strcmp(topic, topic_control) == 0) {
    if (strncmp((char*)payload, "aprinde", length) == 0) {
      relayState = 1;
      remoteWorkMode = 0;
      Serial.println(relayState);
    } else if (strncmp((char*)payload, "stinge", length) == 0) {
      relayState = 0;
      remoteWorkMode = 0;
      Serial.println(relayState);
    }
  }

  char time_str[6]; // Buffer to hold the time string
  int hours, minutes;
    
   if (strcmp(topic, topic_clock_start) == 0) {
        startTime = ""; // Initialize an empty String
        for (int i = 0; i < length; i++) {
            startTime += (char)payload[i]; // Append each character to the String
        }
        Serial.print("Ora de start primită: ");
        Serial.println(startTime);
    }

    if (strcmp(topic, topic_clock_stop) == 0) {
        stopTime = ""; // Initialize an empty String
        for (int i = 0; i < length; i++) {
            stopTime += (char)payload[i]; // Append each character to the String
        }
        Serial.print("Ora de stop primită: ");
        Serial.println(stopTime);
    }

  if (strcmp(topic, topic_work_mode) == 0) {
    if (strncmp((char*)payload, "AUTOMAT", length) == 0) {
      Serial.println("MOD_LUCRU_AUTOMAT");
      remoteWorkMode = 1;
    } else if (strncmp((char*)payload, "MANUAL", length) == 0) {
      Serial.println("MOD_LUCRU_MANUAL");
      remoteWorkMode = 0;
      relayState = 0;
    }
  }
}


void publishData() {
  if(relayState == 1){
      client.publish(topic_date, String("Releu este Aprins").c_str());
      Serial.println("Date publicate!_APRINS");
  }
  if(relayState == 0){
      client.publish(topic_date, String("Releu este Stins").c_str());
      Serial.println("Date publicate!_STINS");
  }
  if(remoteWorkMode == 1){
    client.publish(topic_data_work_mode, String("AUTOMAT").c_str());
  }
  if(remoteWorkMode == 0){
    client.publish(topic_data_work_mode, String("MANUAL").c_str());
  }
  if(remoteWorkMode == 555){
    client.publish(topic_data_work_mode, String(" EROARE  !!!").c_str());
  }

   client.publish(topic_data_clock_stored, (String(startTime)+ " - " +String(stopTime)).c_str());
 
}
