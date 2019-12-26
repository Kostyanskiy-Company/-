#include "LPH8731.h"
#include <Arduino.h> // нужно для ардуино-функций
int i; //переменная для цикла
const byte PROGMEM CHR[256][5] = {
{0x00, 0x00, 0x00, 0x00, 0x00},  // (space)  0
{0x00, 0x00, 0x00, 0x00, 0x00}, // (space)  1
{0x00, 0x00, 0x00, 0x00, 0x00}, // (space)  2
{0x00, 0x00, 0x00, 0x00, 0x00}, // (space)  3
{0x00, 0x00, 0x00, 0x00, 0x00}, // (space)  4
{0x00, 0x00, 0x00, 0x00, 0x00}, // (space)  5
{0x00, 0x00, 0x00, 0x00, 0x00}, // (space)  6
{0x00, 0x00, 0x00, 0x00, 0x00}, // (space)  7
{0x00, 0x00, 0x00, 0x00, 0x00}, // (space)  8
{0x00, 0x00, 0x00, 0x00, 0x00}, // (space)  9
{0x00, 0x00, 0x00, 0x00, 0x00}, // (space)  10
{0x00, 0x00, 0x00, 0x00, 0x00}, // (space)  11
{0x00, 0x00, 0x00, 0x00, 0x00}, // (space)  12
{0x00, 0x00, 0x00, 0x00, 0x00}, // (space)  13
{0x00, 0x00, 0x00, 0x00, 0x00}, // (space)  14
{0x00, 0x00, 0x00, 0x00, 0x00}, // (space)  15
{0x00, 0x00, 0x00, 0x00, 0x00}, // (space)  16
{0x00, 0x00, 0x00, 0x00, 0x00}, // (space)  17
{0x00, 0x00, 0x00, 0x00, 0x00}, // (space)  18
{0x00, 0x00, 0x00, 0x00, 0x00}, // (space)  19
{0x00, 0x00, 0x00, 0x00, 0x00}, // (space)  20
{0x00, 0x00, 0x00, 0x00, 0x00}, // (space)  21
{0x00, 0x00, 0x00, 0x00, 0x00}, // (space)  22
{0x00, 0x00, 0x00, 0x00, 0x00}, // (space)  23
{0x00, 0x00, 0x00, 0x00, 0x00}, // (space)  24
{0x00, 0x00, 0x00, 0x00, 0x00}, // (space)  25
{0x00, 0x00, 0x00, 0x00, 0x00}, // (space)  26
{0x00, 0x00, 0x00, 0x00, 0x00}, // (space)  27
{0x00, 0x00, 0x00, 0x00, 0x00}, // (space)  28
{0x00, 0x00, 0x00, 0x00, 0x00}, // (space)  29
{0x00, 0x00, 0x00, 0x00, 0x00}, // (space)  30
{0x00, 0x00, 0x00, 0x00, 0x00}, // (space)  31
{0x00, 0x00, 0x00, 0x00, 0x00}, // (space)  32
{0x00, 0x00, 0x5F, 0x00, 0x00}, // !        33
{0x00, 0x07, 0x00, 0x07, 0x00}, // "        34
{0x14, 0x7F, 0x14, 0x7F, 0x14}, // #        35
{0x24, 0x2A, 0x7F, 0x2A, 0x12}, // $        36
{0x23, 0x13, 0x08, 0x64, 0x62}, // %        37
{0x36, 0x49, 0x55, 0x22, 0x50}, // &        38
{0x00, 0x05, 0x03, 0x00, 0x00}, // '        39
{0x00, 0x1C, 0x22, 0x41, 0x00}, // (        40
{0x00, 0x41, 0x22, 0x1C, 0x00}, // )        41
{0x08, 0x2A, 0x1C, 0x2A, 0x08}, // *        42
{0x08, 0x08, 0x3E, 0x08, 0x08}, // +        43
{0x00, 0x50, 0x30, 0x00, 0x00}, // 44
{0x08, 0x08, 0x08, 0x08, 0x08}, // -        45
{0x00, 0x30, 0x30, 0x00, 0x00}, // .        46
{0x20, 0x10, 0x08, 0x04, 0x02}, // /        47
{0x3E, 0x51, 0x49, 0x45, 0x3E}, // 0        48
{0x00, 0x42, 0x7F, 0x40, 0x00}, // 1        49
{0x42, 0x61, 0x51, 0x49, 0x46}, // 2        50
{0x21, 0x41, 0x45, 0x4B, 0x31}, // 3        51
{0x18, 0x14, 0x12, 0x7F, 0x10}, // 4        52
{0x27, 0x45, 0x45, 0x45, 0x39}, // 5        53
{0x3C, 0x4A, 0x49, 0x49, 0x30}, // 6        54
{0x01, 0x71, 0x09, 0x05, 0x03}, // 7        55
{0x36, 0x49, 0x49, 0x49, 0x36}, // 8        56
{0x06, 0x49, 0x49, 0x29, 0x1E}, // 9        57
{0x00, 0x36, 0x36, 0x00, 0x00}, // :        58
{0x00, 0x56, 0x36, 0x00, 0x00}, // ;        59
{0x00, 0x08, 0x14, 0x22, 0x41}, // <        60
{0x14, 0x14, 0x14, 0x14, 0x14}, // =        61
{0x41, 0x22, 0x14, 0x08, 0x00}, // >        62
{0x02, 0x01, 0x51, 0x09, 0x06}, // ?        63
{0x32, 0x49, 0x79, 0x41, 0x3E}, // @        64
{0x7E, 0x11, 0x11, 0x11, 0x7E}, // A        65
{0x7F, 0x49, 0x49, 0x49, 0x36}, // B        66
{0x3E, 0x41, 0x41, 0x41, 0x22}, // C        67
{0x7F, 0x41, 0x41, 0x22, 0x1C}, // D        68
{0x7F, 0x49, 0x49, 0x49, 0x41}, // E        69
{0x7F, 0x09, 0x09, 0x01, 0x01}, // F        70
{0x3E, 0x41, 0x41, 0x51, 0x32}, // G        71
{0x7F, 0x08, 0x08, 0x08, 0x7F}, // H        72
{0x00, 0x41, 0x7F, 0x41, 0x00}, // I        73
{0x20, 0x40, 0x41, 0x3F, 0x01}, // J        74
{0x7F, 0x08, 0x14, 0x22, 0x41}, // K        75
{0x7F, 0x40, 0x40, 0x40, 0x40}, // L        76
{0x7F, 0x02, 0x04, 0x02, 0x7F}, // M        77
{0x7F, 0x04, 0x08, 0x10, 0x7F}, // N        78
{0x3E, 0x41, 0x41, 0x41, 0x3E}, // O        79
{0x7F, 0x09, 0x09, 0x09, 0x06}, // P        80
{0x3E, 0x41, 0x51, 0x21, 0x5E}, // Q        81
{0x7F, 0x09, 0x19, 0x29, 0x46}, // R        82
{0x46, 0x49, 0x49, 0x49, 0x31}, // S        83
{0x01, 0x01, 0x7F, 0x01, 0x01}, // T        84
{0x3F, 0x40, 0x40, 0x40, 0x3F}, // U        85
{0x1F, 0x20, 0x40, 0x20, 0x1F}, // V        86
{0x7F, 0x20, 0x18, 0x20, 0x7F}, // W        87
{0x63, 0x14, 0x08, 0x14, 0x63}, // X        88
{0x03, 0x04, 0x78, 0x04, 0x03}, // Y        89
{0x61, 0x51, 0x49, 0x45, 0x43}, // Z        90
{0x00, 0x00, 0x7F, 0x41, 0x41}, // [        91
{0x02, 0x04, 0x08, 0x10, 0x20}, // "\"      92
{0x41, 0x41, 0x7F, 0x00, 0x00}, // ]        93
{0x04, 0x02, 0x01, 0x02, 0x04}, // ^        94
{0x40, 0x40, 0x40, 0x40, 0x40}, // _        95
{0x00, 0x01, 0x02, 0x04, 0x00}, // `        96
{0x20, 0x54, 0x54, 0x54, 0x78}, // a        97
{0x7F, 0x48, 0x44, 0x44, 0x38}, // b        98
{0x38, 0x44, 0x44, 0x44, 0x20}, // c        99
{0x38, 0x44, 0x44, 0x48, 0x7F}, // d        100
{0x38, 0x54, 0x54, 0x54, 0x18}, // e        101
{0x08, 0x7E, 0x09, 0x01, 0x02}, // f        102
{0x08, 0x14, 0x54, 0x54, 0x3C}, // g        103
{0x7F, 0x08, 0x04, 0x04, 0x78}, // h        104
{0x00, 0x44, 0x7D, 0x40, 0x00}, // i        105
{0x20, 0x40, 0x44, 0x3D, 0x00}, // j        106
{0x00, 0x7F, 0x10, 0x28, 0x44}, // k        107
{0x00, 0x41, 0x7F, 0x40, 0x00}, // l        108
{0x7C, 0x04, 0x18, 0x04, 0x78}, // m        109
{0x7C, 0x08, 0x04, 0x04, 0x78}, // n        110
{0x38, 0x44, 0x44, 0x44, 0x38}, // o        111
{0x7C, 0x14, 0x14, 0x14, 0x08}, // p        112
{0x08, 0x14, 0x14, 0x18, 0x7C}, // q        113
{0x7C, 0x08, 0x04, 0x04, 0x08}, // r        114
{0x48, 0x54, 0x54, 0x54, 0x20}, // s        115
{0x04, 0x3F, 0x44, 0x40, 0x20}, // t        116
{0x3C, 0x40, 0x40, 0x20, 0x7C}, // u        117
{0x1C, 0x20, 0x40, 0x20, 0x1C}, // v        118
{0x3C, 0x40, 0x30, 0x40, 0x3C}, // w        119
{0x44, 0x28, 0x10, 0x28, 0x44}, // x        120
{0x0C, 0x50, 0x50, 0x50, 0x3C}, // y        121
{0x44, 0x64, 0x54, 0x4C, 0x44}, // z        122
{0x00, 0x08, 0x36, 0x41, 0x00}, // {        123
{0x00, 0x00, 0x7F, 0x00, 0x00}, // |        124
{0x00, 0x41, 0x36, 0x08, 0x00}, // }        125
{0x00, 0x00, 0x00, 0x00, 0x00}, // (space)  126
{0x00, 0x00, 0x00, 0x00, 0x00}, // (space)  127
{0x00, 0x00, 0x00, 0x00, 0x00}, // (space)  128
{0x00, 0x00, 0x00, 0x00, 0x00}, // (space)  129
{0x00, 0x00, 0x00, 0x00, 0x00}, // (space)  130
{0x00, 0x00, 0x00, 0x00, 0x00}, // (space)  131
{0x00, 0x00, 0x00, 0x00, 0x00}, // (space)  132
{0x00, 0x00, 0x00, 0x00, 0x00}, // (space)  133
{0x00, 0x00, 0x00, 0x00, 0x00}, // (space)  134
{0x00, 0x00, 0x00, 0x00, 0x00}, // (space)  135
{0x00, 0x00, 0x00, 0x00, 0x00}, // (space)  136
{0x00, 0x00, 0x00, 0x00, 0x00}, // (space)  137
{0x00, 0x00, 0x00, 0x00, 0x00}, // (space)  138
{0x08, 0x1C, 0x2A, 0x08, 0x08}, // <-      139
{0x00, 0x00, 0x00, 0x00, 0x00}, // (space)  140
{0x00, 0x00, 0x00, 0x00, 0x00}, // (space)  141
{0x00, 0x00, 0x00, 0x00, 0x00}, // (space)  142
{0x00, 0x00, 0x00, 0x00, 0x00}, // (space)  143
{0x00, 0x00, 0x00, 0x00, 0x00}, // (space)  144
{0x00, 0x00, 0x00, 0x00, 0x00}, // (space)  145
{0x00, 0x00, 0x00, 0x00, 0x00}, // (space)  146
{0x00, 0x00, 0x00, 0x00, 0x00}, // (space)  147
{0x00, 0x00, 0x00, 0x00, 0x00}, // (space)  148
{0x00, 0x00, 0x00, 0x00, 0x00}, // (space)  149
{0x00, 0x00, 0x00, 0x00, 0x00}, // (space)  150
{0x00, 0x00, 0x00, 0x00, 0x00}, // (space)  151
{127, 65, 65, 65, 127},          //Пустой квадрат  152
{127, 127, 127, 127, 127},      //Заполн квадрат  153
{0x00, 0x00, 0x00, 0x00, 0x00}, // (space)  154
{28, 127, 62, 28, 8},              // ->       155
{0x00, 0x00, 0x00, 0x00, 0x00}, // (space)  156
{0x00, 0x00, 0x00, 0x00, 0x00}, // (space)  157
{0x00, 0x00, 0x00, 0x00, 0x00}, // (space)  158
{0x00, 0x00, 0x00, 0x00, 0x00}, // (space)  159
{0x00, 0x00, 0x00, 0x00, 0x00}, // (space)  160
{0x00, 0x00, 0x00, 0x00, 0x00}, // (space)  161
{0x00, 0x00, 0x00, 0x00, 0x00}, // (space)  162
{0x00, 0x00, 0x00, 0x00, 0x00}, // (space)  163
{184, 69, 95, 85, 184},  // Значек будильника  164, 
{16, 30, 31, 62, 16},         //Колокольчик     165, 
{0x00, 0x00, 0x00, 0x00, 0x00}, // (space)  166
{0x00, 0x00, 0x00, 0x00, 0x00}, // (space)  167
{0x00, 0x00, 0x00, 0x00, 0x00}, // (space)  168
{0x00, 0x00, 0x00, 0x00, 0x00}, // (space)  169
{0x00, 0x00, 0x00, 0x00, 0x00}, // (space)  170
{0x00, 0x00, 0x00, 0x00, 0x00}, // (space)  171
{0x00, 0x00, 0x00, 0x00, 0x00}, // (space)  172
{0x00, 0x00, 0x00, 0x00, 0x00}, // (space)  173
{0x00, 0x00, 0x00, 0x00, 0x00}, // (space)  174
{0x00, 0x00, 0x00, 0x00, 0x00}, // (space)  175
{0x00, 0x00, 0x00, 0x00, 0x00}, // (space)  176
{0x00, 0x00, 0x00, 0x00, 0x00}, // (space)  177
{0x00, 0x00, 0x00, 0x00, 0x00}, // (space)  178
{0x00, 0x00, 0x00, 0x00, 0x00}, // (space)  179
{0x00, 0x00, 0x00, 0x00, 0x00}, // (space)  180
{0x00, 0x00, 0x00, 0x00, 0x00}, // (space)  181
{0x00, 0x00, 0x00, 0x00, 0x00}, // (space)  182
{0x00, 0x00, 0x00, 0x00, 0x00}, // (space)  183
{0x00, 0x00, 0x00, 0x00, 0x00}, // (space)  184
{0x00, 0x00, 0x00, 0x00, 0x00}, // (space)  185
{0x00, 0x00, 0x00, 0x00, 0x00}, // (space)  186
{0x00, 0x00, 0x00, 0x00, 0x00}, // (space)  187
{0x00, 0x00, 0x00, 0x00, 0x00}, // (space)  188
{0x00, 0x00, 0x00, 0x00, 0x00}, // (space)  189
{0x00, 0x00, 0x00, 0x00, 0x00}, // (space)  190
{0x00, 0x00, 0x00, 0x00, 0x00}, // (space)  191
{0x7E, 0x11, 0x11, 0x11, 0x7E}, // A        192
{0x7F, 0x45, 0x45, 0x45, 0x39}, // Б        193
{0x7F, 0x49, 0x49, 0x49, 0x36}, // B        194
{0x7F, 0x01, 0x01, 0x01, 0x03}, // Г        195
{0xC0, 0x7E, 0x41, 0x7F, 0xC0}, // Д        196
{0x7F, 0x49, 0x49, 0x49, 0x41}, // E        197
{119, 8, 127, 8, 119},                 // Ж        198
{34, 73, 73, 73, 54},                  // З        199
{127, 32, 16, 8, 127},                 // И        200
{127, 32, 19, 8, 127},                 // Й        201
{0x7F, 0x08, 0x14, 0x22, 0x41}, // K        202
{64, 62, 1, 1, 127},                   // Л        203
{0x7F, 0x02, 0x04, 0x02, 0x7F}, // M        204
{0x7F, 0x08, 0x08, 0x08, 0x7F}, // H        205
{0x3E, 0x41, 0x41, 0x41, 0x3E}, // O        206
{127, 1, 1, 1, 127},                   // П        207
{0x7F, 0x09, 0x09, 0x09, 0x06}, // P        208
{0x3E, 0x41, 0x41, 0x41, 0x22}, // C        209
{0x01, 0x01, 0x7F, 0x01, 0x01}, // T        210
{39, 72, 72, 72, 63},                  // У        211
{30, 33, 127, 33, 30},                 // Ф        212
{0x63, 0x14, 0x08, 0x14, 0x63}, // X        213
{127, 64, 64, 127, 192},               // Ц        214
{15, 16, 16, 16, 127},                 // Ч        215
{127, 64, 124, 64, 127},               // Ш        216
{127, 64, 124, 64, 255},               // Щ        217
{1, 127, 72, 72, 48},                  // Ъ        218
{127, 72, 48, 0, 127},                 // Ы        219
{127, 72, 72, 72, 48},                 // Ь        220
{34, 73, 73, 73, 62},                  // Э        221
{127, 8, 62, 65, 62},                  // Ю        222
{118, 9, 9, 9, 127},                   // Я        223
{0x20, 0x54, 0x54, 0x54, 0x78}, // a        224
{124, 84, 84, 84, 36},             // б        225
{124, 84, 84, 84, 40},             // в        226
{124, 4, 4, 4, 12},                // г        227
{192, 120, 68, 124, 192},          // д        228
{0x38, 0x54, 0x54, 0x54, 0x18}, // e        229
{108, 16, 124, 16, 108},           // ж        230
{40, 68, 84, 84, 40},              // з        231
{124, 32, 16, 8, 124},             // и        232
{124, 33, 18, 8, 124},             // й        233
{124, 16, 16, 40, 68},             // к        234
{64, 56, 4, 4, 124},               // л        235
{124, 8, 16, 8, 124},              // м        236
{124, 16, 16, 16, 124},       // н        237
{0x38, 0x44, 0x44, 0x44, 0x38}, // o        238
{124, 4, 4, 4, 124},               // п        239
{0x7C, 0x14, 0x14, 0x14, 0x08}, // p        240
{0x38, 0x44, 0x44, 0x44, 0x20}, // c        241
{4, 4, 124, 4, 4},                 // т        242
{0x0C, 0x50, 0x50, 0x50, 0x3C}, // y        243
{24, 36, 124, 36, 24},             // ф        244
{0x44, 0x28, 0x10, 0x28, 0x44}, // x        245
{124, 64, 64, 124, 192},           // ц        246
{12, 16, 16, 16, 124},             // ч        247
{124, 64, 120, 64, 124},           // ш        248
{124, 64, 120, 64, 252},           // щ        249
{124, 84, 80, 80, 32},             // ъ        250
{124, 80, 32, 0, 124},                 // ы        251
{124, 80, 80, 80, 32},             // ь        252
{40, 68, 84, 84, 56},               //э        253
{124, 16, 56, 68, 56},             // ю        254
{72, 52, 20, 20, 124}      // я        255
};
//-----------------------------------------------------------------
void SendLcd(unsigned char RS, unsigned char data)//портирована
{
 if (RS == 1){
  LCD_RS_ON;
  LCD_CLK_OFF;
  shiftOut(LCD_DATA, LCD_CLK, MSBFIRST, data);
 }
 else
 {
  LCD_CS_ON;
  LCD_RS_OFF;
  LCD_CS_OFF;
  LCD_CLK_OFF;
  shiftOut(LCD_DATA, LCD_CLK, MSBFIRST, data);
 }
}

