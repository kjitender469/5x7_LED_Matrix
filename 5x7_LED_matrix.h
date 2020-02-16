/************************** 5x7 LED Dot Matrix **********************/
/*
             14 13 12 11 10  9  8
              |  |  |  |  |  |  |
            |---------------------|
            |                     |
            |                     |
            |                     |
            |                     |
            |                     |
            |                     |
            |                     |
            |                     |
            |                     |
            |---------------------|
                  HB55701ASR
              |  |  |  |  |  |  |
              1  2  3  4  5  6  7

  Connections : 

        Arduino         5x7 LED Matrix
          2      -->        2
          3      -->        3
          4      -->        4
          5      -->        5
          6      -->        6
          7      -->        7
          8      -->        8
          9      -->        9
          10     -->        10
          11     -->        14
          12     -->        1
          13     -->        13

  Note : Pin no 4 and 11 shorted
         Pin no 5 and 12 shorted

  Author : Jitender Kumar
  email  : kjitender469@gmail.com
*/

#include <Arduino.h>

//#define debug

/*
    This function make all the LEDs to glow.
*/
void glow_all();

/*
    This function make all the LEDs to off.
*/
void off_all();

/*
    Pass the index no of the corresponding led from led matrix to make it glow. 
    The function takes integer no as an argument and will make that Led to glow.
 */
void glow_led(int ledNumber);

/*
    Pass the index no of the corresponding led from led matrix to make it off. 
    The function takes integer no as an argument and will make that Led off.
*/
void off_led(int ledNumber);

/*

*/
void disp_char(char c);

/*

*/
void disp_custom_char(int *arr, int size);

/*

*/
void print_pattern(int *arr, int size);

void glow_led_scroll(int);
void off_led_scroll(int);
void glow_matrix_scroll(char);
void disp_char_scroll(char c);
