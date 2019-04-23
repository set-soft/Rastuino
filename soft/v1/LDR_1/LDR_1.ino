/*
 * Ejemplo básico del uso del Bloque LDR (Luz)
 * El Bloque LDR debe estar en ENT1 y un Bloque LED en SAL1
 * En este ejemplo si iluminamos el LDR con una linterna el LED
 * tiende a apagarse, por el contrario, si lo tapamos el LED
 * se enciende lo más fuerte posible.
 */

int SAL1=10;
int ENT1=14;

void setup() 
{
  pinMode(SAL1,OUTPUT);
  pinMode(ENT1,INPUT);
}

void loop() 
{
 analogWrite(SAL1,~analogRead(ENT1)/4);
}