void ResetSoftwareDispay(){
LCD_CS_ON;
LCD_RS_OFF;
LCD_CS_OFF;
LCD_CLK_OFF;
shiftOut(LCD_DATA, LCD_CLK, MSBFIRST, 0x01);  //софтовый сброс дисплея
delay(50);

}
void LcdFill( int Collor ) {
  
  //command
  LCD_CS_ON;
  LCD_RS_OFF;
  LCD_CS_OFF;
  LCD_CLK_OFF;
   shiftOut(LCD_DATA, LCD_CLK, MSBFIRST, 0x2a);
 
   //data
  LCD_RS_ON;
  LCD_CLK_OFF;
  shiftOut(LCD_DATA, LCD_CLK, MSBFIRST, 0);
  shiftOut(LCD_DATA, LCD_CLK, MSBFIRST, 100);
 
  //command  
  LCD_CS_ON;
  LCD_RS_OFF;
  LCD_CS_OFF;
  LCD_CLK_OFF;
  shiftOut(LCD_DATA, LCD_CLK, MSBFIRST, 0x2b);
 
  //data
  LCD_RS_ON;
  LCD_CLK_OFF;
  shiftOut(LCD_DATA, LCD_CLK, MSBFIRST, 0);
  shiftOut(LCD_DATA, LCD_CLK, MSBFIRST, 80);
    
  //command
  LCD_CS_ON;
  LCD_RS_OFF;
  LCD_CS_OFF;
  LCD_CLK_OFF;
  shiftOut(LCD_DATA, LCD_CLK, MSBFIRST, 0x2c);
 
 
  //data Подряд передаем данные в нашем случае одни и теже 8080 раз
  LCD_RS_ON;
  LCD_CLK_OFF;
        for (i = 1; i < 8081; i++) {
 
  shiftOut(LCD_DATA, LCD_CLK, MSBFIRST, Collor);
        }
}
void LcdInitt( ) {
  DDRD |=  (1 << LCD_CS);
  DDRD |=  (1 << LCD_RESET);
  DDRD |=  (1 << LCD_RS);
  DDRD |=  (1 << LCD_CLK);
  DDRD |=  (1 << LCD_DATA);
 PORTD &= ~ _BV(LCD_DATA); // LOW
 LCD_RESET_OFF;
  delay(100);
  LCD_RESET_ON;
  delay(500);
  LCD_CS_ON;
  delay(5);
  LCD_CS_OFF;
  
  
  LCD_CS_ON;
  LCD_RS_OFF;
  LCD_CS_OFF;
  LCD_CLK_OFF;
  shiftOut(LCD_DATA, LCD_CLK, MSBFIRST, 0x01);  //софтовый сброс дисплея
  delay(50);
  
    
  LCD_CS_ON;
  LCD_RS_OFF;
  LCD_CS_OFF;
  LCD_CLK_OFF;
  shiftOut(LCD_DATA, LCD_CLK, MSBFIRST, 0xc6); //
  delay(50);
    
    
    
  //command
  LCD_CS_ON;
  LCD_RS_OFF;
  LCD_CS_OFF;
  LCD_CLK_OFF;
  shiftOut(LCD_DATA, LCD_CLK, MSBFIRST, 0xb9);
   
  //data
  LCD_RS_ON;
  LCD_CLK_OFF;
  shiftOut(LCD_DATA, LCD_CLK, MSBFIRST, 0x00);
    
  //command
  LCD_CS_ON;
  LCD_RS_OFF;
  LCD_CS_OFF;
  LCD_CLK_OFF;
  shiftOut(LCD_DATA, LCD_CLK, MSBFIRST, 0xb6);
   
    
  //data
  LCD_RS_ON;
  LCD_CLK_OFF;
  shiftOut(LCD_DATA, LCD_CLK, MSBFIRST, 0x80);
  shiftOut(LCD_DATA, LCD_CLK, MSBFIRST, 0x04);
  shiftOut(LCD_DATA, LCD_CLK, MSBFIRST, 0x8a);
  shiftOut(LCD_DATA, LCD_CLK, MSBFIRST, 0x54);
  shiftOut(LCD_DATA, LCD_CLK, MSBFIRST, 0x45);
  shiftOut(LCD_DATA, LCD_CLK, MSBFIRST, 0x52);
  shiftOut(LCD_DATA, LCD_CLK, MSBFIRST, 0x43);
    
  //command
  LCD_CS_ON;
  LCD_RS_OFF;
  LCD_CS_OFF;
  LCD_CLK_OFF;
  shiftOut(LCD_DATA, LCD_CLK, MSBFIRST, 0xb3); //УРОВЕНЬ СЕРОГО
   
  //data
  LCD_RS_ON;
  LCD_CLK_OFF;
  shiftOut(LCD_DATA, LCD_CLK, MSBFIRST, 0x02);
  shiftOut(LCD_DATA, LCD_CLK, MSBFIRST, 0x0a);
  shiftOut(LCD_DATA, LCD_CLK, MSBFIRST, 0x15);
  shiftOut(LCD_DATA, LCD_CLK, MSBFIRST, 0x1f);
  shiftOut(LCD_DATA, LCD_CLK, MSBFIRST, 0x28);
  shiftOut(LCD_DATA, LCD_CLK, MSBFIRST, 0x30);
  shiftOut(LCD_DATA, LCD_CLK, MSBFIRST, 0x37);
  shiftOut(LCD_DATA, LCD_CLK, MSBFIRST, 0x3f);
  shiftOut(LCD_DATA, LCD_CLK, MSBFIRST, 0x47);
  shiftOut(LCD_DATA, LCD_CLK, MSBFIRST, 0x4c);
  shiftOut(LCD_DATA, LCD_CLK, MSBFIRST, 0x54);
  shiftOut(LCD_DATA, LCD_CLK, MSBFIRST, 0x65);
  shiftOut(LCD_DATA, LCD_CLK, MSBFIRST, 0x75);
  shiftOut(LCD_DATA, LCD_CLK, MSBFIRST, 0x80);
  shiftOut(LCD_DATA, LCD_CLK, MSBFIRST, 0x85);
    
    
  //command
  LCD_CS_ON;
  LCD_RS_OFF;
  LCD_CS_OFF;
  LCD_CLK_OFF;
  shiftOut(LCD_DATA, LCD_CLK, MSBFIRST, 0xb5); // КРИВАЯ ГАММЫ
   
  //data
  LCD_RS_ON;
  LCD_CLK_OFF;
  shiftOut(LCD_DATA, LCD_CLK, MSBFIRST, 0x01);
    
 //command
  LCD_CS_ON;
  LCD_RS_OFF;
  LCD_CS_OFF;
  LCD_CLK_OFF;
  shiftOut(LCD_DATA, LCD_CLK, MSBFIRST, 0xb7);
    
  //data
  LCD_RS_ON;
  LCD_CLK_OFF;
  shiftOut(LCD_DATA, LCD_CLK, MSBFIRST, 0x00);
  shiftOut(LCD_DATA, LCD_CLK, MSBFIRST, 0x00);
  shiftOut(LCD_DATA, LCD_CLK, MSBFIRST, 0x00);
  shiftOut(LCD_DATA, LCD_CLK, MSBFIRST, 0x00);
  shiftOut(LCD_DATA, LCD_CLK, MSBFIRST, 0x00);
  shiftOut(LCD_DATA, LCD_CLK, MSBFIRST, 0x00);
  shiftOut(LCD_DATA, LCD_CLK, MSBFIRST, 0x00);
  shiftOut(LCD_DATA, LCD_CLK, MSBFIRST, 0x00);
  shiftOut(LCD_DATA, LCD_CLK, MSBFIRST, 0x00);
  shiftOut(LCD_DATA, LCD_CLK, MSBFIRST, 0x00);
  shiftOut(LCD_DATA, LCD_CLK, MSBFIRST, 0x00);
  shiftOut(LCD_DATA, LCD_CLK, MSBFIRST, 0x00);
  shiftOut(LCD_DATA, LCD_CLK, MSBFIRST, 0x00);
  shiftOut(LCD_DATA, LCD_CLK, MSBFIRST, 0x00);
  
  //command
  LCD_CS_ON;
  LCD_RS_OFF;
  LCD_CS_OFF;
  LCD_CLK_OFF;
  shiftOut(LCD_DATA, LCD_CLK, MSBFIRST, 0xbd);
  //data
  LCD_RS_ON;
  LCD_CLK_OFF;
  shiftOut(LCD_DATA, LCD_CLK, MSBFIRST, 0x00);
    
  //command
  LCD_CS_ON;
  LCD_RS_OFF;
  LCD_CS_OFF;
  LCD_CLK_OFF;
  shiftOut(LCD_DATA, LCD_CLK, MSBFIRST, 0x36);
   
  //data
  LCD_RS_ON;
  LCD_CLK_OFF;
  shiftOut(LCD_DATA, LCD_CLK, MSBFIRST, 0x48);
    
    
  //command
  LCD_CS_ON;
  LCD_RS_OFF;
  LCD_CS_OFF;
  LCD_CLK_OFF;
  shiftOut(LCD_DATA, LCD_CLK, MSBFIRST, 0x2d);
   
  //data
  LCD_RS_ON;
  LCD_CLK_OFF;
  shiftOut(LCD_DATA, LCD_CLK, MSBFIRST, 0x00);
  shiftOut(LCD_DATA, LCD_CLK, MSBFIRST, 0x03);
  shiftOut(LCD_DATA, LCD_CLK, MSBFIRST, 0x05);
  shiftOut(LCD_DATA, LCD_CLK, MSBFIRST, 0x07);
  shiftOut(LCD_DATA, LCD_CLK, MSBFIRST, 0x09);
  shiftOut(LCD_DATA, LCD_CLK, MSBFIRST, 0x0b);
  shiftOut(LCD_DATA, LCD_CLK, MSBFIRST, 0x0d);
  shiftOut(LCD_DATA, LCD_CLK, MSBFIRST, 0x0f);
  shiftOut(LCD_DATA, LCD_CLK, MSBFIRST, 0x00);
  shiftOut(LCD_DATA, LCD_CLK, MSBFIRST, 0x03);
  shiftOut(LCD_DATA, LCD_CLK, MSBFIRST, 0x05);
  shiftOut(LCD_DATA, LCD_CLK, MSBFIRST, 0x07);
  shiftOut(LCD_DATA, LCD_CLK, MSBFIRST, 0x09);
  shiftOut(LCD_DATA, LCD_CLK, MSBFIRST, 0x0b);
  shiftOut(LCD_DATA, LCD_CLK, MSBFIRST, 0x0b);
  shiftOut(LCD_DATA, LCD_CLK, MSBFIRST, 0x0f);
  shiftOut(LCD_DATA, LCD_CLK, MSBFIRST, 0x00);
  shiftOut(LCD_DATA, LCD_CLK, MSBFIRST, 0x05);
  shiftOut(LCD_DATA, LCD_CLK, MSBFIRST, 0x0b);
  shiftOut(LCD_DATA, LCD_CLK, MSBFIRST, 0x0f);
  
//command
  LCD_CS_ON;
  LCD_RS_OFF;
  LCD_CS_OFF;
  LCD_CLK_OFF;
  shiftOut(LCD_DATA, LCD_CLK, MSBFIRST, 0xba);
    
  //data
  LCD_RS_ON;
  LCD_CLK_OFF;
  shiftOut(LCD_DATA, LCD_CLK, MSBFIRST, 0x6d);
  shiftOut(LCD_DATA, LCD_CLK, MSBFIRST, 0x03);
    
    
  //command
  LCD_CS_ON;
  LCD_RS_OFF;
  LCD_CS_OFF;
  LCD_CLK_OFF;
  shiftOut(LCD_DATA, LCD_CLK, MSBFIRST, 0x25); //УСТАНОВИТЬ КОНТРАСТ было 25
   
  //data
  LCD_RS_ON;
  LCD_CLK_OFF;
  shiftOut(LCD_DATA, LCD_CLK, MSBFIRST, 0x25);
 // shiftOut(LCD_DATA, LCD_CLK, MSBFIRST, 0x61;
    
  //command
  LCD_CS_ON;
  LCD_RS_OFF;
  LCD_CS_OFF;
  LCD_CLK_OFF;
  shiftOut(LCD_DATA, LCD_CLK, MSBFIRST, 0xbe);
    
  //data
  LCD_RS_ON;
  LCD_CLK_OFF;
  shiftOut(LCD_DATA, LCD_CLK, MSBFIRST, 0x58);
    
  //command
  LCD_CS_ON;
  LCD_RS_OFF;
  LCD_CS_OFF;
  LCD_CLK_OFF;
  shiftOut(LCD_DATA, LCD_CLK, MSBFIRST, 0x3a);
   
  //data
  LCD_RS_ON;
  LCD_CLK_OFF;
  shiftOut(LCD_DATA, LCD_CLK, MSBFIRST, 0x02);
    
  //command
  LCD_CS_ON;
  LCD_RS_OFF;
  LCD_CS_OFF;
  LCD_CLK_OFF;
  shiftOut(LCD_DATA, LCD_CLK, MSBFIRST, 0x03);
  delay(40);
     
  //command
  LCD_CS_ON;
  LCD_RS_OFF;
  LCD_CS_OFF;
  LCD_CLK_OFF;
  shiftOut(LCD_DATA, LCD_CLK, MSBFIRST, 0x11);
   delay(20);
    
  //command
  LCD_CS_ON;
  LCD_RS_OFF;
  LCD_CS_OFF;
  LCD_CLK_OFF;
  shiftOut(LCD_DATA, LCD_CLK, MSBFIRST, 0x29);
  }
 
