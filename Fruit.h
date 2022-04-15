#pragma once
#include <iostream>
#include <cstdio>
#include <vector>
#include "ConsoleWindow.h"
#include "Draw.h"
#define x first
#define y second
using namespace std;

class Fruit {
    int rangeX = WALL_RIGHT - WALL_LEFT - 2;
    int rangeY = WALL_BOTTOM - WALL_ABOVE - 2;
    public:
        pii cor;
        Fruit() {
            srand(time(NULL));
            cor.x = WALL_LEFT + rand() % rangeX + 1;
            cor.y = WALL_ABOVE + rand() % rangeY + 1;
        }
        void generateFruit();
        void generateFruit(vector <pii> pos);
        void deleteFruit();
        void printCurrent();
    private:
        void printFruit(pii cor);
};