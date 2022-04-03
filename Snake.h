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
    bool isTouchWall(const vector<pii> wall) {
        int newX = position[0].first + changeX[direction];
        int newY = position[0].second + changeY[direction];
        for (int i = 0; i < wall.size(); i++) {
            if (pii(newX, newY) == wall[i])return 1;
        }
        return (newX == WALL_LEFT || newX == WALL_RIGHT || newY == WALL_ABOVE || newY == WALL_BOTTOM);
    }
    bool isTouchBody() {
        for (int i = 1; i < length; i++)
            if (position[0] == position[i])
                return 1;
        return 0;
    }
    bool isTouchGate(const vector<pii> gate) {
        int newX = position[0].first + changeX[direction];
        int newY = position[0].second + changeY[direction];
        for (pii i : gate) {
            if (i == pii(newX, newY))return 1;
        }
        return 0;
    }
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
    void init(pii location, int dir) {
        direction = dir;
        position.resize(0);
        position.push_back(location);
        for (int i = 1; i < length; i++) {
            position.push_back(position.back());
            position[i].first -= changeX[direction];
            position[i].second -= changeY[direction];
        }
    }
    bool isNextLevel(const pii gate) {
        int newX = position[0].first + changeX[direction];
        int newY = position[0].second + changeY[direction];
        if (pii(newX, newY) == gate)return 1;
        return 0;
    }
    void restart() {
        position.resize(0);
        length = 5;
        srand(time(NULL));
        direction = rand() % 4;
        speed = 150;
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
            if (appear[cnt + 1]) {
                if (i == *position.begin())
                    cout << (char)2;
                else cout << MSSV[cnt];
            }
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
        appear.push_back(1);
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
    bool isDeath(const vector<pii> wall, const vector<pii> gate) {
        return isTouchBody() || isTouchWall(wall) || isTouchGate(gate);
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
