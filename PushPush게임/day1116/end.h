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
		gotoxy(10, 5); cout << "*             ���ϵ帳�ϴ�          *";
		gotoxy(10, 6); cout << "*   Ǫ��Ǫ�������� �ذ��ϼ̽��ϴ�   *";
		gotoxy(10, 7); cout << "*                                   *";
		gotoxy(10, 8); cout << "*                                   *";
		gotoxy(10, 9); cout << "*    ����ð�:"<<min<<"��"<<seconds<<"��"<<"               *";
		gotoxy(10, 10); cout << "*      ������ Ƚ��: "<<a<<"��           *";
		gotoxy(10, 11); cout << "*                                   *";
		gotoxy(10, 12); cout << "*                                   *";
		gotoxy(10, 13); cout << "*           �����ϼ̽��ϴ�          *";
		gotoxy(10, 14); cout << "*  SPACE-BAR�� ������ ����˴ϴ�    *";
		gotoxy(10, 15); cout << "*************************************";
		
		int key = conUnit::getkey();
		if (key == M_SPACEBAR)
			return 3;
	}
};

