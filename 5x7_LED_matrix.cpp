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

int char_swastik[21] = {1,3,4,5,6,8,11,13,16,17,18,19,20,23,25,28,30,31,32,33,35};
int char_A[18] = {2,3,4,6,10,11,15,16,17,18,19,20,21,25,26,30,31,35};
int char_B[20] = {1,2,3,4,6,10,11,15,16,17,18,19,21,25,26,30,31,32,33,34};
int char_C[13] = {2,3,4,6,10,11,16,21,26,30,32,33,34};
int char_D[18] = {1,2,3,4,6,10,11,15,16,20,21,25,26,30,31,32,33,34};
int char_E[19] = {1,2,3,4,5,6,11,16,17,18,19,20,21,26,31,32,33,34,35};
int char_F[15] = {1,2,3,4,5,6,11,16,17,18,19,20,21,26,31};
int char_G[16] = {2,3,4,5,6,11,16,18,19,21,25,26,30,32,33,34};
int char_H[17] = {1,5,6,10,11,15,16,17,18,19,20,21,25,26,30,31,35};
int char_I[15] = {1,2,3,4,5,8,13,18,23,28,31,32,33,34,35};
int char_J[14] = {1,2,3,4,5,8,13,18,23,28,33,32,26,21};
int char_K[14] = {1,5,6,9,11,13,16,17,21,23,26,29,31,35};
int char_L[11] = {1,6,11,16,21,26,31,32,33,34,35};
int char_M[18] = {1,2,4,5,6,8,10,11,13,15,16,20,21,25,26,30,31,35};
int char_N[13] = {6,10,11,12,15,16,18,20,21,24,25,26,30};
int char_O[16] = {2,3,4,6,10,11,15,16,20,21,25,26,30,32,33,34};
int char_P[14] = {2,3,4,6,10,11,15,16,17,18,19,21,26,31};
int char_Q[15] = {7,8,9,11,15,16,20,21,23,25,26,29,32,33,35};
int char_R[17] = {2,3,4,6,10,11,15,16,17,18,19,21,23,26,29,31,35};
int char_S[15] = {2,3,4,6,10,11,17,18,19,25,26,30,32,33,34};
int char_T[11] = {1,2,3,4,5,8,13,18,23,28,33};
int char_U[15] = {1,5,6,10,11,15,16,20,21,25,26,30,32,33,34};
int char_V[13] = {1,5,6,10,11,15,16,20,21,25,27,29,33};
int char_W[15] = {6,10,11,15,16,18,20,21,23,25,26,28,30,32,34};
int char_X[13] = {1,5,6,10,12,14,18,22,24,26,30,31,35};
int char_Y[10] = {1,5,6,10,12,14,18,23,28,33};
int char_Z[15] = {1,2,3,4,5,10,14,18,22,26,31,32,33,34,35};

int char_0[] = {};
int char_1[] = {};
int char_2[] = {};
int char_3[] = {};
int char_4[] = {};
int char_5[] = {};
int char_6[] = {};
int char_7[] = {};
int char_8[] = {};
int char_9[] = {};
int char_plus[9] = {8,13,18,23,28,16,17,19,20};

int char_err[] = {};

int A[7][5] = { 
  {0, 0, 1, 0, 0},
  {0, 1, 0, 1, 0},
  {1, 0, 0, 0, 1},
  {1, 1, 1, 1, 1},
  {1, 0, 0, 0, 1},
  {1, 0, 0, 0, 1},
  {1, 0, 0, 0, 1}
};

int B[7][5] = { 
  {1, 1, 1, 1, 0},
  {1, 0, 0, 0, 1},
  {1, 0, 0, 0, 1},
  {1, 1, 1, 1, 0},
  {1, 0, 0, 0, 1},
  {1, 0, 0, 0, 1},
  {1, 1, 1, 1, 0}
};

int C[7][5] = { 
  {0, 1, 1, 1, 0},
  {1, 0, 0, 0, 1},
  {1, 0, 0, 0, 0},
  {1, 0, 0, 0, 0},
  {1, 0, 0, 0, 0},
  {1, 0, 0, 0, 1},
  {0, 1, 1, 1, 0}
};

int D[7][5] = { 
  {1, 1, 1, 1, 0},
  {1, 0, 0, 0, 1},
  {1, 0, 0, 0, 1},
  {1, 0, 0, 0, 1},
  {1, 0, 0, 0, 1},
  {1, 0, 0, 0, 1},
  {1, 1, 1, 1, 0}
};

