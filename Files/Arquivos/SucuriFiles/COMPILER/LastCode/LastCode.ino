#include "Funcs.h"

void setup(){
#define D2(BIP) 2
pinMode(D2(BIP), OUTPUT);
#define D9 9
pinMode(D9, INPUT);


}
void loop(){
    if(digitalRead(D9) == HIGH){
        digitalWrite(D2(BIP), HIGH);
        delay(1.00*1000.0);
    }

    digitalWrite(D2(BIP), LOW);
    delay(1.00*1000.0);


}
