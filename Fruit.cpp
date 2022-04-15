#include "Fruit.h"
using namespace std;
void Fruit::generateFruit() {
    cor.x = WALL_LEFT + rand() % rangeX + 1;
    cor.y = WALL_ABOVE + rand() % rangeY + 1;
    printFruit(cor);
}
void Fruit::generateFruit(vector <pii> pos) {
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
void Fruit::deleteFruit() {
    gotoXY(cor.x, cor.y);
    cout << (char)255;
}
void Fruit::printCurrent() {
    printFruit(cor);
}
void Fruit::printFruit(pii cor) {
    const int symbol[5] = { 3, 4, 5, 6, 14 };
    gotoXY(cor.x, cor.y);
    setTextColor(1 + rand() % 14);
    cout << (char)symbol[rand() % 5];
    setTextColor(15);
}