int pinRele = 2;
int pinSensor = A0; 
int umidade;
int i = 0;
int soma=0;
int quantidade = 10;
int leitura = 0;

void setup(){
 Serial.begin(9600);
 pinMode(pinRele,OUTPUT); //Pino de saída para chavear relé
 pinMode(pinSensor,INPUT);
}
 
void loop() {
   soma = 0;
   for(i=0;i<quantidade;i++){
     leitura = analogRead(pinSensor);
     soma= soma + leitura;
     Serial.print("parcial:");
      Serial.println(leitura);
      delay(10);
   }
   umidade = soma/quantidade;
   //Umidade
   Serial.print("total:");
   Serial.println(umidade);

   if(umidade > 700){
     digitalWrite(pinRele, LOW);
     delay(1000);
   }
   else{
     //liga o pino vermelho, abre a mangueira
     digitalWrite(pinRele, HIGH);
     //delay de 1 minuto
     delay(2000);
   }
 
}

