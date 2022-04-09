#pragma once
#include <stdio.h>
#include <conio.h>
#include <windows.h>

#define BLACK_COLOR			0
#define DARK_BLUE_COLOR		1
#define DARK_GREEN_COLOR	2
#define DARK_CYAN_COLOR		3
#define DARK_RED_COLOR		4
#define DARK_PINK_COLOR		5
#define DARK_YELLOW_COLOR	6
#define DARK_WHITE_COLOR	7
#define GREY_COLOR			8
#define BLUE_COLOR			9
#define GREEN_COLOR			10
#define CYAN_COLOR			11
#define RED_COLOR			12
#define PINK_COLOR			13
#define YELLOW_COLOR		14
#define WHITE_COLOR			15

#define KEY_UP		1072
#define KEY_DOWN		1080
#define KEY_LEFT		1077
#define KEY_RIGHT	1075
#define KEY_NONE		-1
#define SPACE_BAR	32
#define ENTER		13
#define ESCAPE		27
#define KEY_B		98
#define KEY_P		112
#define KEY_A       65
#define KEY_S		83
#define KEY_D		68
#define KEY_W		87
#define KEY_a		97
#define KEY_d		100
#define KEY_w		119
#define KEY_s		115

#define pii pair<int, int>

// Lấy nút bàn phím do người dùng bấm
// Trả về: Mã của phím
int inputKey();

// Xóa màn hình
void clrscr();

// Di chuyển con trỏ console đến vị trí có tọa độ (x, y)
void gotoXY(int x, int y);

// Lấy tọa độ x hiện tại của con trỏ console
int whereX();

// Lấy tọa độ y hiện tại của con trỏ console
int whereY();

// Xóa con trỏ nháy
void noCursorType();

// Đổi màu chữ
// Tham số: Mã màu
void setTextColor(int color);

// Cố định kích thước của console window
void fixConsoleWindow();

// Thay đổi kích thước của Console Window
void resizeConsole(int width, int height);
//end----------------------Screen----------------------end

void noScrollbar();
/*void fontsize(int a, int b);*/

//Vô hiệu hóa bôi đen text
void DisableSelection();