// -----------------------------------------------------------------------------
void SetArea(char x1, char x2, char y1, char y2)
{
 SendLcd( CMD, 0x2A );  //задаем область по X
 SendLcd( DAT, x1 );    //начальная
 SendLcd( DAT, x2 );    //конечная
 SendLcd( CMD, 0x2B );  //задаем область по Y
 SendLcd( DAT, y1+1 );  //начальная (у этого контроллера Y отсчитывается от 1, а не от 0)
 SendLcd( DAT, y2+1 );  //конечная
 SendLcd( CMD, 0x2C );  //отправляем команду на начало записи в память и начинаем посылать данные
}

void SendImage (char x, char y, char width, char height, char *img, int rot)  
{  
char x1, y1;
switch (rot)
{
  case 0: case 180:  
  for(y1=y; y1<(y+height); y1++)
  {
   SetArea( x, x1+(width-1), y1,y1);   
   for(x1=x; x1<x+width;x1++)
   {   
//   #ifdef _8_BIT_COLOR    //(8-ми битовая цветовая палитра (256 цветов))
    SendLcd( DAT,pgm_read_byte(&(*img++))); //Данные SPI - задаём цвет пикселя 
//  #else   //(16-ти битовая цветовая палитра (65536 цветов))
//  SendLcd( DAT, pgm_read_byte(&(*img++))); //отправляем данные по SPI
//  SendLcd( DAT, pgm_read_byte(&(*img++)));    
//   #endif
   }
  }
  break;
 }; 
}

