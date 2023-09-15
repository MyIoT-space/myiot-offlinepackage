#include "Funcs.h"


void setup(){


#define D13 13
pinMode(D13, OUTPUT);

Serial.begin(9600);


}
void loop(){
    if(ler_serial() == "a"){
        digitalWrite(D13, HIGH);
        delay(1.00*1000.0);
    }

    digitalWrite(D13, LOW);
    delay(2.00*1000.0);


}
