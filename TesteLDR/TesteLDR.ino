// #include "Bibliotecas.h"
// Alimentação 3,3v. Pino: PWM ou analógico

int lightPin = 14; //define o pino para o foto resistor
int ledPin=11; //define o pino para o LED
void setup()
{
 Serial.begin(9600); //Inicia a comicacao com Monitor Serial
 pinMode( lightPin, INPUT );
}

void loop(){
  // Tem saída menor (90) pra mais claridade e saída maior (4500) para menos claridade. 
  Serial.println(analogRead(lightPin)); //Mostra o valor de leitura no Monitor Serial
  //analogWrite(ledPin, analogRead(lightPin)/4); //Envia o Valor de Leitura para o Pino do LED
  //Voce tem que dividir o valor por 2
  delay(500); //Tempo curto para acionamento do LED
}
