// Sensor de chuva com controlador LM393
const int pinoSensor = 14; //PINO DIGITAL UTILIZADO PELO SENSOR
//Ligar ao primeiro pino da esquerda do sensor, pino analógico
 
void setup(){
  Serial.begin(9600);
  pinMode(pinoSensor, INPUT); //DEFINE O PINO COMO ENTRADA
}
 
void loop(){
  if(analogRead(pinoSensor) > 1200){ //SE A LEITURA DO PINO FOR IGUAL A LOW, FAZ
      Serial.println("Sensor Seco");

      Serial.println(analogRead(pinoSensor));
  }else{ //SENÃO, FAZ
      Serial.println("Agua detectada");
      Serial.println(analogRead(pinoSensor));

  }
  delay(2000);
}
