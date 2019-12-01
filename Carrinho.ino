/* Mecatronic Car 3º Módulo Version 1.7.2
Projeto semestral, Carrinho por controle via Bluetooth */
  
#include <Servo.h>
Servo motor; 

//**** VARIABLES ******

char leitura;
int contador;

//Neon
const int neon=A3;

//Farol
const int farol1=A0;
const int farol2=A1;

//Lamp
const int lamp1=A4;
const int lamp2=A5;

//Buzzer
const int buzzer=8;

//1 Motor Control 
int in1=7;
int in2=6;
int m1=10;
int m2=11;

//2 Motor Control 
int in3=3;
int in4=2;
int m3=12;
int m4=13;

void setup (){
  
  pinMode(neon,1);
  pinMode(farol1,1);
  pinMode(farol2,1);
  pinMode(lamp1,1);
  pinMode(lamp2,1);
  pinMode(buzzer,1);
  pinMode(in1,1);
  pinMode(in2,1);
  pinMode(in3,1);
  pinMode(in4,1);
  pinMode(m1,1);
  pinMode(m2,1);
  pinMode(m3,1);
  pinMode(m4,1);

  //Serial
Serial.begin(9600);  
Serial.println("Digite uma tecla");

 //Servo Motor
motor.attach(9);
motor.write(90); 
}

void loop (){

    digitalWrite(neon,1);
    
if(Serial.available()>0){
leitura=Serial.read();
Serial.print("Tecla Digitada => ");
Serial.println(leitura);

 switch(leitura) {

  //Motor Front on
  case 'F' :
  digitalWrite(in1,1);
  digitalWrite(in2,0);
  digitalWrite(m1,1);
  digitalWrite(m2,0);
  digitalWrite(in3,0);
  digitalWrite(in4,1);
  digitalWrite(m3,0);
  digitalWrite(m4,1);
    motor.write(90);
   break;
   
    //Motor STOP 
  case 'S' :
  digitalWrite(in1,1);
  digitalWrite(in2,1);
  digitalWrite(in3,1);
  digitalWrite(in4,1);
  digitalWrite(m1,0);
  digitalWrite(m2,0);
  digitalWrite(m3,0);
  digitalWrite(m4,0);
    motor.write(90);
   break;

  //Motor Back 
  case 'B' :
  digitalWrite(in1,0);
  digitalWrite(in2,1);
  digitalWrite(m1,0);
  digitalWrite(m2,1);
  digitalWrite(in3,1);
  digitalWrite(in4,0);
  digitalWrite(m3,1);
  digitalWrite(m4,0);
    motor.write(90);
   break;

 //Left
case 'L' :
  digitalWrite(in1,1);
  digitalWrite(in2,0);
  digitalWrite(m1,1);
  digitalWrite(m2,0);
  digitalWrite(in3,0);
  digitalWrite(in4,1);
  digitalWrite(m3,0);
  digitalWrite(m4,1);
    motor.write(45);
   break;

 //Right
case 'R' :
  digitalWrite(in1,1);
  digitalWrite(in2,0);
  digitalWrite(m1,1);
  digitalWrite(m2,0);
  digitalWrite(in3,0);
  digitalWrite(in4,1);
  digitalWrite(m3,0);
  digitalWrite(m4,1);
    motor.write(135);
   break;

   
  //Back Left
     case 'H' :
  digitalWrite(in1,0);
  digitalWrite(in2,1);
  digitalWrite(m1,0);
  digitalWrite(m2,1);
  digitalWrite(in3,1);
  digitalWrite(in4,0);
  digitalWrite(m3,1);
  digitalWrite(m4,0);
  motor.write(45);
   break;

 //Back Right
  case 'J' :
  digitalWrite(in1,0);
  digitalWrite(in2,1);
  digitalWrite(m1,0);
  digitalWrite(m2,1);
  digitalWrite(in3,1);
  digitalWrite(in4,0);
  digitalWrite(m3,1);
  digitalWrite(m4,0);
  motor.write(135);
   break;

 // Foward Left
  case 'G' :
  digitalWrite(in1,1);
  digitalWrite(in2,0);
  digitalWrite(m1,1);
  digitalWrite(m2,0);
  digitalWrite(in3,0);
  digitalWrite(in4,1);
  digitalWrite(m3,0);
  digitalWrite(m4,1);
  motor.write(45);
   break;
 
 // Foward Right
  case 'I' :
  digitalWrite(in1,1);
  digitalWrite(in2,0);
  digitalWrite(m1,1);
  digitalWrite(m2,0);
  digitalWrite(in3,0);
  digitalWrite(in4,1);
  digitalWrite(m3,0);
  digitalWrite(m4,1);
  motor.write(135);
   break;

   
  //Headlights
   case 'W' : 
  digitalWrite(farol1,1);
  digitalWrite(farol2,1);
   break;

   case 'w' : 
  digitalWrite(farol1,0);
  digitalWrite(farol2,0);
   break;

  //Lamps
   case 'U' : 
  digitalWrite(lamp1,1);
  digitalWrite(lamp2,1);
   break;

   case 'u' : 
  digitalWrite(lamp1,0);
  digitalWrite(lamp2,0);
   break;

  //Buzzer
   case 'V' : 
   for(contador=0;contador<5;contador++){
  digitalWrite(buzzer,1);
   delay(200);
  digitalWrite(buzzer,0);
   delay(200);
   }
   break;

  //Flashes Alert
   case 'X' : 
   for(contador=0;contador<5;contador++){
  digitalWrite(lamp1,1);
  digitalWrite(lamp2,1);
  digitalWrite(farol1,1);
  digitalWrite(farol2,1);
   delay(200);
  digitalWrite(farol1,0);
  digitalWrite(farol2,0);
  digitalWrite(lamp1,0);
  digitalWrite(lamp2,0);
   delay(200);
   }
   break;
  
  }
 }
}
