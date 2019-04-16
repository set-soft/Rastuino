/*
  Uso de motores del Rastuino v1. Con la biblioteca.
  Usando el vehículo de tres ruedas, con un "paragolpes" que presiona dos
pulsadores y ayuda a detectar colisión.
  Espera a que se presione un botón en ENT3, indica con un LED en SAL1 que
está esperando.
  Luego avanza hasta que detecta colisión con pulsadores en ENT1 y ENT2.
  Al detectar colisión retrocede, gira a la derecha y vuelve a avanzar.  
*/

#include <Rastuino.h>

void setup()
{
 // Inicializa todas las entradas y salidas 
 Inicializar(); 
 // Calibra la diferencia de velocidad entre los motores
 CalibrarMotor(2,190);
}

void loop() 
{
 // Esperar el pulsador 3, indicar en un LED en SAL1
 Encender(1);
 EsperarUnPulsador(3);
 Apagar(1);
 
 while (1)
   {
    Avanzar();
    // Esperar a colisionar 
    EsperarUnPulsador(1,2); 
    Frenar();
    // Retroceder:
    // Los cambios de sentido de giro hay que hacerlos con
    // cuidado para evitar que el consumo de corriente sea
    // excesivo y se resetee la CPU.
    delay(250);
    Retroceder(128);
    delay(1000);
    Frenar();
    delay(400);
    // Girar
    GirarDerecha();
    delay(700);
   }
}

