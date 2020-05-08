#include "functions.h"


void drawtable(char table[][9]){
  for (int i = 0; i < 9; i++) {
      for (int j = 0; j < 9; j++) {
          cout << "  " << table[i][j];
      }
      cout << endl;
  };
}

void move(char table[][9])
{
    int x1 = 9, x2 = 9, y1 = 0, y2 = 0;
    string turn;
    cout << endl << "Your move: ";
    cin >> turn;
    if (turn == "exit") {
        cout << "Exit the programm";
        exit(0);
    }
    if (turn.length() != 5) {
        cout << "\nERROR\n";
        return;
    }
    switch (turn[0]) {
    case 'a':
      y1 = 1;
      break;
    case 'b':
      y1 = 2;
      break;
    case 'c':
      y1 = 3;
      break;
    case 'd':
      y1 = 4;
      break;
    case 'e':
      y1 = 5;
      break;
    case 'f':
      y1 = 6;
      break;
    case 'g':
      y1 = 7;
      break;
    case 'h':
      y1 = 8;
      break;
    default:
      cout << "\nERROR\n";
      return;
    }
    switch (turn[1]) {
    case '1':
      x1 = 7;
      break;
    case '2':
      x1 = 6;
      break;
    case '3':
      x1 = 5;
      break;
    case '4':
      x1 = 4;
      break;
    case '5':
      x1 = 3;
      break;
    case '6':
      x1 = 2;
      break;
    case '7':
      x1 = 1;
      break;
    case '8':
      x1 = 0;
      break;
    default:
        cout << "\nERROR\n";
        return;
    }
    if(turn[2]!='-'){
      cout << "\nERROR\n";
      return;
    }

    switch (turn[3]) {
    case 'a':
      y2 = 1;
      break;
    case 'b':
      y2 = 2;
      break;
    case 'c':
      y2 = 3;
      break;
    case 'd':
      y2 = 4;
      break;
    case 'e':
      y2 = 5;
      break;
    case 'f':
      y2 = 6;
      break;
    case 'g':
      y2 = 7;
      break;
    case 'h':
      y2 = 8;
      break;
    default:
      cout << "\nERROR\n";
      return;
    }
    switch (turn[4]) {
    case '1':
      x2 = 7;
      break;
    case '2':
      x2 = 6;
      break;
    case '3':
      x2 = 5;
      break;
    case '4':
      x2 = 4;
      break;
    case '5':
      x2 = 3;
      break;
    case '6':
      x2 = 2;
      break;
    case '7':
      x2 = 1;
      break;
    case '8':
      x2 = 0;
      break;
    default:
      cout << "\nERROR\n";
      return;
    }
    if (table[x1][y1] == 'P') {
      table[x2][y2] = 'P';
      table[x1][y1] = ' ';
    }
    else
      if (table[x1][y1] == 'p') {
        table[x2][y2] = 'p';
        table[x1][y1] = ' ';
      }
}
