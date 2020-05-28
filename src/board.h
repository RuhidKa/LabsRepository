#ifndef BOARD_H_
#define BOARD_H_

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int x_1, x_2, y_1, y_2, k;
void board(char mas[10][10]);
void chess_logic(char mas[10][10]);
int getxy(char a[20], char f1, char f2, int mode);
int correct_move(int y1, int x1, int y2, int x2, char mas[10][10]);
#endif
