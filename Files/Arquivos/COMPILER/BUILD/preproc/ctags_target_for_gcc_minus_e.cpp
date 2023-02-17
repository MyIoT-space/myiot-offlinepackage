# 1 "E:\\Downloads\\PacoteMyIoTCompleto_V4\\Files\\Arquivos\\COMPILER\\Final\\Final.ino"

# 3 "E:\\Downloads\\PacoteMyIoTCompleto_V4\\Files\\Arquivos\\COMPILER\\Final\\Final.ino" 2
String serialrx;
long currentMillis;

// THREAD 1
 long T1timer = 0; int T1delay = 0; int T1nextFunc = 0;





void setup(){
    Serial.begin(9600);
    pinMode(2, 0x0);
    pinMode(3, 0x0);
    pinMode(4, 0x1);
    pinMode(5, 0x1);
    pinMode(6, 0x1);
    pinMode(7, 0x1);
    pinMode(8, 0x1);
    pinMode(9, 0x1);
    pinMode(10, 0x1);
    pinMode(11, 0x1);
    pinMode(12, 0x1);
    pinMode(13, 0x1);
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
        digitalWrite(10, 0x1);
        T1delay = 1*1000;
        T1timer = currentMillis;
        T1nextFunc = 1;
        goto T1End;
        T1_1:;
    }
    if(serialrx=="A"){
        digitalWrite(10, 0x0);
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
