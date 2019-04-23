/* 
 *  Ejemplo básico del "Bloque de Buzzer" con la biblioteca
 *  El bloque se coloca en SAL4.
 *  Toca un simple tono.
 */
 
#include <Rastuino.h>

void setup() 
{
 Inicializar();
 SalidaBeep(4);
 Beep();
}

void loop() 
{
}
