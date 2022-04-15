#include "Snake.h"
using namespace std;
bool Snake::isTouchWall(const vector<pii> wall) {
    int newX = position[0].first + changeX[direction];
    int newY = position[0].second + changeY[direction];
    for (int i = 0; i < wall.size(); i++) {
        if (pii(newX, newY) == wall[i])return 1;
    }
    return (newX == WALL_LEFT || newX == WALL_RIGHT || newY == WALL_ABOVE || newY == WALL_BOTTOM);
}
bool Snake::isTouchBody() {
    for (int i = 1; i < length; i++)
        if (position[0] == position[i])
            return 1;
    return 0;
}
bool Snake::isTouchGate(const vector<pii> gate) {
    int newX = position[0].first + changeX[direction];
    int newY = position[0].second + changeY[direction];
    for (pii i : gate) {
        if (i == pii(newX, newY))return 1;
    }
    return 0;
}
void Snake::init(pii location, int dir) {
    direction = dir;
    position.resize(0);
    position.push_back(location);
    for (int i = 1; i < length; i++) {
        position.push_back(position.back());
        position[i].first -= changeX[direction];
        position[i].second -= changeY[direction];
    }
}
bool Snake::isNextLevel(const pii gate) {
    int newX = position[0].first + changeX[direction];
    int newY = position[0].second + changeY[direction];
    if (pii(newX, newY) == gate)return 1;
    return 0;
}
void Snake::restart() {
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
void Snake::printSnake() {
    int cnt = -1;
    int color = 1;
    for (pii i : position) {
        setTextColor(color);
        gotoXY(i.first, i.second);
        if (appear[cnt + 1]) {
            if (i == *position.begin())
                cout << (char)2;
            else cout << MSSV[cnt];
        }
        cnt++;
        color = (color + 1) % 15 + 1;
    }
}
void Snake::move() {
    gotoXY(position.back().first, position.back().second);
    if (appear[length - 1] == 1)
        cout << (char)255;
    for (int i = length - 1; i >= 1; i--) {
        position[i] = position[i - 1];
    }
    position[0] = pii(position[0].first + changeX[direction], position[0].second + changeY[direction]);
    printSnake();
    Sleep(speed);
}
void Snake::addDot() {
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
void Snake::changeDirection(int newDirection) {
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
    case KEY_W:
        newDirection = UP;
        break;
    case KEY_S:
        newDirection = DOWN;
        break;
    case KEY_D:
        newDirection = LEFT;
        break;
    case KEY_a:
        newDirection = RIGHT;
        break;
    case KEY_w:
        newDirection = UP;
        break;
    case KEY_s:
        newDirection = DOWN;
        break;
    case KEY_d:
        newDirection = LEFT;
        break;
    default:
        newDirection = -1;
        break;
    }
    if (newDirection == direction || direction + newDirection == 3 || newDirection < 0)
        return;
    direction = newDirection;
}
bool Snake::isDeath(const vector<pii> wall, const vector<pii> gate) {
    return isTouchBody() || isTouchWall(wall) || isTouchGate(gate);
}
bool Snake::isEatFruit(pii fruit) {
    return position[0] == fruit;
}
void Snake::blink() {
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