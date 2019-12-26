#include <LPH8731.h>
/*
-------------------------------
  CS                      PD2 
  RESET                   PD3
  RS                      PD4
  CLK                     PD5 
  DATA                    PD6
-------------------------------
------------------------------------------------------------------------
LcdStringPrint(String,  PosX,  PosY,  CharCollor,  CharFon, length(distance)); 
------------------------------------------------------------------------
*/

void setup() {
 LcdInitt();
LcdStringPrint("Kostyaskiy Company", 0, 0, VIOLET , 0, 0);
LcdStringPrint("----------------------", 0, -15, YELLOW , 0, 0);
LcdStringPrint("Hello World", 0, -30, DARK_BLUE, 0, 0);
LcdStringPrint("Library for LPH", 0, -45, BLUE , 0, 0);
LcdStringPrint("Atmega328", 10, -60, ORANGE, 0, 0);
LcdStringPrint("----------------------", 0, -75, RED , 0, 0);
LcdStringPrint("AVR power", -20, -90, RED, 0, 0);
LcdStringPrint("ON", 0, -105,GREEN, 0, 2);
LcdStringPrint("----------", 0, -120,WHITE, 0, 2);
LcdStringPrint("OFF", 0, -135,RED, 0, 0);
}

void loop() {
 while(1) //для ускорения работы кода 
{
      
   }
}
