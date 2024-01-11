#define _CRT_SECURE_NO_WARNINGS
#pragma once

#include<iostream>
#include"Consola.h"
#include"keyboard.h"
#include"conUnit.h" 
#include<windows.h>
#include <mmsystem.h>

using namespace std;
class FirstPrint {
public:

	static int first() {
		textbackground(BLACK);
		system("cls");
		int x = 55;
		int y = 20;
		cout << endl << endl << endl << endl << endl;
		cout << "\t\t\t #####   ##   ##     ####   ##  ##  #####   ##   ##     ####   ##  ##\n";
		cout << "\t\t\t #    #  ##   ##    #    #  ##  ##  #    #  ##   ##    #    #  ##  ##\n";
		cout << "\t\t\t #####   ##   ##      #     ######  #####   ##   ##      #     ######\n";
		cout << "\t\t\t ##      ##   ##   #    #   ##  ##  ##      ##   ##   #    #   ##  ##\n";
		cout << "\t\t\t ##      #######    ####    ##  ##  ##      #######    ####    ##  ##\n";
		cout << "\n\n\n\n"<<"\t\t\t\t    하고싶은 선택지를 골라서 SPACE_BAR를 눌러주세요";
		gotoxy(x - 2, y);
		cout << "> 게임 시작";
		gotoxy(x, y + 1);
		cout << " 도움말";
		gotoxy(x, y + 2);
		cout << " 종료";
		gotoxy(x - 2, y);

		while (1) {
			int key = conUnit::getkey();
			PlaySound(TEXT("쉭_!.wav"), NULL, SND_FILENAME | SND_ASYNC);
			switch (key)
			{

			case M_UPKEY: if (y > 20) {
				gotoxy(x - 2, y);
				cout << " ";
				gotoxy(x - 2, --y);
				cout << ">";

			}
						break;
			case M_DOWNKEY:if (y < 22) {
				gotoxy(x - 2, y);
				cout << " ";
				gotoxy(x - 2, ++y);
				cout << ">";
			}
						  break;
			case M_SPACEBAR:
				return y - 19;
			}

		}

	}
	static int  second() {
		textbackground(BLACK);
		system("cls");
		int x = 55;
		int y = 5;
		gotoxy(x, y); cout << "도움말";
		gotoxy(x-10, y+2); cout << "사용 키 UP DOWN LEFT RIGHT";
		gotoxy(x - 10, y + 4); cout << "주의: 게임을 종료하고 다시하면 1단계부터 시작합니다 .";
		gotoxy(x-10 , y+5); cout << "중간에 게임을 종료하면 이전단계 저장 없이 종료됩니다";
		gotoxy(x - 10, y + 8); cout << "만든 사람 :이주현";
		gotoxy(x - 10, y + 10); cout << "버그가 발생하면 guswlwl22@naver.com으로 제보해주세요";
		gotoxy(x - 10, y + 15); cout << "버전: 1.16.1";
			y = 20;
	
		gotoxy(x, y + 2);
		cout << " 닫기";
		gotoxy(x , y+2);
		while (1) {
			int key = conUnit::getkey();
			PlaySound(TEXT("쉭_!.wav"), NULL, SND_FILENAME | SND_ASYNC);
			
			if(key== M_SPACEBAR){
				return y - 19;
			}

		}

	}


};