//----------------------------------------------------------------
void LcdPixel(int PosX, int PosY, int Collor ) {
  
  //command
  LCD_CS_ON;
  LCD_RS_OFF;
  LCD_CS_OFF;
  LCD_CLK_OFF;
  shiftOut(LCD_DATA, LCD_CLK, MSBFIRST, 0x2a);
   //data
  LCD_RS_ON;
  LCD_CLK_OFF;
  shiftOut(LCD_DATA, LCD_CLK, MSBFIRST, PosX);
  shiftOut(LCD_DATA, LCD_CLK, MSBFIRST, 100);
    
  LCD_CS_ON;
  LCD_RS_OFF;
  LCD_CS_OFF;
  LCD_CLK_OFF;
  shiftOut(LCD_DATA, LCD_CLK, MSBFIRST, 0x2b);
  //data
  LCD_RS_ON;
  LCD_CLK_OFF;
  shiftOut(LCD_DATA, LCD_CLK, MSBFIRST, PosY);
  shiftOut(LCD_DATA, LCD_CLK, MSBFIRST, 80);
    
   LCD_CS_ON;
  LCD_RS_OFF;
  LCD_CS_OFF;
  LCD_CLK_OFF;
  shiftOut(LCD_DATA, LCD_CLK, MSBFIRST, 0x2c);
  //data
   
  LCD_RS_ON;
  LCD_CLK_OFF;
  shiftOut(LCD_DATA, LCD_CLK, MSBFIRST, Collor);
   
}
// ----------------------------------------------------------------
void LcdCharPrint( int Chh, int PosX, int PosY, int CharCollor, int CharFon ) { 
int j,i,k;
  
  
  //command
  LCD_CS_ON;
  LCD_RS_OFF;
  LCD_CS_OFF;
  LCD_CLK_OFF;
  shiftOut(LCD_DATA, LCD_CLK, MSBFIRST, 0x2a);
   //data
  LCD_RS_ON;
  LCD_CLK_OFF;

  shiftOut(LCD_DATA, LCD_CLK, MSBFIRST, (PosX * 5));
  shiftOut(LCD_DATA, LCD_CLK, MSBFIRST, (PosX * 5 + 4));
   
  LCD_CS_ON;
  LCD_RS_OFF;
  LCD_CS_OFF;
  LCD_CLK_OFF;
  shiftOut(LCD_DATA, LCD_CLK, MSBFIRST, 0x2b);
  //data
  LCD_RS_ON;
  LCD_CLK_OFF;
  shiftOut(LCD_DATA, LCD_CLK, MSBFIRST, (PosY * 8 + 1));
  shiftOut(LCD_DATA, LCD_CLK, MSBFIRST, (PosY * 8 + 7 +1 ));
   
   LCD_CS_ON;
  LCD_RS_OFF;
  LCD_CS_OFF;
  LCD_CLK_OFF;
  shiftOut(LCD_DATA, LCD_CLK, MSBFIRST, 0x2c);


    //data
  LCD_RS_ON;
  LCD_CLK_OFF;

        for (i = 0; i < 40; i++) {

j = i / 5;
k = i - (j * 5);
char bbb = pgm_read_byte(&(CHR[Chh][k]));


int myChar =  bitRead(bbb, j); 

  
   if(myChar == 0){ 
  shiftOut(LCD_DATA, LCD_CLK, MSBFIRST, CharFon);
  }
  else {
  shiftOut(LCD_DATA, LCD_CLK, MSBFIRST, CharCollor);
 }

     }    
   
   }

void LcdStringPrint(char *str, int PosX, int PosY, int CharCollor, int CharFon, float zoom_width) { 
  unsigned char i = 0;
  if (zoom_width == 0)   zoom_width = 1;

while (str[i]) //x и y - адрес пикселя начальной позиции; с увеличением переменной i адрес вывода очередного символа смещается на i*6 (чем организуются столбцы дисплея)
  {
   LcdCharPrint(str[i], PosX + (i * 1 * zoom_width),PosY,CharCollor,CharFon);
    i++;
  }
}
// ---------------------------------------------------------------





/********************************************************************************************/
