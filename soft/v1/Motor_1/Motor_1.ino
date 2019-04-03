/*
  Prueba de motores del Rastuino v1.
  Utiliza el motor controlado por IN3/IN4/ENB.
  Lo hace girar en un sentido a diferentes velocidades, lo para e invierte el
sentido de giro.
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

/* Inicializa como salidas a todos los pines usados para el L298N */
void setup() 
{
 pinMode(IN1,OUTPUT);
 pinMode(IN2,OUTPUT);
 pinMode(ENA,OUTPUT);
 pinMode(IN3,OUTPUT);
 pinMode(IN4,OUTPUT);
 pinMode(ENB,OUTPUT);
}

void loop() 
{
 /* El motor 1 gira a la derecha */
 ModoMotor(1,DERECHA);
 /* Velocidad a 20% por 1 segundo */
 VelMotor(1,50);
 delay(1000);
 /* Velocidad a 40% por 1 segundo */
 VelMotor(1,100);
 delay(1000);
 /* Velocidad a 60% por 1 segundo */
 VelMotor(1,150);
 delay(1000);
 /* Velocidad a 40% por 1 segundo */
 VelMotor(1,100);
 delay(1000);
 /* Velocidad a 20% por 1 segundo */
 VelMotor(1,50);
 delay(1000);
 /* Frenar el motor por 1 segundo */
 ModoMotor(1,FRENO);
 delay(1000);
 /* El motor 1 gira a la izquierda por 5 segundos */
 ModoMotor(1,IZQUIERDA);
 delay(5000);
 /* Apagar el motor 1 por 1 segundo */
 VelMotor(1,0);
 delay(1000);
}
