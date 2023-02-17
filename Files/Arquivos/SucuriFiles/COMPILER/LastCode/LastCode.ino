#include "Funcs.h"


void setup(){


#define led 13
pinMode(led, OUTPUT);

Serial.begin(9600);


}
void loop(){
    if(ler_serial() == "A"){
        digitalWrite(led, HIGH);
    }

    if(ler_serial() == "a"){
        digitalWrite(led, LOW);
    }

    delay(0.50*1000.0);


}
