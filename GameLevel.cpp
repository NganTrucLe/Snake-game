#include "GameLevel.h"

void Level_1()
{
	drawWall();
}
void Level_2()
{
	Sleep(95);
	drawWall();
	for (int x = 15; x <= 70; x++)
	{
		gotoXY(x, 11);
		cout << (char)223;
	}
}
void Level_3()
{
	Sleep(90);
	drawWall();
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
	Sleep(85);
	drawWall();
	for (int y = WALL_ABOVE + 1; y < 9; y++) {
		gotoXY( WALL_CHALLENGE_RIGHT , y);
		cout << (char)222;
	}
	for (int x = 60; x < WALL_RIGHT-5; x++) {
		gotoXY(x,WALL_CHALLENGE_ABOVE);
		cout << (char)223;
	}
	for (int x = WALL_LEFT+3; x <40; x++) {
		gotoXY(x,WALL_CHALLENGE_BOTTOM);
		cout << (char)223;
	}
	for (int y = 15; y < WALL_BOTTOM - 3; y++) {
		gotoXY(WALL_CHALLENGE_LEFT, y);
		cout << (char)222;
	}
}