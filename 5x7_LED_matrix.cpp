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

  LED Number on 5x7 LED Matix. Used to Access individual LED if needed.

      { 1, 2, 3, 4, 5},
      { 6, 7, 8, 9,10},
      {11,12,13,14,15},
      {16,17,18,19,20},
      {21,22,23,24,25},
      {26,27,28,29,30},
      {31,32,33,34,35}

  Note : Pin no 4 and 11 shorted
         Pin no 5 and 12 shorted

  Author : Jitender Kumar
  email  : kjitender469@gmail.com

*/

#include <Arduino.h>
#include "5x7_LED_matrix.h";

//#define enable_disp_char_scroll
#define dataInFlash

#define dataInRAM

#ifdef dataInFlash
  const char data_A[] PROGMEM = {"00100010101000111111100011000110001"};
  const char data_B[] PROGMEM = {"11110100011000111110100011000111110"};
  const char data_C[] PROGMEM = {"01110100011000010000100001000101110"};
  const char data_D[] PROGMEM = {"11110100011000110001100011000111110"};
  const char data_E[] PROGMEM = {"11111100001000011111100001000011111"};
  const char data_F[] PROGMEM = {"11111100001000011111100001000010000"};
  const char data_G[] PROGMEM = {"01110100011000010110100011000101110"};
  const char data_H[] PROGMEM = {"10001100011000111111100011000110001"};
  const char data_I[] PROGMEM = {"11111001000010000100001000010011111"};
  const char data_J[] PROGMEM = {"11111001000010000100101001010001100"};
  const char data_K[] PROGMEM = {"10001100101010011000101001001010001"};
  const char data_L[] PROGMEM = {"10000100001000010000100001000011111"};
  const char data_M[] PROGMEM = {"10001110111010110001100011000110001"};
  const char data_N[] PROGMEM = {"10001100011100110101100111000110001"};
  const char data_O[] PROGMEM = {"01110100011000110001100011000101110"};
  const char data_P[] PROGMEM = {"11110100011000111110100001000010000"};
  const char data_Q[] PROGMEM = {"01110100011000110001100011001101110"};
  const char data_R[] PROGMEM = {"11110100011000111110101001001010001"};
  const char data_S[] PROGMEM = {"01110100011000001110000011000101110"};
  const char data_T[] PROGMEM = {"11111001000010000100001000010000100"};
  const char data_U[] PROGMEM = {"10001100011000110001100011000101110"};
  const char data_V[] PROGMEM = {"10001100011000110001100010101000100"};
  const char data_W[] PROGMEM = {"10001100011000110001101011010101010"};
  const char data_X[] PROGMEM = {"10001100010101000100010101000110001"};
  const char data_Y[] PROGMEM = {"10001100010101000100001000010000100"};
  const char data_Z[] PROGMEM = {"11111000010001000100010001000011111"};
  const char data_0[] PROGMEM = {"01110100011000110001100011000101110"};
  const char data_1[] PROGMEM = {"00100011000010000100001000010001110"};
  const char data_2[] PROGMEM = {"01110100010001000100010001000011110"};
  const char data_3[] PROGMEM = {"11110000010000111110000010000111110"};
  const char data_4[] PROGMEM = {"10001100011000111111000010000100001"};
  const char data_5[] PROGMEM = {"01111100001000001111000010000111111"};
  const char data_6[] PROGMEM = {"01111100001000011110100011000101110"};
  const char data_7[] PROGMEM = {"11111000010000100010001000100010000"};
  //const char data_8[] PROGMEM = {"11111100011000111111100011000111111"};
  const char data_8[] PROGMEM = {"01110100011000101110100011000101110"};
  const char data_9[] PROGMEM = {"11111100011000111111000010000111111"};
  
  const char *const data_table[] PROGMEM = {data_A, data_B, data_C, data_D, data_E, data_F,
                                            data_G, data_H, data_I, data_J, data_K, data_L,
                                            data_M, data_N, data_O, data_P, data_Q, data_R,
                                            data_S, data_T, data_U, data_V, data_W, data_X,
                                            data_Y, data_Z, data_0, data_1, data_2, data_3,
                                            data_4, data_5, data_6, data_7, data_8, data_9
                                           };
#endif

#ifdef dataInRAM
const int A[7][5]  = {
  {0, 0, 1, 0, 0},
  {0, 1, 0, 1, 0},
  {1, 0, 0, 0, 1},
  {1, 1, 1, 1, 1},
  {1, 0, 0, 0, 1},
  {1, 0, 0, 0, 1},
  {1, 0, 0, 0, 1}
};

const int B[7][5]  = {
  {1, 1, 1, 1, 0},
  {1, 0, 0, 0, 1},
  {1, 0, 0, 0, 1},
  {1, 1, 1, 1, 0},
  {1, 0, 0, 0, 1},
  {1, 0, 0, 0, 1},
  {1, 1, 1, 1, 0}
};

const int C[7][5]  = {
  {0, 1, 1, 1, 0},
  {1, 0, 0, 0, 1},
  {1, 0, 0, 0, 0},
  {1, 0, 0, 0, 0},
  {1, 0, 0, 0, 0},
  {1, 0, 0, 0, 1},
  {0, 1, 1, 1, 0}
};

const int D[7][5]  = {
  {1, 1, 1, 1, 0},
  {1, 0, 0, 0, 1},
  {1, 0, 0, 0, 1},
  {1, 0, 0, 0, 1},
  {1, 0, 0, 0, 1},
  {1, 0, 0, 0, 1},
  {1, 1, 1, 1, 0}
};

const int E[7][5]  = {
  {1, 1, 1, 1, 1},
  {1, 0, 0, 0, 0},
  {1, 0, 0, 0, 0},
  {1, 1, 1, 1, 1},
  {1, 0, 0, 0, 0},
  {1, 0, 0, 0, 0},
  {1, 1, 1, 1, 1}
};

const int F[7][5]  = {
  {1, 1, 1, 1, 1},
  {1, 0, 0, 0, 0},
  {1, 0, 0, 0, 0},
  {1, 1, 1, 1, 1},
  {1, 0, 0, 0, 0},
  {1, 0, 0, 0, 0},
  {1, 0, 0, 0, 0}
};

const int G[7][5] = {
  {0, 1, 1, 1, 0},
  {1, 0, 0, 0, 1},
  {1, 0, 0, 0, 0},
  {1, 0, 1, 1, 0},
  {1, 0, 0, 0, 1},
  {1, 0, 0, 0, 1},
  {0, 1, 1, 1, 0}
};

const int H[7][5]  = {
  {1, 0, 0, 0, 1},
  {1, 0, 0, 0, 1},
  {1, 0, 0, 0, 1},
  {1, 1, 1, 1, 1},
  {1, 0, 0, 0, 1},
  {1, 0, 0, 0, 1},
  {1, 0, 0, 0, 1}
};

const int I[7][5]  = {
  {1, 1, 1, 1, 1},
  {0, 0, 1, 0, 0},
  {0, 0, 1, 0, 0},
  {0, 0, 1, 0, 0},
  {0, 0, 1, 0, 0},
  {0, 0, 1, 0, 0},
  {1, 1, 1, 1, 1}
};

const int J[7][5]  = {
  {1, 1, 1, 1, 1},
  {0, 0, 1, 0, 0},
  {0, 0, 1, 0, 0},
  {0, 0, 1, 0, 0},
  {1, 0, 1, 0, 0},
  {1, 0, 1, 0, 0},
  {0, 1, 1, 0, 0}
};

const int K[7][5]  = {
  {1, 0, 0, 0, 1},
  {1, 0, 0, 1, 0},
  {1, 0, 1, 0, 0},
  {1, 1, 0, 0, 0},
  {1, 0, 1, 0, 0},
  {1, 0, 0, 1, 0},
  {1, 0, 0, 0, 1}
};

const int L[7][5] = {
  {1, 0, 0, 0, 0},
  {1, 0, 0, 0, 0},
  {1, 0, 0, 0, 0},
  {1, 0, 0, 0, 0},
  {1, 0, 0, 0, 0},
  {1, 0, 0, 0, 0},
  {1, 1, 1, 1, 1}
};

const int M[7][5]  = {
  {1, 0, 0, 0, 1},
  {1, 1, 0, 1, 1},
  {1, 0, 1, 0, 1},
  {1, 0, 0, 0, 1},
  {1, 0, 0, 0, 1},
  {1, 0, 0, 0, 1},
  {1, 0, 0, 0, 1}
};

const int N[7][5]  = {
  {1, 0, 0, 0, 1},
  {1, 0, 0, 0, 1},
  {1, 1, 0, 0, 1},
  {1, 0, 1, 0, 1},
  {1, 0, 0, 1, 1},
  {1, 0, 0, 0, 1},
  {1, 0, 0, 0, 1}
};

const int O[7][5]  = {
  {0, 1, 1, 1, 0},
  {1, 0, 0, 0, 1},
  {1, 0, 0, 0, 1},
  {1, 0, 0, 0, 1},
  {1, 0, 0, 0, 1},
  {1, 0, 0, 0, 1},
  {0, 1, 1, 1, 0}
};

const int P[7][5]  = {
  {1, 1, 1, 1, 0},
  {1, 0, 0, 0, 1},
  {1, 0, 0, 0, 1},
  {1, 1, 1, 1, 0},
  {1, 0, 0, 0, 0},
  {1, 0, 0, 0, 0},
  {1, 0, 0, 0, 0}
};

const int Q[7][5]  = {
  {0, 1, 1, 1, 0},
  {1, 0, 0, 0, 1},
  {1, 0, 0, 0, 1},
  {1, 0, 0, 0, 1},
  {1, 0, 0, 0, 1},
  {1, 0, 0, 1, 1},
  {0, 1, 1, 1, 0}
};

const int R[7][5]  = {
  {1, 1, 1, 1, 0},
  {1, 0, 0, 0, 1},
  {1, 0, 0, 0, 1},
  {1, 1, 1, 1, 0},
  {1, 0, 1, 0, 0},
  {1, 0, 0, 1, 0},
  {1, 0, 0, 0, 1}
};

const int S[7][5]  = {
  {0, 1, 1, 1, 0},
  {1, 0, 0, 0, 1},
  {1, 0, 0, 0, 0},
  {0, 1, 1, 1, 0},
  {0, 0, 0, 0, 1},
  {1, 0, 0, 0, 1},
  {0, 1, 1, 1, 0}
};

const int T[7][5]  = {
  {1, 1, 1, 1, 1},
  {0, 0, 1, 0, 0},
  {0, 0, 1, 0, 0},
  {0, 0, 1, 0, 0},
  {0, 0, 1, 0, 0},
  {0, 0, 1, 0, 0},
  {0, 0, 1, 0, 0}
};

const int U[7][5]  = {
  {1, 0, 0, 0, 1},
  {1, 0, 0, 0, 1},
  {1, 0, 0, 0, 1},
  {1, 0, 0, 0, 1},
  {1, 0, 0, 0, 1},
  {1, 0, 0, 0, 1},
  {0, 1, 1, 1, 0}
};

const int V[7][5]  = {
  {1, 0, 0, 0, 1},
  {1, 0, 0, 0, 1},
  {1, 0, 0, 0, 1},
  {1, 0, 0, 0, 1},
  {1, 0, 0, 0, 1},
  {0, 1, 0, 1, 0},
  {0, 0, 1, 0, 0}
};

const int W[7][5]  = {
  {1, 0, 0, 0, 1},
  {1, 0, 0, 0, 1},
  {1, 0, 0, 0, 1},
  {1, 0, 0, 0, 1},
  {1, 0, 1, 0, 1},
  {1, 0, 1, 0, 1},
  {0, 1, 0, 1, 0}
};

