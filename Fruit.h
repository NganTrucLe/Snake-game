#pragma once
#include <iostream>
#include <cstdio>
#include <vector>
#include "ConsoleWindow.h"
#include "Draw.h"

using namespace std;

class Fruit {
    int corX, corY;
    int rangeX = WALL_LEFT - WALL_RIGHT - 2;
    int rangeY = WALL_ABOVE - WALL_BOTTOM - 2;
    public:
        Fruit() {
            srand(time(NULL));
            corX = WALL_LEFT + rand() % rangeX + 1;
            corY = WALL_ABOVE + rand() % rangeY + 1;
        }
        void generateFruit() {
            corX = WALL_LEFT + rand() % rangeX + 1;
            corY = WALL_ABOVE + rand() % rangeY + 1;
            printFruit(corX,corY);
        }
    private:
        void printFruit(int x, int y) {
            const int symbol[5] = {3, 4, 5, 6, 14};
            gotoXY(x, y);
            cout << (char) symbol[rand() % 5];
        }
    
};