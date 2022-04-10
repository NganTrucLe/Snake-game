#include <iostream>
#include <cstdio>
#include <vector>
#include <conio.h>
#include <Windows.h>
#include "ConsoleWindow.h"
#include "Draw.h"
#include "Snake.h"
#include "Fruit.h"
#include "GameLevel.h"
#include "Menu.h"
#include "GameControl.h"
#include "MenuGame.h"
#include "AudioandSound.h"

using namespace std;

void Prepare();

int main()
{
    Prepare();
    Game MyGame;
    MyGame.startNewGame();
    MyGame.gameControl();

    /*while (1) {
        int key = inputKey();
        cout << key << endl;
        Sleep(500);
    }*/

    
}
void Prepare() {
    clrscr();
    resizeConsole(1050,600);
    fixConsoleWindow();
    noCursorType();
    noScrollbar();
}