const int X[7][5]  = {
  {1, 0, 0, 0, 1},
  {1, 0, 0, 0, 1},
  {0, 1, 0, 1, 0},
  {0, 0, 1, 0, 0},
  {0, 1, 0, 1, 0},
  {1, 0, 0, 0, 1},
  {1, 0, 0, 0, 1}
};

const int Y[7][5]  = {
  {1, 0, 0, 0, 1},
  {1, 0, 0, 0, 1},
  {0, 1, 0, 1, 0},
  {0, 0, 1, 0, 0},
  {0, 0, 1, 0, 0},
  {0, 0, 1, 0, 0},
  {0, 0, 1, 0, 0}
};

const int Z[7][5]  = {
  {1, 1, 1, 1, 1},
  {0, 0, 0, 0, 1},
  {0, 0, 0, 1, 0},
  {0, 0, 1, 0, 0},
  {0, 1, 0, 0, 0},
  {1, 0, 0, 0, 0},
  {1, 1, 1, 1, 1}
};

const int m_char_0[7][5]  = {
  {0, 1, 1, 1, 0},
  {1, 0, 0, 0, 1},
  {1, 0, 0, 0, 1},
  {1, 0, 0, 0, 1},
  {1, 0, 0, 0, 1},
  {1, 0, 0, 0, 1},
  {0, 1, 1, 1, 0}
};

const int m_char_1[7][5]  = {
  {0, 0, 1, 0, 0},
  {0, 1, 1, 0, 0},
  {0, 0, 1, 0, 0},
  {0, 0, 1, 0, 0},
  {0, 0, 1, 0, 0},
  {0, 0, 1, 0, 0},
  {0, 1, 1, 1, 0}
};

const int m_char_2[7][5]  = {
  {0, 1, 1, 1, 0},
  {1, 0, 0, 0, 1},
  {0, 0, 0, 1, 0},
  {0, 0, 1, 0, 0},
  {0, 1, 0, 0, 0},
  {1, 0, 0, 0, 0},
  {1, 1, 1, 1, 0}
};

const int m_char_3[7][5]  = {
  {1, 1, 1, 1, 0},
  {0, 0, 0, 0, 1},
  {0, 0, 0, 0, 1},
  {1, 1, 1, 1, 0},
  {0, 0, 0, 0, 1},
  {0, 0, 0, 0, 1},
  {1, 1, 1, 1, 0}
};

const int m_char_4[7][5]  = {
  {1, 0, 0, 0, 1},
  {1, 0, 0, 0, 1},
  {1, 0, 0, 0, 1},
  {1, 1, 1, 1, 1},
  {0, 0, 0, 0, 1},
  {0, 0, 0, 0, 1},
  {0, 0, 0, 0, 1}
};

const int m_char_5[7][5]  = {
  {0, 1, 1, 1, 1},
  {1, 0, 0, 0, 0},
  {1, 0, 0, 0, 0},
  {0, 1, 1, 1, 1},
  {0, 0, 0, 0, 1},
  {0, 0, 0, 0, 1},
  {1, 1, 1, 1, 1}
};

int m_char_6[7][5]  = {
  {0, 1, 1, 1, 1},
  {1, 0, 0, 0, 0},
  {1, 0, 0, 0, 0},
  {1, 1, 1, 1, 0},
  {1, 0, 0, 0, 1},
  {1, 0, 0, 0, 1},
  {0, 1, 1, 1, 0}
};

int m_char_7[7][5]  = {
  {1, 1, 1, 1, 1},
  {0, 0, 0, 0, 1},
  {0, 0, 0, 0, 1},
  {0, 0, 0, 1, 0},
  {0, 0, 1, 0, 0},
  {0, 1, 0, 0, 0},
  {1, 0, 0, 0, 0}
};

int m_char_8[7][5]  = {
  {0, 1, 1, 1, 0},
  {1, 0, 0, 0, 1},
  {1, 0, 0, 0, 1},
  {0, 1, 1, 1, 0},
  {1, 0, 0, 0, 1},
  {1, 0, 0, 0, 1},
  {0, 1, 1, 1, 0}
};

int m_char_9[7][5]  = {
  {1, 1, 1, 1, 1},
  {1, 0, 0, 0, 1},
  {1, 0, 0, 0, 1},
  {1, 1, 1, 1, 1},
  {0, 0, 0, 0, 1},
  {0, 0, 0, 0, 1},
  {1, 1, 1, 1, 1}
};
#endif

void glow_all()
{
#ifdef debug
  Serial.println("glow all LEDs.");
#endif
  digitalWrite(12, LOW);    // Dot Matrix pin no 1
  digitalWrite(11, LOW);    // Dot Matrix pin no 14
  digitalWrite(9, LOW);
  digitalWrite(8, LOW);
  digitalWrite(5, LOW);
  digitalWrite(7, LOW);
  digitalWrite(2, LOW);
  digitalWrite(13, HIGH);
  digitalWrite(3, HIGH);
  digitalWrite(4, HIGH);
  digitalWrite(10, HIGH);
  digitalWrite(6, HIGH);
}

void off_all()
{
#ifdef debug
  Serial.println("off all LEDs.");
#endif
  digitalWrite(12, LOW);    // Dot Matrix pin no 1
  digitalWrite(11, LOW);    // Dot Matrix pin no 14
  digitalWrite(9, LOW);
  digitalWrite(8, LOW);
  digitalWrite(5, LOW);
  digitalWrite(7, LOW);
  digitalWrite(2, LOW);
  digitalWrite(13, LOW);
  digitalWrite(3, LOW);
  digitalWrite(4, LOW);
  digitalWrite(10, LOW);
  digitalWrite(6, LOW);
}

void glow_led(int ledNumber)
{
  switch (ledNumber)
  {
    case 1:
#ifdef debug
      Serial.print("Case : ");
      Serial.println(ledNumber);
#endif
      digitalWrite(9, LOW);
      digitalWrite(11, HIGH);
      digitalWrite(8, HIGH);
      digitalWrite(5, HIGH);
      digitalWrite(12, HIGH);
      digitalWrite(7, HIGH);
      digitalWrite(2, HIGH);

      digitalWrite(13, HIGH);
      break;
    case 2:
      digitalWrite(9, LOW);
      digitalWrite(11, HIGH);
      digitalWrite(8, HIGH);
      digitalWrite(5, HIGH);
      digitalWrite(12, HIGH);
      digitalWrite(7, HIGH);
      digitalWrite(2, HIGH);

      digitalWrite(3, HIGH);
      break;
    case 3:
      digitalWrite(9, LOW);
      digitalWrite(11, HIGH);
      digitalWrite(8, HIGH);
      digitalWrite(5, HIGH);
      digitalWrite(12, HIGH);
      digitalWrite(7, HIGH);
      digitalWrite(2, HIGH);

      digitalWrite(4, HIGH);
      break;
    case 4:
      digitalWrite(9, LOW);
      digitalWrite(11, HIGH);
      digitalWrite(8, HIGH);
      digitalWrite(5, HIGH);
      digitalWrite(12, HIGH);
      digitalWrite(7, HIGH);
      digitalWrite(2, HIGH);

      digitalWrite(10, HIGH);
      break;
    case 5:
      digitalWrite(9, LOW);
      digitalWrite(11, HIGH);
      digitalWrite(8, HIGH);
      digitalWrite(5, HIGH);
      digitalWrite(12, HIGH);
      digitalWrite(7, HIGH);
      digitalWrite(2, HIGH);

      digitalWrite(6, HIGH);
      break;
    case 6:
      digitalWrite(9, HIGH);
      //off_all();
      digitalWrite(11, LOW);
      digitalWrite(8, HIGH);
      digitalWrite(5, HIGH);
      digitalWrite(12, HIGH);
      digitalWrite(7, HIGH);
      digitalWrite(2, HIGH);

      digitalWrite(13, HIGH);
      break;
    case 7:
      digitalWrite(9, HIGH);
      digitalWrite(11, LOW);
      digitalWrite(8, HIGH);
      digitalWrite(5, HIGH);
      digitalWrite(12, HIGH);
      digitalWrite(7, HIGH);
      digitalWrite(2, HIGH);

      digitalWrite(3, HIGH);
      break;
    case 8:
      digitalWrite(9, HIGH);
      digitalWrite(11, LOW);
      digitalWrite(8, HIGH);
      digitalWrite(5, HIGH);
      digitalWrite(12, HIGH);
      digitalWrite(7, HIGH);
      digitalWrite(2, HIGH);

      digitalWrite(4, HIGH);
      break;
    case 9:
      digitalWrite(9, HIGH);
      digitalWrite(11, LOW);
      digitalWrite(8, HIGH);
      digitalWrite(5, HIGH);
      digitalWrite(12, HIGH);
      digitalWrite(7, HIGH);
      digitalWrite(2, HIGH);

      digitalWrite(10, HIGH);
      break;
    case 10:
      digitalWrite(9, HIGH);
      digitalWrite(11, LOW);
      digitalWrite(8, HIGH);
      digitalWrite(5, HIGH);
      digitalWrite(12, HIGH);
      digitalWrite(7, HIGH);
      digitalWrite(2, HIGH);

      digitalWrite(6, HIGH);
      break;
    case 11:
      digitalWrite(9, HIGH);
      digitalWrite(11, HIGH);
      digitalWrite(8, LOW);
      digitalWrite(5, HIGH);
      digitalWrite(12, HIGH);
      digitalWrite(7, HIGH);
      digitalWrite(2, HIGH);

      digitalWrite(13, HIGH);
      break;
    case 12:
      digitalWrite(9, HIGH);
      digitalWrite(11, HIGH);
      digitalWrite(8, LOW);
      digitalWrite(5, HIGH);
      digitalWrite(12, HIGH);
      digitalWrite(7, HIGH);
      digitalWrite(2, HIGH);

      digitalWrite(3, HIGH);
      break;
    case 13:
      digitalWrite(9, HIGH);
      digitalWrite(11, HIGH);
      digitalWrite(8, LOW);
      digitalWrite(5, HIGH);
      digitalWrite(12, HIGH);
      digitalWrite(7, HIGH);
      digitalWrite(2, HIGH);

      digitalWrite(4, HIGH);
      break;
    case 14:
      digitalWrite(9, HIGH);
      digitalWrite(11, HIGH);
      digitalWrite(8, LOW);
      digitalWrite(5, HIGH);
      digitalWrite(12, HIGH);
      digitalWrite(7, HIGH);
      digitalWrite(2, HIGH);

      digitalWrite(10, HIGH);
      break;
    case 15:
      digitalWrite(9, HIGH);
      digitalWrite(11, HIGH);
      digitalWrite(8, LOW);
      digitalWrite(5, HIGH);
      digitalWrite(12, HIGH);
      digitalWrite(7, HIGH);
      digitalWrite(2, HIGH);

      digitalWrite(6, HIGH);
      break;
    case 16:
      digitalWrite(9, HIGH);
      digitalWrite(11, HIGH);
      digitalWrite(8, HIGH);
      digitalWrite(5, LOW);
      digitalWrite(12, HIGH);
      digitalWrite(7, HIGH);
      digitalWrite(2, HIGH);

      digitalWrite(13, HIGH);
      break;
    case 17:
      digitalWrite(9, HIGH);
      digitalWrite(11, HIGH);
      digitalWrite(8, HIGH);
      digitalWrite(5, LOW);
      digitalWrite(12, HIGH);
      digitalWrite(7, HIGH);
      digitalWrite(2, HIGH);

      digitalWrite(3, HIGH);
      break;
    case 18:
      digitalWrite(9, HIGH);
      digitalWrite(11, HIGH);
      digitalWrite(8, HIGH);
      digitalWrite(5, LOW);
      digitalWrite(12, HIGH);
      digitalWrite(7, HIGH);
      digitalWrite(2, HIGH);

      digitalWrite(4, HIGH);
      break;
    case 19:
      digitalWrite(9, HIGH);
      digitalWrite(11, HIGH);
      digitalWrite(8, HIGH);
      digitalWrite(5, LOW);
      digitalWrite(12, HIGH);
      digitalWrite(7, HIGH);
      digitalWrite(2, HIGH);

      digitalWrite(10, HIGH);
      break;
    case 20:
      digitalWrite(9, HIGH);
      digitalWrite(11, HIGH);
      digitalWrite(8, HIGH);
      digitalWrite(5, LOW);
      digitalWrite(12, HIGH);
      digitalWrite(7, HIGH);
      digitalWrite(2, HIGH);

      digitalWrite(6, HIGH);
      break;
    case 21:
      digitalWrite(9, HIGH);
      digitalWrite(11, HIGH);
      digitalWrite(8, HIGH);
      digitalWrite(5, HIGH);
      digitalWrite(12, LOW);
      digitalWrite(7, HIGH);
      digitalWrite(2, HIGH);

      digitalWrite(13, HIGH);
      break;
    case 22:
      digitalWrite(9, HIGH);
      digitalWrite(11, HIGH);
      digitalWrite(8, HIGH);
      digitalWrite(5, HIGH);
      digitalWrite(12, LOW);
      digitalWrite(7, HIGH);
      digitalWrite(2, HIGH);

      digitalWrite(3, HIGH);
      break;
    case 23:
      digitalWrite(9, HIGH);
      digitalWrite(11, HIGH);
      digitalWrite(8, HIGH);
      digitalWrite(5, HIGH);
      digitalWrite(12, LOW);
      digitalWrite(7, HIGH);
      digitalWrite(2, HIGH);

      digitalWrite(4, HIGH);
      break;
    case 24:
      digitalWrite(9, HIGH);
      digitalWrite(11, HIGH);
      digitalWrite(8, HIGH);
      digitalWrite(5, HIGH);
      digitalWrite(12, LOW);
      digitalWrite(7, HIGH);
      digitalWrite(2, HIGH);

      digitalWrite(10, HIGH);
      break;
    case 25:
      digitalWrite(9, HIGH);
      digitalWrite(11, HIGH);
      digitalWrite(8, HIGH);
      digitalWrite(5, HIGH);
      digitalWrite(12, LOW);
      digitalWrite(7, HIGH);
      digitalWrite(2, HIGH);

      digitalWrite(6, HIGH);
      break;
    case 26:
      digitalWrite(9, HIGH);
      digitalWrite(11, HIGH);
      digitalWrite(8, HIGH);
      digitalWrite(5, HIGH);
      digitalWrite(12, HIGH);
      digitalWrite(7, LOW);
      digitalWrite(2, HIGH);

      digitalWrite(13, HIGH);
      break;
    case 27:
      digitalWrite(9, HIGH);
      digitalWrite(11, HIGH);
      digitalWrite(8, HIGH);
      digitalWrite(5, HIGH);
      digitalWrite(12, HIGH);
      digitalWrite(7, LOW);
      digitalWrite(2, HIGH);

      digitalWrite(3, HIGH);
      break;
    case 28:
      digitalWrite(9, HIGH);
      digitalWrite(11, HIGH);
      digitalWrite(8, HIGH);
      digitalWrite(5, HIGH);
      digitalWrite(12, HIGH);
      digitalWrite(7, LOW);
      digitalWrite(2, HIGH);

      digitalWrite(4, HIGH);
      break;
    case 29:
      digitalWrite(9, HIGH);
      digitalWrite(11, HIGH);
      digitalWrite(8, HIGH);
      digitalWrite(5, HIGH);
      digitalWrite(12, HIGH);
      digitalWrite(7, LOW);
      digitalWrite(2, HIGH);

      digitalWrite(10, HIGH);
      break;
    case 30:
      digitalWrite(9, HIGH);
      digitalWrite(11, HIGH);
      digitalWrite(8, HIGH);
      digitalWrite(5, HIGH);
      digitalWrite(12, HIGH);
      digitalWrite(7, LOW);
      digitalWrite(2, HIGH);

      digitalWrite(6, HIGH);
      break;
    case 31:
      digitalWrite(9, HIGH);
      digitalWrite(11, HIGH);
      digitalWrite(8, HIGH);
      digitalWrite(5, HIGH);
      digitalWrite(12, HIGH);
      digitalWrite(7, HIGH);
      digitalWrite(2, LOW);

      digitalWrite(13, HIGH);
      break;
    case 32:
      digitalWrite(9, HIGH);
      digitalWrite(11, HIGH);
      digitalWrite(8, HIGH);
      digitalWrite(5, HIGH);
      digitalWrite(12, HIGH);
      digitalWrite(7, HIGH);
      digitalWrite(2, LOW);

      digitalWrite(3, HIGH);
      break;
    case 33:
      digitalWrite(9, HIGH);
      digitalWrite(11, HIGH);
      digitalWrite(8, HIGH);
      digitalWrite(5, HIGH);
      digitalWrite(12, HIGH);
      digitalWrite(7, HIGH);
      digitalWrite(2, LOW);

      digitalWrite(4, HIGH);
      break;
    case 34:
      digitalWrite(9, HIGH);
      digitalWrite(11, HIGH);
      digitalWrite(8, HIGH);
      digitalWrite(5, HIGH);
      digitalWrite(12, HIGH);
      digitalWrite(7, HIGH);
      digitalWrite(2, LOW);

      digitalWrite(10, HIGH);
      break;
    case 35:
      digitalWrite(9, HIGH);
      digitalWrite(11, HIGH);
      digitalWrite(8, HIGH);
      digitalWrite(5, HIGH);
      digitalWrite(12, HIGH);
      digitalWrite(7, HIGH);
      digitalWrite(2, LOW);

      digitalWrite(6, HIGH);
      break;
    default:
      break;
  }
}

