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
	gotoXY(WALL_RIGHT + 16, WALL_ABOVE+1);
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
	setTextColor(8);
	gotoXY(WALL_RIGHT + 5, WALL_ABOVE + 18);
	cout << "PAUSE (SPACE_BAR)";
	gotoXY(WALL_RIGHT + 5, WALL_ABOVE + 20);
	cout << "SAVE AND EXIT";
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
void deleteGameScreen() {
	for (int i = WALL_ABOVE + 1; i < WALL_BOTTOM; i++)
		for (int j = WALL_LEFT + 1; j < WALL_RIGHT; j++) {
			gotoXY(j, i);
			cout << (char)255;
		}
}

void drawLevel1()
{
	gotoXY(15, 23);
	setTextColor(12);
	cout << R"(
	  .---.       .-''-.  ,---.  ,---.   .-''-.    .---.                ,---.  
	  | ,_|     .'_ _   \ |   /  |   | .'_ _   \   | ,_|               /_   |  
	,-./  )    / ( ` )   '|  |   |  .'/ ( ` )   ',-./  )                 ,_ |  
	\  '_ '`) . (_ o _)  ||  | _ |  |. (_ o _)  |\  '_ '`)           ,-./  )|  
	 > (_)  ) |  (_,_)___||  _( )_  ||  (_,_)___| > (_)  )           \  '_ '`) 
	(  .  .-' '  \   .---.\ (_ o._) /'  \   .---.(  .  .-'            > (_)  ) 
	 `-'`-'|___\  `-'    / \ (_,_) /  \  `-'    / `-'`-'|___         (  .  .-' 
	  |        \\       /   \     /    \       /   |        \         `-'`-'|  
	  `--------` `'-..-'     `---`      `'-..-'    `--------`           '---'  )";
}
void drawLevel2()
{
	gotoXY(15, 23);
	setTextColor(10);
	cout << R"(
	  .---.       .-''-.  ,---.  ,---.   .-''-.    .---.                 .`````-.   
	  | ,_|     .'_ _   \ |   /  |   | .'_ _   \   | ,_|                /   ,-.  \  
	,-./  )    / ( ` )   '|  |   |  .'/ ( ` )   ',-./  )               (___/  |   | 
	\  '_ '`) . (_ o _)  ||  | _ |  |. (_ o _)  |\  '_ '`)                   .'  /  
	 > (_)  ) |  (_,_)___||  _( )_  ||  (_,_)___| > (_)  )               _.-'_.-'   
	(  .  .-' '  \   .---.\ (_ o._) /'  \   .---.(  .  .-'             _/_  .'      
	 `-'`-'|___\  `-'    / \ (_,_) /  \  `-'    / `-'`-'|___          ( ' )(__..--. 
	  |        \\       /   \     /    \       /   |        \        (_{;}_)      | 
	  `--------` `'-..-'     `---`      `'-..-'    `--------`         (_,_)-------' )";
}
void drawLevel3()
{
	gotoXY(12, 23);
	setTextColor(14);
	cout << R"(
	  .---.       .-''-.  ,---.  ,---.   .-''-.    .---.                .-'''-.    
	  | ,_|     .'_ _   \ |   /  |   | .'_ _   \   | ,_|               /   _   \   
	,-./  )    / ( ` )   '|  |   |  .'/ ( ` )   ',-./  )              |__/` '.  |  
	\  '_ '`) . (_ o _)  ||  | _ |  |. (_ o _)  |\  '_ '`)               .--'  /   
	 > (_)  ) |  (_,_)___||  _( )_  ||  (_,_)___| > (_)  )            ___'--._ _\  
	(  .  .-' '  \   .---.\ (_ o._) /'  \   .---.(  .  .-'           |   |  ( ` )  
	 `-'`-'|___\  `-'    / \ (_,_) /  \  `-'    / `-'`-'|___         |   `-(_{;}_) 
	  |        \\       /   \     /    \       /   |        \         \     (_,_)  
	  `--------` `'-..-'     `---`      `'-..-'    `--------`          `-..__.-'   )";
}
void drawLevel4()
{
	gotoXY(12, 23);
	setTextColor(13);
	cout << R"(
	  .---.       .-''-.  ,---.  ,---.   .-''-.    .---.                   ,---.   
	  | ,_|     .'_ _   \ |   /  |   | .'_ _   \   | ,_|                  /,--.|   
	,-./  )    / ( ` )   '|  |   |  .'/ ( ` )   ',-./  )                 //_  ||   
	\  '_ '`) . (_ o _)  ||  | _ |  |. (_ o _)  |\  '_ '`)              /_( )_||   
	 > (_)  ) |  (_,_)___||  _( )_  ||  (_,_)___| > (_)  )             /(_ o _)|   
	(  .  .-' '  \   .---.\ (_ o._) /'  \   .---.(  .  .-'            / /(_,_)||_  
	 `-'`-'|___\  `-'    / \ (_,_) /  \  `-'    / `-'`-'|___         /  `-----' || 
	  |        \\       /   \     /    \       /   |        \        `-------|||-' 
	  `--------` `'-..-'     `---`      `'-..-'    `--------`                '-'   )";
}
void drawLevel5()
{
	gotoXY(12, 23);
	setTextColor(11);
	cout << R"(
	  .---.       .-''-.  ,---.  ,---.   .-''-.    .---.             ,--------.   
	  | ,_|     .'_ _   \ |   /  |   | .'_ _   \   | ,_|             |   _____|   
	,-./  )    / ( ` )   '|  |   |  .'/ ( ` )   ',-./  )             |  )         
	\  '_ '`) . (_ o _)  ||  | _ |  |. (_ o _)  |\  '_ '`)           |  '----.    
	 > (_)  ) |  (_,_)___||  _( )_  ||  (_,_)___| > (_)  )           |_.._ _  '.  
	(  .  .-' '  \   .---.\ (_ o._) /'  \   .---.(  .  .-'              ( ' )   \ 
	 `-'`-'|___\  `-'    / \ (_,_) /  \  `-'    / `-'`-'|___          _(_{;}_)  | 
	  |        \\       /   \     /    \       /   |        \        |  (_,_)  /  
	  `--------` `'-..-'     `---`      `'-..-'    `--------`         `...__..'   )";
}
void announceGameOver(int score) {
	int key;
	key = inputKey();  
	setTextColor(11);
	gotoXY(50, 25);
	cout << R"(
		  _______      ___      .___  ___.  _______      ______   ____    ____  _______ .______      
		 /  _____|    /   \     |   \/   | |   ____|    /  __  \  \   \  /   / |   ____||   _  \     
		|  |  __     /  ^  \    |  \  /  | |  |__      |  |  |  |  \   \/   /  |  |__   |  |_)  |    
		|  | |_ |   /  /_\  \   |  |\/|  | |   __|     |  |  |  |   \      /   |   __|  |      /     
		|  |__| |  /  _____  \  |  |  |  | |  |____    |  `--'  |    \    /    |  |____ |  |\  \----.
		 \______| /__/     \__\ |__|  |__| |_______|    \______/      \__/     |_______|| _| `._____|)";
	gotoXY(57, 32);
	cout << "Your score: " << score;
	gotoXY(57, 33);
	cout << "Try again? (Y/N)";
	setTextColor(15);
}
void announceWin(const int score, char *&saveName) {
	clrscr();
	int key;
	key = inputKey();
	setTextColor(11);
	gotoXY(25, 25);
	cout << R"(



						____    ____  ______    __    __   __.______       _______    ____    __    ____  __  .__   __.  __  
						\   \  /   / /  __  \  |  |  |  | (_ )   _  \     |   ____|   \   \  /  \  /   / |  | |  \ |  | |  | 
						 \   \/   / |  |  |  | |  |  |  |  |/|  |_)  |    |  |__       \   \/    \/   /  |  | |   \|  | |  | 
						  \_    _/  |  |  |  | |  |  |  |    |      /     |   __|       \            /   |  | |  . `  | |  | 
							|  |    |  `--'  | |  `--'  |    |  |\  \----.|  |____       \    /\    /    |  | |  |\   | |__| 
							|__|     \______/   \______/     | _| `._____||_______|       \__/  \__/     |__| |__| \__| (__)




)";



	deleteGameScreen();
	gotoXY(30, 8);
	cout << "Your score: " << score;
	gotoXY(30,10);
	cout << "Enter your name: ";
	char name[10] = {}, ch, cnt = 0;
	cin.getline(name, 10);
	gotoXY(32, 10);
	saveName=name;
}