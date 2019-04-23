/*
 * Ejemplo básico del uso del Bloque LDR (Luz) usando la biblioteca.
 * El Bloque LDR debe estar en ENT1 y un Bloque LED en SAL1
 * En este ejemplo si iluminamos el LDR con una linterna el LED
 * tiende a apagarse, por el contrario, si lo tapamos el LED
 * se enciende lo más fuerte posible.
 */

#include <Rastuino.h>

void setup() 
{
 Inicializar();
}

void loop() 
{
 EscribirAnalogico(1,~LeerAnalogico(1)/4);
}
