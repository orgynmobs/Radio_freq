typedef struct  {
uint8_t JoyIzq;
uint8_t JoyDer;
byte Botones ;   // estructura "JoYIzQButton JoyDerButton SW1 SW2  B1 B2 B3 B4"   
}InfoMando;

InfoMando MiMando;
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
Serial.println(sizeof( MiMando));
}

void loop() {
  // put your main code here, to run repeatedly:

}
