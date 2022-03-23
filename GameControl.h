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

#define NOT_IN_GAME 0
#define IN_GAME     1
#define PAUSE       2
#define GAME_OVER   3
#define MENU        4
#define NEXT_LEVEL  5
using namespace std;

class Game {
    Snake MySnake;
    Fruit MyFruit;
    Menu MyMenu;
    vector<pii>wall;
    int state, score, level;
    vector<pii> gate; // biến này dùng để lưu vị trí các cổng
    // tạo thêm 1 biến kiểu dữ liệu pii để lưu vị trí rắn cần vô để qua màn
public:
    Game() {
        score = 0;
        state = MENU;
        level = 5;
        MyMenu.restart();
    }
    void gameControl() {
        loadLevel(level);
        while (1) {
            switch (state) {
            case MENU:
                MyMenu.menuControl();
                if (MyMenu.state == NEW_GAME) {
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
                nextLevel();
                break;
            case PAUSE:
                pauseGame();
                break;

            case NEXT_LEVEL:
                isNextLevel();
                snakeActivities();
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
        level = 1;
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
            AudioUpScore();
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
            AudioGameOver();
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
    void nextLevel()
    {
        if (score % 50 == 0 && score != 0)
        {
            MyFruit.deleteFruit();
            // random position of gate
            // kiểm tra có trùng với vị trí tường không
            // không trùng mới in ra
            // lưu vị trí con rắn cần đi vào để qua màn
            drawGate(10, 10, gate);
            state = NEXT_LEVEL;
        }
    }
    void isNextLevel() {
        // kiểm tra rắn có chạm cổng không, chạm thì set state = GAME_OVER
        // chạm vào chỗ cần đi vào để qua màn thì tăng level lên 1, xóa màn hình vẽ lại màn mới
    }
};