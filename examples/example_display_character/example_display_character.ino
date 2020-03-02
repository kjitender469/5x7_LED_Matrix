
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

#include "5x7_LED_matrix.h"

char msg[36] = {'A','B','C','D','E','F','G','H','I','J','K','L',
                'M','N','O','P','Q','R','S','T','U','V','W','X',
                'Y','Z','0','1','2','3','4','5','6','7','8','9'};

void setup()
{
  Serial.begin(9600);
  for (int i = 2; i < 14; i++)
  {
    pinMode(i, OUTPUT);
  }
  Serial.println("Setup Completed");
  glow_all();
  Serial.println("glow all");
  delay(1000);
  off_all();
  Serial.println("off all");
  delay(2000);
}

void loop()
{
  for(int i=0; i<35; i++)
  {
    disp_char(msg[i]);
  }
  //disp_char('F');
  //delay(200);
}
