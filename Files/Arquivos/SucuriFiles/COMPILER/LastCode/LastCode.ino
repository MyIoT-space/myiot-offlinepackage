#include "Funcs.h"

void setup(){
#define D13 13
pinMode(D13, OUTPUT);
int A0 = A0;


}
void loop(){
    if(analogRead(A0) > 1023){
        digitalWrite(D13, HIGH);
    }



}
