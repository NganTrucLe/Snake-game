#pragma warning(disable : 4996)
#include <iostream>
#include <conio.h>
#include <fstream>
#include "ConsoleWindow.h"
#include "Snake.h"
#include "Fruit.h"
#include "GameLevel.h"
#include "Draw.h"
#include "GameControl.h"

using namespace std;


bool CheckEmptyHighScoreFile();
void SaveHighScore();
void CreateNewHighScore();
void SortHighScore();
void InitializeHighScore();
void ResetHighScore();
void ShowHighScore();
bool IsExistedFileName(char FileName[]);
bool IsValidFileName(char FileName[]);
void SaveData();
void LoadData();

