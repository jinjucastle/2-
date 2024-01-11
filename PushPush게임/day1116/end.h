#pragma once

#include <iostream>
#include <conio.h>
#include"conUnit.h"
#include"keyboard.h"

using namespace std;
class end 
{
public :
	static int endprint( double time ,int a) {
		int min = (int)time / 60;
		int seconds = (int)time % 60;
		textcolor(WHITE);
		textbackground(BLACK);
		system("cls");
		
		gotoxy(10, 4); cout << "*************************************";
		gotoxy(10, 5); cout << "*             축하드립니다          *";
		gotoxy(10, 6); cout << "*   푸쉬푸쉬게임을 해결하셨습니다   *";
		gotoxy(10, 7); cout << "*                                   *";
		gotoxy(10, 8); cout << "*                                   *";
		gotoxy(10, 9); cout << "*    경과시간:"<<min<<"분"<<seconds<<"초"<<"               *";
		gotoxy(10, 10); cout << "*      움직인 횟수: "<<a<<"번           *";
		gotoxy(10, 11); cout << "*                                   *";
		gotoxy(10, 12); cout << "*                                   *";
		gotoxy(10, 13); cout << "*           수고하셨습니다          *";
		gotoxy(10, 14); cout << "*  SPACE-BAR를 누르면 종료됩니다    *";
		gotoxy(10, 15); cout << "*************************************";
		
		int key = conUnit::getkey();
		if (key == M_SPACEBAR)
			return 3;
	}
};

