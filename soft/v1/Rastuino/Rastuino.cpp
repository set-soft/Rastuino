#include "Rastuino.h"

static int fullMotor1=256;
static int fullMotor2=256;

void Inicializar()
{
 /* Inicializa como salidas a todos los pines usados para el L298N */
 pinMode(IN1,OUTPUT);
 pinMode(IN2,OUTPUT);
 pinMode(ENA,OUTPUT);
 pinMode(IN3,OUTPUT);
 pinMode(IN4,OUTPUT);
 pinMode(ENB,OUTPUT);
 /* Inicializar las salidas */
 pinMode(SAL1,OUTPUT);
 pinMode(SAL2,OUTPUT);
 pinMode(SAL3,OUTPUT);
 pinMode(SAL4,OUTPUT);
 /* Inicializar las entradas */
 pinMode(ENT1,INPUT);
 pinMode(ENT2,INPUT);
 pinMode(ENT3,INPUT);
 pinMode(ENT4,INPUT);
}

static char canalesSal[]={SAL1,SAL2,SAL3,SAL4};
static char canalesEnt[]={ENT1,ENT2,ENT3,ENT4};

void Encender(int canal)
{
 if (canal<1 || canal>4) return;
 digitalWrite(canalesSal[canal-1],HIGH);
}

void Apagar(int canal)
{
 if (canal<1 || canal>4) return;
 digitalWrite(canalesSal[canal-1],LOW);
}

void Invertir(int canal)
{
 if (canal<1 || canal>4) return;
 digitalWrite(canalesSal[canal-1],!digitalRead(canalesSal[canal-1]));
}

int Leer(int canal)
{
 if (canal<1 || canal>4) return LOW;
 return digitalRead(canalesEnt[canal-1]);
}

void Esperar(int segundos)
{
 delay(segundos*1000);
}

void EsperarUnPulsador(int p1, int p2, int p3, int p4)
{
 while (Leer(p1)==LOW && Leer(p2)==LOW && Leer(p3)==LOW && Leer(p4)==LOW);
}

void CalibrarMotor(int motor, int full)
{
 if (motor==1)
    fullMotor1=full;
 else
    fullMotor2=full;
}

void Avanzar(int vel)
{
 /* Ambos motores giran a derecha */
 ModoMotor(1,DERECHA);
 ModoMotor(2,DERECHA);
 /* Encender ambos */
 VelMotor(1,vel);
 VelMotor(2,vel);
}

void Retroceder(int vel)
{
 /* Ambos motores giran a derecha */
 ModoMotor(1,IZQUIERDA);
 ModoMotor(2,IZQUIERDA);
 /* Encender ambos */
 VelMotor(1,vel);
 VelMotor(2,vel);
}

void Frenar()
{
 ModoMotor(1,FRENO);
 ModoMotor(2,FRENO);
}

/* Selecciona el modo para uno de los motores */
void ModoMotor(int motor, int modo)
{
 if (motor==1)
   {
    digitalWrite(IN3,modo & 1);
    digitalWrite(IN4,modo & 2);
   }
 else
   {
    digitalWrite(IN1,modo & 1);
    digitalWrite(IN2,modo & 2);
   }
}

/* Selecciona la velocidad para uno de los motores */
void VelMotor(int motor, int vel)
{
 if (motor==1)
    analogWrite(ENB,(vel*fullMotor1)>>8);
 else
    analogWrite(ENA,(vel*fullMotor2)>>8);
}

static int salBeep=4;

void SalidaBeep(int canal)
{
 salBeep=canal;
}

void Beep()
{
 if (salBeep<1 || salBeep>4) return;
 tone(canalesSal[salBeep-1],1000,1000);
}
