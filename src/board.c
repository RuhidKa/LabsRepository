#include "board.h"
#include "board_print.h"
#include <locale.h>

int getxy(char a[20], char f1, char f2, int mode)
{
    char b;

    b = a[k];
    for (int i = 0; i < 3; ++i) {
        if (b <= 'h' && b >= 'a') {
            if (mode == 1)
                x_1 = (int)(-1 * ('a' - b)) + 1;
            else
                x_2 = (int)(-1 * ('a' - b)) + 1;
        }
        if (b <= '8' && b >= '1') {
            if (mode == 1)
                y_1 = (int)((int)b - 49);
            else
                y_2 = (int)b - 49;
        }
        k++;
        b = a[k];
        if (b == '\n')
            k++;
        if (b == '#')
            return 1;
    }

    return 0;
}

int correct_move(int y1, int x1, int y2, int x2, char mas[10][10])
{
    if (mas[y1][x1] == 'p') {
        if (mas[y2][x2] == ' ' && x1 == x2 && abs(y2 - y1) <= 2) {
            mas[y2][x2] = mas[y1][x1];
            mas[y1][x1] = ' ';
            return 1;
        }
        if (mas[y2][x2] != ' ' && mas[y2][x2] >= 65 && mas[y2][x2] <= 90
            && ((y1 - 1 == y2 && x1 - 1 == x2)
                || (y1 - 1 == y2 && x1 + 1 == x2))) {
            mas[y2][x2] = mas[y1][x1];
            mas[y1][x1] = ' ';
            return 1;
        }
        return 0;
    }
    if (mas[y1][x1] == 'P') {
        if (mas[y2][x2] == ' ' && x1 == x2 && abs(y2 - y1) <= 2) {
            mas[y2][x2] = mas[y1][x1];
            mas[y1][x1] = ' ';
            return 1;
        }
        if (mas[y2][x2] != ' ' && mas[y2][x2] >= 97 && mas[y2][x2] <= 122
            && ((y1 + 1 == y2 && x1 - 1 == x2)
                || (y1 + 1 == y2 && x1 + 1 == x2))) {
            mas[y2][x2] = mas[y1][x1];
            mas[y1][x1] = ' ';
            return 1;
        }
        return 0;
    }
    if (mas[y1][x1] == 'r') {
        if (mas[y2][x2] == ' ' && (x1 == x2 || y1 == y2)) {
            mas[y2][x2] = mas[y1][x1];
            mas[y1][x1] = ' ';
            return 1;
        }
        if (mas[y2][x2] != ' ' && mas[y2][x2] >= 65 && mas[y2][x2] <= 90
            && (x1 == x2 || y1 == y2)) {
            mas[y2][x2] = mas[y1][x1];
            mas[y1][x1] = ' ';
            return 1;
        }
        return 0;
    }
    if (mas[y1][x1] == 'R') {
        if (mas[y2][x2] == ' ' && (x1 == x2 || y1 == y2)) {
            mas[y2][x2] = mas[y1][x1];
            mas[y1][x1] = ' ';
            return 1;
        }
        if (mas[y2][x2] != ' ' && mas[y2][x2] >= 97 && mas[y2][x2] <= 122
            && (x1 == x2 || y1 == y2)) {
            mas[y2][x2] = mas[y1][x1];
            mas[y1][x1] = ' ';
            return 1;
        }
        return 0;
    }
    if (mas[y1][x1] == 'n') {
        if (mas[y2][x2] == ' ' && (pow(x2 - x1, 2) + pow(y2 - y1, 2)) == 5) {
            mas[y2][x2] = mas[y1][x1];
            mas[y1][x1] = ' ';

            return 1;
        }
        if (mas[y2][x2] != ' ' && mas[y2][x2] >= 65 && mas[y2][x2] <= 90
            && (pow(x2 - x1, 2) + pow(y2 - y1, 2)) == 5) {
            mas[y2][x2] = mas[y1][x1];
            mas[y1][x1] = ' ';

            return 1;
        }
        return 0;
    }
    if (mas[y1][x1] == 'N') {
        if (mas[y2][x2] == ' ' && (pow(x2 - x1, 2) + pow(y2 - y1, 2)) == 5) {
            mas[y2][x2] = mas[y1][x1];
            mas[y1][x1] = ' ';

            return 1;
        }
        if (mas[y2][x2] != ' ' && mas[y2][x2] >= 97 && mas[y2][x2] <= 122
            && (pow(x2 - x1, 2) + pow(y2 - y1, 2)) == 5) {
            mas[y2][x2] = mas[y1][x1];
            mas[y1][x1] = ' ';
            return 1;
        }
        return 0;
    }
    if (mas[y1][x1] == 'b') {
        if (mas[y2][x2] == ' ' && abs(y2 - y1) == abs(x2 - x1)) {
            mas[y2][x2] = mas[y1][x1];
            mas[y1][x1] = ' ';
            return 1;
        }
        if (mas[y2][x2] != ' ' && mas[y2][x2] >= 65 && mas[y2][x2] <= 90
            && abs(y2 - y1) == abs(x2 - x1)) {
            mas[y2][x2] = mas[y1][x1];
            mas[y1][x1] = ' ';
            return 1;
        }
        return 0;
    }
    if (mas[y1][x1] == 'B') {
        if (mas[y2][x2] == ' ' && abs(y2 - y1) == abs(x2 - x1)) {
            mas[y2][x2] = mas[y1][x1];
            mas[y1][x1] = ' ';
            return 1;
        }
        if (mas[y2][x2] != ' ' && mas[y2][x2] >= 97 && mas[y2][x2] <= 122
            && abs(y2 - y1) == abs(x2 - x1)) {
            mas[y2][x2] = mas[y1][x1];
            mas[y1][x1] = ' ';
            return 1;
        }
        return 0;
    }
    if (mas[y1][x1] == 'q') {
        if (mas[y2][x2] == ' '
            && (x1 == x2 || y1 == y2 || (abs(y2 - y1) == abs(x2 - x1)))) {
            mas[y2][x2] = mas[y1][x1];
            mas[y1][x1] = ' ';
            return 1;
        }
        if (mas[y2][x2] != ' '
            && (x1 == x2 || y1 == y2 || (abs(y2 - y1) == abs(x2 - x1)))
            && mas[y2][x2] >= 65 && mas[y2][x2] <= 90) {
            mas[y2][x2] = mas[y1][x1];
            mas[y1][x1] = ' ';
            return 1;
        }
        return 0;
    }
    if (mas[y1][x1] == 'Q') {
        if (mas[y2][x2] == ' '
            && (x1 == x2 || y1 == y2 || (abs(y2 - y1) == abs(x2 - x1)))) {
            mas[y2][x2] = mas[y1][x1];
            mas[y1][x1] = ' ';
            return 1;
        }
        if (mas[y2][x2] != ' '
            && (x1 == x2 || y1 == y2 || (abs(y2 - y1) == abs(x2 - x1)))
            && mas[y2][x2] >= 97 && mas[y2][x2] <= 122) {
            mas[y2][x2] = mas[y1][x1];
            mas[y1][x1] = ' ';
            return 1;
        }
        return 0;
    }
    if (mas[y1][x1] == 'k') {
        if (mas[y2][x2] == ' ' && (abs(y2 - y1) == 1 || abs(x2 - x1) == 1)) {
            mas[y2][x2] = mas[y1][x1];
            mas[y1][x1] = ' ';
            return 1;
        }
        if (mas[y2][x2] != ' ' && (abs(y2 - y1) == 1 || abs(x2 - x1) == 1)
            && mas[y2][x2] >= 65 && mas[y2][x2] <= 90) {
            mas[y2][x2] = mas[y1][x1];
            mas[y1][x1] = ' ';
            return 1;
        }
        return 0;
    }
    if (mas[y1][x1] == 'K') {
        if (mas[y2][x2] == ' ' && (abs(y2 - y1) == 1 || abs(x2 - x1) == 1)) {
            mas[y2][x2] = mas[y1][x1];
            mas[y1][x1] = ' ';
            return 1;
        }
        if (mas[y2][x2] != ' ' && (abs(y2 - y1) == 1 || abs(x2 - x1) == 1)
            && mas[y2][x2] >= 97 && mas[y2][x2] <= 122) {
            mas[y2][x2] = mas[y1][x1];
            mas[y1][x1] = ' ';
            return 1;
        }
        return 0;
    }
    return 0;
}

