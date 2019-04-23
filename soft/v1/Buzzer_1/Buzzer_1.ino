/* 
 *  Ejemplo básico del "Bloque de Buzzer"
 *  El bloque se coloca en SAL4.
 *  Toca un simple tono.
 */

int SAL4=18;

void setup() 
{
 pinMode(SAL4,OUTPUT);
 // 1000 Hz 300 ms
 tone(SAL4,1000,300);
}

void loop() 
{
}
