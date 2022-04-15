#include "SaveAndLoad.h"
using namespace std;
bool checkEmptyHighScoreFile()
{
	ifstream fi;
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

void saveHighScore(HIGHSCORE HighScore[19])
{
	ofstream fo;
	fo.open("highscore.txt");

	for (int i = 0; i < 18; i++)
		fo << HighScore[i].name << " " << HighScore[i].score << endl << HighScore[i].time<<endl;
	fo << HighScore[18].name << " " << HighScore[18].score << endl << HighScore[18].time;

	fo.close();
}

void resetHighScore(HIGHSCORE HighScore[19])
{
	for (int i = 0; i < 19; i++)
	{
		strcpy(HighScore[i].name, "NONE");
		HighScore[i].score = 0;
		strcpy(HighScore[i].time, "_");
	}
	saveHighScore(HighScore);
}

void initializeHighScore(HIGHSCORE HighScore[19])
{
	if (!checkEmptyHighScoreFile())
	{
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
			if (i == 19) break;
		}
		fi.close();
	}
	else resetHighScore(HighScore);
}

void createNewHighScore(HIGHSCORE HighScore[19], HIGHSCORE NewScore)
{
	int index = -1;
	for (int i = 0; i < 19; i++)
	{
		if (strcmp(HighScore[i].name,"NONE") == 0 || HighScore[i].score < NewScore.score)
		{
			index = i;
			break;
		}
	}
	if (index == -1) return;
	for (int j = 18; j > index; j--) {
		strcpy(HighScore[j].name, HighScore[j - 1].name);
		strcpy(HighScore[j].time, HighScore[j - 1].time);
		HighScore[j].score = HighScore[j - 1].score;
	}
	strcpy(HighScore[index].name, NewScore.name);
	strcpy(HighScore[index].time, NewScore.time);
	HighScore[index].score = NewScore.score;
	saveHighScore(HighScore);
}

void sortHighScore(HIGHSCORE HighScore[19])
{
	for (int i = 0; i < 18; i++)
		for (int j = i + 1; j < 19; j++)
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
	saveHighScore(HighScore);
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
bool isExistedFileName(char FileName[])
{
	ifstream inputFile(FileName);
	if (!inputFile.good()) {
		return false;
	}
	return true;
}
bool isValidFileName(char FileName[])
{
	for (int i = 0; i < 40; i++)
		if (FileName[i] == '>' || FileName[i] == '<' || FileName[i] == ':'
			|| FileName[i] == '"' || FileName[i] == '/' || FileName[i] == '\\'
			|| FileName[i] == '|' || FileName[i] == '?' || FileName[i] == '*')
			return false;
	return true;
}
