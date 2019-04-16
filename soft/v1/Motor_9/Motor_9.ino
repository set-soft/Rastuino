/*
  Uso de motores del Rastuino v1. Con la biblioteca.
  Usando el vehículo de tres ruedas, con un "paragolpes" que presiona dos
pulsadores y ayuda a detectar colisión.
  Espera a que se presione un botón en ENT3, indica con un LED en SAL1 que
está esperando.
  Luego avanza hasta que detecta colisión con pulsadores en ENT1 y ENT2.
  Al detectar colisión hace sonar un buzzer en SAL4 y vuelve a esperar que
se presione el botón de ENT3.  
*/

#include <Rastuino.h>

void setup()
{
 // Inicializa todas las entradas y salidas 
 Inicializar(); 
 // Calibra la diferencia de velocidad entre los motores
 CalibrarMotor(2,190); 
 // Informa a la biblioteca que el buzzer está en SAL4
 SalidaBeep(4);
}

void loop() 
{
 // Esperar el pulsador 3, indicar en un LED en SAL1
 Encender(1);
 EsperarUnPulsador(3);
 Apagar(1);
 
 Avanzar();
 // Esperar a colisionar 
 EsperarUnPulsador(1,2); 
 Frenar();
 Beep();
}

