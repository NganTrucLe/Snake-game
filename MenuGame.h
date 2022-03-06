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

#define LOADING         0
#define MENU            1
#define INTRODUCTION    2
#define LEADER_BOARD    3
#define EXIT_GAME       4
#define NEW_GAME        5
#define LOAD_GAME       6

using namespace std;

class Menu {
public:
    int state;
    Menu() {
        state = LOADING;
    }
    void menuControl() {
        while (1) {
            switch (state) {
            case LOADING:
                title();
                loadingBar();
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
            case EXIT_GAME:
                exitGame();
                break;
            }
        }
    }
    void restart() {
        state = LOADING;
        menuControl();
    }
private:
    void title()
    {
        setTextColor(10);
        gotoXY(0, 0);
        cout << R"(                                  
     
                    




                              ___ ___         __  .__                   _________              __           
                             /   |   \ __ ___/  |_|__| ____    ____    /   _____/ ____ _____  |  | __ ____  
                            /    ~    \  |  \   __\  |/    \  / ___\   \_____  \ /    \\__  \ |  |/ // __ \ 
                            \    Y    /  |  /|  | |  |   |  \/ /_/  >  /        \   |  \/ __ \|    <\  ___/ 
                             \___|_  /|____/ |__| |__|___|  /\___  /  /_______  /___|  (____  /__|_ \\___  >
                                   \/                     \//_____/           \/     \/     \/     \/    \/ 
                                            
       
)";
    }
    void menuOptions() {
        setTextColor(2);
        title();
        int Set[] = { 7,7,7,7,7 }; // Màu mặc định
        int counter = 1, key;
        while (1)
        {
            title();
            //Đổi màu options, option counter thì có màu đỏ, còn lại trắng
            for (int i = 0; i < 5; i++)
                Set[i] = 7;
            Set[counter - 1] = 12;

            gotoXY(59, 20);
            setTextColor(Set[0]);
            cout << "1. New game";

            gotoXY(59, 22);
            setTextColor(Set[1]);
            cout << "2. Continue";

            gotoXY(59, 24);
            setTextColor(Set[2]);
            cout << "3. Leaderboard";

            gotoXY(59, 26);
            setTextColor(Set[3]);
            cout << "4. Introduction";

            gotoXY(59, 28);
            setTextColor(Set[4]);
            cout << "5. Exit game";

            counterEvent(key, counter, 5);
            const int newState[5] = { NEW_GAME, LOAD_GAME, LEADER_BOARD, INTRODUCTION, EXIT_GAME };

            if (key == ENTER)//Người dùng nhấn phím enter
            {
                state = newState[counter - 1];
                return;
            }
        }
    }
    void loadingBar() {
        cout << "\n\n\n";
        cout << "\t\t\t\t\tLoading ";
        char x = 219;
        for (int i = 0; i < 37; i++)
        {
            cout << x;
            if (i < 10)
                Sleep(300);
            if (i >= 10 && i < 20)
                Sleep(150);
            if (i >= 10)
                Sleep(25);
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
        cout << "   DO AN RAN SAN MOI HCMUS 21CLC01" << endl;
        gotoXY(40, 17);
        setTextColor(11);
        cout << "Giao vien huong dan: Truong Toan Thinh" << endl;
        gotoXY(40, 19);
        cout << "Danh sach thanh vien: " << endl;
        gotoXY(40, 21);
        cout << "1. Le Vu Ngan Truc: Nhom truong - 21127709" << endl;
        gotoXY(40, 23);
        cout << "2. Cao Hoai Yen Vy - 21127205" << endl;
        gotoXY(40, 25);
        cout << "3. Au Duong Khang - 21127621" << endl;
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
                Set[i] = 7;
            Set[counter - 1] = 12;

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
    void counterEvent(int& key, int& counter, const int num) {
        key = inputKey(); // đồng bộ toàn chương trình, lấy hàm trong ConsoleWindow.h
        if (key == KEY_DOWN) // đồng bộ toàn chương trình, lấy define 
        {
            counter = min(counter + 1, num);
        }
        if (key == KEY_UP)
        {
            counter = max(counter - 1, 1);
        }
    }
};

