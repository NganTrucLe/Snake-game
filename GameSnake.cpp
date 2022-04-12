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
    /*string filename("output.txt");
    fstream output_fstream;

    output_fstream.open(filename, std::ios_base::out);
    if (!output_fstream.is_open()) {
        cerr << "Failed to open " << filename << '\n';
    }
    else {
        output_fstream << "Maecenas accumsan purus id \norci gravida pellentesque." << endl;
        cerr << "Done Writing!" << endl;
    }*/
    Prepare();
    Game MyGame;
    //MyGame.startNewGame();
    MyGame.gameControl();    
}
void Prepare() {
    clrscr();
    resizeConsole(1050,600);
    fixConsoleWindow();
    noCursorType();
    noScrollbar();
}
