#include "SaveAndLoad.h"
using namespace std;
bool CheckEmptyHighScoreFile()
{
	ifstream fi;
	//string name;
	char name[40] = {};
	int score;

	fi.open("highscore.txt");
	if (fi >> name >> score)
	{
		fi.close();
		return false;
	}

	fi.close();
	return true;
}

void SaveHighScore(HIGHSCORE HighScore[5])
{
	ofstream fo;
	fo.open("highscore.txt");

	for (int i = 0; i < 4; i++)
		fo << HighScore[i].name << " " << HighScore[i].score << endl << HighScore[i].time << endl;
	fo << HighScore[4].name << " " << HighScore[4].score << endl << HighScore[4].time;

	fo.close();
}

void ResetHighScore(HIGHSCORE HighScore[5])
{
	for (int i = 0; i < 5; i++)
	{
		strcpy(HighScore[i].name, "NONE");
		HighScore[i].score = 0;
		strcpy(HighScore[i].time, "_");
	}
	SaveHighScore(HighScore);
}

void InitializeHighScore(HIGHSCORE HighScore[5])
{
	if (!CheckEmptyHighScoreFile())
	{
		//string name;
		char name[40] = {};
		char time[30] = {};
		int score;

		ifstream fi;
		fi.open("highscore.txt");

		int i = 0;

		while (fi >> name >> score)
		{
			strcpy(HighScore[i].name, name);
			HighScore[i].score = score;
			fi.ignore();
			fi.getline(time, 30);
			strcpy(HighScore[i].time, time);
			i++;
		}

		fi.close();
	}
	else
		ResetHighScore(HighScore);
}

void CreateNewHighScore(HIGHSCORE HighScore[5], HIGHSCORE NewScore)
{
	int minScore = HighScore[0].score;
	int index = 0;
	char* none = new char[10];
	none[0] = 'N';
	none[1] = 'O';
	none[2] = 'N';
	none[3] = 'E';
	for (int i = 0; i < 5; i++)
	{
		if (strcmp(HighScore[i].name,"NONE")==0)
		{
			minScore = HighScore[i].score;
			index = i;
			break;
		}
		else if (HighScore[i].score < minScore)
		{
			minScore = HighScore[i].score;
			index = i;
		}
	}
	if (NewScore.score > minScore || (NewScore.score == 0 && strcmp(HighScore[index].name,"NONE") == 0))
	{
		
			HighScore[index] = NewScore;
		SaveHighScore(HighScore);
	}
}

void SortHighScore(HIGHSCORE HighScore[5])
{
	for (int i = 0; i < 4; i++)
		for (int j = i + 1; j < 5; j++)
			if (HighScore[i].score < HighScore[j].score)
			{
				char name[40];
				strcpy(name, HighScore[i].name);
				strcpy(HighScore[i].name, HighScore[j].name);
				strcpy(HighScore[j].name, name);

				int score = HighScore[i].score;
				HighScore[i].score = HighScore[j].score;
				HighScore[j].score = score;
			}
	SaveHighScore(HighScore);
}
void saveDataGame(char FileName[], const int level, const int score, vector<pii> gate) {
	ofstream fo;
	fo.open(FileName);
	fo << level << endl;
	fo << score << endl;
	fo << gate.size() << endl;
	for (pii i : gate) 
		fo << i.first << " " << i.second << endl;
}

void saveDataSnake(char FileName[], vector<pii>position, vector<bool>appear, const int direction) {
	ofstream fo;
	fo.open(FileName, fstream::app);
	fo << direction << endl;
	fo << position.size() << endl;
	int cnt = 0;
	for (pii i : position) {
		fo << i.first << " " << i.second << " " << appear[cnt++] << endl;
	}
}
void saveDataFruit(char FileName[], pii position) {
	ofstream fo;
	fo.open(FileName, fstream::app);
	fo << position.first << " " << position.second << endl;
}
void loadDataGame(char FileName[], int& level, int& score, vector<pii>& gate, vector<pii>& position, vector<bool>& appear, int& direction, pii& fruit) {
	ifstream fi;
	fi.open(FileName);
	fi >> level;
	fi >> score;
	int gate_size;
	fi >> gate_size;
	gate.resize(0);
	for (int i = 0; i < gate_size; i++) {
		int x, y;
		fi >> x >> y;
		gate.push_back(pii(x, y));
	}
	if (gate.size() == 0) {
		fi >> fruit.first >> fruit.second;
	}
	fi >> direction;
	int n;
	fi >> n;
	position.resize(0);
	appear.resize(0);
	for (int i = 0; i < n; i++) {
		int x, y;
		fi >> x >> y;
		position.push_back(pii(x, y));
		bool appearing;
		fi >> appearing;
		appear.push_back(appearing);
	}
}
void loadDataFruit(char FileName[], pii& position) {
	ifstream fi;
	fi.open(FileName);
	fi >> position.first >> position.second;
}
bool IsExistedFileName(char FileName[])
{
	ifstream f_user("username.txt");
	char tmp[40];

	while (f_user >> tmp)
		if (tmp == FileName)
		{
			f_user.close();
			return true;
		}
	f_user.close();
	return false;
}

bool IsValidFileName(char FileName[])
{
	for (int i = 0; i < 40; i++)
		if (FileName[i] == '>' || FileName[i] == '<' || FileName[i] == ':'
			|| FileName[i] == '"' || FileName[i] == '/' || FileName[i] == '\\'
			|| FileName[i] == '|' || FileName[i] == '?' || FileName[i] == '*')
			return false;
	return true;
}