void off_led(int ledNumber)
{
  switch (ledNumber)
  {
    case 1:
#ifdef debug
      Serial.print("Case : ");
      Serial.println(ledNumber);
#endif
      digitalWrite(9, LOW);
      digitalWrite(11, HIGH);
      digitalWrite(8, HIGH);
      digitalWrite(5, HIGH);
      digitalWrite(12, HIGH);
      digitalWrite(7, HIGH);
      digitalWrite(2, HIGH);

      digitalWrite(13, LOW);
      break;
    case 2:
      digitalWrite(9, LOW);
      digitalWrite(11, HIGH);
      digitalWrite(8, HIGH);
      digitalWrite(5, HIGH);
      digitalWrite(12, HIGH);
      digitalWrite(7, HIGH);
      digitalWrite(2, HIGH);

      digitalWrite(3, LOW);
      break;
    case 3:
      digitalWrite(9, LOW);
      digitalWrite(11, HIGH);
      digitalWrite(8, HIGH);
      digitalWrite(5, HIGH);
      digitalWrite(12, HIGH);
      digitalWrite(7, HIGH);
      digitalWrite(2, HIGH);

      digitalWrite(4, LOW);
      break;
    case 4:
      digitalWrite(9, LOW);
      digitalWrite(11, HIGH);
      digitalWrite(8, HIGH);
      digitalWrite(5, HIGH);
      digitalWrite(12, HIGH);
      digitalWrite(7, HIGH);
      digitalWrite(2, HIGH);

      digitalWrite(10, LOW);
      break;
    case 5:
      digitalWrite(9, LOW);
      digitalWrite(11, HIGH);
      digitalWrite(8, HIGH);
      digitalWrite(5, HIGH);
      digitalWrite(12, HIGH);
      digitalWrite(7, HIGH);
      digitalWrite(2, HIGH);

      digitalWrite(6, LOW);
      break;
    case 6:
      digitalWrite(9, HIGH);
      digitalWrite(11, LOW);
      digitalWrite(8, HIGH);
      digitalWrite(5, HIGH);
      digitalWrite(12, HIGH);
      digitalWrite(7, HIGH);
      digitalWrite(2, HIGH);

      digitalWrite(13, LOW);
      break;
    case 7:
      digitalWrite(9, HIGH);
      digitalWrite(11, LOW);
      digitalWrite(8, HIGH);
      digitalWrite(5, HIGH);
      digitalWrite(12, HIGH);
      digitalWrite(7, HIGH);
      digitalWrite(2, HIGH);

      digitalWrite(3, LOW);
      break;
    case 8:
      digitalWrite(9, HIGH);
      digitalWrite(11, LOW);
      digitalWrite(8, HIGH);
      digitalWrite(5, HIGH);
      digitalWrite(12, HIGH);
      digitalWrite(7, HIGH);
      digitalWrite(2, HIGH);

      digitalWrite(4, LOW);
      break;
    case 9:
      digitalWrite(9, HIGH);
      digitalWrite(11, LOW);
      digitalWrite(8, HIGH);
      digitalWrite(5, HIGH);
      digitalWrite(12, HIGH);
      digitalWrite(7, HIGH);
      digitalWrite(2, HIGH);

      digitalWrite(10, LOW);
      break;
    case 10:
      digitalWrite(9, HIGH);
      digitalWrite(11, LOW);
      digitalWrite(8, HIGH);
      digitalWrite(5, HIGH);
      digitalWrite(12, HIGH);
      digitalWrite(7, HIGH);
      digitalWrite(2, HIGH);

      digitalWrite(6, LOW);
      break;
    case 11:
      digitalWrite(9, HIGH);
      digitalWrite(11, HIGH);
      digitalWrite(8, LOW);
      digitalWrite(5, HIGH);
      digitalWrite(12, HIGH);
      digitalWrite(7, HIGH);
      digitalWrite(2, HIGH);

      digitalWrite(13, LOW);
      break;
    case 12:
      digitalWrite(9, HIGH);
      digitalWrite(11, HIGH);
      digitalWrite(8, LOW);
      digitalWrite(5, HIGH);
      digitalWrite(12, HIGH);
      digitalWrite(7, HIGH);
      digitalWrite(2, HIGH);

      digitalWrite(3, LOW);
      break;
    case 13:
      digitalWrite(9, HIGH);
      digitalWrite(11, HIGH);
      digitalWrite(8, LOW);
      digitalWrite(5, HIGH);
      digitalWrite(12, HIGH);
      digitalWrite(7, HIGH);
      digitalWrite(2, HIGH);

      digitalWrite(4, LOW);
      break;
    case 14:
      digitalWrite(9, HIGH);
      digitalWrite(11, HIGH);
      digitalWrite(8, LOW);
      digitalWrite(5, HIGH);
      digitalWrite(12, HIGH);
      digitalWrite(7, HIGH);
      digitalWrite(2, HIGH);

      digitalWrite(10, LOW);
      break;
    case 15:
      digitalWrite(9, HIGH);
      digitalWrite(11, HIGH);
      digitalWrite(8, LOW);
      digitalWrite(5, HIGH);
      digitalWrite(12, HIGH);
      digitalWrite(7, HIGH);
      digitalWrite(2, HIGH);

      digitalWrite(6, LOW);
      break;
    case 16:
      digitalWrite(9, HIGH);
      digitalWrite(11, HIGH);
      digitalWrite(8, HIGH);
      digitalWrite(5, LOW);
      digitalWrite(12, HIGH);
      digitalWrite(7, HIGH);
      digitalWrite(2, HIGH);

      digitalWrite(13, LOW);
      break;
    case 17:
      digitalWrite(9, HIGH);
      digitalWrite(11, HIGH);
      digitalWrite(8, HIGH);
      digitalWrite(5, LOW);
      digitalWrite(12, HIGH);
      digitalWrite(7, HIGH);
      digitalWrite(2, HIGH);

      digitalWrite(3, LOW);
      break;
    case 18:
      digitalWrite(9, HIGH);
      digitalWrite(11, HIGH);
      digitalWrite(8, HIGH);
      digitalWrite(5, LOW);
      digitalWrite(12, HIGH);
      digitalWrite(7, HIGH);
      digitalWrite(2, HIGH);

      digitalWrite(4, LOW);
      break;
    case 19:
      digitalWrite(9, HIGH);
      digitalWrite(11, HIGH);
      digitalWrite(8, HIGH);
      digitalWrite(5, LOW);
      digitalWrite(12, HIGH);
      digitalWrite(7, HIGH);
      digitalWrite(2, HIGH);

      digitalWrite(10, LOW);
      break;
    case 20:
      digitalWrite(9, HIGH);
      digitalWrite(11, HIGH);
      digitalWrite(8, HIGH);
      digitalWrite(5, LOW);
      digitalWrite(12, HIGH);
      digitalWrite(7, HIGH);
      digitalWrite(2, HIGH);

      digitalWrite(6, LOW);
      break;
    case 21:
      digitalWrite(9, HIGH);
      digitalWrite(11, HIGH);
      digitalWrite(8, HIGH);
      digitalWrite(5, HIGH);
      digitalWrite(12, LOW);
      digitalWrite(7, HIGH);
      digitalWrite(2, HIGH);

      digitalWrite(13, LOW);
      break;
    case 22:
      digitalWrite(9, HIGH);
      digitalWrite(11, HIGH);
      digitalWrite(8, HIGH);
      digitalWrite(5, HIGH);
      digitalWrite(12, LOW);
      digitalWrite(7, HIGH);
      digitalWrite(2, HIGH);

      digitalWrite(3, LOW);
      break;
    case 23:
      digitalWrite(9, HIGH);
      digitalWrite(11, HIGH);
      digitalWrite(8, HIGH);
      digitalWrite(5, HIGH);
      digitalWrite(12, LOW);
      digitalWrite(7, HIGH);
      digitalWrite(2, HIGH);

      digitalWrite(4, LOW);
      break;
    case 24:
      digitalWrite(9, HIGH);
      digitalWrite(11, HIGH);
      digitalWrite(8, HIGH);
      digitalWrite(5, HIGH);
      digitalWrite(12, LOW);
      digitalWrite(7, HIGH);
      digitalWrite(2, HIGH);

      digitalWrite(10, LOW);
      break;
    case 25:
      digitalWrite(9, HIGH);
      digitalWrite(11, HIGH);
      digitalWrite(8, HIGH);
      digitalWrite(5, HIGH);
      digitalWrite(12, LOW);
      digitalWrite(7, HIGH);
      digitalWrite(2, HIGH);

      digitalWrite(6, LOW);
      break;
    case 26:
      digitalWrite(9, HIGH);
      digitalWrite(11, HIGH);
      digitalWrite(8, HIGH);
      digitalWrite(5, HIGH);
      digitalWrite(12, HIGH);
      digitalWrite(7, LOW);
      digitalWrite(2, HIGH);

      digitalWrite(13, LOW);
      break;
    case 27:
      digitalWrite(9, HIGH);
      digitalWrite(11, HIGH);
      digitalWrite(8, HIGH);
      digitalWrite(5, HIGH);
      digitalWrite(12, HIGH);
      digitalWrite(7, LOW);
      digitalWrite(2, HIGH);

      digitalWrite(3, LOW);
      break;
    case 28:
      digitalWrite(9, HIGH);
      digitalWrite(11, HIGH);
      digitalWrite(8, HIGH);
      digitalWrite(5, HIGH);
      digitalWrite(12, HIGH);
      digitalWrite(7, LOW);
      digitalWrite(2, HIGH);

      digitalWrite(4, LOW);
      break;
    case 29:
      digitalWrite(9, HIGH);
      digitalWrite(11, HIGH);
      digitalWrite(8, HIGH);
      digitalWrite(5, HIGH);
      digitalWrite(12, HIGH);
      digitalWrite(7, LOW);
      digitalWrite(2, HIGH);

      digitalWrite(10, LOW);
      break;
    case 30:
      digitalWrite(9, HIGH);
      digitalWrite(11, HIGH);
      digitalWrite(8, HIGH);
      digitalWrite(5, HIGH);
      digitalWrite(12, HIGH);
      digitalWrite(7, LOW);
      digitalWrite(2, HIGH);

      digitalWrite(6, LOW);
      break;
    case 31:
      digitalWrite(9, HIGH);
      digitalWrite(11, HIGH);
      digitalWrite(8, HIGH);
      digitalWrite(5, HIGH);
      digitalWrite(12, HIGH);
      digitalWrite(7, HIGH);
      digitalWrite(2, LOW);

      digitalWrite(13, LOW);
      break;
    case 32:
      digitalWrite(9, HIGH);
      digitalWrite(11, HIGH);
      digitalWrite(8, HIGH);
      digitalWrite(5, HIGH);
      digitalWrite(12, HIGH);
      digitalWrite(7, HIGH);
      digitalWrite(2, LOW);

      digitalWrite(3, LOW);
      break;
    case 33:
      digitalWrite(9, HIGH);
      digitalWrite(11, HIGH);
      digitalWrite(8, HIGH);
      digitalWrite(5, HIGH);
      digitalWrite(12, HIGH);
      digitalWrite(7, HIGH);
      digitalWrite(2, LOW);

      digitalWrite(4, LOW);
      break;
    case 34:
      digitalWrite(9, HIGH);
      digitalWrite(11, HIGH);
      digitalWrite(8, HIGH);
      digitalWrite(5, HIGH);
      digitalWrite(12, HIGH);
      digitalWrite(7, HIGH);
      digitalWrite(2, LOW);

      digitalWrite(10, LOW);
      break;
    case 35:
      digitalWrite(9, HIGH);
      digitalWrite(11, HIGH);
      digitalWrite(8, HIGH);
      digitalWrite(5, HIGH);
      digitalWrite(12, HIGH);
      digitalWrite(7, HIGH);
      digitalWrite(2, LOW);

      digitalWrite(6, LOW);
      break;
    default:
      break;
  }
}

