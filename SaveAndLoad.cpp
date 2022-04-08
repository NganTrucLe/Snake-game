#include "SaveAndLoad.h"
#include "GameControl.h"

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

void SaveData() {
	char FileName[40];
	do
	{
		cin.getline(FileName,40);
		if (IsExistedFileName(FileName))
			cout << "File existed, re-type!";
		if (!IsValidFileName(FileName))
			cout << "Invalid char, re-type!";
		if (strlen(FileName) > 40)
			cout << "Too long, re-type!";

		if (IsExistedFileName(FileName) || !IsValidFileName(FileName) || strlen(FileName) > 40)
		{
			for (int i = 0; i < 40; i++)
				cout << " ";
		}
	} while (IsExistedFileName(FileName) || !IsValidFileName(FileName) || strlen(FileName) > 40);
	//ofstream fo("dataofsnake.txt" + FileName[40]);

	ofstream f_user;
	f_user.open("username.txt", ios::app);
	f_user << FileName << endl;
	f_user.close();

	/*fo << length << " " << score << endl;

	for (int i = 0; i < length; i++)
		fo << position[i].x << " " << position[i].y << endl;


	fo << MyFruit.corX<<" "<< MyFruit.corY<< endl;

	if (GATE_EXIST)                      //cổng xuất hiện ?
		fo << a.x << " " << a.y << endl; //vị trí cổng ?
	else
		fo << -1 << " " << -1 << endl;

	fo << speed << endl;

	fo << state << endl;

	fo<<level<<endl;

	fo << MOVING << endl; //?

	fo << CHAR_LOCK << endl; //?


	fo.close();

	strcpy(NewScore.name, FileName);
	NewScore.score = score;

	CreateNewHighScore();
	SortHighScore();*/
}
void LoadData()
{
	char FileName[40];
	do
	{
		cin.getline(FileName,40);
		if (!IsExistedFileName(FileName))
		{
			cout << "Not existed user!";
			for (int i = 0; i < 18; i++)
				cout << " ";
		}
	} while (!IsExistedFileName(FileName));

	/*for (int i = 0; i < length; i++)
	{
		GotoXY(position[i].x, position[i].y);
		cout << " ";
	}

	ifstream fi("dataofsnake.txt" + FileName[40]);

	fi >> length >> score;


	for (int i = 0; i < length; i++)
		fi >> position[i].x >> position[i].y;

	GotoXY(MyFruit.corX, MyFruit.corY);

	cout << " ";
	fi >> fMyFruit.corX >> MyFruit.corY;

	fi >> a.x >> a.y;
	if (a.x != -1 && a.y != -1)
	{
		drawGate(a.x,a.y);
	}


	fi >> speed;

	fi >> state;

	fi >> level;

	fi >> MOVING; //?

	fi >> CHAR_LOCK; //?


	fi.close();*/
}