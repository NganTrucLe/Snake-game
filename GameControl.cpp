#include "GameControl.h"
using namespace std;
void Game::gameControl() {
    loadLevel(level);
    while (1) {
        switch (state) {
        case MENU:
            if (MyMenu.state == NEW_GAME) {
                state = IN_GAME;
                startNewGame();
            }
            else if (MyMenu.state == 6) {
                state = LOAD_GAME;
            }
            break;
        case GAME_OVER:
            // draw menu restart? back to menu? exit game?
            handleAfterGameOver();
            break;
        case IN_GAME:
            setTextColor(15);
            snakeActivities();
            increaseScore();
            nextLevel();
            if (gameOver())
                state = GAME_OVER;
            break;
        case INCREASE_LEVEL:
            increaseLevel();
            break;
        case LOAD_GAME:
            loadGame();
            break;
        }

    }
}
void Game::snakeActivities() {
    if (MySnake.appearing >= 0) {
        MySnake.appear[MySnake.appearing] = 1;
        MySnake.appearing++;
        if (MySnake.appearing == MySnake.length) {
            MySnake.appearing = -1;
            for (pii i : gate) {
                gotoXY(i.first, i.second);
                cout << (char)255;
            }
            gate.resize(0);
            MyFruit.generateFruit(wall);
        }
    }
    MySnake.move();
    int key = inputKey();
    MySnake.changeDirection(key);
    if (key == SPACE_BAR) {
        pauseGame();
    }
    else if (key == ESCAPE) {
        deleteGameScreen();
        saveGame();
        exit(0);
    }
}
void Game::startNewGame() {
    clrscr();
    level = 1;
    gotoXY(0, 0);
    MySnake.restart();
    MyFruit.generateFruit(wall);
    loadLevel(level);
    state = IN_GAME;
    score = 0;
    gate.resize(0);
    gameControl();
}
void Game::increaseScore() {
    if (MySnake.isEatFruit(MyFruit.cor)) {
        audioUpScore();
        MySnake.addDot();
        MyFruit.generateFruit(wall);
        score += 10;
    }
    drawScore(score);
}
void Game::pauseGame() {
    deleteGameScreen();
    UINT old_cp = GetConsoleOutputCP();
    SetConsoleOutputCP(CP_UTF8);
    gotoXY(23, 10);
    setTextColor(11);
    cout << u8"██████╗  █████╗ ██╗   ██╗███████╗███████╗";
    gotoXY(23, 11);
    setTextColor(11);
    cout << u8"██╔══██╗██╔══██╗██║   ██║██╔════╝██╔════╝";
    gotoXY(23, 12);
    setTextColor(11);
    cout << u8"██████╔╝███████║██║   ██║███████╗█████╗";
    gotoXY(23, 13);
    setTextColor(11);
    cout << u8"██╔═══╝ ██╔══██║██║   ██║╚════██║██╔══╝ ";
    gotoXY(23, 14);
    setTextColor(11);
    cout << u8"██║     ██║  ██║╚██████╔╝███████║███████╗";
    gotoXY(23, 15);
    setTextColor(11);
    cout << u8"╚═╝     ╚═╝  ╚═╝ ╚═════╝ ╚══════╝╚══════╝";
    SetConsoleOutputCP(old_cp);
    while (1) {
        int key = inputKey();
        if (key == SPACE_BAR) {
            deleteGameScreen();
            loadLevel(level);
            MyFruit.printCurrent();
            if (!gate.empty())
                drawGate(gate_position[level - 1].first, gate_position[level - 1].second, gate);
            break;
        }
    }
}
void Game::saveGame() {
    char filename[44] = {};
    do {
        deleteGameScreen();
        gotoXY(30, 10);
        cout << "Enter your name: ";
        cin.getline(filename, 10);
        if (isValidFileName(filename)) break;
        deleteGameScreen();
        gotoXY(28, 10);
        cout << "Invalid file name, re-enter!";
        Sleep(2000);
    } while (1);
    int n = strlen(filename);
    filename[n] = '.';
    filename[n + 1] = 't';
    filename[n + 2] = 'x';
    filename[n + 3] = 't';
    fstream output_fstream;
    output_fstream.open(filename, std::ios_base::out);
    saveDataGame(filename, level, score, gate);
    if (gate.size() == 0) saveDataFruit(filename, MyFruit.cor);
    saveDataSnake(filename, MySnake.position, MySnake.appear, MySnake.direction);
}
void Game::loadGame() {
    char filename[44] = {};
    do {
        clrscr();
        gotoXY(30, 10);
        cout << "Enter your name: ";
        cin.getline(filename, 10);
        if (isValidFileName(filename)) {
            int n = strlen(filename);
            filename[n] = '.';
            filename[n + 1] = 't';
            filename[n + 2] = 'x';
            filename[n + 3] = 't';
            if (isExistedFileName(filename)) break;
        }
        clrscr();
        gotoXY(28, 10);
        audioGameOver();
        cout << "Invalid file name or non-existed file, re-enter!";
        Sleep(2000);
    } while (1);
    loadDataGame(filename, level, score, gate, MySnake.position, MySnake.appear, MySnake.direction, MyFruit.cor);
    state = IN_GAME;
    deleteGameScreen();
    MySnake.length = MySnake.position.size();
    loadLevel(level);
    if (gate.size() != 0) {
        drawGate(gate_position[level - 1].first, gate_position[level - 1].second, gate);
        nextLevelPosition.first = (gate[0].first + gate.back().first) / 2;
        nextLevelPosition.second = gate[0].second;
    }
    else MyFruit.printCurrent();
}
bool Game::gameOver() {
    if (MySnake.isDeath(wall, gate)) {
        audioGameOver();
        MySnake.blink();
        time_t now = time(0);
        char* dt = ctime(&now);
        *(dt + strlen(dt) - 1) = '\0';
        NewScore.time = dt;
        char* name_ = new char[10];
        announceGameOver(score, name_);
        NewScore.score = score;
        NewScore.name = name_;
        createNewHighScore(HighScore, NewScore);
        return 1;
    }
    return 0;
}
void Game::handleAfterGameOver() {
    int key = inputKey();
    while (1) {
        if (key == 121) {
            startNewGame();
            break;
        }
        else if (key == 110) {
            state = MENU;
            clrscr();
            MyMenu.restart();
            break;
        }
        key = inputKey();
    }
}
void Game::handleAfterWin() {
    audioBanLaNhat();
    time_t now = time(0);
    char* dt = ctime(&now);
    *(dt + strlen(dt) - 1) = '\0';
    NewScore.time = dt;
    char* name_ = new char[10];
    announceWin(score, name_);
    NewScore.name = name_;
    NewScore.score = score;
    createNewHighScore(HighScore, NewScore);
    deleteGameScreen();
    gotoXY(30, 10);
    int Set[3] = { WHITE_COLOR, WHITE_COLOR, WHITE_COLOR }; // Màu mặc định
    int counter = 1, key;
    char menuList[3][20] = { "1. Back to menu", "2. Restart", "3. Exit game" };
    int positionY[3] = { 10,12,14 };
    while (1)
    {
        counterEvent(key, counter, 3);
        //Đổi màu options, option counter thì có màu đỏ, còn lại trắng
        for (int i = 0; i < 3; i++) Set[i] = WHITE_COLOR;
        Set[counter - 1] = RED_COLOR;
        for (int i = 0; i < 3; i++) {
            gotoXY(36, positionY[i]);
            setTextColor(Set[i]);
            cout << menuList[i];
            gotoXY(32, positionY[i]);
            if (counter - 1 != i) cout << (char)255;
        }
        gotoXY(32, positionY[counter - 1]);
        setTextColor(RED_COLOR);
        cout << (char)16;
        if (key == ENTER)//Người dùng nhấn phím enter
        {
            switch (counter) {
            case 1:
                state = MENU;
                clrscr();
                MyMenu.restart();
                break;
            case 2:
                startNewGame();
                break;
            case 3:
                exit(0);
                break;
            }
            return;
        }
    }
}
void Game::loadLevel(int n) {
    switch (n) {
    case 1:
        Level_1(wall, HighScore[0].score);
        break;
    case 2:
        Level_2(wall, HighScore[0].score);
        break;
    case 3:
        Level_3(wall, HighScore[0].score);
        break;
    case 4:
        Level_4(wall, HighScore[0].score);
        break;
    case 5:
        Level_5(wall, HighScore[0].score);
        break;
    }
    MySnake.speed = speedLevel[n - 1];
}
void Game::nextLevel()
{
    if (score == 30*5)handleAfterWin();
    if (score == 30 * level)
    {
        MyFruit.deleteFruit();
        drawGate(gate_position[level - 1].first, gate_position[level - 1].second, gate);
        nextLevelPosition.first = (gate[0].first + gate.back().first) / 2;
        nextLevelPosition.second = gate[0].second;
    }
    if (MySnake.isNextLevel(nextLevelPosition)) {
        MySnake.disappearing = 0;
        state = INCREASE_LEVEL;
    }
}
void Game::increaseLevel() {
    if (MySnake.disappearing < 0)return;
    for (int i = 0; i < MySnake.length; i++) {
        MySnake.move();
        MySnake.appear[MySnake.disappearing] = 0;
        MySnake.disappearing++;
    }
    MySnake.move();
    MySnake.disappearing = -1;
    deleteGameScreen();
    level++;
    audioNewLevel();
    loadLevel(level);
    drawGate(gate_position[level - 1].first, gate_position[level - 1].second, gate);
    nextLevelPosition.first = (gate[0].first + gate.back().first) / 2;
    nextLevelPosition.second = gate[0].second;
    MySnake.init(nextLevelPosition, 3);
    MySnake.appearing = 0;
    state = IN_GAME;
}
// ________________________________________________________________________________________________
HIGHSCORE HighScore[19];
HIGHSCORE NewScore;
void Game::saveHighScore() {
    initializeHighScore(HighScore);
}