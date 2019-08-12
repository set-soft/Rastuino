#include <Rastuino.h>

void setup()
{
  Inicializar();
}

void loop()
{
  Encender(1);
  Apagar(2);
  Apagar(3);
  delay( 1000 );
  Apagar(1);
  Encender(2);
  Apagar(3);
  delay( 1000 );
  Apagar(1);
  Apagar(2);
  Encender(3);
  delay( 1000 );
}


