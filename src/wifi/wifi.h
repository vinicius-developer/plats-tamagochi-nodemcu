#include <ESP8266WiFi.h>
#include <WiFiClientSecure.h>

void connectToWiFi();

void setMqttServer();

void reconnectMqttServer();

void sendInformationForMqtt(int isRain, int soil, int temperature, int humidity);