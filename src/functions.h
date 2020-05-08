
#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

extern int team;

void drawtable(char table[][9]);
void move(char table[][9]);
int Check(int x1, int x2, int y1, int y2, char table[][9]);
int CheckFriend(int x2, int y2, char table[][9]);
