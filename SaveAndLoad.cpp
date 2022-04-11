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
//bool IsExistedFileName(char FileName[])
//{
//	ifstream f_user("username.txt");
//	char tmp[40];
//
//	while (f_user >> tmp)
//		if (tmp == FileName)
//		{
//			f_user.close();
//			return true;
//		}
//	f_user.close();
//	return false;
//}
//
//bool IsValidFileName(char FileName[])
//{
//	for (int i = 0; i < 40; i++)
//		if (FileName[i] == '>' || FileName[i] == '<' || FileName[i] == ':'
//			|| FileName[i] == '"' || FileName[i] == '/' || FileName[i] == '\\'
//			|| FileName[i] == '|' || FileName[i] == '?' || FileName[i] == '*')
//			return false;
//	return true;
//}
//
//void SaveData() {
//	Game MyGame;
//	Snake MySnake;
//	Fruit MyFruit;
//	char FileName[40];
//	do
//	{
//		cin.getline(FileName,40);
//		if (IsExistedFileName(FileName))
//			cout << "File existed, re-type!";
//		if (!IsValidFileName(FileName))
//			cout << "Invalid char, re-type!";
//		if (strlen(FileName) > 40)
//			cout << "Too long, re-type!";
//
//		if (IsExistedFileName(FileName) || !IsValidFileName(FileName) || strlen(FileName) > 40)
//		{
//			for (int i = 0; i < 40; i++)
//				cout << " ";
//		}
//	} while (IsExistedFileName(FileName) || !IsValidFileName(FileName) || strlen(FileName) > 40);
//	ofstream fo("dataofsnake.txt" + FileName[40]);
//
//	ofstream f_user;
//	f_user.open("username.txt", ios::app);
//	f_user << FileName << endl;
//	f_user.close();
//
//	//fo << MySnake.length << " " << MyGame.score << endl;
//
//	for (int i = 0; i < MySnake.length; i++)
//		fo << MySnake.position[i].first<< " " << MySnake.position[i].second << endl;
//
//	fo << MySnake.speed << endl;
//
//	fo << MySnake.direction<<endl;
//
//	fo << MyFruit.corX<<" "<< MyFruit.corY<< endl;
//
//	/*if (GATE_EXIST)                      //cổng xuất hiện ?
//		fo << MyGame.gate_position[MyGame.level - 1].first << " " << MyGame.gate_position[MyGame.level - 1].second << " " << MyGame.gate << endl; //vị trí cổng ?
//	else
//		fo << -1 << " " << -1 << endl;*/
//
//	/*fo << MyGame.state << endl;
//
//	fo<<MyGame.level<<endl;*/
//
//
//	fo.close();
//
//	strcpy(NewScore.name, FileName);
//	//NewScore.score = MyGame.score;
//
//	CreateNewHighScore();
//	SortHighScore();
//}
//void LoadData()
//{
//	Game MyGame;
//	Snake MySnake;
//	Fruit MyFruit;
//	vector<pii>gate;
//	char FileName[40];
//	do
//	{
//		cin.getline(FileName,40);
//		if (!IsExistedFileName(FileName))
//		{
//			cout << "Not existed user!";
//			for (int i = 0; i < 18; i++)
//				cout << " ";
//		}
//	} while (!IsExistedFileName(FileName));
//
//	for (int i = 0; i < MySnake.length; i++)
//	{
//		gotoXY(MySnake.position[i].first, MySnake.position[i].second);
//		cout << " ";
//	}
//
//	ifstream fi("dataofsnake.txt" + FileName[40]);
//
//	//fi >> MySnake.length >> MyGame.score;
//
//
//	for (int i = 0; i < MySnake.length; i++)
//		fi >> MySnake.position[i].first >> MySnake.position[i].second;
//
//	fi >> MySnake.speed;
//
//	fi >> MySnake.direction;
//
//	gotoXY(MyFruit.corX, MyFruit.corY);
//
//	cout << " ";
//
//	fi >> MyFruit.corX >> MyFruit.corY;
//
//	//fi >> a.x >> a.y;
//
//	/*if (a.x != -1 && a.y != -1)
//	{
//		drawGate(a.x,a.y,gate);
//	}*/
//
//
//	/*fi >> MyGame.state;
//
//	fi >> MyGame.level;*/
//
//
//	fi.close();
//}