int E[7][5] = { 
  {1, 1, 1, 1, 1},
  {1, 0, 0, 0, 0},
  {1, 0, 0, 0, 0},
  {1, 1, 1, 1, 1},
  {1, 0, 0, 0, 0},
  {1, 0, 0, 0, 0},
  {1, 1, 1, 1, 1}
};

int F[7][5] = { 
  {1, 1, 1, 1, 1},
  {1, 0, 0, 0, 0},
  {1, 0, 0, 0, 0},
  {1, 1, 1, 1, 1},
  {1, 0, 0, 0, 0},
  {1, 0, 0, 0, 1},
  {1, 0, 0, 0, 0}
};

int G[7][5] = { 
  {0, 1, 1, 1, 0},
  {1, 0, 0, 0, 1},
  {1, 0, 0, 0, 0},
  {1, 0, 1, 1, 0},
  {1, 0, 0, 0, 1},
  {1, 0, 0, 0, 1},
  {0, 1, 1, 1, 0}
};

int H[7][5] = { 
  {1, 0, 0, 0, 1},
  {1, 0, 0, 0, 1},
  {1, 0, 0, 0, 1},
  {1, 1, 1, 1, 1},
  {1, 0, 0, 0, 1},
  {1, 0, 0, 0, 1},
  {1, 0, 0, 0, 1}
};

int I[7][5] = { 
  {1, 1, 1, 1, 1},
  {0, 0, 1, 0, 0},
  {0, 0, 1, 0, 0},
  {0, 0, 1, 0, 0},
  {0, 0, 1, 0, 0},
  {0, 0, 1, 0, 0},
  {1, 1, 1, 1, 1}
};

int J[7][5] = { 
  {1, 1, 1, 1, 1},
  {0, 0, 1, 0, 0},
  {0, 0, 1, 0, 0},
  {0, 0, 1, 0, 0},
  {1, 0, 1, 0, 0},
  {1, 0, 1, 0, 0},
  {0, 1, 1, 0, 0}
};

int K[7][5] = { 
  {1, 0, 0, 0, 1},
  {1, 0, 0, 1, 0},
  {1, 0, 1, 0, 0},
  {1, 1, 0, 0, 0},
  {1, 0, 1, 0, 0},
  {1, 0, 0, 1, 0},
  {1, 0, 0, 0, 1}
};

int L[7][5] = { 
  {1, 0, 0, 0, 0},
  {1, 0, 0, 0, 0},
  {1, 0, 0, 0, 0},
  {1, 0, 0, 0, 0},
  {1, 0, 0, 0, 0},
  {1, 0, 0, 0, 0},
  {1, 1, 1, 1, 1}
};

int M[7][5] = { 
  {1, 0, 0, 0, 1},
  {1, 1, 0, 1, 1},
  {1, 0, 1, 0, 1},
  {1, 0, 0, 0, 1},
  {1, 0, 0, 0, 1},
  {1, 0, 0, 0, 1},
  {1, 0, 0, 0, 1}
};

int N[7][5] = { 
  {1, 0, 0, 0, 1},
  {1, 0, 0, 0, 1},
  {1, 1, 0, 0, 1},
  {1, 0, 1, 0, 1},
  {1, 0, 0, 1, 1},
  {1, 0, 0, 0, 1},
  {1, 0, 0, 0, 1}
};

int O[7][5] = { 
  {0, 1, 1, 1, 0},
  {1, 0, 0, 0, 1},
  {1, 0, 0, 0, 1},
  {1, 0, 0, 0, 1},
  {1, 0, 0, 0, 1},
  {1, 0, 0, 0, 1},
  {0, 1, 1, 1, 0}
};

int P[7][5] = { 
  {1, 1, 1, 1, 0},
  {1, 0, 0, 0, 1},
  {1, 0, 0, 0, 1},
  {1, 1, 1, 1, 0},
  {1, 0, 0, 0, 0},
  {1, 0, 0, 0, 0},
  {1, 0, 0, 0, 0}
};

int Q[7][5] = { 
  {0, 1, 1, 1, 0},
  {1, 0, 0, 0, 1},
  {1, 0, 0, 0, 1},
  {1, 0, 0, 0, 1},
  {1, 0, 0, 0, 1},
  {1, 0, 0, 1, 1},
  {0, 1, 1, 1, 0}
};

int R[7][5] = { 
  {1, 1, 1, 1, 0},
  {1, 0, 0, 0, 1},
  {1, 0, 0, 0, 1},
  {1, 1, 1, 1, 0},
  {1, 0, 1, 0, 0},
  {1, 0, 0, 1, 0},
  {1, 0, 0, 0, 1}
};

