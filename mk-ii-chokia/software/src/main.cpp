#include <Arduino.h>
#include <U8g2lib.h>
#include <SPI.h>
#include <Wire.h>

// //
// // LCD Test
// //
// U8G2_ST7920_128X64_1_SW_SPI u8g2(
//     U8G2_R0, // rotation
//     PA1,     // Clock "E" enable?
//     PA2,     // Data "R/W" might have this and next wrong way.. but meh
//     PA3,     // CS "RS"
//     PA4      // Reset "RST"
// );
// // Also connect +5v to VCC, BLA
// // and - to GND, PSB, BLK
// void setup(void)
// {
//   u8g2.begin();
// }
// void loop(void)
// {
//   u8g2.firstPage();
//   do
//   {
//     // https://github.com/olikraus/u8g2/wiki/u8g2reference
//     u8g2.setFont(u8g2_font_ncenB14_tr);
//     u8g2.drawStr(0, 24, "Hello World!");
//     // Can't bleeding get it to output a random string
//     // char alphabet[] = {"ABCDEFGHIJKLMNOPQRSTUVWXYZ"};
//     // char char_array[] = {""};
//     // char_array[0] = char(random(0, 9));
//     // // strcpy(char_array, alphabet[random(0, 25)].c_str());
//     u8g2.drawStr(40, 50, char_array);
//     u8g2.drawBox(random(0, 100), random(30, 50), 8, 8);
//     // Not amazing, then again I've no idea what the page system is so..
//   } while (u8g2.nextPage());
// }

// // Backlight dimming test
// // Not quite sure about this.. I heard a 39ohm resistor to gpio could control it. dimming on would be ace
// // but - don't stress too much, if it's just on all the tiem that'd be okay too
// // https://www.algissalys.com/electronics/nokia-5110-lcd-backlight-to-ground-using-gpio
// void setup()
// {
//   Serial.begin(115200);
//   delay(5000);
//   // I think D1, D2, are 1, 2.. A0, A1 are A0, A1..
//   pinMode(9, OUTPUT);
// }
// float x = 0;
// float pi = 3.141592;
// void loop()
// {
//   // if (x > 255)
//   //   x = 0;
//   // Serial.print(x);
//   // Serial.print(' ');
//   // analogWrite(9, x);
//   // delay(20);
//   // x++;
//   if (x > 4 * pi)
//     x = 0;
//   int y = floor(255 * ((sin(x / 2 - pi / 2)) / 2 + .5));
//   // Serial.print(y);
//   // Serial.print(' ');
//   analogWrite(9, y);
//   x += 0.01;
//   delay(5);
// }