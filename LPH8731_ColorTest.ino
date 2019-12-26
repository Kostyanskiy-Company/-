#include <LPH8731.h>
/*
-------------------------------
  CS                      PD2 
  RESET                   PD3
  RS                      PD4
  CLK                     PD5 
  DATA                    PD6
-------------------------------
*/

void setup() {
 LcdInitt();
}

void loop() {
 while(1) //для ускорения работы кода 
{
LcdFill(GREEN);
LcdFill(DARK_GREEN);
LcdFill(RED);
LcdFill(BLUE);
LcdFill(DARK_BLUE);
LcdFill(YELLOW);
LcdFill(ORANGE);
LcdFill(VIOLET);
LcdFill(WHITE);  
LcdFill(BLACK);  
LcdFill(GREY);        
   }
}
