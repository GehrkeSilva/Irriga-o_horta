int pinRele = 2;
int pinSensor = A0; 
int umidade;
void setup(){
 Serial.begin(9600);
 pinMode(pinRele,OUTPUT); //Pino de saída para chavear relé
 pinMode(pinSensor,INPUT);
}
 
void loop() {
 
   
   umidade = analogRead(pinSensor);
   //Umidade
   Serial.print("Umidade:");
   Serial.println(umidade);
   //digitalWrite(pinRele, HIGH); //Altera estado do pino
   //delay(1000);
   //digitalWrite(pinRele, LOW); //Altera estado do pino
   //delay(1000);
   //Se umidade menor que 300 == molhado
   if(umidade > 700){
     //delay de 10 minutos, 1000*60 == 1 minuto * 10 == 10 minutos
     digitalWrite(pinRele, LOW);
     delay(1000);
   }
   else{
     //liga o pino vermelho, abre a mangueira
     digitalWrite(pinRele, HIGH);
     //delay de 1 minuto
     delay(1000);
   }
 
}

