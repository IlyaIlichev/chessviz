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
    if(Check(x1,x2,y1,y2,table)){
      table[x2][y2] = table[x1][y1];
      table[x1][y1] = ' ';
      if(team==0)
        team = 1;
      else
        team = 0;
    }
}

int CheckFriend(int x2, int y2, char table[][9])
{
    int flag = 1;
    switch (team) {
    case 0:
        if ((table[x2][y2] == 'P') || (table[x2][y2] == 'R')
            || (table[x2][y2] == 'N') || (table[x2][y2] == 'B')
            || (table[x2][y2] == 'Q') || (table[x2][y2] == 'K')) {
            cout << "\n ERROR: You can't move your figure on your figures \n "
                    "\n";
            flag = 0;
        }
        break;
    case 1:
        if ((table[x2][y2] == 'p') || (table[x2][y2] == 'r')
            || (table[x2][y2] == 'n') || (table[x2][y2] == 'b')
            || (table[x2][y2] == 'q') || (table[x2][y2] == 'k')) {
            cout << "\n ERROR: You can't move your figure on your figures \n "
                    "\n";
            flag = 0;
        }
        break;
    }
    return flag;
}

int Check(int x1, int x2, int y1, int y2, char table[][9])
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
            if (CheckFriend(x2, y2, table)) {
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
            }
            break;

          case 'R':
            if (CheckFriend(x2, y2, table)) {
            if ((y1 == y2) && (x1 != x2)) {
              if (x1 > x2) {
                for (int i = x1 - 1; i > x2; i--) {
                  if (table[i][y1] != ' ') {
                    cout << "\n ERROR: Rook can't reach the "
                            "position through the figure' \n \n";
                    return 0;
                  }
                }
                flag = 1;
              }
              if (x1 < x2) {
                for (int i = x2 - 1; i > x1; i--) {
                  if (table[i][y1] != ' ') {
                    cout << "\n ERROR: Rook can't reach the "
                            "position through the figure' \n \n";
                    return 0;
                  }
                }
                flag = 1;
              }
            }
            if ((x1 == x2) && (y1 != y2)) {
              if (y1 > y2) {
                for (int i = y1 - 1; i > y2; i--) {
                  if (table[x1][i] != ' ') {
                    cout << "\n ERROR: Rook can't reach the "
                            "position through the figure' \n \n";
                    return 0;
                  }
                }
                flag = 1;
              }
              if (y1 < y2) {
                for (int i = y2 - 1; i > y1; i--) {
                  if (table[x1][i] != ' ') {
                    cout << "\n ERROR: Rook can't reach the "
                            "position through the figure' \n \n";
                    return 0;
                  }
                }
                flag = 1;
              }
            }
          }
          break;

          case 'N':
            if (CheckFriend(x2, y2, table)) {
                if (((x2 == x1 - 2) && (y2 == y1 + 1))
                    || ((x2 == x1 - 2) && (y2 == y1 - 1))
                    || ((x2 == x1 + 2) && (y2 == y1 + 1))
                    || ((x2 == x1 + 2) && (y2 == y1 - 1))
                    || ((x2 == x1 - 1) && (y2 == y1 + 2))
                    || ((x2 == x1 - 1) && (y2 == y1 - 2))
                    || ((x2 == x1 + 1) && (y2 == y1 + 2))
                    || ((x2 == x1 + 1) && (y2 == y1 - 2))) {
                    flag = 1;
                }
            }
            break;

            case 'B':
                        if (CheckFriend(x2, y2, table)) {
                            if ((y2 < y1) && (x2 < x1)) {
                                if (y1 - y2 == x1 - x2) {
                                    for (int i = y1 - 1, v = x1 - 1; i > y2 && v > x2;
                                         i--, v--) {
                                        if (table[v][i] != ' ') {
                                            cout << "\n ERROR: Bishop can't reach the "
                                                    "position through the figure' \n \n";
                                            return 0;
                                        }
                                    }
                                    flag = 1;
                                }
                            }
                            if ((y2 < y1) && (x2 > x1)) {
                                if (y1 - y2 == x2 - x1) {
                                    for (int i = y1 - 1, v = x1 + 1; i > y2 && v < x2;
                                         i--, v++) {
                                        if (table[v][i] != ' ') {
                                            cout << "\n ERROR: Bishop can't reach the "
                                                    "position through the figure' \n \n";
                                            return 0;
                                        }
                                    }
                                    flag = 1;
                                }
                            }
                            if ((y2 > y1) && (x2 < x1)) {
                                if (y2 - y1 == x1 - x2) {
                                    for (int i = y1 + 1, v = x1 - 1; i < y2 && v > x2;
                                         i++, v--) {
                                        if (table[v][i] != ' ') {
                                            cout << "\n ERROR: Bishop can't reach the "
                                                    "position through the figure' \n \n";
                                            return 0;
                                        }
                                    }
                                    flag = 1;
                                }
                            }
                            if ((y2 > y1) && (x2 > x1)) {
                                if (y2 - y1 == x2 - x1) {
                                    for (int i = y1 + 1, v = x1 + 1; i < y2 && v < x2;
                                         i++, v++) {
                                        if (table[v][i] != ' ') {
                                            cout << "\n ERROR: Bishop can't reach the "
                                                    "position through the figure' \n \n";
                                            return 0;
                                        }
                                    }
                                    flag = 1;
                                }
                            }
                        }
                        break;

                        case 'Q':
            if (CheckFriend(x2, y2, table)) {
                if ((y1 == y2) && (x1 != x2)) {
                    if (x1 > x2) {
                        for (int i = x1 - 1; i > x2; i--) {
                            if (table[i][y1] != ' ') {
                                cout << "\n ERROR: Queen can't reach the "
                                        "position through the figure \n \n";
                                return 0;
                            }
                        }
                        flag = 1;
                    }
                    if (x1 < x2) {
                        for (int i = x2 - 1; i > x1; i--) {
                            if (table[i][y1] != ' ') {
                                cout << "\n ERROR: Queen can't reach the "
                                        "position through the figure \n \n";
                                return 0;
                            }
                        }
                        flag = 1;
                    }
                }
                if ((x1 == x2) && (y1 != y2)) {
                    if (y1 > y2) {
                        for (int i = y1 - 1; i > y2; i--) {
                            if (table[x1][i] != ' ') {
                                cout << "\n ERROR: Queen can't reach the "
                                        "position through the figure \n \n";
                                return 0;
                            }
                        }
                        flag = 1;
                    }
                    if (y1 < y2) {
                        for (int i = y2 - 1; i > y1; i--) {
                            if (table[x1][i] != ' ') {
                                cout << "\n ERROR: Queen can't reach the "
                                        "position through the figure \n \n";
                                return 0;
                            }
                        }
                        flag = 1;
                    }
                }
                if ((y2 < y1) && (x2 < x1)) {
                    if (y1 - y2 == x1 - x2) {
                        for (int i = y1 - 1, v = x1 - 1; i > y2 && v > x2;
                             i--, v--) {
                            if (table[v][i] != ' ') {
                                cout << "\n ERROR: Queen can't reach the "
                                        "position through the figure \n \n";
                                return 0;
                            }
                        }
                        flag = 1;
                    }
                }
                if ((y2 < y1) && (x2 > x1)) {
                    if (y1 - y2 == x2 - x1) {
                        for (int i = y1 - 1, v = x1 + 1; i > y2 && v < x2;
                             i--, v++) {
                            if (table[v][i] != ' ') {
                                cout << "\n ERROR: Queen can't reach the "
                                        "position through the figure \n \n";
                                return 0;
                            }
                        }
                        flag = 1;
                    }
                }
                if ((y2 > y1) && (x2 < x1)) {
                    if (y2 - y1 == x1 - x2) {
                        for (int i = y1 + 1, v = x1 - 1; i < y2 && v > x2;
                             i++, v--) {
                            if (table[v][i] != ' ') {
                                cout << "\n ERROR: Queen can't reach the "
                                        "position through the figure \n \n";
                                return 0;
                            }
                        }
                        flag = 1;
                    }
                }
                if ((y2 > y1) && (x2 > x1)) {
                    if (y2 - y1 == x2 - x1) {
                        for (int i = y1 + 1, v = x1 + 1; i < y2 && v < x2;
                             i++, v++) {
                            if (table[v][i] != ' ') {
                                cout << "\n ERROR: Queen can't reach the "
                                        "position through the figure \n \n";
                                return 0;
                            }
                        }
                        flag = 1;
                    }
                }
            }
            break;

            case 'K':
                if (CheckFriend(x2, y2, table)) {
                    if (((y2 - y1 >= -1) && (y2 - y1 <= 1))
                        && ((x2 - x1 >= -1) && (x2 - x1 <= 1))) {
                            flag = 1;
                        }
                    }
                }
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
            if (CheckFriend(x2, y2, table)) {
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
            }
            break;
          case 'r':
            if (CheckFriend(x2, y2, table)) {
              if ((y1 == y2) && (x1 != x2)) {
                    if (x1 > x2) {
                        for (int i = x1 - 1; i > x2; i--) {
                            if (table[i][y1] != ' ') {
                                cout << "\n ERROR: Rook can't reach the "
                                        "position through the figure' \n \n";
                                return 0;
                            }
                        }
                        flag = 1;
                    }
                    if (x1 < x2) {
                        for (int i = x2 - 1; i > x1; i--) {
                            if (table[i][y1] != ' ') {
                                cout << "\n ERROR: Rook can't reach the "
                                        "position through the figure' \n \n";
                                return 0;
                            }
                        }
                        flag = 1;
                    }
                }
                if ((x1 == x2) && (y1 != y2)) {
                    if (y1 > y2) {
                        for (int i = y1 - 1; i > y2; i--) {
                            if (table[x1][i] != ' ') {
                                cout << "\n ERROR: Rook can't reach the "
                                        "position through the figure' \n \n";
                                return 0;
                            }
                        }
                      flag = 1;
                    }
                    if (y1 < y2) {
                        for (int i = y2 - 1; i > y1; i--) {
                            if (table[x1][i] != ' ') {
                                cout << "\n ERROR: Rook can't reach the "
                                        "position through the figure' \n \n";
                                return 0;
                            }
                        }
                        flag = 1;
                    }
                }
              }
              break;

              case 'n':
                if (CheckFriend(x2, y2, table)) {
                    if (((x2 == x1 - 2) && (y2 == y1 + 1))
                        || ((x2 == x1 - 2) && (y2 == y1 - 1))
                        || ((x2 == x1 + 2) && (y2 == y1 + 1))
                        || ((x2 == x1 + 2) && (y2 == y1 - 1))
                        || ((x2 == x1 - 1) && (y2 == y1 + 2))
                        || ((x2 == x1 - 1) && (y2 == y1 - 2))
                        || ((x2 == x1 + 1) && (y2 == y1 + 2))
                        || ((x2 == x1 + 1) && (y2 == y1 - 2))) {
                        flag = 1;
                    }
                }
                break;

                case 'b':
            if (CheckFriend(x2, y2, table)) {
                if ((y2 < y1) && (x2 < x1)) {
                    if (y1 - y2 == x1 - x2) {
                        for (int i = y1 - 1, v = x1 - 1; i > y2 && v > x2;
                             i--, v--) {
                            if (table[v][i] != ' ') {
                                cout << "\n ERROR: Bishop can't reach the "
                                        "position through the figure' \n \n";
                                return 0;
                            }
                        }
                        flag = 1;
                    }
                }
                if ((y2 < y1) && (x2 > x1)) {
                    if (y1 - y2 == x2 - x1) {
                        for (int i = y1 - 1, v = x1 + 1; i > y2 && v < x2;
                             i--, v++) {
                            if (table[v][i] != ' ') {
                                cout << "\n ERROR: Bishop can't reach the "
                                        "position through the figure' \n \n";
                                return 0;
                            }
                        }
                        flag = 1;
                    }
                }
                if ((y2 > y1) && (x2 < x1)) {
                    if (y2 - y1 == x1 - x2) {
                        for (int i = y1 + 1, v = x1 - 1; i < y2 && v > x2;
                             i++, v--) {
                            if (table[v][i] != ' ') {
                                cout << "\n ERROR: Bishop can't reach the "
                                        "position through the figure' \n \n";
                                return 0;
                            }
                        }
                        flag = 1;
                    }
                }
                if ((y2 > y1) && (x2 > x1)) {
                    if (y2 - y1 == x2 - x1) {
                        for (int i = y1 + 1, v = x1 + 1; i < y2 && v < x2;
                             i++, v++) {
                            if (table[v][i] != ' ') {
                                cout << "\n ERROR: Bishop can't reach the "
                                        "position through the figure' \n \n";
                                return 0;
                            }
                        }
                        flag = 1;
                    }
                }
            }
            break;

            case 'q':
                        if (CheckFriend(x2, y2, table)) {
                            if ((y1 == y2) && (x1 != x2)) {
                                if (x1 > x2) {
                                    for (int i = x1 - 1; i > x2; i--) {
                                        if (table[i][y1] != ' ') {
                                            cout << "\n ERROR: Queen can't reach the "
                                                    "position through the figure \n \n";
                                            return 0;
                                        }
                                    }
                                    flag = 1;
                                }
                                if (x1 < x2) {
                                    for (int i = x2 - 1; i > x1; i--) {
                                        if (table[i][y1] != ' ') {
                                            cout << "\n ERROR: Queen can't reach the "
                                                    "position through the figure \n \n";
                                            return 0;
                                        }
                                    }
                                    flag = 1;
                                }
                            }
                            if ((x1 == x2) && (y1 != y2)) {
                                if (y1 > y2) {
                                    for (int i = y1 - 1; i > y2; i--) {
                                        if (table[x1][i] != ' ') {
                                            cout << "\n ERROR: Queen can't reach the "
                                                    "position through the figure \n \n";
                                            return 0;
                                        }
                                    }
                                    flag = 1;
                                }
                                if (y1 < y2) {
                                    for (int i = y2 - 1; i > y1; i--) {
                                        if (table[x1][i] != ' ') {
                                            cout << "\n ERROR: Queen can't reach the "
                                                    "position through the figure \n \n";
                                            return 0;
                                        }
                                    }
                                    flag = 1;
                                }
                            }
                          if ((y2 < y1) && (x2 < x1)) {
                                if (y1 - y2 == x1 - x2) {
                                    for (int i = y1 - 1, v = x1 - 1; i > y2 && v > x2;
                                         i--, v--) {
                                        if (table[v][i] != ' ') {
                                            cout << "\n ERROR: Queen can't reach the "
                                                    "position through the figure \n \n";
                                            return 0;
                                        }
                                    }
                                    flag = 1;
                                }
                            }
                            if ((y2 < y1) && (x2 > x1)) {
                                if (y1 - y2 == x2 - x1) {
                                    for (int i = y1 - 1, v = x1 + 1; i > y2 && v < x2;
                                         i--, v++) {
                                        if (table[v][i] != ' ') {
                                            cout << "\n ERROR: Queen can't reach the "
                                                    "position through the figure \n \n";
                                            return 0;
                                        }
                                    }
                                    flag = 1;
                                }
                            }
                            if ((y2 > y1) && (x2 < x1)) {
                                if (y2 - y1 == x1 - x2) {
                                    for (int i = y1 + 1, v = x1 - 1; i < y2 && v > x2;
                                         i++, v--) {
                                        if (table[v][i] != ' ') {
                                            cout << "\n ERROR: Queen can't reach the "
                                                    "position through the figure \n \n";
                                            return 0;
                                        }
                                    }
                                    flag = 1;
                                }
                            }
                            if ((y2 > y1) && (x2 > x1)) {
                                if (y2 - y1 == x2 - x1) {
                                    for (int i = y1 + 1, v = x1 + 1; i < y2 && v < x2;
                                         i++, v++) {
                                        if (table[v][i] != ' ') {
                                            cout << "\n ERROR: Queen can't reach the "
                                                    "position through the figure \n \n";
                                            return 0;
                                        }
                                    }
                                    flag = 1;
                                }
                            }
                        }
                        break;

                        case 'k':
                            if (CheckFriend(x2, y2, table)) {
                                if (((y2 - y1 >= -1) && (y2 - y1 <= 1))
                                    && ((x2 - x1 >= -1) && (x2 - x1 <= 1))) {
                                        flag = 1;
                                }
                            }
                            break;

          default:
            cout << "\nERROR\n";
            return 0;
        }

    }
    return flag;
}
