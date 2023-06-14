


/**********************************************************************/
// FUNÇÃO PARA LEITURA DA SERIAL
/***********************************************************************/
const byte numChars = 32;
char receivedChars[numChars]; // an array to store the received data
String serialrx;

String ler_serial() {
  static byte ndx = 0;
  char rc;

  while (Serial.available() > 0) {
    rc = Serial.read();

    if (rc != '\n' && rc != '\r') {
      receivedChars[ndx] = rc;
      ndx++;
      if (ndx >= numChars) {
        ndx = numChars - 1;
      }
    }
    else {
      receivedChars[ndx] = '\0'; // terminate the string
      ndx = 0;
//      Serial.println(receivedChars);
      serialrx = String(receivedChars);
      return serialrx;
    }
  }

  return "";
  
}





/**********************************************************************/
// FUNÇÃO PARA LEITURA DO ULTRASSONICO
/***********************************************************************/

long OnTime = 10; //microseconds of on-time
long OffTime = 2; //microseconds of off-time
int triggerState = LOW; // triggerState used to set it up
int lastRead = 0;
unsigned long previousMicros = 0;
int ler_ultrassonico(int trigPin, int echoPin) {

  unsigned long currentMicros = micros();
  if ((triggerState == LOW) && (currentMicros - previousMicros >= OffTime))
  {
    triggerState = HIGH; // turn it on
    previousMicros = currentMicros; // remember the time
    digitalWrite(trigPin, triggerState); // update the actual trigger
  }
  else if ((triggerState == HIGH) && (currentMicros - previousMicros >= OnTime))
  {
    triggerState = LOW; // turn it off
    previousMicros = currentMicros; // remember the time
    digitalWrite(trigPin, triggerState); // update the actual trigger
  }
  int leitura = pulseIn(echoPin, HIGH, 50000) / 58;

  if ( leitura != 0 ) {
    lastRead = leitura;
  }

  return lastRead;

}

void mover_motor_ponteH_1(int fio1, int fio2, int dir) {
  if (dir == 0) {
    digitalWrite(fio1, LOW);   // Desligar
    digitalWrite(fio2, LOW);
  }
  if (dir == 1) {
    digitalWrite(fio1, HIGH);  // Frente
    digitalWrite(fio2, LOW);
  }
  if (dir == 2) {
    digitalWrite(fio1, HIGH);  // Reverso
    digitalWrite(fio2, HIGH);
  }
}

void mover_motor_ponteH_2(int fio1, int fio2, int dir) {
  if (dir == 0) {
    digitalWrite(fio1, LOW);   // Desligar
    digitalWrite(fio2, LOW);
  }
  if (dir == 1) {
    digitalWrite(fio1, HIGH);  // Frente
    digitalWrite(fio2, LOW);
  }
  if (dir == 2) {
    digitalWrite(fio1, LOW);   // Reverso
    digitalWrite(fio2, HIGH);
  }
}
