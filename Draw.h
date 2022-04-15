#pragma once
#include <iostream>
#include <cstdio>
#include <vector>
#include "GameLevel.h"
#include "ConsoleWindow.h"

#define WALL_LEFT 3
#define WALL_RIGHT 83
#define WALL_ABOVE 1
#define WALL_BOTTOM 23

#define WHITE	7
#define RED		12
#define YELLOW	14

using namespace std;
void drawSand();
void drawWall(); 
void drawScoreBoard(int highscore);
void drawScore(int score);
void drawKeyMove();
void drawGate(int x,int y, vector<pii>& gate);
void drawWallAroundScoreBoard();
void drawSettingsBoard();
void drawLeaderBoard();
void deleteGameScreen();
void deleteAnnounceArea();
void drawKeyBoard();
void drawLevel1();
void drawLevel2();
void drawLevel3();
void drawLevel4();
void drawLevel5();
void announceGameOver(int score, char*& saveName);
void announceWin(const int score, char *&saveName);