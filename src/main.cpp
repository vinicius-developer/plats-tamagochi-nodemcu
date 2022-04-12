#include <Arduino.h>
#include "air/air.h"
#include "soil/soil.h"
#include "rain/rain.h"
#include "wifi/wifi.h"
#include "display/display.h"

int soilReadInterval = 5 * 1000;

long lastSoilMillis = millis() + soilReadInterval;

int lastSoilRead = 0;

void setup()
{
    Serial.begin(9600);
    connectToWiFi();
    setMqttServer();
    setupEnvironmentSensor();
    setupDisplay();
}

void loop()
{

    if (millis() - lastSoilMillis > soilReadInterval)
    {
        reconnectMqttServer();

        int isRain = getRainInformation();

        int soil = getSoilInformation();

        int temperature = (int) getTemperature();

        int humidity = (int) getHumidity();

        selectBitmap(isRain, soil, humidity);

        sendInformationForMqtt(isRain, soil, temperature, humidity);

        lastSoilMillis = millis();
    }
}