int S[7][5] = { 
  {0, 1, 1, 1, 0},
  {1, 0, 0, 0, 1},
  {1, 0, 0, 0, 0},
  {0, 1, 1, 1, 0},
  {0, 0, 0, 0, 1},
  {1, 0, 0, 0, 1},
  {0, 1, 1, 1, 0}
};

int T[7][5] = { 
  {1, 1, 1, 1, 1},
  {0, 0, 1, 0, 0},
  {0, 0, 1, 0, 0},
  {0, 0, 1, 0, 0},
  {0, 0, 1, 0, 0},
  {0, 0, 1, 0, 0},
  {0, 0, 1, 0, 0}
};

int U[7][5] = { 
  {1, 0, 0, 0, 1},
  {1, 0, 0, 0, 1},
  {1, 0, 0, 0, 1},
  {1, 0, 0, 0, 1},
  {1, 0, 0, 0, 1},
  {1, 0, 0, 0, 1},
  {0, 1, 1, 1, 0}
};

int V[7][5] = { 
  {1, 0, 0, 0, 1},
  {1, 0, 0, 0, 1},
  {1, 0, 0, 0, 1},
  {1, 0, 0, 0, 1},
  {1, 0, 0, 0, 1},
  {0, 1, 0, 1, 0},
  {0, 0, 1, 0, 0}
};

int W[7][5] = { 
  {1, 0, 0, 0, 1},
  {1, 0, 0, 0, 1},
  {1, 0, 0, 0, 1},
  {1, 0, 0, 0, 1},
  {1, 0, 1, 0, 1},
  {1, 0, 1, 0, 1},
  {0, 1, 0, 1, 0}
};

int X[7][5] = { 
  {1, 0, 0, 0, 1},
  {1, 0, 0, 0, 1},
  {0, 1, 0, 1, 0},
  {0, 0, 1, 0, 0},
  {0, 1, 0, 1, 0},
  {1, 0, 0, 0, 1},
  {1, 0, 0, 0, 1}
};

int Y[7][5] = { 
  {1, 0, 0, 0, 1},
  {1, 0, 0, 0, 1},
  {0, 1, 0, 1, 0},
  {0, 0, 1, 0, 0},
  {0, 0, 1, 0, 0},
  {0, 0, 1, 0, 0},
  {0, 0, 1, 0, 0}
};

int Z[7][5] = { 
  {1, 1, 1, 1, 1},
  {0, 0, 0, 0, 1},
  {0, 0, 0, 1, 0},
  {0, 0, 1, 0, 0},
  {0, 1, 0, 0, 0},
  {1, 0, 0, 0, 0},
  {1, 1, 1, 1, 1}
};

int m_char_0[7][5] = { 
  {0, 1, 1, 1, 0},
  {1, 0, 0, 0, 1},
  {1, 0, 0, 0, 1},
  {1, 0, 0, 0, 1},
  {1, 0, 0, 0, 1},
  {1, 0, 0, 0, 1},
  {0, 1, 1, 1, 0}
};

int m_char_1[7][5] = { 
  {0, 0, 1, 0, 0},
  {0, 1, 1, 0, 0},
  {0, 0, 1, 0, 0},
  {0, 0, 1, 0, 0},
  {0, 0, 1, 0, 0},
  {0, 0, 1, 0, 0},
  {0, 1, 1, 1, 0}
};

int m_char_2[7][5] = { 
  {0, 1, 1, 1, 0},
  {1, 0, 0, 0, 1},
  {0, 0, 0, 1, 0},
  {0, 0, 1, 0, 0},
  {0, 1, 0, 0, 0},
  {1, 0, 0, 0, 0},
  {1, 1, 1, 1, 0}
};

int m_char_3[7][5] = { 
  {1, 1, 1, 1, 0},
  {0, 0, 0, 0, 1},
  {0, 0, 0, 0, 1},
  {1, 1, 1, 1, 0},
  {0, 0, 0, 0, 1},
  {0, 0, 0, 0, 1},
  {1, 1, 1, 1, 0}
};

int m_char_4[7][5] = { 
  {1, 0, 0, 0, 1},
  {1, 0, 0, 0, 1},
  {1, 0, 0, 0, 1},
  {1, 1, 1, 1, 1},
  {0, 0, 0, 0, 1},
  {0, 0, 0, 0, 1},
  {0, 0, 0, 0, 1}
};

int m_char_5[7][5] = { 
  {0, 1, 1, 1, 1},
  {1, 0, 0, 0, 0},
  {1, 0, 0, 0, 0},
  {0, 1, 1, 1, 1},
  {0, 0, 0, 0, 1},
  {0, 0, 0, 0, 1},
  {1, 1, 1, 1, 1}
};

