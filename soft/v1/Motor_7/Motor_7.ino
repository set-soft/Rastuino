/*
  Prueba de motores del Rastuino v1.
  Usando el vehículo de tres ruedas, con un "paragolpes" que presiona dos
pulsadores y ayuda a detectar colisión.
  Espera a que se presione un botón en ENT3, indica con un LED en SAL1 que
está esperando.
  Luego avanza hasta que detecta colisión con pulsadores en ENT1 y ENT2.
*/
/* Definición de lo pines usados para el L298N */
int IN1=2; 
int IN2=4;
int ENA=3;  
int IN3=7; 
int IN4=17;
int ENB=5;
int SAL1=10; /* LED */
int ENT1=14; /* Pulsador de colisión 1 */
int ENT2=15; /* Pulsador de colisión 2 */
int ENT3=16; /* Pulsador de arranque */

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
 pinMode(SAL1,OUTPUT);
 /* Inicializa las entradas */
 pinMode(ENT1,INPUT);
 pinMode(ENT2,INPUT);
 pinMode(ENT3,INPUT);
 /* Ambos motores giran a derecha */
 ModoMotor(0,DERECHA);
 ModoMotor(1,DERECHA);
}

void loop() 
{
 /* Esperar el pulsador 3, indicar en un LED */
 digitalWrite(SAL1,HIGH);
 while (digitalRead(ENT3)==LOW);
 digitalWrite(SAL1,LOW);
 /* Ambos motores avanzan por 5 segundos.
    Uno de mis motores es mucho más lento que el otro (falla de fábrica?).
    Por ello uno tiene que ir al 40% de velocidad. */
 VelMotor(0,65);
 VelMotor(1,255);
 /* Esperar a colisionar */
 while (digitalRead(ENT1)==LOW && digitalRead(ENT2)==LOW);
 
 /* Apagar ambos motores */
 VelMotor(0,0);
 VelMotor(1,0);
}
