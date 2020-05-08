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
    if(Check(x1,x2,y1,y2,table,turn)){
      table[x2][y2] = table[x1][y1];
      table[x1][y1] = ' ';
      if(team==0)
        team = 1;
      else
        team = 0;
    }
}

int Check(int x1, int x2, int y1, int y2, char table[][9], string turn)
{
    int flag = 0;
    if ((x1 == x2) && (x1 == y2)) {
        cout << "\nERROR\n";
        return 0;
    }
    switch (team) {
      case 0:
        switch (table[x1][y1]) {
          case ' ':
            cout << "\nERROR\n";
            return 0;
          case 'P':
            if ((y1 == y2) && (x1 - x2 == 1) && (table[x2][y2] == ' '))
              flag = 1;
            if ((y1 == y2) && (x1 - x2 == 2) && (x1 == 6) && (table[x2][y2] == ' ')) {
              if (table[x2 + 1][y2] == ' ') {
                flag = 1;
              } else {
                cout << "\nERROR\n";
                return 0;
              }
            }
            if ((x1 - x2 == 1) && (table[x2][x2] != ' ') && ((y1 - y2 == 1) || (y2 - y1 == 1)))
              flag = 1;
            break;
          default:
            cout << "\nERROR\n";
            return 0;
        }
        break;
      case 1:
        switch (table[x1][y1]) {
          case ' ':
            cout << "\nERROR\n";
            return 0;
          case 'p':
            if ((y1 == y2) && (x2 - x1 == 1) && (table[x2][y2] == ' '))
              flag = 1;
            if ((y1 == y2) && (x2 - x1 == 2) && (x1 == 1) && (table[x2][y2] == ' ')) {
              if (table[x2 - 1][y2] == ' ') {
                flag = 1;
              } else {
                cout << "\nERROR\n";
                return 0;
              }
            }
            if ((x2 - x1 == 1) && (table[x2][y2] != ' ') && ((y2 - y1 == 1) || (y1 - y2 == 1)))
              flag = 1;
            break;
          default:
            cout << "\nERROR\n";
            return 0;
        }
    }
    return flag;
}