int m_char_6[7][5] = { 
  {0, 1, 1, 1, 1},
  {1, 0, 0, 0, 0},
  {1, 0, 0, 0, 0},
  {1, 1, 1, 1, 0},
  {1, 0, 0, 0, 1},
  {1, 0, 0, 0, 1},
  {0, 1, 1, 1, 0}
};

int m_char_7[7][5] = { 
  {1, 1, 1, 1, 1},
  {0, 0, 0, 0, 1},
  {0, 0, 0, 0, 1},
  {0, 0, 0, 1, 0},
  {0, 0, 1, 0, 0},
  {0, 1, 0, 0, 0},
  {1, 0, 0, 0, 0}
};

int m_char_8[7][5] = { 
  {1, 1, 1, 1, 1},
  {1, 0, 0, 0, 1},
  {1, 0, 0, 0, 1},
  {1, 1, 1, 1, 1},
  {1, 0, 0, 0, 1},
  {1, 0, 0, 0, 1},
  {1, 1, 1, 1, 1}
};

int m_char_9[7][5] = { 
  {1, 1, 1, 1, 1},
  {1, 0, 0, 0, 1},
  {1, 0, 0, 0, 1},
  {1, 1, 1, 1, 1},
  {0, 0, 0, 0, 1},
  {0, 0, 0, 0, 1},
  {1, 1, 1, 1, 1}
};

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
    switch(ledNumber)
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
    switch(ledNumber)
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
    switch(ledNumber)
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
    switch(ledNumber)
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

void disp_char(char c)
{
  switch(c)
  {
    case 'A':
      print_pattern(char_A, sizeof(char_A));
      break; 
    case 'B':
      print_pattern(char_B, sizeof(char_B));
      break;
    case 'C':
      print_pattern(char_C, sizeof(char_C));
      break;
    case 'D':
      print_pattern(char_D, sizeof(char_D));
      break;
    case 'E':
      print_pattern(char_E, sizeof(char_E));
      break;
    case 'F':
      print_pattern(char_F, sizeof(char_F));
      break;
    case 'G':
      print_pattern(char_G, sizeof(char_G));
      break;
    case 'H':
      print_pattern(char_H, sizeof(char_H));
      break;
    case 'I':
      print_pattern(char_I, sizeof(char_I));
      break;
    case 'J':
      print_pattern(char_J, sizeof(char_J));
      break;
    case 'K':
      print_pattern(char_K, sizeof(char_K));
      break;
    case 'L':
      print_pattern(char_L, sizeof(char_L));
      break;
    case 'M':
      print_pattern(char_M, sizeof(char_M));
      break;
    case 'N':
      print_pattern(char_N, sizeof(char_N));
      break;
    case 'O':
      print_pattern(char_O, sizeof(char_O));
      break;
    case 'P':
      print_pattern(char_P, sizeof(char_P));
      break;
    case 'Q':
      print_pattern(char_Q, sizeof(char_Q));
      break;
    case 'R':
      print_pattern(char_R, sizeof(char_R));
      break;
    case 'S':
      print_pattern(char_S, sizeof(char_S));
      break;
    case 'T':
      print_pattern(char_T, sizeof(char_T));
      break;
    case 'U':
      print_pattern(char_U, sizeof(char_U));
      break;
    case 'V':
      print_pattern(char_V, sizeof(char_V));
      break;
    case 'W':
      print_pattern(char_W, sizeof(char_W));
      break;
    case 'X':
      print_pattern(char_X, sizeof(char_X));
      break;
    case 'Y':
      print_pattern(char_Y, sizeof(char_Y));
      break;
    case 'Z':
      print_pattern(char_Z, sizeof(char_Z));
      break;
    case '0':
      print_pattern(char_0, sizeof(char_0));
      break;
    case '1':
      print_pattern(char_1, sizeof(char_1));
      break;
    case '2':
      print_pattern(char_2, sizeof(char_2));
      break;
    case '3':
      print_pattern(char_3, sizeof(char_3));
      break;
    case '4':
      print_pattern(char_4, sizeof(char_4));
      break;
    case '5':
      print_pattern(char_5, sizeof(char_5));
      break;
    case '6':
      print_pattern(char_6, sizeof(char_6));
      break;
    case '7':
      print_pattern(char_7, sizeof(char_7));
      break;
    case '8':
      print_pattern(char_8, sizeof(char_8));
      break;
    case '9':
      print_pattern(char_9, sizeof(char_9));
      break;
    case '+':
      print_pattern(char_plus, sizeof(char_plus));
      break;
    case '#':
      print_pattern(char_swastik, sizeof(char_swastik));
      break;
    default:
      break;
  }
}

