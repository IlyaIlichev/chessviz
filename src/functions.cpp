#include "functions.h"


void drawtable(){
  for (int i = 0; i < 9; i++) {
      for (int j = 0; j < 9; j++) {
          cout << "  " << table[i][j];
      }
      cout << endl;
  };
}
