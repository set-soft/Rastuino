/*
  Ejemplo básico para destellar un LED usando la biblioteca de Rastuino.
  Un bloque LED debe estar conectado a la SAL1.
*/

#include <Rastuino.h>

void setup() 
{
 Inicializar();
}

void loop() 
{
 Encender(1);
 EsperarMilis(500);
 Apagar(1);
 EsperarMilis(500);
} 
