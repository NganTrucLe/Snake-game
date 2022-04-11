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
#define NEXT_LEVEL      4
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
                setTextColor(15);
                snakeActivities();
                increaseScore();
                if (gameOver())
                    state = GAME_OVER;
                nextLevel();
                break;
            case INCREASE_LEVEL:
                increaseLevel();
                break;
            }

        }
    }
    void snakeActivities() {
        if (MySnake.appearing >= 0) {
            MySnake.appear[MySnake.appearing] = 1;
            MySnake.appearing++;
            if (MySnake.appearing == MySnake.length) {
                MySnake.appearing = -1;
                for (pii i : gate) {
                    gotoXY(i.first, i.second);
                    cout << (char)255;
                }
                gate.resize(0);
                MyFruit.generateFruit();
            }
        }
        MySnake.move();
        int key = inputKey();
        MySnake.changeDirection(key);
        if (key == SPACE_BAR) {
            pauseGame();
        }
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
        gate.resize(0);
    }
    void startWholeGame() {
        clrscr();
        state = MENU;
    }
private:
    const pii gate_position[5] = { pii(43,12),pii(77,10),pii(10,10),pii(43,12),pii(10,10) };
    void increaseScore() {
        if (MySnake.isEatFruit(pii(MyFruit.corX, MyFruit.corY))) {
            AudioUpScore();
            MySnake.addDot();
            MyFruit.generateFruit();
            score += 10;
        }
        drawScore(score);
    }
    void pauseGame() {
        deleteGameScreen();
        gotoXY(23, 10);
        cout << " _______  _______  __   __  _______  _______" << endl;
        gotoXY(23, 11);
        cout << "|       ||   _   ||  | |  ||       ||       |" << endl;
        gotoXY(23, 12);
        cout << "|    _  ||  |_|  ||  | |  ||  _____||    ___|" << endl;
        gotoXY(23, 13);
        cout << "|   |_| ||       ||  |_|  || |_____ |   |___   " << endl;
        gotoXY(23, 14);
        cout << "|    ___||       ||       ||_____  ||    ___|  " << endl;
        gotoXY(23, 15);
        cout << "|   |    |   _   ||       | _____| ||   |___ " << endl;
        gotoXY(23, 16);
        cout << "|___|    |__| |__||_______||_______||_______|";

        while (1) {
            int key = inputKey();
            if (key == SPACE_BAR) {
                deleteGameScreen();
                loadLevel(level);
                MyFruit.printCurrent();
                if (!gate.empty())
                    drawGate(gate_position[level - 1].first, gate_position[level - 1].second, gate);
                break;
            }
        }
    }
    void loadGame() {

    }
    bool gameOver() {
        if (MySnake.isDeath(wall, gate)) {
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
    void handleAfterWin() {
        time_t now = time(0);
        char* dt = ctime(&now);
        NewScore.time = dt;
        char *name_=new char[10];
        announceWin(score, name_);
        NewScore.name = name_;
        NewScore.score = score;
        CreateNewHighScore(HighScore, NewScore);
        deleteGameScreen();
        gotoXY(30, 10);
        int Set[3] = { WHITE_COLOR, WHITE_COLOR, WHITE_COLOR }; // Màu mặc định
        int counter = 1, key;
        char menuList[3][20] = { "1. Back to menu", "2. Restart", "3. Exit game"};
        int positionY[3] = { 10,12,14 };
        while (1)
        {
            counterEvent(key, counter, 3);
            //Đổi màu options, option counter thì có màu đỏ, còn lại trắng
            for (int i = 0; i < 3; i++) Set[i] = WHITE_COLOR;
            Set[counter - 1] = RED_COLOR;
            for (int i = 0; i < 3; i++) {
                gotoXY(36, positionY[i]);
                setTextColor(Set[i]);
                cout << menuList[i];
                gotoXY(32, positionY[i]);
                if (counter - 1 != i) cout << (char)255;
            }
            gotoXY(32, positionY[counter - 1]);
            setTextColor(RED_COLOR);
            cout << (char)16;
            if (key == ENTER)//Người dùng nhấn phím enter
            {
                switch (counter) {
                case 1:
                    state = MENU;
                    clrscr();
                    MyMenu.restart();
                    break;
                case 2:
                    startNewGame();
                    break;
                case 3:
                    exit(0);
                    break;
                }
                return;
            }
        }
    }
    void loadLevel(int n) {
        switch (n) {
        case 1:
            Level_1(wall, HighScore[0].score);
            break;
        case 2:
            Level_2(wall, HighScore[0].score);
            break;
        case 3:
            Level_3(wall, HighScore[0].score);
            break;
        case 4:
            Level_4(wall, HighScore[0].score);
            break;
        case 5:
            Level_5(wall, HighScore[0].score);
            break;
        }
        MySnake.speed = speedLevel[n-1];
    }
    void nextLevel()
    {
        if (score == 1 * 10) {
            handleAfterWin();
        }
        if (score == 10*level)
        {
            MyFruit.deleteFruit();
            drawGate(gate_position[level - 1].first, gate_position[level-1].second, gate);
            nextLevelPosition.first = (gate[0].first + gate.back().first) / 2;
            nextLevelPosition.second = gate[0].second;
        }
        if (MySnake.isNextLevel(nextLevelPosition)) {
            MySnake.disappearing = 0;
            state = INCREASE_LEVEL;
        }
    }
    void increaseLevel() {
        if (MySnake.disappearing < 0)return;
        for (int i = 0; i < MySnake.length; i++) {
            MySnake.move();
            MySnake.appear[MySnake.disappearing] = 0;
            MySnake.disappearing++;
        }
        MySnake.move();
        MySnake.disappearing = -1;
        deleteGameScreen();
        level++;
        loadLevel(level);
        drawGate(gate_position[level - 1].first, gate_position[level - 1].second, gate);
        nextLevelPosition.first = (gate[0].first + gate.back().first) / 2;
        nextLevelPosition.second = gate[0].second;
        MySnake.init(nextLevelPosition, 3);
        MySnake.appearing = 0;
        state = IN_GAME;
    }
// ________________________________________________________________________________________________
    HIGHSCORE HighScore[5];
    HIGHSCORE NewScore;
    void saveHighScore() {
        InitializeHighScore(HighScore);
    }
};