void board(char mas[10][10])
{
    for (int i = 0; i <= 9; i++) {
        for (int j = 0; j <= 9; j++)
            mas[i][j] = ' ';
    }
    for (int i = 1; i < 9; ++i) {
        mas[9][i] = (char)((int)'a' + (i - 1));
        mas[0][i] = (char)((int)'a' + (i - 1));
        mas[i][9] = (char)((int)'1' + (i - 1));
        mas[i][0] = (char)((int)'1' + (i - 1));
        mas[2][i] = 'P';
        mas[7][i] = 'p';
    }

    mas[1][1] = 'R';
    mas[1][2] = 'N';
    mas[1][3] = 'B';
    mas[1][4] = 'Q';
    mas[1][5] = 'K';
    mas[1][6] = 'B';
    mas[1][7] = 'N';
    mas[1][8] = 'R';

    mas[8][1] = 'r';
    mas[8][2] = 'n';
    mas[8][3] = 'b';
    mas[8][4] = 'q';
    mas[8][5] = 'k';
    mas[8][6] = 'b';
    mas[8][7] = 'n';
    mas[8][8] = 'r';
}

void chess(char mas[10][10])
{
    setlocale(LC_ALL, "Rus");
    int end = 0;
    FILE* ch;
    printf("\n To do this, enter it in a file chessboard.txt\n");
    if ((ch = fopen("chessboard.txt", "r")) == NULL) {
        printf("Unable to open file\n");
    }
    fseek(ch, 0, SEEK_END);
    int size_t = ftell(ch);
    fseek(ch, 0, SEEK_SET);
    char str[size_t];
    int count = 0;
    fread(str, sizeof(char), size_t, ch);
    printf("%s", str);
    k = 0;
    while (k <= size_t) {
        printf("\n\n");
        printf("%d", (int)(count / 2) + 1);
        printf(".");
        end = getxy(str, '-', 'x', 1);
        end = getxy(str, '#', ' ', 2);
        y_1 = (y_1 - 8) * (-1);
        y_2 = (y_2 - 8) * (-1);
        correct_move(y_1, x_1, y_2, x_2, mas);
        for (int i = k - 7; i < k; ++i)
            if (str[i] != '\n')
                printf("%c", str[i]);
        printf("\n");
        PrintMas(mas);
        count++;
        if (end == 1)
            break;
    }
}
