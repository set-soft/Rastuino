/*
  Ejemplo básico para leer un pulsador.
  Muestra su estado en el LED interno y en la salida 1.
  La salida 13 es el LED interno del Arduino NANO.
  La salida 10 es la primer salida digital del Rastuino (cercana al USB del
  Arduino NANO)
  La entrada 14 es la primer entrada del Rastuino (cercana al USB del
  Arduino NANO)
 */
int LED=13;
int SAL1=10;
int ENT1=14;

void setup()
{
 pinMode(LED,OUTPUT);
 pinMode(SAL1,OUTPUT);
 pinMode(ENT1,INPUT);
}

void loop() 
{
 int val; /* Variable para retener el valor leido */
 
 val=digitalRead(ENT1); /* Leer la entrada*/
 digitalWrite(LED,val); /* Copiarlo al LED interno*/
 digitalWrite(SAL1,val); /* y a la salida 1 */
 delay(50); /* Una demora arbitraria */
}
