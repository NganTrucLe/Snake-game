#pragma once
#include <iostream>
#include <cstdio>
#include <vector>
#include "ConsoleWindow.h"
#include "Draw.h"
#include "Snake.h"
#include "Fruit.h"
#include "GameLevel.h"

#define NOT_IN_GAME 0
#define IN_GAME 1
#define PAUSE 2
#define GAME_OVER 3
using namespace std;

class Game {
    Snake MySnake;
    Fruit MyFruit;
    int state, score, level;
public:
    Game() {
        score = 0;
        state = IN_GAME;
        level = 1;
    }
    void gameControl() {
        loadLevel(level);
        MyFruit.generateFruit();
        while (1) {
            switch (state) {
            case GAME_OVER:
                // draw menu restart? back to menu? exit game?
                handleAfterGameOver();
                break;
            case IN_GAME:
                drawScore(score);
                setTextColor(15);
                snakeActivities();
                increaseScore();
                if (gameOver()) {
                    state = GAME_OVER;
                    break;
                }
            case PAUSE:
                pauseGame();
                break;
            }
        }
    }
    void snakeActivities() {
        MySnake.move();
        int key = inputKey();
        MySnake.changeDirection(key);
    }
    void startNewGame() {
        loadLevel(1);
        state = IN_GAME;
        score = 0;
    }
private:
    void increaseScore() {
        if (MySnake.isEatFruit(pii(MyFruit.corX, MyFruit.corY))) {
            MySnake.addDot();
            MyFruit.generateFruit();
            score += 10;
        }
    }
    void pauseGame() {
        int key = inputKey();
        if (key == SPACE_BAR) {
            while (1) {
                if (key == SPACE_BAR) {
                    clrscr();
                    loadLevel(level);
                    state = IN_GAME;
                }
            }
        }
    }
    void loadGame() {

    }
    bool gameOver() {
        if (MySnake.isDeath()) {
            MySnake.blink();
            announceGameOver(score);
            return 1;
        }
        return 0;
    }
    void handleAfterGameOver() {

    }
    void restart() {

    }
    void loadLevel(int n) {
        switch (n) {
        case 1:
            Level_1();
            break;
        case 2:
            Level_2();
            break;
        case 3:
            Level_3();
            break;
        case 4:
            Level_4();
            break;
        case 5:
            Level_5();
            break;
        }
    }
};