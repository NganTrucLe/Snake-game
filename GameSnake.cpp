#include <iostream>
#include "ConsoleWindow.h"

void Prepare();

int main()
{
    Prepare();
}

void Prepare() {
    resizeConsole(1000,600);
    fixConsoleWindow();
}