#ifndef Rastuino_h
#define Rastuino_h

#include "Arduino.h"

/* Motores (L298N) */
#define IN1  2
#define IN2  4
#define ENA  3
#define IN3  7
#define IN4 17
#define ENB  5
/* Salidas */
#define SAL1 10
#define SAL2  9
#define SAL3  6
#define SAL4 18
/* Entradas */
#define ENT1 14
#define ENT2 15
#define ENT3 16
#define ENT4 19

/* Posibles modos para los motores: */
#define FRENO     0
#define DERECHA   1
#define IZQUIERDA 2

void Inicializar(void);

void Encender(int canal);
void Apagar(int canal);
void Invertir(int canal);
int  Leer(int canal);
int  LeerAnalogico(int canal);
void EscribirAnalogico(int canal, int valor);

void Esperar(int segundos);

void EsperarUnPulsador(int p1, int p2=0, int p3=0, int p4=0);

void CalibrarMotor(int motor, int full);
void Avanzar(int vel=255);
void Retroceder(int vel=255);
void GirarDerecha(int vel=255);
void GirarIzquierda(int vel=255);
void Frenar();
void ModoMotor(int motor, int modo);
void VelMotor(int motor, int valor);

/* Buzzer */
void SalidaBeep(int canal);
void Beep();

inline
void EsperarMilis(int miliSegundos)
{
 delay(miliSegundos);
}

#endif
