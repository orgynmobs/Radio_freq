#include "nRF24L01.h"
#include <RF24.h>
#include "RF24_config.h"
#include <SPI.h>


typedef struct  {
int JoyIzq;
int JoyDer;
byte Botones ;   // estructura "JoYIzQButton JoyDerButton SW1 SW2  B1 B2 B3 B4"   
}InfoMando;



 
const int pinCE = 9;
const int pinCSN = 10;
RF24 radio(pinCE, pinCSN);
 
// Single radio pipe address for the 2 nodes to communicate.
//const uint64_t pipe = 0xE8E8F0F0E1LL;
 byte direccion[5] ={'c','a','n','a','l'};
char data[16];
 InfoMando Mimando;
void setup(void)
{
   Serial.begin(115200);
   radio.begin();
   radio.openReadingPipe(0,direccion);
   radio.startListening();
}
 
void loop(void)
{
   if (radio.available())
   {
    radio.read(&Mimando, sizeof  Mimando);
       //radio.read(&data, sizeof data); 
Serial.print(" lectura Joystick izq: ");
Serial.println(Mimando.JoyIzq);
Serial.print(" lectura Joystick der: ");
Serial.println(Mimando.JoyDer);
Serial.print(" lectura botones: ");
Serial.println(Mimando.Botones);
   }
}
