#include "Funcs.h"

void mover_motor1(int pino1, int pino2, int dir)
{
  if(dir==0){
    digitalWrite(pino1, LOW);
    digitalWrite(pino2, LOW);
  }
  else if(dir==1){
    digitalWrite(pino1, LOW);
    digitalWrite(pino2, HIGH);
  }
  else if(dir==2){
    digitalWrite(pino1, HIGH);
    digitalWrite(pino2, LOW);
  }
}

void mover_motor2(int pino1, int pino2, int dir)
{
  if(dir==0){
    digitalWrite(pino1, LOW);
    digitalWrite(pino2, LOW);
  }
  else if(dir==1){
    digitalWrite(pino1, LOW);
    digitalWrite(pino2, HIGH);
  }
  else if(dir==2){
    digitalWrite(pino1, HIGH);
    digitalWrite(pino2, LOW);
  }
}

void setup(){





pinMode(4, OUTPUT);
pinMode(5, OUTPUT);

pinMode(7, OUTPUT);
pinMode(6, OUTPUT);


}
void loop(){
mover_motor1(5, 4, 2);
mover_motor2(6, 7, 2);
    delay(2.00*1000.0);
mover_motor1(5, 4, 2);
mover_motor2(6, 7, 1);
    delay(0.50*1000.0);


}
