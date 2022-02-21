#pragma once
#include <iostream>
#include <cstdio>
#include "GameLevel.h"
#include "ConsoleWindow.h"

#define WALL_LEFT 3
#define WALL_RIGHT 83
#define WALL_ABOVE 1
#define WALL_BOTTOM 23

using namespace std;

void drawWall(); 
void drawScoreBoard();
void drawScore(int score);
void drawKeyMove();
void drawGate(int x,int y);
void drawWallAroundScoreBoard();
void drawSettingsBoard();
void announceGameOver(int score);