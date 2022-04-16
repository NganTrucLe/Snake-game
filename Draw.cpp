#include "Draw.h"
#include "SaveAndLoad.h"
void drawSand()
{
	for (int i = WALL_LEFT; i < WALL_RIGHT; i++)
	{
		for (int j = WALL_ABOVE; j < WALL_BOTTOM; j++)
		{
			UINT old_cp = GetConsoleOutputCP();
			SetConsoleOutputCP(CP_UTF8);
			gotoXY(i, j);
			setTextColor(6);
			cout << u8"█";
			SetConsoleOutputCP(old_cp);

		}
	}
}
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
	setTextColor(12);
	gotoXY(WALL_RIGHT + 5, WALL_ABOVE + 4);
	cout << "SCORE: " << score;
}
void drawWallAroundScoreBoard()
{
	for (int x = WALL_RIGHT + 1; x <= 120; x++)
	{
		gotoXY(x, WALL_ABOVE);
		cout << (char)220;
	}
	for (int x = WALL_RIGHT + 1; x <= 120; x++)
	{
		gotoXY(x, WALL_BOTTOM);
		cout << (char)223;
	}
	for (int x = WALL_RIGHT + 1; x <= 120; x++)
	{
		gotoXY(x, WALL_ABOVE+15);
		cout << (char)223;
	}
	for (int y = WALL_ABOVE+1; y <= WALL_BOTTOM-1; y++)
	{
		gotoXY(120, y);
		cout << (char)219;
	}
}
void drawScoreBoard(int highscore)
{
	drawWallAroundScoreBoard();
	drawSettingsBoard();
	/*fontsize(30, 30);*/
	setTextColor(11);
	gotoXY(WALL_RIGHT + 12, WALL_ABOVE + 2);
	cout << "SCOREBOARD"; 
	setTextColor(6);
	gotoXY(WALL_RIGHT + 5, WALL_ABOVE+6);
	cout << "HOW TO PLAY:";
	drawKeyMove();
	setTextColor(3);
	gotoXY(WALL_RIGHT + 5, WALL_ABOVE + 13);
	cout << "HIGHSCORE: " << highscore;

}
void drawKeyMove()
{
	gotoXY(WALL_RIGHT + 13, WALL_ABOVE + 9);
	cout << "LEFT";
	gotoXY(WALL_RIGHT + 24, WALL_ABOVE + 9);
	cout << "RIGHT";
	gotoXY(WALL_RIGHT + 20, WALL_ABOVE + 7);
	cout << "UP";
	gotoXY(WALL_RIGHT + 19, WALL_ABOVE + 11);
	cout << "DOWN";
	gotoXY(WALL_RIGHT + 18, WALL_ABOVE + 9);
	cout << (char)17;
	gotoXY(WALL_RIGHT + 22, WALL_ABOVE + 9);
	cout << (char)16;
	gotoXY(WALL_RIGHT + 20, WALL_ABOVE + 8);
	cout << (char)30;
	gotoXY(WALL_RIGHT + 20, WALL_ABOVE + 10);
	cout << (char)31;

}
void drawGate(int x,int y, vector<pii> & gate)
{
	gate.resize(0);
	setTextColor(YELLOW);
	gotoXY(x, y);
	cout << (char)221;
	gate.push_back(pii(x, y));
	for (int i = x; i < x + 3; i++)
	{
		gotoXY(i, y - 1);
		cout << (char)220;
		gate.push_back(pii(i, y-1));
	}
	gotoXY(x + 2, y);
	cout << (char)222;
	gate.push_back(pii(x+2, y));
	setTextColor(WHITE);
}
void drawSettingsBoard()
{
	setTextColor(11);
	gotoXY(WALL_RIGHT + 12, 17);
	cout << "SETTINGS";
	setTextColor(8);
	gotoXY(WALL_RIGHT + 5, WALL_ABOVE + 18);
	cout << "PAUSE (SPACE_BAR)";
	gotoXY(WALL_RIGHT + 5, WALL_ABOVE + 20);
	cout << "SAVE AND EXIT (ESC)";
}
void drawLeaderBoard() {
	//duong ngang o tren
	for (int x = WALL_LEFT + 10; x <= 125; x++)
	{
		gotoXY(x, WALL_ABOVE + 6);
		cout << (char)176;
	}
	//duong ngang o duoi
	for (int x = WALL_LEFT + 10; x <= 125; x++)
	{
		gotoXY(x, WALL_BOTTOM + 8);
		cout << (char)176;
	}
	// 2 duong doc
	for (int y = WALL_ABOVE + 7; y < WALL_BOTTOM + 8; y++)
	{
		gotoXY(WALL_LEFT + 122, y);
		cout << (char)176;
	}
	for (int y = WALL_ABOVE + 7; y < WALL_BOTTOM + 8; y++) {
		gotoXY(WALL_LEFT + 10, y);
		cout << (char)176;
	}
	//duong phan cach
	for (int y = WALL_ABOVE + 7; y < WALL_BOTTOM + 8; y++)
	{
		gotoXY(WALL_LEFT + 20, y);
		cout << (char)176;
	}
	for (int y = WALL_ABOVE + 7; y < WALL_BOTTOM + 8; y++)
	{
		gotoXY(WALL_LEFT + 60, y);
		cout << (char)176;
	}
	for (int y = WALL_ABOVE + 7; y < WALL_BOTTOM + 8; y++)
	{
		gotoXY(WALL_LEFT + 85, y);
		cout << (char)176;
	}
	for (int x = WALL_LEFT + 10; x <= 125; x++)
	{
		gotoXY(x, WALL_ABOVE + 8);
		cout << (char)176;
	}
	gotoXY(WALL_LEFT + 13, WALL_ABOVE + 7);
	setTextColor(12);
	cout << "RANK";
	gotoXY(WALL_LEFT + 23, WALL_ABOVE + 7);
	setTextColor(12);
	cout << "NAME";
	gotoXY(WALL_LEFT + 63, WALL_ABOVE + 7);
	setTextColor(12);
	cout << "SCORE";
	gotoXY(WALL_LEFT + 92, WALL_ABOVE + 7);
	setTextColor(12);
	cout << "TIME";
}

