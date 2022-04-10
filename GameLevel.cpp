#include "GameLevel.h"

void Level_1(vector<pii>& wallChallenge, int highScore)
{
	wallChallenge.resize(0);
	setTextColor(1);
	drawWall();
	drawScoreBoard(highScore);
	drawLevel1();
}
void Level_2(vector<pii>& wallChallenge, int highScore)
{
	wallChallenge.resize(0);
	setTextColor(10);
	drawWall();
	drawScoreBoard(highScore);
	drawLevel2();
	setTextColor(10);
	for (int x = 15; x <= 70; x++)
	{
		gotoXY(x, 11);
		cout << (char)223;
		wallChallenge.push_back(pii(x, 11));
	}
}
void Level_3(vector<pii>& wallChallenge, int highScore)
{
	wallChallenge.resize(0);
	setTextColor(13);
	drawWall();
	drawScoreBoard(highScore);
	drawLevel3();
	setTextColor(13);
	for (int y = WALL_ABOVE + 1; y < 15; y++)
	{
		gotoXY(30, y);
		cout << (char)222;
		wallChallenge.push_back(pii(30, y));
	}
	for (int y = WALL_BOTTOM - 1; y > 7; y--)
	{
		gotoXY(57, y);
		cout << (char)222;
		wallChallenge.push_back(pii(57, y));
	}
}
void Level_4(vector<pii>& wallChallenge, int highScore)
{
	wallChallenge.resize(0);
	setTextColor(12);
	drawWall();
	drawScoreBoard(highScore);
	drawLevel4();
	setTextColor(12);
	for (int y = WALL_ABOVE + 1; y < 8; y++) {
		gotoXY( 50 , y);
		cout << (char)222;
		wallChallenge.push_back(pii(50, y));
	}
	for (int x = 63; x < WALL_RIGHT-7; x++) {
		gotoXY(x,11);
		cout << (char)223;
		wallChallenge.push_back(pii(x,11 ));
	}
	for (int x = WALL_LEFT+7; x <25; x++) {
		gotoXY(x,13);
		cout << (char)223;
		wallChallenge.push_back(pii(x, 13));
	}
	for (int y = 17; y < WALL_BOTTOM ; y++) {
		gotoXY(35, y);
		cout << (char)222;
		wallChallenge.push_back(pii(35, y));
	}
}
void Level_5(vector<pii> & wallChallenge, int highScore)
{
	wallChallenge.resize(0);
	setTextColor(14);
	drawWall();
	drawScoreBoard(highScore);
	drawLevel5();
	setTextColor(14);
	for (int x = 17; x < 37; x++)
	{
		gotoXY(x, 5);
		cout << (char)223;
		wallChallenge.push_back(pii(x, 5));
	}
	for (int x = 50; x < 70; x++)
	{
		gotoXY(x, 5);
		cout << (char)223;
		wallChallenge.push_back(pii(x, 5));
	}
	for (int x = 17; x < 37; x++)
	{
		gotoXY(x, 19);
		cout << (char)223;
		wallChallenge.push_back(pii(x, 19));
	}
	for (int x = 50; x < 70; x++)
	{
		gotoXY(x, 19);
		cout << (char)223;
		wallChallenge.push_back(pii(x, 19));
	}
	for (int y = 5; y < 9; y++)
	{
		gotoXY(17, y);
		cout << (char)222;
		wallChallenge.push_back(pii(17, y));
	}
	for (int y = 18; y > 15; y--)
	{
		gotoXY(36, y);
		cout << (char)222;
		wallChallenge.push_back(pii(36, y));
	}
	for (int y = 5; y < 9; y++)
	{
		gotoXY(50, y);
		cout << (char)222;
		wallChallenge.push_back(pii(50, y));
	}
	for (int y = 18; y > 15; y--)
	{
		gotoXY(69, y);
		cout << (char)222;
		wallChallenge.push_back(pii(69, y));
	}
	for (int y = 11; y < 14; y++)
	{
		gotoXY(42, y);
		cout << (char)222;
		wallChallenge.push_back(pii(42, y));
	}
}