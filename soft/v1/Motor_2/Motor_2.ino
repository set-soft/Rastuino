/*
  Prueba de motores del Rastuino v1.
  Utiliza ambos motores.
  Los va acelerando de 20 a 80% y luego desacelerando de 80 a 20%.
  Mientras uno acelera el otro desacelera.
*/
/* Definición de lo pines usados para el L298N */
int IN1=2; 
int IN2=4;
int ENA=3;  
int IN3=7; 
int IN4=17;
int ENB=5;

/* Posibles modos: */
int DERECHA=1;
int IZQUIERDA=2;
int FRENO=0;

/* Selecciona el modo para uno de los motores */
void ModoMotor(int motor, int modo)
{
 if (motor)
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
void VelMotor(int motor, int valor)
{
 if (motor) 
    analogWrite(ENB,valor);
 else
    analogWrite(ENA,valor);
}

/* Inicializa como salidas a todos los pines usados para el L298N. */
/* Ambos motores giran a la derecha. */
void setup() 
{
 pinMode(IN1,OUTPUT);
 pinMode(IN2,OUTPUT);
 pinMode(ENA,OUTPUT);
 pinMode(IN3,OUTPUT);
 pinMode(IN4,OUTPUT);
 pinMode(ENB,OUTPUT);
 ModoMotor(0,DERECHA);
 ModoMotor(1,DERECHA);  
}

void loop()
{ 
 int i;
 int motor=0;

 /* Acelerar de 20% a 80% el motor 1
    Desacelerar de 80% a 20% el motor 0 */
 for (i=50; i<200; i++)
    {
     VelMotor(1,i);
     VelMotor(0,255-i);
     delay(100);
    }
 /* Desacelerar de 80% a 20% el motor 1
    Acelerar de 20% a 80% el motor 0 */
 for (; i>50; i--)
    {
     VelMotor(1,i);
     VelMotor(0,255-i);
     delay(100);
    }
}
