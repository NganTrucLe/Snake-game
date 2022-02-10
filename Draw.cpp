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