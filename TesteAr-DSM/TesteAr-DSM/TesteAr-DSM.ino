#include <Arduino.h>
#include <string.h>
// Pino Vermelho - OUTPUT | Pino Laranja - GND | Pino branco - VCC
byte buff[2];
int pin = 14; //DSM501A input D8

unsigned long duration;
unsigned long starttime;
unsigned long endtime;

unsigned long sampletime_ms     = 30000;
unsigned long lowpulseoccupancy = 0;

float ratio                     = 0;
float concentration             = 0;

void setup(){
    Serial.begin(9600);
    pinMode(14, INPUT);
    starttime = millis();
}

void loop(){
    duration = pulseIn(pin, LOW);
    lowpulseoccupancy += duration;
    endtime = millis();
    if ((endtime - starttime) > sampletime_ms){
        ratio = (lowpulseoccupancy - endtime + starttime + sampletime_ms) / (sampletime_ms * 10.0); // Integer percentage 0=>100
        concentration = 1.1 * pow(ratio, 3) - 3.8 * pow(ratio, 2) + 520 * ratio + 0.62;             // using spec sheet curve
        Serial.print("lowpulseoccupancy:");
        Serial.print(lowpulseoccupancy);
        Serial.print("\n");
        Serial.print("ratio:");
        Serial.print("\n");
        Serial.print(ratio);
        Serial.print("DSM501A:");
        Serial.println(concentration);
        Serial.print(";\n\n");

        lowpulseoccupancy = 0;
        starttime = millis();
    }
}