////////////////////////////////////////////////////////////////////////////////////////

void glow_led_scroll(int ledNumber)
{
  switch (ledNumber)
  {
    case 6:
#ifdef debug
      Serial.print("Case : ");
      Serial.println(ledNumber);
#endif
      digitalWrite(9, LOW);
      digitalWrite(11, HIGH);
      digitalWrite(8, HIGH);
      digitalWrite(5, HIGH);
      digitalWrite(12, HIGH);
      digitalWrite(7, HIGH);
      digitalWrite(2, HIGH);

      digitalWrite(13, HIGH);
      break;
    case 7:
      digitalWrite(9, LOW);
      digitalWrite(11, HIGH);
      digitalWrite(8, HIGH);
      digitalWrite(5, HIGH);
      digitalWrite(12, HIGH);
      digitalWrite(7, HIGH);
      digitalWrite(2, HIGH);

      digitalWrite(3, HIGH);
      break;
    case 8:
      digitalWrite(9, LOW);
      digitalWrite(11, HIGH);
      digitalWrite(8, HIGH);
      digitalWrite(5, HIGH);
      digitalWrite(12, HIGH);
      digitalWrite(7, HIGH);
      digitalWrite(2, HIGH);

      digitalWrite(4, HIGH);
      break;
    case 9:
      digitalWrite(9, LOW);
      digitalWrite(11, HIGH);
      digitalWrite(8, HIGH);
      digitalWrite(5, HIGH);
      digitalWrite(12, HIGH);
      digitalWrite(7, HIGH);
      digitalWrite(2, HIGH);

      digitalWrite(10, HIGH);
      break;
    case 10:
      digitalWrite(9, LOW);
      digitalWrite(11, HIGH);
      digitalWrite(8, HIGH);
      digitalWrite(5, HIGH);
      digitalWrite(12, HIGH);
      digitalWrite(7, HIGH);
      digitalWrite(2, HIGH);

      digitalWrite(6, HIGH);
      break;
    case 21:
      digitalWrite(9, HIGH);
      //off_all();
      digitalWrite(11, LOW);
      digitalWrite(8, HIGH);
      digitalWrite(5, HIGH);
      digitalWrite(12, HIGH);
      digitalWrite(7, HIGH);
      digitalWrite(2, HIGH);

      digitalWrite(13, HIGH);
      break;
    case 22:
      digitalWrite(9, HIGH);
      digitalWrite(11, LOW);
      digitalWrite(8, HIGH);
      digitalWrite(5, HIGH);
      digitalWrite(12, HIGH);
      digitalWrite(7, HIGH);
      digitalWrite(2, HIGH);

      digitalWrite(3, HIGH);
      break;
    case 23:
      digitalWrite(9, HIGH);
      digitalWrite(11, LOW);
      digitalWrite(8, HIGH);
      digitalWrite(5, HIGH);
      digitalWrite(12, HIGH);
      digitalWrite(7, HIGH);
      digitalWrite(2, HIGH);

      digitalWrite(4, HIGH);
      break;
    case 24:
      digitalWrite(9, HIGH);
      digitalWrite(11, LOW);
      digitalWrite(8, HIGH);
      digitalWrite(5, HIGH);
      digitalWrite(12, HIGH);
      digitalWrite(7, HIGH);
      digitalWrite(2, HIGH);

      digitalWrite(10, HIGH);
      break;
    case 25:
      digitalWrite(9, HIGH);
      digitalWrite(11, LOW);
      digitalWrite(8, HIGH);
      digitalWrite(5, HIGH);
      digitalWrite(12, HIGH);
      digitalWrite(7, HIGH);
      digitalWrite(2, HIGH);

      digitalWrite(6, HIGH);
      break;
    case 36:
      digitalWrite(9, HIGH);
      digitalWrite(11, HIGH);
      digitalWrite(8, LOW);
      digitalWrite(5, HIGH);
      digitalWrite(12, HIGH);
      digitalWrite(7, HIGH);
      digitalWrite(2, HIGH);

      digitalWrite(13, HIGH);
      break;
    case 37:
      digitalWrite(9, HIGH);
      digitalWrite(11, HIGH);
      digitalWrite(8, LOW);
      digitalWrite(5, HIGH);
      digitalWrite(12, HIGH);
      digitalWrite(7, HIGH);
      digitalWrite(2, HIGH);

      digitalWrite(3, HIGH);
      break;
    case 38:
      digitalWrite(9, HIGH);
      digitalWrite(11, HIGH);
      digitalWrite(8, LOW);
      digitalWrite(5, HIGH);
      digitalWrite(12, HIGH);
      digitalWrite(7, HIGH);
      digitalWrite(2, HIGH);

      digitalWrite(4, HIGH);
      break;
    case 39:
      digitalWrite(9, HIGH);
      digitalWrite(11, HIGH);
      digitalWrite(8, LOW);
      digitalWrite(5, HIGH);
      digitalWrite(12, HIGH);
      digitalWrite(7, HIGH);
      digitalWrite(2, HIGH);

      digitalWrite(10, HIGH);
      break;
    case 40:
      digitalWrite(9, HIGH);
      digitalWrite(11, HIGH);
      digitalWrite(8, LOW);
      digitalWrite(5, HIGH);
      digitalWrite(12, HIGH);
      digitalWrite(7, HIGH);
      digitalWrite(2, HIGH);

      digitalWrite(6, HIGH);
      break;
    case 51:
      digitalWrite(9, HIGH);
      digitalWrite(11, HIGH);
      digitalWrite(8, HIGH);
      digitalWrite(5, LOW);
      digitalWrite(12, HIGH);
      digitalWrite(7, HIGH);
      digitalWrite(2, HIGH);

      digitalWrite(13, HIGH);
      break;
    case 52:
      digitalWrite(9, HIGH);
      digitalWrite(11, HIGH);
      digitalWrite(8, HIGH);
      digitalWrite(5, LOW);
      digitalWrite(12, HIGH);
      digitalWrite(7, HIGH);
      digitalWrite(2, HIGH);

      digitalWrite(3, HIGH);
      break;
    case 53:
      digitalWrite(9, HIGH);
      digitalWrite(11, HIGH);
      digitalWrite(8, HIGH);
      digitalWrite(5, LOW);
      digitalWrite(12, HIGH);
      digitalWrite(7, HIGH);
      digitalWrite(2, HIGH);

      digitalWrite(4, HIGH);
      break;
    case 54:
      digitalWrite(9, HIGH);
      digitalWrite(11, HIGH);
      digitalWrite(8, HIGH);
      digitalWrite(5, LOW);
      digitalWrite(12, HIGH);
      digitalWrite(7, HIGH);
      digitalWrite(2, HIGH);

      digitalWrite(10, HIGH);
      break;
    case 55:
      digitalWrite(9, HIGH);
      digitalWrite(11, HIGH);
      digitalWrite(8, HIGH);
      digitalWrite(5, LOW);
      digitalWrite(12, HIGH);
      digitalWrite(7, HIGH);
      digitalWrite(2, HIGH);

      digitalWrite(6, HIGH);
      break;
    case 66:
      digitalWrite(9, HIGH);
      digitalWrite(11, HIGH);
      digitalWrite(8, HIGH);
      digitalWrite(5, HIGH);
      digitalWrite(12, LOW);
      digitalWrite(7, HIGH);
      digitalWrite(2, HIGH);

      digitalWrite(13, HIGH);
      break;
    case 67:
      digitalWrite(9, HIGH);
      digitalWrite(11, HIGH);
      digitalWrite(8, HIGH);
      digitalWrite(5, HIGH);
      digitalWrite(12, LOW);
      digitalWrite(7, HIGH);
      digitalWrite(2, HIGH);

      digitalWrite(3, HIGH);
      break;
    case 68:
      digitalWrite(9, HIGH);
      digitalWrite(11, HIGH);
      digitalWrite(8, HIGH);
      digitalWrite(5, HIGH);
      digitalWrite(12, LOW);
      digitalWrite(7, HIGH);
      digitalWrite(2, HIGH);

      digitalWrite(4, HIGH);
      break;
    case 69:
      digitalWrite(9, HIGH);
      digitalWrite(11, HIGH);
      digitalWrite(8, HIGH);
      digitalWrite(5, HIGH);
      digitalWrite(12, LOW);
      digitalWrite(7, HIGH);
      digitalWrite(2, HIGH);

      digitalWrite(10, HIGH);
      break;
    case 70:
      digitalWrite(9, HIGH);
      digitalWrite(11, HIGH);
      digitalWrite(8, HIGH);
      digitalWrite(5, HIGH);
      digitalWrite(12, LOW);
      digitalWrite(7, HIGH);
      digitalWrite(2, HIGH);

      digitalWrite(6, HIGH);
      break;
    case 81:
      digitalWrite(9, HIGH);
      digitalWrite(11, HIGH);
      digitalWrite(8, HIGH);
      digitalWrite(5, HIGH);
      digitalWrite(12, HIGH);
      digitalWrite(7, LOW);
      digitalWrite(2, HIGH);

      digitalWrite(13, HIGH);
      break;
    case 82:
      digitalWrite(9, HIGH);
      digitalWrite(11, HIGH);
      digitalWrite(8, HIGH);
      digitalWrite(5, HIGH);
      digitalWrite(12, HIGH);
      digitalWrite(7, LOW);
      digitalWrite(2, HIGH);

      digitalWrite(3, HIGH);
      break;
    case 83:
      digitalWrite(9, HIGH);
      digitalWrite(11, HIGH);
      digitalWrite(8, HIGH);
      digitalWrite(5, HIGH);
      digitalWrite(12, HIGH);
      digitalWrite(7, LOW);
      digitalWrite(2, HIGH);

      digitalWrite(4, HIGH);
      break;
    case 84:
      digitalWrite(9, HIGH);
      digitalWrite(11, HIGH);
      digitalWrite(8, HIGH);
      digitalWrite(5, HIGH);
      digitalWrite(12, HIGH);
      digitalWrite(7, LOW);
      digitalWrite(2, HIGH);

      digitalWrite(10, HIGH);
      break;
    case 85:
      digitalWrite(9, HIGH);
      digitalWrite(11, HIGH);
      digitalWrite(8, HIGH);
      digitalWrite(5, HIGH);
      digitalWrite(12, HIGH);
      digitalWrite(7, LOW);
      digitalWrite(2, HIGH);

      digitalWrite(6, HIGH);
      break;
    case 96:
      digitalWrite(9, HIGH);
      digitalWrite(11, HIGH);
      digitalWrite(8, HIGH);
      digitalWrite(5, HIGH);
      digitalWrite(12, HIGH);
      digitalWrite(7, HIGH);
      digitalWrite(2, LOW);

      digitalWrite(13, HIGH);
      break;
    case 97:
      digitalWrite(9, HIGH);
      digitalWrite(11, HIGH);
      digitalWrite(8, HIGH);
      digitalWrite(5, HIGH);
      digitalWrite(12, HIGH);
      digitalWrite(7, HIGH);
      digitalWrite(2, LOW);

      digitalWrite(3, HIGH);
      break;
    case 98:
      digitalWrite(9, HIGH);
      digitalWrite(11, HIGH);
      digitalWrite(8, HIGH);
      digitalWrite(5, HIGH);
      digitalWrite(12, HIGH);
      digitalWrite(7, HIGH);
      digitalWrite(2, LOW);

      digitalWrite(4, HIGH);
      break;
    case 99:
      digitalWrite(9, HIGH);
      digitalWrite(11, HIGH);
      digitalWrite(8, HIGH);
      digitalWrite(5, HIGH);
      digitalWrite(12, HIGH);
      digitalWrite(7, HIGH);
      digitalWrite(2, LOW);

      digitalWrite(10, HIGH);
      break;
    case 100:
      digitalWrite(9, HIGH);
      digitalWrite(11, HIGH);
      digitalWrite(8, HIGH);
      digitalWrite(5, HIGH);
      digitalWrite(12, HIGH);
      digitalWrite(7, HIGH);
      digitalWrite(2, LOW);

      digitalWrite(6, HIGH);
      break;
    default:
      break;
  }
}

