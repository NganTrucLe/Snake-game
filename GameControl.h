#pragma once
#include <iostream>
#include <cstdio>
#include <vector>
#include "ConsoleWindow.h"
#include "Draw.h"
#include "Snake.h"
#include "Fruit.h"
#include "GameLevel.h"
#include "MenuGame.h"
#include "AudioandSound.h"
#include "Component.h"

#define NOT_IN_GAME     0
#define IN_GAME         1
#define GAME_OVER       2
#define MENU            3
#define LOAD_GAME       4
#define INCREASE_LEVEL  5
using namespace std;

class Game {
    Snake MySnake;
    Fruit MyFruit;
    Menu MyMenu;
    vector<pii> wall, gate;
    const int speedLevel[5] = { 175, 150, 125, 100, 75};
    int state, score, level;
    pii nextLevelPosition;
public:
    Game() {
        score = 0;
        state = IN_GAME;
        level = 1;
        saveHighScore();
        MyMenu.restart();
        state = MENU;
    }
    void gameControl();
    void snakeActivities();
    void startNewGame();
private:
    const pii gate_position[5] = { pii(43,12),pii(77,10),pii(10,10),pii(43,12),pii(10,10) };
    void increaseScore();
    void pauseGame();
    void saveGame();
    void loadGame();
    bool gameOver();
    void handleAfterGameOver();
    void handleAfterWin();
    void loadLevel(int n);
    void nextLevel();
    void increaseLevel();
// ________________________________________________________________________________________________
    HIGHSCORE HighScore[19];
    HIGHSCORE NewScore;
    void saveHighScore();
};