long OnTime = 10; //microseconds of on-time
long OffTime = 2; //microseconds of off-time
int triggerState = LOW; // triggerState used to set it up
int lastRead = 0;
unsigned long previousMicros = 0;
int ler_ultrassonico(int trigPin,int echoPin){

  unsigned long currentMicros = micros();
  if((triggerState == LOW) && (currentMicros - previousMicros >= OffTime))
   {
     triggerState = HIGH; // turn it on
     previousMicros = currentMicros; // remember the time
     digitalWrite(trigPin, triggerState); // update the actual trigger
   }
   else if((triggerState == HIGH) && (currentMicros - previousMicros >= OnTime))
   {
     triggerState = LOW; // turn it off
     previousMicros = currentMicros; // remember the time
     digitalWrite(trigPin, triggerState); // update the actual trigger
   }
  int leitura = pulseIn(echoPin, HIGH, 50000)/58;
  
  if ( leitura != 0 ){ lastRead = leitura; }
  
  return lastRead;
    
}

void mover_motor_ponteH_1(int fio1, int fio2, int dir){
    if (dir == 0){ digitalWrite(fio1, LOW);  digitalWrite(fio2, LOW);}  // Desligar
    if (dir == 1){ digitalWrite(fio1, HIGH); digitalWrite(fio2, LOW);}  // Frente
    if (dir == 2){ digitalWrite(fio1, HIGH); digitalWrite(fio2, HIGH);} // Reverso
}

void mover_motor_ponteH_2(int fio1, int fio2, int dir){
    if (dir == 0){ digitalWrite(fio1, LOW);  digitalWrite(fio2, LOW);}  // Desligar
    if (dir == 1){ digitalWrite(fio1, HIGH); digitalWrite(fio2, LOW);}  // Frente
    if (dir == 2){ digitalWrite(fio1, LOW);  digitalWrite(fio2, HIGH);} // Reverso


    
}
void servo(int x, int pin){
  int val = (x*10.25)+500;
  digitalWrite(pin,HIGH);
  delayMicroseconds(val);
  digitalWrite(pin,LOW);
  delay(10);
  }
