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
                            '2','1','1','2','7','6','0','5',
                            '2','1','1','2','7','6','0','1' };
    bool isTouchWall() {
        int newX = position[0].first + changeX[direction];
        int newY = position[0].second + changeY[direction];
        return (newX == WALL_LEFT || newX == WALL_RIGHT || newY == WALL_ABOVE || newY == WALL_BOTTOM);
    }
    bool isTouchBody() {
        for (int i = 1; i < length; i++)
            if (position[0] == position[i])
                return 1;
        return 0;
    }
public:
    int length;
    int speed;
    vector<pii> position;
    int direction;
    Snake() {
        length = 5;
        srand(time(NULL));
        direction = rand() % 4;
        speed = 100;
        position.push_back(pii((WALL_LEFT + WALL_RIGHT) * 0.5, (WALL_ABOVE + WALL_BOTTOM) * 0.5));
        for (int i = 1; i < length; i++) {
            position.push_back(position.back());
            position[i].first -= changeX[direction];
            position[i].second -= changeY[direction];
        }
    }
    void restart() {
        position.resize(0);
        length = 5;
        srand(time(NULL));
        direction = rand() % 4;
        speed = 100;
        position.push_back(pii((WALL_LEFT + WALL_RIGHT) * 0.5, (WALL_ABOVE + WALL_BOTTOM) * 0.5));
        for (int i = 1; i < length; i++) {
            position.push_back(position.back());
            position[i].first -= changeX[direction];
            position[i].second -= changeY[direction];
        }
    }
    void printSnake() {
        int cnt = -1;
        for (pii i : position) {
            gotoXY(i.first, i.second);
            if (i == *position.begin())
                cout << (char)2;
            else cout << MSSV[cnt];
            cnt++;
        }
    }
    void move() {
        gotoXY(position.back().first, position.back().second);
        cout << (char)255;
        for (int i = length - 1; i >= 1; i--) {
            position[i] = position[i - 1];
        }
        position[0] = pii(position[0].first + changeX[direction], position[0].second + changeY[direction]);
        printSnake();
        Sleep(speed);
    }
    void addDot() {
        if (length == 25) return;
        position.push_back(position.back());
        for (int i = length - 1; i >= 1; i--) {
            position[i] = position[i - 1];
        }
        length++;
        position[0] = pii(position[0].first + changeX[direction], position[0].second + changeY[direction]);
        printSnake();
        Sleep(speed);
    }
    void changeDirection(int newDirection) {
        switch (newDirection) {
        case KEY_UP:
            newDirection = UP;
            break;
        case KEY_DOWN:
            newDirection = DOWN;
            break;
        case KEY_LEFT:
            newDirection = LEFT;
            break;
        case KEY_RIGHT:
            newDirection = RIGHT;
            break;
        default:
            newDirection = -1;
            break;
        }
        if (newDirection == direction || direction + newDirection == 3 || newDirection < 0)
            return;
        direction = newDirection;
    }
    bool isDeath() {
        return isTouchBody() || isTouchWall();
    }
    bool isEatFruit(pii fruit) {
        return position[0] == fruit;
    }
    void blink() {
        for (int i = 1; i <= 3; i++) {
            for (pii i : position) {
                gotoXY(i.first, i.second);
                cout << (char)255;
            }
            Sleep(100);
            printSnake();
            Sleep(100);
        }
    }

};
