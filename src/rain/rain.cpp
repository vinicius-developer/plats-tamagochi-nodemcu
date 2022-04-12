#include <Arduino.h>

const int DIGITAL_PIN = D4;

int getRainInformation() {

    int rainInput = digitalRead(DIGITAL_PIN);

    Serial.print(F("Sensor Chuva: "));
    if(rainInput == 0) {
        Serial.println("chovendo");
    } else {
        Serial.println("sem chuva");
    }

    return rainInput;

}
