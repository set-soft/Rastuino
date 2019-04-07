/*
  Prueba de motores del Rastuino v1.
  Usando el vehículo de tres ruedas.
  Avanza por 5 segundos, gira 180 grados y avanza otros 5 segundos.
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

void setup()
{
 int i;

 /* Inicializa como salidas a todos los pines usados para el L298N */
 pinMode(IN1,OUTPUT);
 pinMode(IN2,OUTPUT);
 pinMode(ENA,OUTPUT);
 pinMode(IN3,OUTPUT);
 pinMode(IN4,OUTPUT);
 pinMode(ENB,OUTPUT);
 /* Inicializa la salida 1 */
 pinMode(10,OUTPUT);
 /* Ambos motores giran a derecha */
 ModoMotor(0,DERECHA);
 ModoMotor(1,DERECHA);  

 /* Ambos motores avanzan por 5 segundos.
    Uno de mis motores es mucho más lento que el otro (falla de fábrica?).
    Por ello uno tiene que ir al 40% de velocidad. */
 VelMotor(0,102);
 VelMotor(1,255);
 /* Encender un LED */
 digitalWrite(10,HIGH);
 delay(5000);
 /* Apagar el motor 1, el 0 sigue avanzando.
    Con lo que el vehículo gira.
    En nuestro caso en 1,7 segundos gira unos 180 grados. */
 VelMotor(1,0);
 delay(1700);
 /* Avanzar por 5 segundos, para volver aprox. al punto de donde salió */
 VelMotor(1,255);
 delay(5000);


 /* Apagar ambos motores */
 VelMotor(0,0);
 VelMotor(1,0);
}

void loop() 
{   
}