void off_led_scroll(int ledNumber)
{
  switch (ledNumber)
  {
    case 6:
#ifdef debug
      Serial.print("Case : ");
      Serial.println(ledNumber);
#endif
      digitalWrite(9, LOW);
      digitalWrite(11, HIGH);
      digitalWrite(8, HIGH);
      digitalWrite(5, HIGH);
      digitalWrite(12, HIGH);
      digitalWrite(7, HIGH);
      digitalWrite(2, HIGH);

      digitalWrite(13, LOW);
      break;
    case 7:
      digitalWrite(9, LOW);
      digitalWrite(11, HIGH);
      digitalWrite(8, HIGH);
      digitalWrite(5, HIGH);
      digitalWrite(12, HIGH);
      digitalWrite(7, HIGH);
      digitalWrite(2, HIGH);

      digitalWrite(3, LOW);
      break;
    case 8:
      digitalWrite(9, LOW);
      digitalWrite(11, HIGH);
      digitalWrite(8, HIGH);
      digitalWrite(5, HIGH);
      digitalWrite(12, HIGH);
      digitalWrite(7, HIGH);
      digitalWrite(2, HIGH);

      digitalWrite(4, LOW);
      break;
    case 9:
      digitalWrite(9, LOW);
      digitalWrite(11, HIGH);
      digitalWrite(8, HIGH);
      digitalWrite(5, HIGH);
      digitalWrite(12, HIGH);
      digitalWrite(7, HIGH);
      digitalWrite(2, HIGH);

      digitalWrite(10, LOW);
      break;
    case 10:
      digitalWrite(9, LOW);
      digitalWrite(11, HIGH);
      digitalWrite(8, HIGH);
      digitalWrite(5, HIGH);
      digitalWrite(12, HIGH);
      digitalWrite(7, HIGH);
      digitalWrite(2, HIGH);

      digitalWrite(6, LOW);
      break;
    case 21:
      digitalWrite(9, HIGH);
      digitalWrite(11, LOW);
      digitalWrite(8, HIGH);
      digitalWrite(5, HIGH);
      digitalWrite(12, HIGH);
      digitalWrite(7, HIGH);
      digitalWrite(2, HIGH);

      digitalWrite(13, LOW);
      break;
    case 22:
      digitalWrite(9, HIGH);
      digitalWrite(11, LOW);
      digitalWrite(8, HIGH);
      digitalWrite(5, HIGH);
      digitalWrite(12, HIGH);
      digitalWrite(7, HIGH);
      digitalWrite(2, HIGH);

      digitalWrite(3, LOW);
      break;
    case 23:
      digitalWrite(9, HIGH);
      digitalWrite(11, LOW);
      digitalWrite(8, HIGH);
      digitalWrite(5, HIGH);
      digitalWrite(12, HIGH);
      digitalWrite(7, HIGH);
      digitalWrite(2, HIGH);

      digitalWrite(4, LOW);
      break;
    case 24:
      digitalWrite(9, HIGH);
      digitalWrite(11, LOW);
      digitalWrite(8, HIGH);
      digitalWrite(5, HIGH);
      digitalWrite(12, HIGH);
      digitalWrite(7, HIGH);
      digitalWrite(2, HIGH);

      digitalWrite(10, LOW);
      break;
    case 25:
      digitalWrite(9, HIGH);
      digitalWrite(11, LOW);
      digitalWrite(8, HIGH);
      digitalWrite(5, HIGH);
      digitalWrite(12, HIGH);
      digitalWrite(7, HIGH);
      digitalWrite(2, HIGH);

      digitalWrite(6, LOW);
      break;
    case 36:
      digitalWrite(9, HIGH);
      digitalWrite(11, HIGH);
      digitalWrite(8, LOW);
      digitalWrite(5, HIGH);
      digitalWrite(12, HIGH);
      digitalWrite(7, HIGH);
      digitalWrite(2, HIGH);

      digitalWrite(13, LOW);
      break;
    case 37:
      digitalWrite(9, HIGH);
      digitalWrite(11, HIGH);
      digitalWrite(8, LOW);
      digitalWrite(5, HIGH);
      digitalWrite(12, HIGH);
      digitalWrite(7, HIGH);
      digitalWrite(2, HIGH);

      digitalWrite(3, LOW);
      break;
    case 38:
      digitalWrite(9, HIGH);
      digitalWrite(11, HIGH);
      digitalWrite(8, LOW);
      digitalWrite(5, HIGH);
      digitalWrite(12, HIGH);
      digitalWrite(7, HIGH);
      digitalWrite(2, HIGH);

      digitalWrite(4, LOW);
      break;
    case 39:
      digitalWrite(9, HIGH);
      digitalWrite(11, HIGH);
      digitalWrite(8, LOW);
      digitalWrite(5, HIGH);
      digitalWrite(12, HIGH);
      digitalWrite(7, HIGH);
      digitalWrite(2, HIGH);

      digitalWrite(10, LOW);
      break;
    case 40:
      digitalWrite(9, HIGH);
      digitalWrite(11, HIGH);
      digitalWrite(8, LOW);
      digitalWrite(5, HIGH);
      digitalWrite(12, HIGH);
      digitalWrite(7, HIGH);
      digitalWrite(2, HIGH);

      digitalWrite(6, LOW);
      break;
    case 51:
      digitalWrite(9, HIGH);
      digitalWrite(11, HIGH);
      digitalWrite(8, HIGH);
      digitalWrite(5, LOW);
      digitalWrite(12, HIGH);
      digitalWrite(7, HIGH);
      digitalWrite(2, HIGH);

      digitalWrite(13, LOW);
      break;
    case 52:
      digitalWrite(9, HIGH);
      digitalWrite(11, HIGH);
      digitalWrite(8, HIGH);
      digitalWrite(5, LOW);
      digitalWrite(12, HIGH);
      digitalWrite(7, HIGH);
      digitalWrite(2, HIGH);

      digitalWrite(3, LOW);
      break;
    case 53:
      digitalWrite(9, HIGH);
      digitalWrite(11, HIGH);
      digitalWrite(8, HIGH);
      digitalWrite(5, LOW);
      digitalWrite(12, HIGH);
      digitalWrite(7, HIGH);
      digitalWrite(2, HIGH);

      digitalWrite(4, LOW);
      break;
    case 54:
      digitalWrite(9, HIGH);
      digitalWrite(11, HIGH);
      digitalWrite(8, HIGH);
      digitalWrite(5, LOW);
      digitalWrite(12, HIGH);
      digitalWrite(7, HIGH);
      digitalWrite(2, HIGH);

      digitalWrite(10, LOW);
      break;
    case 55:
      digitalWrite(9, HIGH);
      digitalWrite(11, HIGH);
      digitalWrite(8, HIGH);
      digitalWrite(5, LOW);
      digitalWrite(12, HIGH);
      digitalWrite(7, HIGH);
      digitalWrite(2, HIGH);

      digitalWrite(6, LOW);
      break;
    case 66:
      digitalWrite(9, HIGH);
      digitalWrite(11, HIGH);
      digitalWrite(8, HIGH);
      digitalWrite(5, HIGH);
      digitalWrite(12, LOW);
      digitalWrite(7, HIGH);
      digitalWrite(2, HIGH);

      digitalWrite(13, LOW);
      break;
    case 67:
      digitalWrite(9, HIGH);
      digitalWrite(11, HIGH);
      digitalWrite(8, HIGH);
      digitalWrite(5, HIGH);
      digitalWrite(12, LOW);
      digitalWrite(7, HIGH);
      digitalWrite(2, HIGH);

      digitalWrite(3, LOW);
      break;
    case 68:
      digitalWrite(9, HIGH);
      digitalWrite(11, HIGH);
      digitalWrite(8, HIGH);
      digitalWrite(5, HIGH);
      digitalWrite(12, LOW);
      digitalWrite(7, HIGH);
      digitalWrite(2, HIGH);

      digitalWrite(4, LOW);
      break;
    case 69:
      digitalWrite(9, HIGH);
      digitalWrite(11, HIGH);
      digitalWrite(8, HIGH);
      digitalWrite(5, HIGH);
      digitalWrite(12, LOW);
      digitalWrite(7, HIGH);
      digitalWrite(2, HIGH);

      digitalWrite(10, LOW);
      break;
    case 70:
      digitalWrite(9, HIGH);
      digitalWrite(11, HIGH);
      digitalWrite(8, HIGH);
      digitalWrite(5, HIGH);
      digitalWrite(12, LOW);
      digitalWrite(7, HIGH);
      digitalWrite(2, HIGH);

      digitalWrite(6, LOW);
      break;
    case 81:
      digitalWrite(9, HIGH);
      digitalWrite(11, HIGH);
      digitalWrite(8, HIGH);
      digitalWrite(5, HIGH);
      digitalWrite(12, HIGH);
      digitalWrite(7, LOW);
      digitalWrite(2, HIGH);

      digitalWrite(13, LOW);
      break;
    case 82:
      digitalWrite(9, HIGH);
      digitalWrite(11, HIGH);
      digitalWrite(8, HIGH);
      digitalWrite(5, HIGH);
      digitalWrite(12, HIGH);
      digitalWrite(7, LOW);
      digitalWrite(2, HIGH);

      digitalWrite(3, LOW);
      break;
    case 83:
      digitalWrite(9, HIGH);
      digitalWrite(11, HIGH);
      digitalWrite(8, HIGH);
      digitalWrite(5, HIGH);
      digitalWrite(12, HIGH);
      digitalWrite(7, LOW);
      digitalWrite(2, HIGH);

      digitalWrite(4, LOW);
      break;
    case 84:
      digitalWrite(9, HIGH);
      digitalWrite(11, HIGH);
      digitalWrite(8, HIGH);
      digitalWrite(5, HIGH);
      digitalWrite(12, HIGH);
      digitalWrite(7, LOW);
      digitalWrite(2, HIGH);

      digitalWrite(10, LOW);
      break;
    case 85:
      digitalWrite(9, HIGH);
      digitalWrite(11, HIGH);
      digitalWrite(8, HIGH);
      digitalWrite(5, HIGH);
      digitalWrite(12, HIGH);
      digitalWrite(7, LOW);
      digitalWrite(2, HIGH);

      digitalWrite(6, LOW);
      break;
    case 96:
      digitalWrite(9, HIGH);
      digitalWrite(11, HIGH);
      digitalWrite(8, HIGH);
      digitalWrite(5, HIGH);
      digitalWrite(12, HIGH);
      digitalWrite(7, HIGH);
      digitalWrite(2, LOW);

      digitalWrite(13, LOW);
      break;
    case 97:
      digitalWrite(9, HIGH);
      digitalWrite(11, HIGH);
      digitalWrite(8, HIGH);
      digitalWrite(5, HIGH);
      digitalWrite(12, HIGH);
      digitalWrite(7, HIGH);
      digitalWrite(2, LOW);

      digitalWrite(3, LOW);
      break;
    case 98:
      digitalWrite(9, HIGH);
      digitalWrite(11, HIGH);
      digitalWrite(8, HIGH);
      digitalWrite(5, HIGH);
      digitalWrite(12, HIGH);
      digitalWrite(7, HIGH);
      digitalWrite(2, LOW);

      digitalWrite(4, LOW);
      break;
    case 99:
      digitalWrite(9, HIGH);
      digitalWrite(11, HIGH);
      digitalWrite(8, HIGH);
      digitalWrite(5, HIGH);
      digitalWrite(12, HIGH);
      digitalWrite(7, HIGH);
      digitalWrite(2, LOW);

      digitalWrite(10, LOW);
      break;
    case 100:
      digitalWrite(9, HIGH);
      digitalWrite(11, HIGH);
      digitalWrite(8, HIGH);
      digitalWrite(5, HIGH);
      digitalWrite(12, HIGH);
      digitalWrite(7, HIGH);
      digitalWrite(2, LOW);

      digitalWrite(6, LOW);
      break;
    default:
      break;
  }
}

