#define CTEST_MAIN
#include "board.h"
#include <ctest.h>

char mas[10][10];

CTEST(coords, incorrect_mode)
{
    ASSERT_FALSE(correct_move(-2, 1, 4, 1, mas));
}

CTEST(coords, incorrect_paws)
{
    ASSERT_FALSE(correct_move(2, 4, 5, 4, mas));
}

CTEST(coords, correct_paws)
{
    ASSERT_TRUE(correct_move(7, 1, 6, 1, mas));
}


CTEST(coords, incorrect_rook)
{
    ASSERT_FALSE(correct_move(8, 1, 8, 2, mas));
}

CTEST(coords, correct_knight)
{
    ASSERT_TRUE(correct_move(8, 2, 6, 3, mas));
}

CTEST(coords, incorrect_knight)
{
    ASSERT_FALSE(correct_move(8, 2, 7, 2, mas));
}

int main(int argc, const char** argv)
{
    board(mas);
    return ctest_main(argc, argv);
}
