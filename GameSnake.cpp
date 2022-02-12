#include <iostream>
#include <cstdio>
#include <vector>
#include <Windows.h>
#include "ConsoleWindow.h"
#include "Draw.h"
#include "Snake.h"
#include "Fruit.h"

using namespace std;

void Prepare();
void gameScreen();

int main()
{
    Prepare();
    drawWall();
    Snake MySnake;
    MySnake.printSnake();
    Fruit MyFruit;
    MyFruit.generateFruit();
    while (1) {
        MySnake.move();
        int key = inputKey();
        MySnake.changeDirection(key);
        if (MySnake.direction == 1)
            MySnake.addDot();
        if (MySnake.isTouchWall()) {
            MySnake.blink();
            break;
        }
    }
    //for (int i = 1; i <= 255; i++)
    //    cout << i<< " "<< (char)i << endl;
}

void Prepare() {
    system("cls");
    clrscr();
    resizeConsole(1000,600);
    fixConsoleWindow();
    noCursorType();
}

void gameScreen() {

}