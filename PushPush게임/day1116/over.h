#pragma once
#include <iostream>
#include"conUnit.h"
#include"keyboard.h"
#include<windows.h>
#include <mmsystem.h>
class over {
public :
	static int Abort() {
		int x = 24;
		int y = 24;
		
		_setcursortype(_NOCURSOR);
		PlaySound(TEXT("ȿ����6.wav"), NULL, SND_FILENAME | SND_ASYNC);
		textcolor(WHITE);
		textbackground(BLACK);
		system("cls");
		gotoxy(x - 3, y);
		cout << "�����Ͻðڽ��ϱ�?";
		gotoxy(x-2, y + 1);
		cout << "> ����ϱ�";
		gotoxy(x, y + 2);
		cout << " ����";
		y = 25;
		while (1) {
			int key = conUnit::getkey();
			PlaySound(TEXT("��_!.wav"), NULL, SND_FILENAME | SND_ASYNC);
			switch (key)
			{

			case M_UPKEY: if (y > 25) {
				gotoxy(x - 2, y);
				cout <<" ";
				gotoxy(x-2 , --y);
				cout << ">";
			}
						break;
			case M_DOWNKEY:if (y < 26) {
				gotoxy(x-2, y);
				cout <<" ";
				gotoxy(x-2, ++y);
				cout << ">";
			}
						  break;
			case M_SPACEBAR:
				textcolor(RED);
				return y - 25;
			}

		}
	
	}
};
