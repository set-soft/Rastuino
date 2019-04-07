/*
  Ejemplo básico para encender 3 LEDs en secuencia.
 */

int SAL1=10; /* Salida digital 1 */
int SAL2=9;  /* Salida digital 2 */
int SAL3=6;  /* Salida digital 3 */

void setup()
{
 pinMode(SAL1,OUTPUT);
 pinMode(SAL2,OUTPUT);
 pinMode(SAL3,OUTPUT);
}

void loop() 
{
 digitalWrite(SAL1,HIGH);
 digitalWrite(SAL2,LOW);
 digitalWrite(SAL3,LOW);
 delay(1000);
 digitalWrite(SAL1,LOW);
 digitalWrite(SAL2,HIGH);
 digitalWrite(SAL3,LOW);
 delay(1000);
 digitalWrite(SAL1,LOW);
 digitalWrite(SAL2,LOW);
 digitalWrite(SAL3,HIGH);
 delay(1000);
}

