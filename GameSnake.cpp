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


using namespace std;

void Prepare();

int main()
{
    Prepare();
    title();
    loadingBar();
    menuOptions();
    /*Game MyGame;
    //title();
    //loadingBar();
    //menuOptions();
    Game MyGame;
    MyGame.startNewGame();
    MyGame.gameControl();*/
    /*for (int i = 0; i <= 256; i++)
    {
        cout << i << ":" << (char)i<<endl;
    }*/
}

void Prepare() {
    clrscr();
    resizeConsole(1000,600);
    fixConsoleWindow();
    noCursorType();
    noScrollbar();
}
