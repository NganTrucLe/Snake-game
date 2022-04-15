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
        void generateFruit() {
            cor.x = WALL_LEFT + rand() % rangeX + 1;
            cor.y = WALL_ABOVE + rand() % rangeY + 1;
            printFruit(cor);
        }
        void generateFruit(vector <pii> pos) {
            do {
                cor.x = WALL_LEFT + rand() % rangeX + 1;
                cor.y = WALL_ABOVE + rand() % rangeY + 1;
                bool same = 0;
                for (pii i : pos) {
                    if (i == cor) {
                        same = 1;
                        break;
                    }
                }
                if (same == 0)break;
            } while (1);
            printFruit(cor);
        }
        void deleteFruit() {
            gotoXY(cor.x, cor.y);
            cout << (char)255;
        }
        void printCurrent() {
            printFruit(cor);
        }
    private:
        void printFruit(pii cor) {
            const int symbol[5] = {3, 4, 5, 6, 14};
            gotoXY(cor.x, cor.y);
            setTextColor(1 + rand() % 14);
            cout << (char) symbol[rand() % 5];
            setTextColor(15);
        }
    
};