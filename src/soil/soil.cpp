#include <Arduino.h>

const int ANALOGIC_PIN = A0;

int getSoilInformation()
{

    int sensorValue = analogRead(ANALOGIC_PIN);
    long lowerMoistureSoil = 1023;
    long highMoistureSoil = 550;

    int percentageMoisture = map(sensorValue, lowerMoistureSoil, highMoistureSoil, 0, 100);

    Serial.print(F("Sensor Solo: "));
    Serial.println(percentageMoisture);

    return percentageMoisture;
} 