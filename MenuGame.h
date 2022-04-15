#pragma once
#include <iostream>
#include <cstdio>
#include <vector>
#include <stdio.h>
#include "ConsoleWindow.h"
#include "Draw.h"
#include "GameLevel.h"
#include "Component.h"
#include "SaveAndLoad.h"
#include "AudioandSound.h"

#define LOADING         0
#define MENU            1
#define INTRODUCTION    2
#define LEADER_BOARD    3
#define EXIT_GAME       4
#define NEW_GAME        5
#define LOAD_GAME       6
#define HOW_TO_PLAY     7

using namespace std;

class Menu {
public:
    int state;
    HIGHSCORE HighScore[19];
    Menu() {
        state = LOADING;
    }
    void menuControl();
    void restart();
private:
    bool once = 0;
    void title();
    void borderMenu();
    void snakeIcon1();
    void flower();
    void menuOptions();
    void loadingBar();
    void people();
    // Menu screens 
    void introduction();
    void leaderBoard();
    void exitGame();
    void border();
    void howToPlay();
    // Components
    void backButton(int x, int y);
};

