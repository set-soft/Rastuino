/*
  Prueba de motores del Rastuino v1.
  Usando el vehículo de tres ruedas, con un "paragolpes" que presiona dos
pulsadores y ayuda a detectar colisión.
  Espera a que se presione un botón en ENT3, indica con un LED en SAL1 que
está esperando.
  Luego avanza hasta que detecta colisión con pulsadores en ENT1 y ENT2.
*/

#include <Rastuino.h>

void setup()
{
 Inicializar();
 CalibrarMotor(1,65);
 SalidaBeep(4);
}

void loop() 
{
 // Esperar el pulsador 3, indicar en un LED 
 Encender(1);
 EsperarUnPulsador(3);
 Apagar(1);
 
 Avanzar();
 // Esperar a colisionar 
 EsperarUnPulsador(1,2); 
 Frenar();
 Beep();
}

