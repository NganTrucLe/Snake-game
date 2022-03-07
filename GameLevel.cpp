#include "GameLevel.h"

void Level_1()
{
	setTextColor(1);
	drawWall();
	drawScoreBoard();
}
void Level_2()
{
	setTextColor(10);
	drawWall();
	drawScoreBoard();
	setTextColor(10);
	for (int x = 15; x <= 70; x++)
	{
		gotoXY(x, 11);
		cout << (char)223;
	}
}
void Level_3()
{
	setTextColor(13);
	drawWall();
	drawScoreBoard();
	setTextColor(13);
	for (int y = WALL_ABOVE + 1; y < 15; y++)
	{
		gotoXY(30, y);
		cout << (char)222;
	}
	for (int y = WALL_BOTTOM - 1; y > 7; y--)
	{
		gotoXY(57, y);
		cout << (char)222;
	}
}
void Level_4()
{
	setTextColor(12);
	drawWall();
	drawScoreBoard();
	setTextColor(12);
	for (int y = WALL_ABOVE + 1; y < 8; y++) {
		gotoXY( WALL_CHALLENGE_RIGHT , y);
		cout << (char)222;
	}
	for (int x = 63; x < WALL_RIGHT-7; x++) {
		gotoXY(x,WALL_CHALLENGE_ABOVE);
		cout << (char)223;
	}
	for (int x = WALL_LEFT+7; x <25; x++) {
		gotoXY(x,WALL_CHALLENGE_BOTTOM);
		cout << (char)223;
	}
	for (int y = 17; y < WALL_BOTTOM ; y++) {
		gotoXY(WALL_CHALLENGE_LEFT, y);
		cout << (char)222;
	}
}
void Level_5()
{
	setTextColor(14);
	drawWall();
	drawScoreBoard();
	setTextColor(14);
	for (int x = 17; x < 37; x++)
	{
		gotoXY(x, 5);
		cout << (char)223;
	}
	for (int x = 50; x < 70; x++)
	{
		gotoXY(x, 5);
		cout << (char)223;
	}
	for (int x = 17; x < 37; x++)
	{
		gotoXY(x, 19);
		cout << (char)223;
	}
	for (int x = 50; x < 70; x++)
	{
		gotoXY(x, 19);
		cout << (char)223;
	}
	for (int y = 5; y < 9; y++)
	{
		gotoXY(17, y);
		cout << (char)222;
	}
	for (int y = 18; y > 15; y--)
	{
		gotoXY(36, y);
		cout << (char)222;
	}
	for (int y = 5; y < 9; y++)
	{
		gotoXY(50, y);
		cout << (char)222;
	}
	for (int y = 18; y > 15; y--)
	{
		gotoXY(69, y);
		cout << (char)222;
	}
	for (int y = 11; y < 14; y++)
	{
		gotoXY(42, y);
		cout << (char)222;
	}
}