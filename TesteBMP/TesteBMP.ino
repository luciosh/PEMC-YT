#include <Adafruit_BMP085.h>
#include <Wire.h>
Adafruit_BMP085 bmp180;
// Alimentação 3,3v. Pino: I2C - SDA-D21 e SCL-D22

void setup()
{
 Serial.begin(9600); //Inicia a comunicacao com Monitor Serial
 if (!bmp180.begin()) {
    Serial.println("Sensor nao encontrado!");
    while (1) {}
  }
}

void loop(){
  Serial.print("Temperatura : ");
  Serial.print(bmp180.readTemperature());
  Serial.println(" C");
  Serial.print("Altitude : ");
  Serial.print(bmp180.readAltitude());
  Serial.println(" m");
  Serial.print("Pressao : ");  
  Serial.print(bmp180.readPressure());
  Serial.println(" Pa");
  delay(2000); //Tempo curto para acionamento do LED
}