void print_pattern(int *arr, int size)
{
  //Serial.println(size);
  //Serial.println(ceil(size/2.0));
  for(int i = 0; i<70; i++)
  {
    // size/2 gives the actual length of the array
    for(int i = 0; i<ceil(size/2.0); i++)
    {
     glow_led(arr[i]);
     delayMicroseconds(500);
     off_led(arr[i]);
     delayMicroseconds(1);
    }  
  }
}

void disp_custom_char(int *arr, int size)
{
  //Serial.println(n);
  for(int i = 0; i<70; i++)
  {
    for(int i = 0; i<size; i++)
    {
     //Serial.println(arr[i]);
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
  int second_iteration_var=0;
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

  switch(c)
  {
	  case 'X':
		while (scroll < 11)
  {
    while (count <= 10)
    {
      for (int i = 0; i < 7; i++)
      {
        for (int j = scroll_var; j <= (scroll_var+4); j++)
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
    count=0;
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
        for (int j = scroll_var; j <= (scroll_var+4); j++)
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
    count=0;
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
	int second_iteration_var=0;
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
            for (int j = scroll_var; j <= (scroll_var+4); j++)
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
        count=0;
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
            for (int j = scroll_var; j <= (scroll_var+4); j++)
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
        count=0;
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
            for (int j = scroll_var; j <= (scroll_var+4); j++)
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
        count=0;
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
            for (int j = scroll_var; j <= (scroll_var+4); j++)
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
        count=0;
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
            for (int j = scroll_var; j <= (scroll_var+4); j++)
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
        count=0;
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
            for (int j = scroll_var; j <= (scroll_var+4); j++)
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
        count=0;
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
            for (int j = scroll_var; j <= (scroll_var+4); j++)
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
        count=0;
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
            for (int j = scroll_var; j <= (scroll_var+4); j++)
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
        count=0;
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
            for (int j = scroll_var; j <= (scroll_var+4); j++)
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
        count=0;
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
            for (int j = scroll_var; j <= (scroll_var+4); j++)
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
        count=0;
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
            for (int j = scroll_var; j <= (scroll_var+4); j++)
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
        count=0;
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
            for (int j = scroll_var; j <= (scroll_var+4); j++)
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
        count=0;
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
            for (int j = scroll_var; j <= (scroll_var+4); j++)
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
        count=0;
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
            for (int j = scroll_var; j <= (scroll_var+4); j++)
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
        count=0;
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
            for (int j = scroll_var; j <= (scroll_var+4); j++)
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
        count=0;
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
            for (int j = scroll_var; j <= (scroll_var+4); j++)
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
        count=0;
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
            for (int j = scroll_var; j <= (scroll_var+4); j++)
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
        count=0;
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
            for (int j = scroll_var; j <= (scroll_var+4); j++)
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
        count=0;
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
            for (int j = scroll_var; j <= (scroll_var+4); j++)
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
        count=0;
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
            for (int j = scroll_var; j <= (scroll_var+4); j++)
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
        count=0;
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
            for (int j = scroll_var; j <= (scroll_var+4); j++)
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
        count=0;
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
            for (int j = scroll_var; j <= (scroll_var+4); j++)
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
        count=0;
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
            for (int j = scroll_var; j <= (scroll_var+4); j++)
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
        count=0;
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
            for (int j = scroll_var; j <= (scroll_var+4); j++)
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
        count=0;
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
            for (int j = scroll_var; j <= (scroll_var+4); j++)
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
        count=0;
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
            for (int j = scroll_var; j <= (scroll_var+4); j++)
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
        count=0;
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
            for (int j = scroll_var; j <= (scroll_var+4); j++)
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
        count=0;
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
            for (int j = scroll_var; j <= (scroll_var+4); j++)
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
        count=0;
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
            for (int j = scroll_var; j <= (scroll_var+4); j++)
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
        count=0;
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
            for (int j = scroll_var; j <= (scroll_var+4); j++)
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
        count=0;
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
            for (int j = scroll_var; j <= (scroll_var+4); j++)
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
        count=0;
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
            for (int j = scroll_var; j <= (scroll_var+4); j++)
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
        count=0;
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
						for (int j = scroll_var; j <= (scroll_var+4); j++)
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
				count=0;
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
						for (int j = scroll_var; j <= (scroll_var+4); j++)
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
				count=0;
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
						for (int j = scroll_var; j <= (scroll_var+4); j++)
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
				count=0;
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
						for (int j = scroll_var; j <= (scroll_var+4); j++)
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
				count=0;
				scroll_var++;
			}
		break;
		default:
			break;
	}
}
