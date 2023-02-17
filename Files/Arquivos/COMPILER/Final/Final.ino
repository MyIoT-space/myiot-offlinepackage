
#include "Funcs.h"
String serialrx;
long currentMillis;

// THREAD 1
 long T1timer = 0; int T1delay = 0; int T1nextFunc = 0;





void setup(){
    Serial.begin(9600);
    pinMode(2,  INPUT);
    pinMode(3,  INPUT);
    pinMode(4,  OUTPUT);
    pinMode(5,  OUTPUT);
    pinMode(6,  OUTPUT);
    pinMode(7,  OUTPUT);
    pinMode(8,  OUTPUT);
    pinMode(9,  OUTPUT);
    pinMode(10, OUTPUT);
    pinMode(11, OUTPUT);
    pinMode(12, OUTPUT);
    pinMode(13, OUTPUT);
    Serial.println("INICIO");
}
void loop(){
    currentMillis = millis();
    while ((Serial.available()>0))
    {
        serialrx = Serial.readStringUntil('\n');
        serialrx.trim();
    }
if (currentMillis - T1timer >= T1delay){ 

if (T1nextFunc == 1){ goto T1_1;}

if (T1nextFunc == 2){ goto T1_2;}
    if(serialrx=="a"){
        digitalWrite(10, HIGH);
        T1delay = 1*1000;
        T1timer = currentMillis;
        T1nextFunc = 1;
        goto T1End;
        T1_1:;
    }
    if(serialrx=="A"){
        digitalWrite(10, LOW);
        T1delay = 1*1000;
        T1timer = currentMillis;
        T1nextFunc = 2;
        goto T1End;
        T1_2:;
    }
T1nextFunc = 0;
}
T1End:;
serialrx="";}