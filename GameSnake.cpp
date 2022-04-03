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
#include "SaveAndLoad.h"

using namespace std;

void Prepare();

int main()
{
    Prepare();
    Game MyGame;
    MyGame.startNewGame();
    MyGame.gameControl();
}

void Prepare() {
    clrscr();
    resizeConsole(1000,600);
    fixConsoleWindow();
    noCursorType();
    noScrollbar();
}
