
#pragma once
#include "Consola.h"
#include<conio.h>
#include <iostream>
using namespace std;
class conUnit
{
public:
	static void xyputc(int x, int y, char ch) {
		gotoxy(x, y);
		cout << ch;
	}
	static void xyputstr(int x, int y, const char* str) {
		gotoxy(x, y);
		cout << str;
	}
	static void fillbox(int x1, int y1, int x2, int y2, char color) {
		textbackground(color);
		for (int y = y1; y < y2; y++)
			for (int x = x1; x <= x2; x++)
				xyputc(x, y, ' ');
	}

	static int getkey() {
		int key = _getch();


		return (key == 0xe0) ? (0x00e000 | _getch()) : key;
	}
};