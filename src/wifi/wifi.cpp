#include <WiFiClientSecure.h>
#include <PubSubClient.h>
#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <secrets.h>

// wifi
WiFiClient wifiClient;

// mqtt
const char *mqtt_broker = "192.168.1.109";
PubSubClient client(wifiClient);

// topics
const char* topicTemperature = "1/temperature";
const char* topicHumidity = "1/humidity";
const char* topicRain = "1/rain";
const char* topicSoil = "1/soil";

// lastValues
int lastValueRain;
int lastValueSoil;
int lastValueTemperature;
int lastValueHumidity;

void connectToWiFi()
{

  WiFi.begin(ssid, pass);

  Serial.println("Connecting: ");
  Serial.println(ssid);

  while (WiFi.status() != WL_CONNECTED)
  {
    Serial.print(".");
    delay(1000);
  }

  Serial.println("conectado");
}

void setMqttServer()
{
  Serial.println("Conectando MQTT");

  client.setServer(mqtt_broker, 1883);

  Serial.println("Conectado");
}

void reconnectMqttServer()
{

  while (!client.connected())
  {
    client.connect(clientId);
  }

}

void sendInformationForTopic(const char* topic, int *lastValue, int value) 
{
  if(*lastValue != value) {
    client.publish(topic, String(value).c_str(), true);
  }

  *lastValue = value;
}

void sendInformationForMqtt(int isRain, int soil, int temperature, int humidity)
{

  reconnectMqttServer();

  sendInformationForTopic(topicRain, &lastValueRain, isRain);

  sendInformationForTopic(topicSoil, &lastValueSoil, soil);

  sendInformationForTopic(topicTemperature, &lastValueTemperature, temperature);

  sendInformationForTopic(topicHumidity, &lastValueHumidity, humidity);
}
