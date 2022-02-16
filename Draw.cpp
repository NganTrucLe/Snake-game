#include "Draw.h"

void drawWall() {
	for (int x = WALL_LEFT; x <= WALL_RIGHT; x++) {
		gotoXY(x, WALL_ABOVE);
		cout << (char)220;
	}
	for (int x = WALL_LEFT; x <= WALL_RIGHT; x++) {
		gotoXY(x, WALL_BOTTOM);
		cout << (char)223;
	}
	for (int y = WALL_ABOVE + 1; y < WALL_BOTTOM; y++) {
		gotoXY(WALL_LEFT, y);
		cout << (char)221;
	}
	for (int y = WALL_ABOVE + 1; y < WALL_BOTTOM; y++) {
		gotoXY(WALL_RIGHT, y);
		cout << (char)222;
	}
}
void drawScore(int score)
{
	setTextColor(10);
	gotoXY(WALL_RIGHT + 5, WALL_ABOVE + 2);
	cout << "SCORE:" << score;
}
void drawScoreBoard()
{
	setTextColor(3);
	gotoXY(WALL_RIGHT + 5, WALL_ABOVE);
	cout << "SCOREBOARD";
	setTextColor(6);
	gotoXY(WALL_RIGHT + 5, WALL_ABOVE+4);
	cout << "HOW TO PLAY:";
	drawKeyMove();
	
}
void drawKeyMove()
{
	gotoXY(WALL_RIGHT + 12, WALL_ABOVE + 7);
	cout << "LEFT";
	gotoXY(WALL_RIGHT + 23, WALL_ABOVE + 7);
	cout << "RIGHT";
	gotoXY(WALL_RIGHT + 19, WALL_ABOVE + 5);
	cout << "UP";
	gotoXY(WALL_RIGHT + 18, WALL_ABOVE + 9);
	cout << "DOWN";
	gotoXY(WALL_RIGHT + 16, WALL_ABOVE + 7);
	cout << (char)17;
	gotoXY(WALL_RIGHT + 22, WALL_ABOVE + 7);
	cout << (char)16;
	gotoXY(WALL_RIGHT + 19, WALL_ABOVE + 6);
	cout << (char)30;
	gotoXY(WALL_RIGHT + 19, WALL_ABOVE + 8);
	cout << (char)31;

}
void drawGate(int x,int y)
{
	gotoXY(x, y);
	cout << (char)221;
	for (int i = x; i < x + 4; i++)
	{
		gotoXY(i, y - 1);
		cout << (char)220;
	}
	gotoXY(x + 3, y);
	cout << (char)222;
}