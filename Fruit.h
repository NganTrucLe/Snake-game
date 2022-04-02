#pragma once
#include <iostream>
#include <cstdio>
#include <vector>
#include "ConsoleWindow.h"
#include "Draw.h"

using namespace std;

class Fruit {
    int rangeX = WALL_RIGHT - WALL_LEFT - 2;
    int rangeY = WALL_BOTTOM - WALL_ABOVE - 2;
    public:
        int corX, corY;
        Fruit() {
            srand(time(NULL));
            corX = WALL_LEFT + rand() % rangeX + 1;
            corY = WALL_ABOVE + rand() % rangeY + 1;
        }
        void generateFruit() {
            corX = WALL_LEFT + rand() % rangeX + 1;
            corY = WALL_ABOVE + rand() % rangeY + 1;
            setTextColor(1 + rand() % 14);
            printFruit(corX,corY);
            setTextColor(15);
        }
        void deleteFruit() {
            gotoXY(corX, corY);
            cout << (char)255;
        }
    private:
        void printFruit(int x, int y) {
            const int symbol[5] = {3, 4, 5, 6, 14};
            gotoXY(x, y);
            cout << (char) symbol[rand() % 5];
        }
    
};