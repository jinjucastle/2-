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
		cout << "\n\n\n\n"<<"\t\t\t\t    �ϰ���� �������� ��� SPACE_BAR�� �����ּ���";
		gotoxy(x - 2, y);
		cout << "> ���� ����";
		gotoxy(x, y + 1);
		cout << " ����";
		gotoxy(x, y + 2);
		cout << " ����";
		gotoxy(x - 2, y);

		while (1) {
			int key = conUnit::getkey();
			PlaySound(TEXT("��_!.wav"), NULL, SND_FILENAME | SND_ASYNC);
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
		gotoxy(x, y); cout << "����";
		gotoxy(x-10, y+2); cout << "��� Ű UP DOWN LEFT RIGHT";
		gotoxy(x - 10, y + 4); cout << "����: ������ �����ϰ� �ٽ��ϸ� 1�ܰ���� �����մϴ� .";
		gotoxy(x-10 , y+5); cout << "�߰��� ������ �����ϸ� �����ܰ� ���� ���� ����˴ϴ�";
		gotoxy(x - 10, y + 8); cout << "���� ��� :������";
		gotoxy(x - 10, y + 10); cout << "���װ� �߻��ϸ� guswlwl22@naver.com���� �������ּ���";
		gotoxy(x - 10, y + 15); cout << "����: 1.16.1";
			y = 20;
	
		gotoxy(x, y + 2);
		cout << " �ݱ�";
		gotoxy(x , y+2);
		while (1) {
			int key = conUnit::getkey();
			PlaySound(TEXT("��_!.wav"), NULL, SND_FILENAME | SND_ASYNC);
			
			if(key== M_SPACEBAR){
				return y - 19;
			}

		}

	}


};