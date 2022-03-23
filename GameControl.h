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

#define NOT_IN_GAME 0
#define IN_GAME     1
#define PAUSE       2
#define GAME_OVER   3
#define MENU        4

using namespace std;

class Game {
    Snake MySnake;
    Fruit MyFruit;
    Menu MyMenu;
    int state, score, level;
    vector<pii> wall;
public:
    Game() {
        score = 0;
        state = MENU;
        level = 5;
        MyMenu.restart();
    }
    void gameControl() {
        loadLevel(level);
        //MyFruit.generateFruit();
        while (1) {
            switch (state) {
            case MENU: 
                MyMenu.menuControl();
                if (MyMenu.state = NEW_GAME) {
                    state = IN_GAME;
                    loadLevel(level);
                    MyFruit.generateFruit();
                }
                break;
            case GAME_OVER:
                // draw menu restart? back to menu? exit game?
                handleAfterGameOver();
                break;
            case IN_GAME:
                drawScore(score);
                setTextColor(15);
                snakeActivities();
                increaseScore();
                if (gameOver()) 
                    state = GAME_OVER;
                break;
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
        clrscr();
        level = 3;
        gotoXY(0, 0);
        MySnake.restart();
        MyFruit.generateFruit();
        loadLevel(level);
        state = IN_GAME;
        score = 0;
    }
    void startWholeGame() {
        state = MENU;
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
        if (MySnake.isDeath(wall)) {
            MySnake.blink();
            announceGameOver(score);
            return 1;
        }
        return 0;
    }
    void handleAfterGameOver() {
        int key = inputKey();
        while (1) {
            if (key == 121) {
                startNewGame();
                break;
            }
            else if (key == 110) {
                state = MENU;
                clrscr();
                MyMenu.restart();
                break;
            }
            key = inputKey();
        }
        
    }
    void restart() {

    }
    void loadLevel(int n) {
        switch (n) {
        case 1:
            Level_1(wall);
            break;
        case 2:
            Level_2(wall);
            break;
        case 3:
            Level_3(wall);
            break;
        case 4:
            Level_4(wall);
            break;
        case 5:
            Level_5(wall);
            break;
        }
    }
};
