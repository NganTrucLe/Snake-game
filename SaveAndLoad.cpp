#include "SaveAndLoad.h"

HIGHSCORE HighScore[5];
HIGHSCORE NewScore;

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

void SaveHighScore()
{
	ofstream fo;
	fo.open("highscore.txt");

	for (int i = 0; i < 4; i++)
		fo << HighScore[i].name << " " << HighScore[i].score << endl;
	fo << HighScore[4].name << " " << HighScore[4].score;

	fo.close();
}

void ResetHighScore()
{
	for (int i = 0; i < 5; i++)
	{
		strcpy(HighScore[i].name, "NONE");
		HighScore[i].score = 0;
	}
	SaveHighScore();
}

void InitializeHighScore()
{
	if (!CheckEmptyHighScoreFile())
	{
		//string name;
		char name[40] = {};
		int score;

		ifstream fi;
		fi.open("highscore.txt");

		int i = 0;

		while (fi >> name >> score)
		{
			strcpy(HighScore[i].name, "NONE");
			HighScore[i].score = score;
			i++;
		}

		fi.close();
	}
	else
		ResetHighScore();
}

void CreateNewHighScore()
{
	int minScore = HighScore[0].score;
	int index = 0;
	for (int i = 0; i < 5; i++)
	{
		if (HighScore[i].name == "NONE")
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
	if (NewScore.score > minScore || (NewScore.score == 0 && HighScore[index].name == "NONE"))
	{
		strcpy(HighScore[index].name, NewScore.name);
		HighScore[index].score = NewScore.score;
	}
}

void SortHighScore()
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
	SaveHighScore();
}

void ShowHighScore()
{
	ifstream fi;
	fi.open("highscore.txt");
	//string name;
	char* name=new char[40];
	int score;
	system("cls");
	while (true)
	{
		int i = 0;
		while (fi >> name >> score)
		{
			
			cout << "#" << i + 1 << ". ";
			
			cout << name<<"\t";
			
			cout << score;

			i++;
			cout << endl;
		}
		if (_kbhit())
		{
			break;
		}
	}
	fi.close();
}

void SaveData() {

}