void drawKeyBoard()
{
	gotoXY(57, 22);
	cout << "LEFT";
	gotoXY(71, 22);
	cout << "RIGHT";
	gotoXY(66, 20);
	cout << "UP";
	gotoXY(65, 24);
	cout << "DOWN";

	gotoXY(63, 22);
	cout << (char)17;
	gotoXY(69, 22);
	cout << (char)16;
	gotoXY(66, 21);
	cout << (char)30;
	gotoXY(66, 23);
	cout << (char)31;

	gotoXY(79, 22);
	cout << "OR";
	gotoXY(83, 22);
	cout << "A";
	gotoXY(95, 22);
	cout << "D";
	gotoXY(89, 20);
	cout << "W";
	gotoXY(89, 24);
	cout << "S";

	gotoXY(85, 22);
	cout << (char)17;
	gotoXY(93, 22);
	cout << (char)16;
	gotoXY(89, 21);
	cout << (char)30;
	gotoXY(89, 23);
	cout << (char)31;
}
void deleteGameScreen() {
	for (int i = WALL_ABOVE + 1; i < WALL_BOTTOM; i++)
		for (int j = WALL_LEFT + 1; j < WALL_RIGHT; j++) {
			gotoXY(j, i);
			cout << (char)255;
		}
}
void deleteAnnounceArea() {
	gotoXY(0, 24);
	for (int i = 0; i < 1500; i++)
		cout << (char)255;
}
void drawLevel1()
{
	UINT old_cp = GetConsoleOutputCP();
	SetConsoleOutputCP(CP_UTF8);
	gotoXY(15, 27);
	setTextColor(12);
	cout << u8"██      ███████ ██    ██ ███████ ██           ██ ";
	gotoXY(15, 28);
	setTextColor(12);
	cout << u8"██      ██      ██    ██ ██      ██          ███ ";
	gotoXY(15, 29);
	setTextColor(12);
	cout << u8"██      █████   ██    ██ █████   ██           ██ ";
	gotoXY(15, 30);
	setTextColor(12);
	cout << u8"██      ██       ██  ██  ██      ██           ██ ";
	gotoXY(15, 31);
	setTextColor(12);
	cout << u8"███████ ███████   ████   ███████ ███████      ██ ";
	SetConsoleOutputCP(old_cp);
}
void drawLevel2()
{
	UINT old_cp = GetConsoleOutputCP();
	SetConsoleOutputCP(CP_UTF8);
	gotoXY(15, 27);
	setTextColor(12);
	cout << u8"██      ███████ ██    ██ ███████ ██          ██████  ";
	gotoXY(15, 28);
	setTextColor(12);
	cout << u8"██      ██      ██    ██ ██      ██               ██ ";
	gotoXY(15, 29);
	setTextColor(12);
	cout << u8"██      █████   ██    ██ █████   ██           █████  ";
	gotoXY(15, 30);
	setTextColor(12);
	cout << u8"██      ██       ██  ██  ██      ██          ██      ";
	gotoXY(15, 31);
	setTextColor(12);
	cout << u8"███████ ███████   ████   ███████ ███████     ███████ ";
	SetConsoleOutputCP(old_cp);
}
void drawLevel3()
{
	UINT old_cp = GetConsoleOutputCP();
	SetConsoleOutputCP(CP_UTF8);
	gotoXY(15, 27);
	setTextColor(12);
	cout << u8"██      ███████ ██    ██ ███████ ██          ██████";
	gotoXY(15, 28);
	setTextColor(12);
	cout << u8"██      ██      ██    ██ ██      ██               ██ ";
	gotoXY(15, 29);
	setTextColor(12);
	cout << u8"██      █████   ██    ██ █████   ██           █████";
	gotoXY(15, 30);
	setTextColor(12);
	cout << u8"██      ██       ██  ██  ██      ██               ██ ";
	gotoXY(15, 31);
	setTextColor(12);
	cout << u8"███████ ███████   ████   ███████ ███████     ██████ ";
	SetConsoleOutputCP(old_cp);
}
void drawLevel4()
{
	UINT old_cp = GetConsoleOutputCP();
	SetConsoleOutputCP(CP_UTF8);
	gotoXY(15, 27);
	setTextColor(12);
	cout << u8"██      ███████ ██    ██ ███████ ██          ██   ██";
	gotoXY(15, 28);
	setTextColor(12);
	cout << u8"██      ██      ██    ██ ██      ██          ██   ██";
	gotoXY(15, 29);
	setTextColor(12);
	cout << u8"██      █████   ██    ██ █████   ██          ███████ ";
	gotoXY(15, 30);
	setTextColor(12);
	cout << u8"██      ██       ██  ██  ██      ██               ██";
	gotoXY(15, 31);
	setTextColor(12);
	cout << u8"███████ ███████   ████   ███████ ███████          ██";
	SetConsoleOutputCP(old_cp);
}
void drawLevel5()
{
	UINT old_cp = GetConsoleOutputCP();
	SetConsoleOutputCP(CP_UTF8);
	gotoXY(15, 27);
	setTextColor(12);
	cout << u8"██      ███████ ██    ██ ███████ ██          ███████";
	gotoXY(15, 28);
	setTextColor(12);
	cout << u8"██      ██      ██    ██ ██      ██          ██     ";
	gotoXY(15, 29);
	setTextColor(12);
	cout << u8"██      █████   ██    ██ █████   ██          ███████";
	gotoXY(15, 30);
	setTextColor(12);
	cout << u8"██      ██       ██  ██  ██      ██               ██";
	gotoXY(15, 31);
	setTextColor(12);
	cout << u8"███████ ███████   ████   ███████ ███████     ███████";
	SetConsoleOutputCP(old_cp);
}
void announceGameOver(int score, char*& saveName) {
	deleteAnnounceArea();
	setTextColor(11);
	UINT old_cp = GetConsoleOutputCP();
	SetConsoleOutputCP(CP_UTF8);
	gotoXY(15, 27);
	setTextColor(12);
	cout << u8" ██████   █████  ███    ███ ███████      ██████  ██    ██ ███████ ██████";
	gotoXY(15, 28);
	setTextColor(12);
	cout << u8"██       ██   ██ ████  ████ ██          ██    ██ ██    ██ ██      ██   ██";
	gotoXY(15, 29);
	setTextColor(12);
	cout << u8"██   ███ ███████ ██ ████ ██ █████       ██    ██ ██    ██ █████   ██████";
	gotoXY(15, 30);
	setTextColor(12);
	cout << u8"██    ██ ██   ██ ██  ██  ██ ██          ██    ██  ██  ██  ██      ██   ██";
	gotoXY(15, 31);
	setTextColor(12);
	cout << u8" ██████  ██   ██ ██      ██ ███████      ██████    ████   ███████ ██   ██ ";
	SetConsoleOutputCP(old_cp);
	char name[10] = {};
	do {
		deleteGameScreen();
		gotoXY(30, 8);
		cout << "Your score: " << score;
		gotoXY(30, 10);
		cout << "Enter your name: ";
		cin.getline(name, 10);
		if (isValidFileName(name)) break;
		deleteGameScreen();
		gotoXY(28, 10);
		cout << "Invalid file name, re-enter!";
		Sleep(2000);
	} while (1);
	saveName = name;
	gotoXY(32, 10);
	deleteGameScreen();
	gotoXY(30, 10);
	cout << "Try again? (Y/N)";
	setTextColor(15);
}
void announceWin(const int score, char *&saveName) {
		deleteAnnounceArea();
		setTextColor(11);
		UINT old_cp = GetConsoleOutputCP();
		SetConsoleOutputCP(CP_UTF8);
		gotoXY(15, 27);
		setTextColor(12);
		cout << u8"██    ██ ██  ██████ ████████  ██████  ██████  ██    ██";
		gotoXY(15, 28);
		setTextColor(12);
		cout << u8"██    ██ ██ ██         ██    ██    ██ ██   ██  ██  ██";
		gotoXY(15, 29);
		setTextColor(12);
		cout << u8"██    ██ ██ ██         ██    ██    ██ ██████    ████";
		gotoXY(15, 30);
		setTextColor(12);
		cout << u8" ██  ██  ██ ██         ██    ██    ██ ██   ██    ██";
		gotoXY(15, 31);
		setTextColor(12);
		cout << u8"  ████   ██  ██████    ██     ██████  ██   ██    ██";
		SetConsoleOutputCP(old_cp);
	deleteGameScreen();
	gotoXY(30, 8);
	cout << "Your score: " << score;
	gotoXY(30, 10);
	cout << "Enter your name: ";
	char name[10] = {};
	cin.getline(name, 10);
	gotoXY(32, 10);
	saveName = name;
}
