#include "Component.h"
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