////////////////////////////////////////////////////////////////////////////////////////

void print_pattern(int print_array[7][5])
{
  int temp[7][5] = {
    { 1,  2,  3,  4,  5},
    { 6,  7,  8,  9, 10},
    {11, 12, 13, 14, 15},
    {16, 17, 18, 19, 20},
    {21, 22, 23, 24, 25},
    {26, 27, 28, 29, 30},
    {31, 32, 33, 34, 35}
  };
  for (int k = 0; k < 30; k++)
  {
    for (int i = 0; i < 7; i++)
    {
      for (int j = 0; j < 5; j++)
      {
        if(print_array[i][j] == 49)
        {
          glow_led(temp[i][j]);
          delayMicroseconds(1000);
          off_led(temp[i][j]);
          delayMicroseconds(1);
        }
      }
    }
  }
}

void disp_char(char c)
{
  int temp[7][5] = {
    {0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0}
  };
  char x[35];
  byte count = 0;
  switch (c)
  {
    case 'A':
      count = 0;
      break;
    case 'B':
      count = 1;
      break;
    case 'C':
      count = 2;
      break;
    case 'D':
      count = 3;
      break;
    case 'E':
      count = 4;
      break;
    case 'F':
      count = 5;
      break;
    case 'G':
      count = 6;
      break;
    case 'H':
      count = 7;
      break;
    case 'I':
      count = 8;
      break;
    case 'J':
      count = 9;
      break;
    case 'K':
      count = 10;
      break;
    case 'L':
      count = 11;
      break;
    case 'M':
      count = 12;
      break;
    case 'N':
      count = 13;
      break;
    case 'O':
      count = 14;
      break;
    case 'P':
      count = 15;
      break;
    case 'Q':
      count = 16;
      break;
    case 'R':
      count = 17;
      break;
    case 'S':
      count = 18;
      break;
    case 'T':
      count = 19;
      break;
    case 'U':
      count = 20;
      break;
    case 'V':
      count = 21;
      break;
    case 'W':
      count = 22;
      break;
    case 'X':
      count = 23;
      break;
    case 'Y':
      count = 24;
      break;
    case 'Z':
      count = 25;
      break;
    case '0':
      count = 26;
      break;
    case '1':
      count = 27;
      break;
    case '2':
      count = 28;
      break;
    case '3':
      count = 29;
      break;
    case '4':
      count = 30;
      break;
    case '5':
      count = 31;
      break;
    case '6':
      count = 32;
      break;
    case '7':
      count = 33;
      break;
    case '8':
      count = 34;
      break;
    case '9':
      count = 35;
      break;
    default:
      break;
  }
  strcpy_P(x, (char *)pgm_read_word(&(data_table[count])));
  count = 0;
  for (int i = 0; i < 7; i++)
  {
    for (int j = 0; j < 5; j++)
    {
      temp[i][j] = x[count];
      count++;
    }
  }
  count = 0;
  print_pattern(temp);
}

void disp_custom_char(int *arr, int size)
{
  for (int i = 0; i < 70; i++)
  {
    for (int i = 0; i < size; i++)
    {
      glow_led(arr[i]);
      delayMicroseconds(500);
      off_led(arr[i]);
      delayMicroseconds(1);
    }
  }
}

void glow_matrix_scroll(char c)
{

  int count = 0;
  int scroll = 0;
  int scroll_var = 0;
  int second_iteration_var = 0;
  int glow_map[7][15] = {
    {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15},
    {16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30},
    {31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45},
    {46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60},
    {61, 62, 63, 64, 65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75},
    {76, 77, 78, 79, 80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90},
    {91, 92, 93, 94, 95, 96, 97, 98, 99, 100, 101, 102, 103, 104, 105}
  };

  //xvar[0] = 'j';

  switch (c)
  {
    case 'X':
      while (scroll < 11)
      {
        while (count <= 10)
        {
          for (int i = 0; i < 7; i++)
          {
            for (int j = scroll_var; j <= (scroll_var + 4); j++)
            {
              if (J[i][second_iteration_var] == 1)
              {
                glow_led_scroll(glow_map[i][j]);
                delayMicroseconds(1500);
                off_led_scroll(glow_map[i][j]);
                delayMicroseconds(1);
                //Serial.print(glow_map[i][j]);
                //Serial.print("+++");
              }
              // Serial.print(j);
              //Serial.print("---");
              second_iteration_var ++;
              //if(second_iteration_var > 4) second_iteration_var=0;
            }
            //Serial.println();
            second_iteration_var = 0;
          }
          count++;
        }
        scroll++;
        count = 0;
        scroll_var++;
        //Serial.println(scroll_var);
      }
      break;
    case 'Y':
      while (scroll < 11)
      {
        while (count <= 10)
        {
          for (int i = 0; i < 7; i++)
          {
            for (int j = scroll_var; j <= (scroll_var + 4); j++)
            {
              if (T[i][second_iteration_var] == 1)
              {
                glow_led_scroll(glow_map[i][j]);
                delayMicroseconds(1500);
                off_led_scroll(glow_map[i][j]);
                delayMicroseconds(1);
              }
              second_iteration_var ++;
            }
            second_iteration_var = 0;
          }
          count++;
        }
        scroll++;
        count = 0;
        scroll_var++;
      }
      break;
    default:
      break;
  }

  //Serial.println("Exit Function");


}

