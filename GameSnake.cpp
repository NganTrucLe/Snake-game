#include <iostream>
#include <cstdio>
#include <vector>
#include <conio.h>
#include <ctime>
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
    MyGame.gameControl();    
}
void Prepare() {
    clrscr();
    resizeConsole(1050,600);
    fixConsoleWindow();
    noCursorType();
    noScrollbar();
}
