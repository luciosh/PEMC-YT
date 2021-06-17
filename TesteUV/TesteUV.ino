// Sensor UVM-30A

int pinSensorUV =  14;

// DECLARAÇÃO DE VARIÁVEIS	
int leituraUV=0; // VARIÁVEL PARA ARMAZENAR A LEITURA DA PORTA ANALÓGICA
byte indiceUV=0; // VARIÁVEL PARA ARMAZENAR A CONVERSÃO PARA INDICE UV

void setup() {
  Serial.begin(9600);
  pinMode(pinSensorUV, INPUT);
  
}

void loop() {

  
  leituraUV = analogRead(pinSensorUV); // REALIZA A LEITURA DA PORTA ANALÓGICA 
  indiceUV = map(leituraUV, 0,1200,0,11) ; // CONVERTE A FAIXA DE SINAL DO SENSOR DE 0V A 1V PARA O INDICE UV DE 0 A 10.  
  Serial.print("Indice UV: ");
  Serial.println(indiceUV);
  Serial.println(leituraUV);

  delay(500); // DELAY PARA APROXIMAR AS MEDIDAS DO TEMPO DE RESPOSTA DO SENSOR DE 500 mS
}
