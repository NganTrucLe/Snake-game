#include <iostream>
#include <cstdio>
#include <vector>
#include <Windows.h>
#include "ConsoleWindow.h"
#include "Draw.h"
#include "Snake.h"
#include "Fruit.h"
#include "GameLevel.h"

using namespace std;

void Prepare();
void gameScreen();

int score = 0;

int main()
{
    Prepare();
    Level_1();
    Snake MySnake;
    Fruit MyFruit;
    MyFruit.generateFruit();
    while (1) {
        drawScore(score);
        setTextColor(15);
        MySnake.move();
        int key = inputKey();
        MySnake.changeDirection(key);
        if (MySnake.isDeath()) {
            MySnake.blink();
            break;
        }
        if (MySnake.isEatFruit(pii(MyFruit.corX,MyFruit.corY))) {
            MySnake.addDot();
            MyFruit.generateFruit();
            score+=10;
        }
    }
    /*for (int i = 0; i <= 256; i++)
    {
        cout << i << ":" << (char)i<<endl;
    }*/
}

void Prepare() {
    system("cls");
    clrscr();
    resizeConsole(1000,600);
    fixConsoleWindow();
    noCursorType();
    noScrollbar();
}

void gameScreen() {

}