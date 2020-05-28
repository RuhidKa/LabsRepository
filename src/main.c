#include "board.h"
#include "board_print.h"

int main()
{
    char mas[10][10];
    board(mas);
    PrintMas(mas);
    chess(mas);
}
