#pragma warning(disable : 4996)
#include <iostream>
#include <cstdio>
#include <vector>
#include <conio.h>
#include <fstream>
#include "ConsoleWindow.h"

using namespace std;

struct HIGHSCORE {
    char* name = new char[10];
    int score;
    char* time = new char[30];
};

bool checkEmptyHighScoreFile();
void saveHighScore(HIGHSCORE HighScore[5]);
void createNewHighScore(HIGHSCORE HighScore[5], HIGHSCORE NewScore);
void sortHighScore(HIGHSCORE HighScore[5]);
void initializeHighScore(HIGHSCORE HighScore[5]);
void resetHighScore(HIGHSCORE HighScore[5]);
void saveDataGame(char FileName[], const int level, const int score, vector<pii> gate);
void saveDataSnake(char FileName[], vector<pii>position, vector<bool>appear, const int direction);
void saveDataFruit(char FileName[], pii position);
void loadDataGame(char FileName[], int& level, int& score, vector<pii>& gate, vector<pii>& position, vector<bool>& appear, int& direction, pii& fruit);
void loadDataSnake(char FileName[], vector<pii>& position, vector<bool>appear, int& direction);
void loadDataFruit(char FileName[], pii& position);
bool isExistedFileName(char FileName[]);
bool isValidFileName(char FileName[]);

