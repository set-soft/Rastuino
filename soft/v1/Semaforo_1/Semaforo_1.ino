/*
  Ejemplo de semáforo.
  Se conecta un bloque de LED rojo a la salida 1, uno amarillo a la salida 2 y
uno verde a la salida 3.
*/
int SAL1=10; /* Salida digital 1 Rojo */
int SAL2=9;  /* Salida digital 2 Amarillo */
int SAL3=6;  /* Salida digital 3 Verde */

void setup()
{/* Configurar las salidas 1 a 3 */
 pinMode(SAL1,OUTPUT);
 pinMode(SAL2,OUTPUT);
 pinMode(SAL3,OUTPUT);
}


void loop() 
{/* Rojo por 30 s */
 digitalWrite(SAL1,HIGH);
 delay(30000);
 /* Apagar el rojo y encender el amarillo por 2 s */
 digitalWrite(SAL1,LOW);
 digitalWrite(SAL2,HIGH);
 delay(2000);
 /* Apagar el amarillo y encender el verde por 30 s */
 digitalWrite(SAL2,LOW);
 digitalWrite(SAL3,HIGH);
 delay(30000);
 /* Apagar el verde y encender el amarillo por 2 s */
 digitalWrite(SAL3,LOW);
 digitalWrite(SAL2,HIGH);
 delay(2000);
 /* Apagar el amarillo */
 digitalWrite(SAL2,LOW);
}
