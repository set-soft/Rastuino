/*
  Ejemplo básico para destellar un LED.
  La salida 13 es el LED interno del Arduino NANO.
  La salida 10 es la primer salida digital del Rastuino (cercana al USB del
  Arduino NANO)
  Este ejemplo utiliza funciones para que sea más claro.
 */

void Encender()
{
 digitalWrite(13,HIGH);
 digitalWrite(10,LOW);
}

void Apagar()
{
 digitalWrite(13,LOW);
 digitalWrite(10,HIGH);
}

void setup() 
{
 pinMode(13,OUTPUT);
 pinMode(10,OUTPUT);
}

void loop() 
{
 Encender();
 delay(500);
 Apagar();
 delay(500);
}
