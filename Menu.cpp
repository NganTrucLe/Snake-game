#include "Menu.h"
#include "ConsoleWindow.h"
#include "Snake.h"
#include "Fruit.h"
#include "Draw.h"
#include <iostream>
#include <stdio.h>
#include "SaveAndLoad.h"

using namespace std;
void loadingBar()
{
   
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
void title()
{
    setTextColor(10);
    gotoXY(0, 0);
    cout <<   R"(

                                                                                                                                                                                                                                                                             
    
          
  __    __   ____  ____  _____  ___  ___________  __    _____  ___    _______        ________  _____  ___        __       __   ___  _______  
 /" |  | "\ ("  _||_ " |(\"   \|"  \("     _   ")|" \  (\"   \|"  \  /" _   "|      /"       )(\"   \|"  \      /""\     |/"| /  ")/"     "| 
(:  (__)  :)|   (  ) : ||.\\   \    |)__/  \\__/ ||  | |.\\   \    |(: ( \___)     (:   \___/ |.\\   \    |    /    \    (: |/   /(: ______) 
 \/      \/ (:  |  | . )|: \.   \\  |   \\_ /    |:  | |: \.   \\  | \/ \           \___  \   |: \.   \\  |   /' /\  \   |    __/  \/    |   
 //  __  \\  \\ \__/ // |.  \    \. |   |.  |    |.  | |.  \    \. | //  \ ___       __/  \\  |.  \    \. |  //  __'  \  (// _  \  // ___)_  
(:  (  )  :) /\\ __ //\ |    \    \ |   \:  |    /\  |\|    \    \ |(:   _(  _|     /" \   :) |    \    \ | /   /  \\  \ |: | \  \(:      "| 
 \__|  |__/ (__________) \___|\____\)    \__|   (__\_|_)\___|\____\) \_______)     (_______/   \___|\____\)(___/    \___)(__|  \__)\_______) 
                                                                                                                                             
                                                                                                                                                                                                                                                               
                                                                                         
                                                                                                                                                                                                                                                                             
                                                                                                                                                                                                                                                                             
                                                                                                                                                                                                                                                                          
                                                                                                                                                                                                                                                                             
)";
    cout << R"(

       ---_ ......._-_--.
      (|\ /      / /| \  \
      /  /     .'  -=-'   `.
     /  /    .'             )
   _/  /   .'        _.)   /
  / o   o        _.-' /  .'
  \          _.-'    / .'*|
   \______.-'//    .'.' \*|
    \|  \ | //   .'.' _ |*|
     `   \|//  .'.'_ _ _|*|
      .  .// .'.' | _ _ \*|
      \`-|\_/ /    \ _ _ \*\
       `/'\__/      \ _ _ \*\
      /^|            \ _ _ \*
     '  `             \ _ _ \     
                       \_
)";


}

void menuOptions()
{
    setTextColor(2);
    title();

    int Set[] = { 7,7,7,7,7 }; // Màu mặc định
    int counter = 1;
    int key;
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

        key = inputKey(); // đồng bộ toàn chương trình, lấy hàm trong ConsoleWindow.h
        if (key == KEY_UP && (counter >= 2 && counter <= 5)) // đồng bộ toàn chương trình, lấy define 
        {

            counter--; 
        }
        if (key == KEY_DOWN && (counter >= 1 && counter <= 4))
        {
            counter++;
        }
        
        if (key == ENTER)//Người dùng nhấn phím enter
        {
            if (counter == 1)
            {
                newGame();
            }
            if (counter == 2)
            {
              /*  loadGame();*/
            }
            if (counter == 3)
            {
       
                leaderBoard();
            }
            if (counter == 4)
            {
                introduction();
            }
            if (counter == 5)
            {
                
                exitGame();
                
            }
            
        }
    }
}
void newGame() {
    system("cls");
    string name;
    gotoXY(53, 12);
    setTextColor(14);
    cout << "What is your name?\n";
    gotoXY(53, 14);
    cout << "Your name: ";
    cin >> name;
    system("cls");
  /*  gotoXY(53, 16);
    setTextColor(13);
    cout << "Back to MENU? Press B"; */
        while (1) {
        int key = inputKey();
        if (key == KEY_B) {
            clrscr();
            return;
        }
    }
}
void continuePage();
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
    setTextColor(11);
    cout << "About us: " << endl;
    gotoXY(40, 21);
    setTextColor(11);
    cout << "1. Leader - Le Vu Ngan Truc - 21127709" << endl;
    gotoXY(40, 23);
    setTextColor(11);
    cout << "2. Member - Cao Hoai Yen Vy - 21127205" << endl;
    gotoXY(40, 25);
    setTextColor(11);
    cout << "3. Member - Au Duong Khang - 21127621" << endl;
    gotoXY(50, 27);
    setTextColor(13);
    cout << "Want to back to MENU? Press B";
    while (1) {
        int key = inputKey();
        if (key == KEY_B) {
            clrscr();
            return;
        }
    }
}
void leaderBoard()
{
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
    //ShowHighScore();
    gotoXY(52, 33);
    setTextColor(13);
    cout << "Want to back to MENU? Press B";
    while (1) {
        int key = inputKey();
        if (key == KEY_B) {
            clrscr();
            return;
        }
    }
}
void exitGame()
{
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

       

        key = inputKey(); // đồng bộ toàn chương trình, lấy hàm trong ConsoleWindow.h
        if (key == KEY_UP) // đồng bộ toàn chương trình, lấy define 
        {

            counter--;
        }
        if (key == KEY_DOWN)
        {
            counter++;
        }

        if (key == ENTER)//Người dùng nhấn phím enter
        {
            if (counter == 1)
            {
                exit(0);
            }
            if (counter == 2)
            {
                gotoXY(52, 33);
                setTextColor(13);
                cout << "Want to back to MENU? Press B";
                while (1) {
                    int key = inputKey();
                    if (key == KEY_B) {
                        clrscr();
                        return;
                    }
                }
            }
           
        }
        
    }
  
}