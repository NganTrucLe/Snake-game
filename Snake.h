#pragma once
#include <iostream>
#include <cstdio>
#include <vector>
#include "ConsoleWindow.h"
#include "Draw.h"

using namespace std;

class Snake {
private:
    const int UP = 0, LEFT = 1, RIGHT = 2, DOWN = 3;
    const int changeX[4] = { 0, 1, -1, 0 };
    const int changeY[4] = { -1, 0, 0, 1 };
    const char bodyChar = 254;
    const char MSSV[24] = { '2','1','1','2','7','7','0','9',
                            '2','1','1','2','7','2','0','5',
                            '2','1','1','2','7','6','2','1' };
    bool isTouchWall(const vector<pii> wall);
    bool isTouchBody();
    bool isTouchGate(const vector<pii> gate);
public:
    int length, speed;
    vector<pii> position;
    int direction;
    vector<bool>appear;
    int disappearing = -1, appearing = -1;
    Snake() {
        appear.resize(0);
        length = 5;
        speed = 200;
        srand(time(NULL));
        for (int i = 0; i < length; i++)appear.push_back(1);
        init(pii((WALL_LEFT + WALL_RIGHT) * 0.5, (WALL_ABOVE + WALL_BOTTOM) * 0.5), rand() % 4);
    }
    void init(pii location, int dir);
    bool isNextLevel(const pii gate);
    void restart();
    void printSnake();
    void move();
    void addDot();
    void changeDirection(int newDirection);
    bool isDeath(const vector<pii> wall, const vector<pii> gate);
    bool isEatFruit(pii fruit);
    void blink();
};
