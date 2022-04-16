#include "MenuGame.h"
using namespace std;
void Menu::menuControl() {
    while (1) {
        switch (state) {
        case LOADING:
            title();
            if (!once) {
                audioBanLaNhat();
                loadingBar();
                once = 1;
            }
            state = MENU;
            break;
        case NEW_GAME:
            clrscr();
            return;
            break;
        case LOAD_GAME:
            return;
            break;
        case MENU:
            menuOptions();
            break;
        case INTRODUCTION:
            introduction();
            break;
        case LEADER_BOARD:
            leaderBoard();
            break;
        case HOW_TO_PLAY:
            howToPlay();
            break;
        case EXIT_GAME:
            exitGame();
            break;

        }

    }
}
void Menu::restart() {
    clrscr();
    state = LOADING;
    menuControl();
}
void Menu::title()
{
    setTextColor(10);
    UINT old_cp = GetConsoleOutputCP();
    SetConsoleOutputCP(CP_UTF8);
    gotoXY(20, 6);
    cout << u8"██╗  ██╗██╗   ██╗███╗   ██╗████████╗██╗███╗   ██╗ ██████╗     ███████╗███╗   ██╗ █████╗ ██╗  ██╗███████╗";
    gotoXY(20, 7);
    cout << u8"██║  ██║██║   ██║████╗  ██║╚══██╔══╝██║████╗  ██║██╔════╝     ██╔════╝████╗  ██║██╔══██╗██║ ██╔╝██╔════╝";
    gotoXY(20, 8);
    cout << u8"███████║██║   ██║██╔██╗ ██║   ██║   ██║██╔██╗ ██║██║  ███╗    ███████╗██╔██╗ ██║███████║█████╔╝ █████╗  ";
    gotoXY(20, 9);
    cout << u8"██╔══██║██║   ██║██║╚██╗██║   ██║   ██║██║╚██╗██║██║   ██║    ╚════██║██║╚██╗██║██╔══██║██╔═██╗ ██╔══╝  ";
    gotoXY(20, 10);
    cout << u8"██║  ██║╚██████╔╝██║ ╚████║   ██║   ██║██║ ╚████║╚██████╔╝    ███████║██║ ╚████║██║  ██║██║  ██╗███████╗";
    gotoXY(20, 11);
    cout << u8"╚═╝  ╚═╝ ╚═════╝ ╚═╝  ╚═══╝   ╚═╝   ╚═╝╚═╝  ╚═══╝ ╚═════╝     ╚══════╝╚═╝  ╚═══╝╚═╝  ╚═╝╚═╝  ╚═╝╚══════╝";
    SetConsoleOutputCP(old_cp);

}
void Menu::borderMenu()
{
    gotoXY(55, 20);
        cout << R"(
                                                   ______________________________
                                                 / \                             \.
                                                |   |                            |.
                                                 \_ |                            |.
                                                    |                            |.
                                                    |                            |.
                                                    |                            |.
                                                    |                            |.
                                                    |                            |.
                                                    |                            |.
                                                    |                            |.
                                                    |                            |.
                                                    |                            |.
                                                    |                            |.
                                                    |                            |.
                                                    |   _________________________|___
                                                    |  /                            /.
                                                    \_/____________________________/.)";
}
void Menu::snakeIcon1()
{
    setTextColor(14);
    cout << R"(         

                                                        __    __    __    __
                                                       /  \  /  \  /  \  /  \
______________________________________________________/  __\/  __\/  __\/  __\__________________________________________________________
_____________________________________________________/  /__/  /__/  /__/  /_____________________________________________________________
                                                    | / \   / \   / \   / \  \____
                                                    |/   \_/   \_/   \_/   \    o \
                                                                            \_____/--<)";
}
void Menu::flower()
{
    gotoXY(10, 27);
    cout << R"(


                      wWWWw               wWWWw               wWWWw              wWWWw               wWWWw               
                vVVVv (___) wWWWw         (___)  vVVVv  vVVVv (___) wWWWw        (___)  vVVVv  vVVVv (___) wWWWw        
                (___)  ~Y~  (___)  vVVVv   ~Y~   (___)  (___)  ~Y~  (___) vVVVv   ~Y~   (___)  (___)  ~Y~  (___)  vVVVv   
                ~Y~   \|    ~Y~   (___)    |/    ~Y~    ~Y~   \|    ~Y~   (___)    |/    ~Y~    ~Y~   \|    ~Y~   (___)       
                \|   \ |/   \| /  \~Y~/   \|    \ |/    \|   \ |/   \| /  \~Y~/   \|    \ |/    \|   \ |/   \| /  \~Y~/  
                \\|// \\|// \\|/// \\|//  \\|// \\\|/// \\|// \\|// \\|/// \\|//  \\|// \\\|/// \\|// \\|// \\|/// \\|//      

)";
}
void Menu::menuOptions() {
    clrscr();
    setTextColor(2);
    title();
    snakeIcon1();
    borderMenu();
    int Set[] = { 7,7,7,7,7,7 }; // Màu mặc định
    int counter = 1, key;
    char menuList[6][20] = { "1. New game", "2. Continue", "3. Leaderboard", "4. Introduction", "5. How to play", "6. Exit game" };
    int positionY[6] = { 20,22,24,26,28,30 };
    while (1)
    {
        counterEvent(key, counter, 6);
        //Đổi màu options, option counter thì có màu đỏ, còn lại trắng
        for (int i = 0; i < 6; i++)
            Set[i] = 7;
        Set[counter - 1] = 12;
        for (int i = 0; i < 6; i++) {
            gotoXY(59, positionY[i]);
            setTextColor(Set[i]);
            cout << menuList[i];
            gotoXY(55, positionY[i]);
            if (counter - 1 != i) cout << (char)255;
        }
        gotoXY(55, positionY[counter - 1]);
        setTextColor(12);
        cout << (char)16;
        const int newState[6] = { NEW_GAME, LOAD_GAME, LEADER_BOARD, INTRODUCTION, HOW_TO_PLAY, EXIT_GAME };
        if (key == ENTER)//Người dùng nhấn phím enter
        {
            state = newState[counter - 1];
            return;
        }
    }
}
void Menu::loadingBar() {
    flower();
    gotoXY(40, 15);
    cout << "LOADING...";
    gotoXY(61, 12);
    cout << "A PROJECT BY GROUP 5";

    int level = 13;


    for (int x = 55; x < 85; x++) { // 2 horizontal lines 
        gotoXY(x, 14);
        cout << char(205);
        gotoXY(x, 16);
        cout << char(205);
    }

    for (int y = 15; y < 16; y++) { //2 vertical lines
        gotoXY(55, y);
        cout << char(186);
        gotoXY(85, y);
        cout << char(186);
    }


    //top left
    gotoXY(55, 14);
    cout << (char)201;
    //top right
    gotoXY(85, 14);
    cout << (char)187;
    //bottom left
    gotoXY(55, 16);
    cout << (char)200;
    //bottom right
    gotoXY(85, 16);
    cout << (char)188;


    //bar internal content
    for (int load = 56; load <= 84; load++) {
        gotoXY(load, 15);
        cout << char(178);
        Sleep(100);


        level += 3;
        gotoXY(88, 15);
        cout << level << "%";

    }
    system("cls");
    clrscr();

}
void Menu::people()
{
    gotoXY(0, 14);
    cout << R"(
         ////^\\\\
         | ^   ^ |
        @ (o) (o) @
         |   <   |
         |  ___  |
          \_____/
        ____|  |____
       /    \__/    \
      /              \
     /\_/|        |\_/\
    / /  |        |  \ \
   ( <   |        |   > )
    \ \  |        |  / /
     \ \ |________| / /
   
)";
}
void Menu::introduction() {
    clrscr();
    people();
    setTextColor(9);
    UINT old_cp = GetConsoleOutputCP();
    SetConsoleOutputCP(CP_UTF8);
    gotoXY(20, 5);
    cout << u8"██╗███╗   ██╗████████╗██████╗  ██████╗ ██████╗ ██╗   ██╗ ██████╗████████╗██╗ ██████╗ ███╗   ██╗";
    gotoXY(20, 6);
    cout << u8"██║████╗  ██║╚══██╔══╝██╔══██╗██╔═══██╗██╔══██╗██║   ██║██╔════╝╚══██╔══╝██║██╔═══██╗████╗  ██║";
    gotoXY(20, 7);
    cout << u8"██║██╔██╗ ██║   ██║   ██████╔╝██║   ██║██║  ██║██║   ██║██║        ██║   ██║██║   ██║██╔██╗ ██║";
    gotoXY(20, 8);
    cout << u8"██║██║╚██╗██║   ██║   ██╔══██╗██║   ██║██║  ██║██║   ██║██║        ██║   ██║██║   ██║██║╚██╗██║";
    gotoXY(20, 9);
    cout << u8"██║██║ ╚████║   ██║   ██║  ██║╚██████╔╝██████╔╝╚██████╔╝╚██████╗   ██║   ██║╚██████╔╝██║ ╚████║";
    gotoXY(20, 10);
    cout << u8"██║██║ ╚████║   ██║   ██║  ██║╚██████╔╝██████╔╝╚██████╔╝╚██████╗   ██║   ██║╚██████╔╝██║ ╚████║";
    gotoXY(20, 11);
    cout << u8"╚═╝╚═╝  ╚═══╝   ╚═╝   ╚═╝  ╚═╝ ╚═════╝ ╚═════╝  ╚═════╝  ╚═════╝   ╚═╝   ╚═╝ ╚═════╝ ╚═╝  ╚═══╝";
    SetConsoleOutputCP(old_cp);
    gotoXY(20, 0);
    cout << R"(                                                                                                                                                     
                                        o  \ o / _ o       __|   \ /    |__      o _ \ o /  o
                                    /|\   |    /\  ___\o  \o   |   o/   o/__  /\    |   /|\
                                    / \  / \  | \ /)  |   ( \ /o\ / )   |  (\ / |  / \  / \)";
    setTextColor(13);
    gotoXY(47, 15);
    cout << "  PROJECT HUNTING SNAKE - HCMUS - 21CLC01" << endl;
    gotoXY(40, 17);
    setTextColor(11);
    cout << "Advisor: PhD. Truong Toan Thinh" << endl;
    gotoXY(40, 19);
    cout << "About us: " << endl;
    gotoXY(40, 21);
    cout << "1. Leader - Le Vu Ngan Truc - 21127709" << endl;
    gotoXY(40, 23);
    cout << "2. Member - Cao Hoai Yen Vy - 21127205" << endl;
    gotoXY(40, 25);
    cout << "3. Member - Au Duong Khang - 21127621" << endl;
    backButton(50, 27);
}
void Menu::leaderBoard() {
    clrscr();
    setTextColor(14);
    UINT old_cp = GetConsoleOutputCP();
    SetConsoleOutputCP(CP_UTF8);
    gotoXY(25, 1);
    setTextColor(14);
    cout << u8"██╗     ███████╗ █████╗ ██████╗ ███████╗██████╗ ██████╗  ██████╗  █████╗ ██████╗ ██████╗ ";
    gotoXY(25, 2);
    cout << u8"██║     ██╔════╝██╔══██╗██╔══██╗██╔════╝██╔══██╗██╔══██╗██╔═══██╗██╔══██╗██╔══██╗██╔══██╗";
    gotoXY(25, 3);
    cout << u8"██║     █████╗  ███████║██║  ██║█████╗  ██████╔╝██████╔╝██║   ██║███████║██████╔╝██║  ██║";
    gotoXY(25, 4);
    setTextColor(14);
    cout << u8"██║     ██╔══╝  ██╔══██║██║  ██║██╔══╝  ██╔══██╗██╔══██╗██║   ██║██╔══██║██╔══██╗██║  ██║";
    gotoXY(25, 5);
    cout << u8"███████╗███████╗██║  ██║██████╔╝███████╗██║  ██║██████╔╝╚██████╔╝██║  ██║██║  ██║██████╔╝";
    gotoXY(25, 6);
    cout << u8"╚══════╝╚══════╝╚═╝  ╚═╝╚═════╝ ╚══════╝╚═╝  ╚═╝╚═════╝  ╚═════╝ ╚═╝  ╚═╝╚═╝  ╚═╝╚═════╝ ";
    SetConsoleOutputCP(old_cp);
    drawLeaderBoard();
    initializeHighScore(HighScore);
    // In bảng điểm ra
    for (int i = 0; i < 19; i++) {
        gotoXY(16, 11 + i);
        cout << "No. " << i + 1;
        gotoXY(26, 11 + i);
        cout << HighScore[i].name;
        gotoXY(66, 11 + i);
        cout << HighScore[i].score;
        gotoXY(95, 11 + i);
        cout << HighScore[i].time;
    }
    backButton(52, 33);
}
void Menu::exitGame() {
    clrscr();
    setTextColor(13);
    UINT old_cp = GetConsoleOutputCP();
    SetConsoleOutputCP(CP_UTF8);
    gotoXY(33, 5);
    cout << u8" ██████╗ ██╗   ██╗██╗████████╗     ██████╗  █████╗ ███╗   ███╗███████╗";
    gotoXY(33, 6);
    cout << u8"██╔═══██╗██║   ██║██║╚══██╔══╝    ██╔════╝ ██╔══██╗████╗ ████║██╔════╝";
    gotoXY(33, 7);
    cout << u8"██║   ██║██║   ██║██║   ██║       ██║  ███╗███████║██╔████╔██║█████╗  ";
    gotoXY(33, 8);
    cout << u8"██║▄▄ ██║██║   ██║██║   ██║       ██║   ██║██╔══██║██║╚██╔╝██║██╔══╝  ";
    gotoXY(33, 9);
    cout << u8"╚██████╔╝╚██████╔╝██║   ██║       ╚██████╔╝██║  ██║██║ ╚═╝ ██║███████╗";
    gotoXY(33, 10);
    cout << u8" ╚══▀▀═╝  ╚═════╝ ╚═╝   ╚═╝        ╚═════╝ ╚═╝  ╚═╝╚═╝     ╚═╝╚══════╝";
    SetConsoleOutputCP(old_cp);
    gotoXY(59, 18);
    setTextColor(11);
    cout << "Do you want to exit?" << endl;
    int counter = 1;
    int Set[] = { 7 , 7 };
    int key;
    while (1)
    {
        //Đổi màu options, option counter thì có màu đỏ, còn lại trắng
        for (int i = 0; i < 2; i++)
            Set[i] = WHITE_COLOR;
        Set[counter - 1] = RED_COLOR;

        gotoXY(64, 22);
        setTextColor(Set[0]);
        cout << "1. Yes";

        gotoXY(64, 24);
        setTextColor(Set[1]);
        cout << "2. No";

        counterEvent(key, counter, 2);

        if (key == ENTER)//Người dùng nhấn phím enter
        {
            if (counter == 1)
            {
                exit(0);
                break;
            }
            if (counter == 2)
            {
                backButton(52, 33);
                break;
            }

        }
    }
}
void Menu::border()
{
    cout << R"(
                /|  /|  ---------------------------
                ||__||  |                         |
               /   O O\__    You want to play?    |
              /          \      Let's play!       |
             /      \     \                       |
            /   _    \     \ ----------------------
           /    |\____\     \      ||
          /     | | | |\____/      ||
         /       \| | | |/ |     __||
        /  /  \   -------  |_____| ||
      /   |   |           |       --|
      |   |   |           |_____  --|
      |  |_|_|_|          |     \----
      /\                  |
     / /\        |        /
    / /  |       |       |
___/ /   |       |       |
|____/    c_c_c_C/ \C_c_c_c
)";
}
void Menu::howToPlay()
{
    clrscr();
    UINT old_cp = GetConsoleOutputCP();
    SetConsoleOutputCP(CP_UTF8);
    gotoXY(24, 10);
    setTextColor(11);
    cout << u8"██╗  ██╗ ██████╗ ██╗    ██╗    ████████╗ ██████╗     ██████╗ ██╗      █████╗ ██╗   ██╗";
    gotoXY(24, 11);
    cout << u8"██║  ██║██╔═══██╗██║    ██║    ╚══██╔══╝██╔═══██╗    ██╔══██╗██║     ██╔══██╗╚██╗ ██╔╝";
    gotoXY(24, 12);
    cout << u8"███████║██║   ██║██║ █╗ ██║       ██║   ██║   ██║    ██████╔╝██║     ███████║ ╚████╔╝ ";
    gotoXY(24, 13);
    cout << u8"██╔══██║██║   ██║██║███╗██║       ██║   ██║   ██║    ██╔═══╝ ██║     ██╔══██║  ╚██╔╝ ";
    gotoXY(24, 14);
    cout << u8"██║  ██║╚██████╔╝╚███╔███╔╝       ██║   ╚██████╔╝    ██║     ███████╗██║  ██║   ██║   ";
    gotoXY(24, 15);
    cout << u8"╚═╝  ╚═╝ ╚═════╝  ╚══╝╚══╝        ╚═╝    ╚═════╝     ╚═╝     ╚══════╝╚═╝  ╚═╝   ╚═╝   ";
    SetConsoleOutputCP(old_cp);
    gotoXY(57, 17);
    cout << "WELCOME TO HUNTING SNAKE";
    gotoXY(53, 19);
    setTextColor(14);
    cout << "How to move: ";
    drawKeyBoard();
    border();
    gotoXY(53, 19);
    cout << "Eat 3 fruits to pass to the next level.";
    gotoXY(53, 21);
    cout << "Go through the gate to move to next level!";
    gotoXY(53, 23);
    cout << "Avoid touching wall, gate, and yourself!";
    gotoXY(53, 25);
    cout << "Press space bar to pause game, press again to continue";
    gotoXY(53, 27);
    cout << "Finally, enjoy the game!";
    backButton(52, 33);
}
// Components
void Menu::backButton(int x, int y) {
    gotoXY(x, y);
    setTextColor(13);
    cout << "Want to back to MENU? Press B";
    while (1) {
        int key = inputKey();
        if (key == KEY_B) {
            state = MENU;
            clrscr();
            return;
        }
    }
}