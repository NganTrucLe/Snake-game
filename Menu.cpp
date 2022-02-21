#include "Menu.h"
#include "ConsoleWindow.h"
#include "Snake.h"
#include "Fruit.h"
#include "Draw.h"
#include <iostream>

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
    
}
void tittle()
{
    
    
    setTextColor(10);
    
    cout <<    R"(                                  
     
                    




                              ___ ___         __  .__                   _________              __           
                             /   |   \ __ ___/  |_|__| ____    ____    /   _____/ ____ _____  |  | __ ____  
                            /    ~    \  |  \   __\  |/    \  / ___\   \_____  \ /    \\__  \ |  |/ // __ \ 
                            \    Y    /  |  /|  | |  |   |  \/ /_/  >  /        \   |  \/ __ \|    <\  ___/ 
                             \___|_  /|____/ |__| |__|___|  /\___  /  /_______  /___|  (____  /__|_ \\___  >
                                   \/                     \//_____/           \/     \/     \/     \/    \/ 
                                            
       
)";
    


}
void menuOptions()
{
    setTextColor(2);
    tittle();

    int Set[] = { 7,7,7,7,7 }; // Màu mặc định
    int counter = 3;
    char key;
    for (int i = 0; ; )
    {


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

        key = _getch();


        if (key == 72 && (counter >= 2 && counter <= 5))
        {
            counter--;
            
        }
        if (key == 80 && (counter >= 1 && counter <= 4))
        {
            counter++;
            
        }
        if (key == '\r')//Người dùng nhấn phím enter
        {
            if (counter == 1)
            {
                system("cls");
                cout << "What is your name?";
            }
            if (counter == 2)
            {
                cout << "Menu 2 is Open";
            }
            if (counter == 3)
            {
                cout << "Menu 3 is Open";
            }
            if (counter == 4)
            {
                setTextColor(9);
                cout << R"(                                                                                                                                                     
                                        .___        __                    .___             __  .__               
                                        |   | _____/  |________  ____   __| _/_ __   _____/  |_|__| ____   ____  
                                        |   |/    \   __\_  __ \/  _ \ / __ |  |  \_/ ___\   __\  |/  _ \ /    \ 
                                        |   |   |  \  |  |  | \(  <_> ) /_/ |  |  /\  \___|  | |  (  <_> )   |  \
                                        |___|___|  /__|  |__|   \____/\____ |____/  \___  >__| |__|\____/|___|  /
                                                 \/                        \/           \/                    \/ 
                        

)";
                setTextColor(13);
                gotoXY(59, 20);
                cout << "DO AN RAN SAN MOI HCMUS 21CLC01" << endl;
                gotoXY(59, 21);
                cout << "Giao vien huong dan: Truong Toan Thinh" << endl;
                gotoXY(59, 22);
                cout << "Danh sach thanh vien: " << endl;
                gotoXY(59, 23);
                cout << "1. Le Vu Ngan Truc: Nhom truong - 21127709" << endl;
                gotoXY(59, 24);
                cout << "2. Cao Hoai Yen Vy - 21127205" << endl;
                gotoXY(59, 25);
                cout << "3. Au Duong Khang - 21127621" << endl;
            }
            if (counter == 5)
            {
                cout << "Do you want to exit the game?" << endl;
                cout << "1. Yes";
                cout << "2. No";
            }
            
        }

        Set[0] = 7;
        Set[1] = 7;
        Set[2] = 7;
        Set[3] = 7;
        Set[4] = 7;

        if (counter == 1)
        {
            Set[0] = 12;
        }
        if (counter == 2)
        {
            Set[1] = 12;
        }
        if (counter == 3)
        {
            Set[2] = 12;
        }
        if (counter == 4)
        {
            Set[3] = 12;
        }
        if (counter == 5)
        {
            Set[4] = 12;
        }


    }
}
