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
