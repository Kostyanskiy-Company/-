/*
 //------------------------------------------------------------------------------------
 The library is written: Kostyanskiy.
 This is a confidential product and does not apply. This is a fast library version 2.0
 //------------------------------------------------------------------------------------
 Библиотека написана: Kostyanskiy.
 Это конфедициальный продукт и не распространяется. Это быстрая билиотека версиие 2.0 
 */

#ifndef LPH8731_h
#define LPH8731_h
#include <Arduino.h>
#include <avr/io.h>
//для ускорения работы 

#define LCD_CS PD2
#define LCD_RESET PD3
#define LCD_RS PD4
#define LCD_CLK PD5
#define LCD_DATA PD6

//-------------------------------------------------------------------
#define GREEN       0x1C
#define DARK_GREEN  0x15
#define RED         0xE0
#define BLUE        0x1F
#define DARK_BLUE   0x03
#define YELLOW      0xFC
#define ORANGE      0xEC
#define VIOLET      0xE3
#define WHITE       0xFF
#define BLACK       0x00
#define GREY        0x6D
// ---------------------------------------------------------------
 //Определяем значения  вкл/выкл пинов
#define LCD_CLK_ON      PORTD |= _BV(LCD_CLK); // HIGH
#define LCD_CLK_OFF     PORTD &= ~ _BV(LCD_CLK); // LOW
#define LCD_RS_ON       PORTD |= _BV(LCD_RS); // HIGH
#define LCD_RS_OFF      PORTD &= ~ _BV(LCD_RS); // LOW
#define LCD_CS_OFF      PORTD &= ~ _BV(LCD_CS); // LOW
#define LCD_CS_ON       PORTD |= _BV(LCD_CS); // HIGH
#define LCD_RESET_ON    PORTD |= _BV(LCD_RESET); // HIGH
#define LCD_RESET_OFF   PORTD &= ~ _BV(LCD_RESET); // LOW
/////////////////////////////////////////////////////////////////////
#define DAT 1  
#define CMD 0
//-------------------------------------------------------------------   
//обьявление
void SendLcd(unsigned char RS, unsigned char data);//портирована
void ResetSoftwareDispay();
void LcdFill(int Collor);
void LcdInitt();
void SetArea(char x1, char x2, char y1, char y2);
void SendImage (char x, char y, char width, char height, char *img, int rot);  
void LcdPixel(int PosX, int PosY, int Collor);
void LcdCharPrint(int Chh, int PosX, int PosY, int CharCollor, int CharFon);
void LcdStringPrint(char *str, int PosX, int PosY, int CharCollor, int CharFon, float zoom_width);
#endif