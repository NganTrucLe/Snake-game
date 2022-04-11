#pragma warning(disable : 4996)
#include <iostream>
#include <conio.h>
#include <fstream>

using namespace std;

struct HIGHSCORE {
    char* name = new char[10];
    int score;
    char* time = new char[30];
};

bool CheckEmptyHighScoreFile();
void SaveHighScore(HIGHSCORE HighScore[5]);
void CreateNewHighScore(HIGHSCORE HighScore[5], HIGHSCORE NewScore);
void SortHighScore(HIGHSCORE HighScore[5]);
void InitializeHighScore(HIGHSCORE HighScore[5]);
void ResetHighScore(HIGHSCORE HighScore[5]);
bool IsExistedFileName(char FileName[]);
bool IsValidFileName(char FileName[]);
void SaveData();
void LoadData();

