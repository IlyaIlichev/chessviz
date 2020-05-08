
#include <stdlib.h>
#include <iostream>
#include <stdio.h>

using namespace std;

int main()
{
    char table[9][9] = {{'8', 'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r'},
                       {'7', 'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p'},
                       {'6', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                       {'5', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                       {'4', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                       {'3', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                       {'2', 'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P'},
                       {'1', 'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R'},
                       {' ', 'a', '6', 'c', 'd', 'e', 'f', 'g', 'h'}};
    int team = 0;
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cout << "  " << table[i][j];
        }
        cout << endl;
    };
}
