#pragma once
#include <iostream>
#include <cstdio>
#include <vector>
#include <stdio.h>
#include "ConsoleWindow.h"
#include "Draw.h"
#include "Snake.h"
#include "Fruit.h"
#include "GameLevel.h"
#include "Component.h"
#include "SaveAndLoad.h"

#define LOADING         0
#define MENU            1
#define INTRODUCTION    2
#define LEADER_BOARD    3
#define EXIT_GAME       4
#define NEW_GAME        5
#define LOAD_GAME       6
#define HOW_TO_PLAY     7

using namespace std;

class Menu {
public:
    int state;
    HIGHSCORE HighScore[5];
    Menu() {
        state = LOADING;
    }
    void menuControl() {
        while (1) {
            switch (state) {
            case LOADING:
                title();
                loadingBar();
                snakeIcon();
                borderMenu();
                state = MENU;
                break;
            case NEW_GAME:
                clrscr();
                return;
                break;
            case LOAD_GAME:
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
    void restart() {
        clrscr();
        state = LOADING;
        menuControl();
    }
private:
    void borderMenu()
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
    void title()
    {
        setTextColor(10);
        gotoXY(5, 3);
        cout << R"(
    __    __   __    __  .__   __. .___________. __  .__   __.   _______         _______..__   __.      ___       __  ___  _______ 
   |  |  |  | |  |  |  | |  \ |  | |           ||  | |  \ |  |  /  _____|       /       ||  \ |  |     /   \     |  |/  / |   ____|
   |  |__|  | |  |  |  | |   \|  | `---|  |----`|  | |   \|  | |  |  __        |   (----`|   \|  |    /  ^  \    |  '  /  |  |__   
   |   __   | |  |  |  | |  . `  |     |  |     |  | |  . `  | |  | |_ |        \   \    |  . `  |   /  /_\  \   |    <   |   __|  
   |  |  |  | |  `--'  | |  |\   |     |  |     |  | |  |\   | |  |__| |    .----)   |   |  |\   |  /  _____  \  |  .  \  |  |____ 
   |__|  |__|  \______/  |__| \__|     |__|     |__| |__| \__|  \______|    |_______/    |__| \__| /__/     \__\ |__|\__\ |_______|
                                                                                                                                
)";
}
    void snakeIcon()
    {
        gotoXY(30, 30);
        setTextColor(14);
        cout << R"(







                                                                                           /^\/^\
                                                                                         _|__|  O|
                                                                                \/     /~     \_/ \
                                                                                 \____|__________/  \
                                                                                        \_______      \
                                                                                                `\     \                 \
                                                                                                  |     |                  \
                                                                                                 /      /                    \
                                                                                                /     /                       \\
                                                                                              /      /                         \ \
                                                                                             /     /                            \  \
                                                                                           /     /             _----_            \   \
                                                                                          /     /           _-~      ~-_         |   |
                                                                                         (      (        _-~    _--_    ~-_     _/   |
                                                                                          \      ~-____-~    _-~    ~-_    ~-_-~    /
                                                                                            ~-_           _-~          ~-_       _-~
                                                                                               ~--______-~                ~-___-~

    )";
    }
    void flower()
    {
        gotoXY(10, 27);
        //setTextColor(13);
        cout << R"(


                       wWWWw                 wWWWw              wWWWw                 wWWWw             wWWWw               
                   vVVVv (___) wWWWw         (___)  vVVVv  vVVVv (___) wWWWw         (___)  vVVVv  vVVVv (___) wWWWw        
                   (___)  ~Y~  (___)  vVVVv   ~Y~   (___)  (___)  ~Y~  (___)  vVVVv   ~Y~   (___)  (___)  ~Y~  (___)  vVVVv   
                    ~Y~   \|    ~Y~   (___)    |/    ~Y~    ~Y~   \|    ~Y~   (___)    |/    ~Y~    ~Y~   \|    ~Y~   (___)       
                    \|   \ |/   \| /  \~Y~/   \|    \ |/    \|   \ |/   \| /  \~Y~/   \|    \ |/    \|   \ |/   \| /  \~Y~/  
                   \\|// \\|// \\|/// \\|//  \\|// \\\|/// \\|// \\|// \\|/// \\|//  \\|// \\\|/// \\|// \\|// \\|/// \\|//      

)";
    }
    void menuOptions() {
        setTextColor(2);
        title();
        int Set[] = { 7,7,7,7,7,7 }; // Màu mặc định
        int counter = 1, key;
        char menuList[6][20] = { "1. New game", "2. Continue", "3. Leaderboard", "4. Introduction", "5. How to play", "6. Exit game"};
        int positionY[6] = { 20,22,24,26,28,30};
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
    void loadingBar() {
        flower();
        gotoXY(40, 15);
        cout << "LOADING...";
        gotoXY(60, 12);
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
    // Menu screens 
    void introduction() {
        clrscr();
        setTextColor(9);
        gotoXY(0, 0);
        cout << R"(                                                                                                                                                     
                          




                                .___        __                    .___             __  .__               
                                |   | _____/  |________  ____   __| _/_ __   _____/  |_|__| ____   ____  
                                |   |/    \   __\_  __ \/  _ \ / __ |  |  \_/ ___\   __\  |/  _ \ /    \ 
                                |   |   |  \  |  |  | \(  <_> ) /_/ |  |  /\  \___|  | |  (  <_> )   |  \
                                |___|___|  /__|  |__|   \____/\____ |____/  \___  >__| |__|\____/|___|  /
                                         \/                        \/           \/                    \/ 


)";
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
    void leaderBoard() {
        clrscr();
        setTextColor(14);
        cout << R"(
                                .____                      .___          ___.                         ___
                                |    |    ____ _____     __| _/__________\_ |__   _________ _______  __| _/
                                |    |  _/ __ \\__  \   / __ |/ __ \_  __ \ __ \ /  _ \__  \\_  __ \/ __ | 
                                |    |__\  ___/ / __ \_/ /_/ \  ___/|  | \/ \_\ (  <_> ) __ \|  | \/ /_/ | 
                                |_______ \___  >____  /\____ |\___  >__|  |___  /\____(____  /__|  \____ | 
                                        \/   \/     \/      \/    \/          \/           \/           \/ 

)";
        drawLeaderBoard();
        InitializeHighScore(HighScore);
        for (int i = 0; i < 5; i++) {
            gotoXY(10, 10 + i);
            cout << "No. " << i + 1;
            gotoXY(20, 10 + i);
            cout << HighScore[i].name;
            gotoXY(50, 10 + i);
            cout << HighScore[i].score;
            gotoXY(70, 10 + i);
            cout << HighScore[i].time;
        }
        backButton(52, 33);
    }
    void exitGame() {
        clrscr();
        cout << R"(





                                      
                                        ________        .__  __                                  
                                        \_____  \  __ __|__|/  |_     _________    _____   ____  
                                         /  / \  \|  |  \  \   __\   / ___\__  \  /     \_/ __ \ 
                                        /   \_/.  \  |  /  ||  |    / /_/  > __ \|  Y Y  \  ___/ 
                                        \_____\ \_/____/|__||__|    \___  (____  /__|_|  /\___  >
                                               \__>                /_____/     \/      \/     \/ 


)";
        gotoXY(59, 20);
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
    void border()
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
    }
                             

    void howToPlay()
    {
        clrscr();
        cout << R"(









                                      ___ ___                   __                  .__                
                                     /   |   \  ______  _  __ _/  |_  ____   ______ |  | _____  ___.__.
                                    /    ~    \/  _ \ \/ \/ / \   __\/  _ \  \____ \|  | \__  \<   |  |
                                    \    Y    (  <_> )     /   |  | (  <_> ) |  |_> >  |__/ __ \\___  |
                                     \___|_  / \____/ \/\_/    |__|  \____/  |   __/|____(____  / ____|
                                           \/                                |__|             \/\/     
)";
        gotoXY(57, 17);
        cout << "WELCOME TO HUNTING SNAKE";
        gotoXY(52, 19);
        setTextColor(14);
        cout << "How to move: ";
        drawKeyBoard();
        border();
        gotoXY(52, 19);
        cout << "Eat 5 fruits to pass to the next level.";
        gotoXY(52, 21);
        cout << "Go through the gate to move to next level!";
        gotoXY(52, 23);
        cout << "Avoid touching wall, gate, and yourself!";
        gotoXY(52, 25);
        cout << "Finally, enjoy the game!";
        backButton(52, 33);
        

    }
    // Components
    void backButton(int x, int y) {
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
};

