#pragma warning(disable : 4996)
#include <iostream>
#include <conio.h>
#include <fstream>

using namespace std;

struct HIGHSCORE {
	char name[40];
	int score;
};

bool CheckEmptyHighScoreFile();
void SaveHighScore();
void CreateNewHighScore();
void SortHighScore();
void InitializeHighScore();
void ResetHighScore();
void ShowHighScore();
void SaveData();
void LoadData();

