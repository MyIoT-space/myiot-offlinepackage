#include "Funcs.h"


void setup(){


#define D11 11
pinMode(D11, OUTPUT);

Serial.begin(9600);


}
void loop(){
    if(ler_serial() == 'A'){
        digitalWrite(D11, HIGH);
        delay(1.00*1000.0);
    }

    digitalWrite(D11, LOW);
    delay(1.00*1000.0);


}
