#include "../src/functions.h"
#include "gtest/gtest.h"

int team;

char table[9][9] = {{'8', 'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r'},
                    {'7', 'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p'},
                    {'6', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                    {'5', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                    {'4', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                    {'3', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                    {'2', 'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P'},
                    {'1', 'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R'},
                    {' ', 'a', '6', 'c', 'd', 'e', 'f', 'g', 'h'}};

TEST(Pawn, WhitePawn_valid)
{
    int x1 = 6, x2 = 5;
    int y1 = 4, y2 = 4;
    team = 0;
    int result = Check(x1, x2, y1, y2, table);
    int expected = 1;
    EXPECT_EQ(expected, result);
}

TEST(Pawn, WhitePawn_invalid)
{
    int x1 = 6, x2 = 3;
    int y1 = 4, y2 = 4;
    team = 0;
    int result = Check(x1, x2, y1, y2, table);
    int expected = 0;
    EXPECT_EQ(expected, result);
}

TEST(Rook, WhiteRook_valid)
{
    table[6][1] = ' ';
    int x1 = 7, x2 = 5;
    int y1 = 1, y2 = 1;
    team = 0;
    int result = Check(x1, x2, y1, y2, table);
    int expected = 1;
    EXPECT_EQ(expected, result);
}

TEST(Rook, WhiteRook_invalid)
{
    table[6][1] = 'P';
    int x1 = 7, x2 = 5;
    int y1 = 1, y2 = 1;
    team = 0;
    int result = Check(x1, x2, y1, y2, table);
    int expected = 0;
    EXPECT_EQ(expected, result);
}

TEST(Bishop, WhiteBishop_valid)
{
    table[6][4] = ' ';
    int x1 = 7, x2 = 5;
    int y1 = 3, y2 = 5;
    team = 0;
    int result = Check(x1, x2, y1, y2, table);
    int expected = 1;
    EXPECT_EQ(expected, result);
}

TEST(Bishop, WhiteBishop_invalid)
{
    table[6][4] = 'P';
    int x1 = 7, x2 = 5;
    int y1 = 3, y2 = 5;
    team = 0;
    int result = Check(x1, x2, y1, y2, table);
    int expected = 0;
    EXPECT_EQ(expected, result);
}

TEST(Knight, WhiteKnight_valid)
{
    int x1 = 7, x2 = 5;
    int y1 = 2, y2 = 3;
    team = 0;
    int result = Check(x1, x2, y1, y2, table);
    int expected = 1;
    EXPECT_EQ(expected, result);
}

TEST(Knight, WhiteKnight_invalid)
{
    int x1 = 7, x2 = 6;
    int y1 = 2, y2 = 4;
    team = 0;
    int result = Check(x1, x2, y1, y2, table);
    int expected = 0;
    EXPECT_EQ(expected, result);
}

TEST(Queen, WhiteQueen_valid)
{
    table[6][3] = ' ';
    int x1 = 7, x2 = 5;
    int y1 = 4, y2 = 2;
    team = 0;
    int result = Check(x1, x2, y1, y2, table);
    int expected = 1;
    EXPECT_EQ(expected, result);
}

TEST(Queen, WhiteQueen_invalid)
{
    table[6][3] = 'P';
    int x1 = 7, x2 = 5;
    int y1 = 4, y2 = 2;
    team = 0;
    int result = Check(x1, x2, y1, y2, table);
    int expected = 0;
    EXPECT_EQ(expected, result);
}
TEST(King, WhiteKing_valid)
{
    table[6][5] = ' ';
    int x1 = 7, x2 = 6;
    int y1 = 5, y2 = 5;
    team = 0;
    int result = Check(x1, x2, y1, y2, table);
    int expected = 1;
    EXPECT_EQ(expected, result);
}

TEST(King, WhiteKing_invalid)
{
    table[6][5] = 'P';
    int x1 = 7, x2 = 6;
    int y1 = 5, y2 = 5;
    team = 0;
    int result = Check(x1, x2, y1, y2, table);
    int expected = 0;
    EXPECT_EQ(expected, result);
}

int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