void disp_char_scroll(char c)
{
  int count = 0;
  int scroll = 0;
  int scroll_var = 0;
  int second_iteration_var = 0;
  int glow_map[7][15] = {
    {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15},
    {16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30},
    {31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45},
    {46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60},
    {61, 62, 63, 64, 65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75},
    {76, 77, 78, 79, 80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90},
    {91, 92, 93, 94, 95, 96, 97, 98, 99, 100, 101, 102, 103, 104, 105}
  };
  switch (c)
  {

    case 'A':
      while (scroll < 11)
      {
        while (count <= 10)
        {
          for (int i = 0; i < 7; i++)
          {
            for (int j = scroll_var; j <= (scroll_var + 4); j++)
            {
              if (A[i][second_iteration_var] == 1)
              {
                glow_led_scroll(glow_map[i][j]);
                delayMicroseconds(1000);
                off_led_scroll(glow_map[i][j]);
                delayMicroseconds(1);
              }
              second_iteration_var ++;
            }
            second_iteration_var = 0;
          }
          count++;
        }
        scroll++;
        count = 0;
        scroll_var++;
      }
      break;

    case 'B':
      while (scroll < 11)
      {
        while (count <= 10)
        {
          for (int i = 0; i < 7; i++)
          {
            for (int j = scroll_var; j <= (scroll_var + 4); j++)
            {
              if (B[i][second_iteration_var] == 1)
              {
                glow_led_scroll(glow_map[i][j]);
                delayMicroseconds(1000);
                off_led_scroll(glow_map[i][j]);
                delayMicroseconds(1);
              }
              second_iteration_var ++;
            }
            second_iteration_var = 0;
          }
          count++;
        }
        scroll++;
        count = 0;
        scroll_var++;
      }
      break;

    case 'C':
      while (scroll < 11)
      {
        while (count <= 10)
        {
          for (int i = 0; i < 7; i++)
          {
            for (int j = scroll_var; j <= (scroll_var + 4); j++)
            {
              if (C[i][second_iteration_var] == 1)
              {
                glow_led_scroll(glow_map[i][j]);
                delayMicroseconds(1000);
                off_led_scroll(glow_map[i][j]);
                delayMicroseconds(1);
              }
              second_iteration_var ++;
            }
            second_iteration_var = 0;
          }
          count++;
        }
        scroll++;
        count = 0;
        scroll_var++;
      }
      break;

    case 'D':
      while (scroll < 11)
      {
        while (count <= 10)
        {
          for (int i = 0; i < 7; i++)
          {
            for (int j = scroll_var; j <= (scroll_var + 4); j++)
            {
              if (D[i][second_iteration_var] == 1)
              {
                glow_led_scroll(glow_map[i][j]);
                delayMicroseconds(1000);
                off_led_scroll(glow_map[i][j]);
                delayMicroseconds(1);
              }
              second_iteration_var ++;
            }
            second_iteration_var = 0;
          }
          count++;
        }
        scroll++;
        count = 0;
        scroll_var++;
      }
      break;

    case 'E':
      while (scroll < 11)
      {
        while (count <= 10)
        {
          for (int i = 0; i < 7; i++)
          {
            for (int j = scroll_var; j <= (scroll_var + 4); j++)
            {
              if (E[i][second_iteration_var] == 1)
              {
                glow_led_scroll(glow_map[i][j]);
                delayMicroseconds(1000);
                off_led_scroll(glow_map[i][j]);
                delayMicroseconds(1);
              }
              second_iteration_var ++;
            }
            second_iteration_var = 0;
          }
          count++;
        }
        scroll++;
        count = 0;
        scroll_var++;
      }
      break;

    case 'F':
      while (scroll < 11)
      {
        while (count <= 10)
        {
          for (int i = 0; i < 7; i++)
          {
            for (int j = scroll_var; j <= (scroll_var + 4); j++)
            {
              if (F[i][second_iteration_var] == 1)
              {
                glow_led_scroll(glow_map[i][j]);
                delayMicroseconds(1000);
                off_led_scroll(glow_map[i][j]);
                delayMicroseconds(1);
              }
              second_iteration_var ++;
            }
            second_iteration_var = 0;
          }
          count++;
        }
        scroll++;
        count = 0;
        scroll_var++;
      }
      break;

    case 'G':
      while (scroll < 11)
      {
        while (count <= 10)
        {
          for (int i = 0; i < 7; i++)
          {
            for (int j = scroll_var; j <= (scroll_var + 4); j++)
            {
              if (G[i][second_iteration_var] == 1)
              {
                glow_led_scroll(glow_map[i][j]);
                delayMicroseconds(1000);
                off_led_scroll(glow_map[i][j]);
                delayMicroseconds(1);
              }
              second_iteration_var ++;
            }
            second_iteration_var = 0;
          }
          count++;
        }
        scroll++;
        count = 0;
        scroll_var++;
      }
      break;

    case 'H':
      while (scroll < 11)
      {
        while (count <= 10)
        {
          for (int i = 0; i < 7; i++)
          {
            for (int j = scroll_var; j <= (scroll_var + 4); j++)
            {
              if (H[i][second_iteration_var] == 1)
              {
                glow_led_scroll(glow_map[i][j]);
                delayMicroseconds(1000);
                off_led_scroll(glow_map[i][j]);
                delayMicroseconds(1);
              }
              second_iteration_var ++;
            }
            second_iteration_var = 0;
          }
          count++;
        }
        scroll++;
        count = 0;
        scroll_var++;
      }
      break;

    case 'K':
      while (scroll < 11)
      {
        while (count <= 10)
        {
          for (int i = 0; i < 7; i++)
          {
            for (int j = scroll_var; j <= (scroll_var + 4); j++)
            {
              if (K[i][second_iteration_var] == 1)
              {
                glow_led_scroll(glow_map[i][j]);
                delayMicroseconds(1000);
                off_led_scroll(glow_map[i][j]);
                delayMicroseconds(1);
              }
              second_iteration_var ++;
            }
            second_iteration_var = 0;
          }
          count++;
        }
        scroll++;
        count = 0;
        scroll_var++;
      }
      break;

    case 'L':
      while (scroll < 11)
      {
        while (count <= 10)
        {
          for (int i = 0; i < 7; i++)
          {
            for (int j = scroll_var; j <= (scroll_var + 4); j++)
            {
              if (L[i][second_iteration_var] == 1)
              {
                glow_led_scroll(glow_map[i][j]);
                delayMicroseconds(1000);
                off_led_scroll(glow_map[i][j]);
                delayMicroseconds(1);
              }
              second_iteration_var ++;
            }
            second_iteration_var = 0;
          }
          count++;
        }
        scroll++;
        count = 0;
        scroll_var++;
      }
      break;

    case 'M':
      while (scroll < 11)
      {
        while (count <= 10)
        {
          for (int i = 0; i < 7; i++)
          {
            for (int j = scroll_var; j <= (scroll_var + 4); j++)
            {
              if (M[i][second_iteration_var] == 1)
              {
                glow_led_scroll(glow_map[i][j]);
                delayMicroseconds(1000);
                off_led_scroll(glow_map[i][j]);
                delayMicroseconds(1);
              }
              second_iteration_var ++;
            }
            second_iteration_var = 0;
          }
          count++;
        }
        scroll++;
        count = 0;
        scroll_var++;
      }
      break;

    case 'N':
      while (scroll < 11)
      {
        while (count <= 10)
        {
          for (int i = 0; i < 7; i++)
          {
            for (int j = scroll_var; j <= (scroll_var + 4); j++)
            {
              if (N[i][second_iteration_var] == 1)
              {
                glow_led_scroll(glow_map[i][j]);
                delayMicroseconds(1000);
                off_led_scroll(glow_map[i][j]);
                delayMicroseconds(1);
              }
              second_iteration_var ++;
            }
            second_iteration_var = 0;
          }
          count++;
        }
        scroll++;
        count = 0;
        scroll_var++;
      }
      break;

    case 'O':
      while (scroll < 11)
      {
        while (count <= 10)
        {
          for (int i = 0; i < 7; i++)
          {
            for (int j = scroll_var; j <= (scroll_var + 4); j++)
            {
              if (O[i][second_iteration_var] == 1)
              {
                glow_led_scroll(glow_map[i][j]);
                delayMicroseconds(1000);
                off_led_scroll(glow_map[i][j]);
                delayMicroseconds(1);
              }
              second_iteration_var ++;
            }
            second_iteration_var = 0;
          }
          count++;
        }
        scroll++;
        count = 0;
        scroll_var++;
      }
      break;

    case 'P':
      while (scroll < 11)
      {
        while (count <= 10)
        {
          for (int i = 0; i < 7; i++)
          {
            for (int j = scroll_var; j <= (scroll_var + 4); j++)
            {
              if (P[i][second_iteration_var] == 1)
              {
                glow_led_scroll(glow_map[i][j]);
                delayMicroseconds(1000);
                off_led_scroll(glow_map[i][j]);
                delayMicroseconds(1);
              }
              second_iteration_var ++;
            }
            second_iteration_var = 0;
          }
          count++;
        }
        scroll++;
        count = 0;
        scroll_var++;
      }
      break;

    case 'Q':
      while (scroll < 11)
      {
        while (count <= 10)
        {
          for (int i = 0; i < 7; i++)
          {
            for (int j = scroll_var; j <= (scroll_var + 4); j++)
            {
              if (Q[i][second_iteration_var] == 1)
              {
                glow_led_scroll(glow_map[i][j]);
                delayMicroseconds(1000);
                off_led_scroll(glow_map[i][j]);
                delayMicroseconds(1);
              }
              second_iteration_var ++;
            }
            second_iteration_var = 0;
          }
          count++;
        }
        scroll++;
        count = 0;
        scroll_var++;
      }
      break;

    case 'R':
      while (scroll < 11)
      {
        while (count <= 10)
        {
          for (int i = 0; i < 7; i++)
          {
            for (int j = scroll_var; j <= (scroll_var + 4); j++)
            {
              if (R[i][second_iteration_var] == 1)
              {
                glow_led_scroll(glow_map[i][j]);
                delayMicroseconds(1000);
                off_led_scroll(glow_map[i][j]);
                delayMicroseconds(1);
              }
              second_iteration_var ++;
            }
            second_iteration_var = 0;
          }
          count++;
        }
        scroll++;
        count = 0;
        scroll_var++;
      }
      break;

    case 'S':
      while (scroll < 11)
      {
        while (count <= 10)
        {
          for (int i = 0; i < 7; i++)
          {
            for (int j = scroll_var; j <= (scroll_var + 4); j++)
            {
              if (S[i][second_iteration_var] == 1)
              {
                glow_led_scroll(glow_map[i][j]);
                delayMicroseconds(1000);
                off_led_scroll(glow_map[i][j]);
                delayMicroseconds(1);
              }
              second_iteration_var ++;
            }
            second_iteration_var = 0;
          }
          count++;
        }
        scroll++;
        count = 0;
        scroll_var++;
      }
      break;

    case 'V':
      while (scroll < 11)
      {
        while (count <= 10)
        {
          for (int i = 0; i < 7; i++)
          {
            for (int j = scroll_var; j <= (scroll_var + 4); j++)
            {
              if (V[i][second_iteration_var] == 1)
              {
                glow_led_scroll(glow_map[i][j]);
                delayMicroseconds(1000);
                off_led_scroll(glow_map[i][j]);
                delayMicroseconds(1);
              }
              second_iteration_var ++;
            }
            second_iteration_var = 0;
          }
          count++;
        }
        scroll++;
        count = 0;
        scroll_var++;
      }
      break;

    case 'W':
      while (scroll < 11)
      {
        while (count <= 10)
        {
          for (int i = 0; i < 7; i++)
          {
            for (int j = scroll_var; j <= (scroll_var + 4); j++)
            {
              if (W[i][second_iteration_var] == 1)
              {
                glow_led_scroll(glow_map[i][j]);
                delayMicroseconds(1000);
                off_led_scroll(glow_map[i][j]);
                delayMicroseconds(1);
              }
              second_iteration_var ++;
            }
            second_iteration_var = 0;
          }
          count++;
        }
        scroll++;
        count = 0;
        scroll_var++;
      }
      break;

    case 'X':
      while (scroll < 11)
      {
        while (count <= 10)
        {
          for (int i = 0; i < 7; i++)
          {
            for (int j = scroll_var; j <= (scroll_var + 4); j++)
            {
              if (X[i][second_iteration_var] == 1)
              {
                glow_led_scroll(glow_map[i][j]);
                delayMicroseconds(1000);
                off_led_scroll(glow_map[i][j]);
                delayMicroseconds(1);
              }
              second_iteration_var ++;
            }
            second_iteration_var = 0;
          }
          count++;
        }
        scroll++;
        count = 0;
        scroll_var++;
      }
      break;

    case 'Y':
      while (scroll < 11)
      {
        while (count <= 10)
        {
          for (int i = 0; i < 7; i++)
          {
            for (int j = scroll_var; j <= (scroll_var + 4); j++)
            {
              if (Y[i][second_iteration_var] == 1)
              {
                glow_led_scroll(glow_map[i][j]);
                delayMicroseconds(1000);
                off_led_scroll(glow_map[i][j]);
                delayMicroseconds(1);
              }
              second_iteration_var ++;
            }
            second_iteration_var = 0;
          }
          count++;
        }
        scroll++;
        count = 0;
        scroll_var++;
      }
      break;

    case 'Z':
      while (scroll < 11)
      {
        while (count <= 10)
        {
          for (int i = 0; i < 7; i++)
          {
            for (int j = scroll_var; j <= (scroll_var + 4); j++)
            {
              if (Z[i][second_iteration_var] == 1)
              {
                glow_led_scroll(glow_map[i][j]);
                delayMicroseconds(1000);
                off_led_scroll(glow_map[i][j]);
                delayMicroseconds(1);
              }
              second_iteration_var ++;
            }
            second_iteration_var = 0;
          }
          count++;
        }
        scroll++;
        count = 0;
        scroll_var++;
      }
      break;

    case '0':
      while (scroll < 11)
      {
        while (count <= 10)
        {
          for (int i = 0; i < 7; i++)
          {
            for (int j = scroll_var; j <= (scroll_var + 4); j++)
            {
              if (m_char_0[i][second_iteration_var] == 1)
              {
                glow_led_scroll(glow_map[i][j]);
                delayMicroseconds(1000);
                off_led_scroll(glow_map[i][j]);
                delayMicroseconds(1);
              }
              second_iteration_var ++;
            }
            second_iteration_var = 0;
          }
          count++;
        }
        scroll++;
        count = 0;
        scroll_var++;
      }
      break;

    case '1':
      while (scroll < 11)
      {
        while (count <= 10)
        {
          for (int i = 0; i < 7; i++)
          {
            for (int j = scroll_var; j <= (scroll_var + 4); j++)
            {
              if (m_char_1[i][second_iteration_var] == 1)
              {
                glow_led_scroll(glow_map[i][j]);
                delayMicroseconds(1000);
                off_led_scroll(glow_map[i][j]);
                delayMicroseconds(1);
              }
              second_iteration_var ++;
            }
            second_iteration_var = 0;
          }
          count++;
        }
        scroll++;
        count = 0;
        scroll_var++;
      }
      break;

    case '2':
      while (scroll < 11)
      {
        while (count <= 10)
        {
          for (int i = 0; i < 7; i++)
          {
            for (int j = scroll_var; j <= (scroll_var + 4); j++)
            {
              if (m_char_2[i][second_iteration_var] == 1)
              {
                glow_led_scroll(glow_map[i][j]);
                delayMicroseconds(1000);
                off_led_scroll(glow_map[i][j]);
                delayMicroseconds(1);
              }
              second_iteration_var ++;
            }
            second_iteration_var = 0;
          }
          count++;
        }
        scroll++;
        count = 0;
        scroll_var++;
      }
      break;

    case '3':
      while (scroll < 11)
      {
        while (count <= 10)
        {
          for (int i = 0; i < 7; i++)
          {
            for (int j = scroll_var; j <= (scroll_var + 4); j++)
            {
              if (m_char_3[i][second_iteration_var] == 1)
              {
                glow_led_scroll(glow_map[i][j]);
                delayMicroseconds(1000);
                off_led_scroll(glow_map[i][j]);
                delayMicroseconds(1);
              }
              second_iteration_var ++;
            }
            second_iteration_var = 0;
          }
          count++;
        }
        scroll++;
        count = 0;
        scroll_var++;
      }
      break;

    case '4':
      while (scroll < 11)
      {
        while (count <= 10)
        {
          for (int i = 0; i < 7; i++)
          {
            for (int j = scroll_var; j <= (scroll_var + 4); j++)
            {
              if (m_char_4[i][second_iteration_var] == 1)
              {
                glow_led_scroll(glow_map[i][j]);
                delayMicroseconds(1000);
                off_led_scroll(glow_map[i][j]);
                delayMicroseconds(1);
              }
              second_iteration_var ++;
            }
            second_iteration_var = 0;
          }
          count++;
        }
        scroll++;
        count = 0;
        scroll_var++;
      }
      break;

    case '5':
      while (scroll < 11)
      {
        while (count <= 10)
        {
          for (int i = 0; i < 7; i++)
          {
            for (int j = scroll_var; j <= (scroll_var + 4); j++)
            {
              if (m_char_5[i][second_iteration_var] == 1)
              {
                glow_led_scroll(glow_map[i][j]);
                delayMicroseconds(1000);
                off_led_scroll(glow_map[i][j]);
                delayMicroseconds(1);
              }
              second_iteration_var ++;
            }
            second_iteration_var = 0;
          }
          count++;
        }
        scroll++;
        count = 0;
        scroll_var++;
      }
      break;

    case '6':
      while (scroll < 11)
      {
        while (count <= 10)
        {
          for (int i = 0; i < 7; i++)
          {
            for (int j = scroll_var; j <= (scroll_var + 4); j++)
            {
              if (m_char_6[i][second_iteration_var] == 1)
              {
                glow_led_scroll(glow_map[i][j]);
                delayMicroseconds(1000);
                off_led_scroll(glow_map[i][j]);
                delayMicroseconds(1);
              }
              second_iteration_var ++;
            }
            second_iteration_var = 0;
          }
          count++;
        }
        scroll++;
        count = 0;
        scroll_var++;
      }
      break;

    case '7':
      while (scroll < 11)
      {
        while (count <= 10)
        {
          for (int i = 0; i < 7; i++)
          {
            for (int j = scroll_var; j <= (scroll_var + 4); j++)
            {
              if (m_char_7[i][second_iteration_var] == 1)
              {
                glow_led_scroll(glow_map[i][j]);
                delayMicroseconds(1000);
                off_led_scroll(glow_map[i][j]);
                delayMicroseconds(1);
              }
              second_iteration_var ++;
            }
            second_iteration_var = 0;
          }
          count++;
        }
        scroll++;
        count = 0;
        scroll_var++;
      }
      break;

    case '8':
      while (scroll < 11)
      {
        while (count <= 10)
        {
          for (int i = 0; i < 7; i++)
          {
            for (int j = scroll_var; j <= (scroll_var + 4); j++)
            {
              if (m_char_8[i][second_iteration_var] == 1)
              {
                glow_led_scroll(glow_map[i][j]);
                delayMicroseconds(1000);
                off_led_scroll(glow_map[i][j]);
                delayMicroseconds(1);
              }
              second_iteration_var ++;
            }
            second_iteration_var = 0;
          }
          count++;
        }
        scroll++;
        count = 0;
        scroll_var++;
      }
      break;

    case '9':
      while (scroll < 11)
      {
        while (count <= 10)
        {
          for (int i = 0; i < 7; i++)
          {
            for (int j = scroll_var; j <= (scroll_var + 4); j++)
            {
              if (m_char_9[i][second_iteration_var] == 1)
              {
                glow_led_scroll(glow_map[i][j]);
                delayMicroseconds(1000);
                off_led_scroll(glow_map[i][j]);
                delayMicroseconds(1);
              }
              second_iteration_var ++;
            }
            second_iteration_var = 0;
          }
          count++;
        }
        scroll++;
        count = 0;
        scroll_var++;
      }
      break;

    case 'J':
      while (scroll < 11)
      {
        while (count <= 10)
        {
          for (int i = 0; i < 7; i++)
          {
            for (int j = scroll_var; j <= (scroll_var + 4); j++)
            {
              if (J[i][second_iteration_var] == 1)
              {
                glow_led_scroll(glow_map[i][j]);
                delayMicroseconds(1000);
                off_led_scroll(glow_map[i][j]);
                delayMicroseconds(1);
              }
              second_iteration_var ++;
            }
            second_iteration_var = 0;
          }
          count++;
        }
        scroll++;
        count = 0;
        scroll_var++;
      }
      break;
    case 'I':
      while (scroll < 11)
      {
        while (count <= 10)
        {
          for (int i = 0; i < 7; i++)
          {
            for (int j = scroll_var; j <= (scroll_var + 4); j++)
            {
              if (I[i][second_iteration_var] == 1)
              {
                glow_led_scroll(glow_map[i][j]);
                delayMicroseconds(1000);
                off_led_scroll(glow_map[i][j]);
                delayMicroseconds(1);
              }
              second_iteration_var ++;
            }
            second_iteration_var = 0;
          }
          count++;
        }
        scroll++;
        count = 0;
        scroll_var++;
      }
      break;
    case 'T':
      while (scroll < 11)
      {
        while (count <= 10)
        {
          for (int i = 0; i < 7; i++)
          {
            for (int j = scroll_var; j <= (scroll_var + 4); j++)
            {
              if (T[i][second_iteration_var] == 1)
              {
                glow_led_scroll(glow_map[i][j]);
                delayMicroseconds(1000);
                off_led_scroll(glow_map[i][j]);
                delayMicroseconds(1);
              }
              second_iteration_var ++;
            }
            second_iteration_var = 0;
          }
          count++;
        }
        scroll++;
        count = 0;
        scroll_var++;
      }
      break;
    case 'U':
      while (scroll < 11)
      {
        while (count <= 10)
        {
          for (int i = 0; i < 7; i++)
          {
            for (int j = scroll_var; j <= (scroll_var + 4); j++)
            {
              if (U[i][second_iteration_var] == 1)
              {
                glow_led_scroll(glow_map[i][j]);
                delayMicroseconds(1000);
                off_led_scroll(glow_map[i][j]);
                delayMicroseconds(1);
              }
              second_iteration_var ++;
            }
            second_iteration_var = 0;
          }
          count++;
        }
        scroll++;
        count = 0;
        scroll_var++;
      }
      break;
    default:
      break;
  }
}
