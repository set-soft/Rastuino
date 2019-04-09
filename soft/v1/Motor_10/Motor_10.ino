/*
  Prueba de motores del Rastuino v1. Con la biblioteca.
  Usando el vehículo de tres ruedas.
  Espera a que se presione el pulsador en ENT3, luego:
  Avanza por 5 segundos, gira 180 grados y avanza otros 5 segundos.
*/

#include <Rastuino.h>

void setup()
{
 // Inicializa todas las entradas y salidas 
 Inicializar(); 
 // Calibra la diferencia de velocidad entre los motores
 CalibrarMotor(2,65); 
}

void loop() 
{
 EsperarUnPulsador(3);
 Avanzar();
 Esperar(5);
 GirarDerecha();
 EsperarMilis(1700);
 /* Avanzar por 5 segundos, para volver aprox. al punto de donde salió */
 Avanzar();
 Esperar(5);
 Frenar();
}
