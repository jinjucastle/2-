#pragma once
#include <iostream>
#include <conio.h>
#include <time.h>
#include"conUnit.h"
#include"keyboard.h"
#include"over.h"
#include<windows.h>
#include <mmsystem.h>

#define MAP_X1	10
#define MAP_Y1	4
#define MAP_HEIGHT	20
#define MAP_WIDTH	20
class map5 {
public:
	int mapData[MAP_HEIGHT][MAP_WIDTH] = {
		{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
		{1,0,0,0,1,1,1,1,1,1,1,1,0,0,1,1,1,1,1,1},
		{1,1,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1},
		{1,1,0,1,0,1,0,0,1,1,1,1,0,0,1,1,1,1,1,1},
		{1,1,0,0,0,0,0,0,1,1,1,1,0,1,1,1,1,1,1,1},
		{1,1,0,0,1,1,0,1,0,0,0,0,0,1,1,1,1,1,1,1},
		{1,1,0,0,0,0,0,1,0,0,0,0,0,1,1,1,1,1,1,1},
		{1,0,0,0,1,0,0,0,0,0,0,1,0,1,1,1,1,1,1,1},
		{1,0,0,0,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1},
		{1,1,1,1,1,0,0,0,1,0,0,0,1,1,1,1,1,1,1,1},
		{1,1,1,1,1,2,2,4,0,0,2,0,1,1,1,1,1,1,1,1},
		{1,1,1,1,1,2,2,2,2,1,0,0,1,1,1,1,1,1,1,1},
		{1,1,1,1,1,2,2,2,2,1,1,1,1,1,1,1,1,1,1,1},
		{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
		{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
	    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
		{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
		{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
		{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
		{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
	};
	int mapData2[MAP_HEIGHT][MAP_WIDTH] = {
		{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
		{1,0,0,0,1,1,1,1,1,1,1,1,0,0,1,1,1,1,1,1},
		{1,1,0,2,0,0,0,0,0,0,0,2,0,0,1,1,1,1,1,1},
		{1,1,0,1,0,1,0,0,1,1,1,1,0,0,1,1,1,1,1,1},
		{1,1,0,0,2,0,0,0,1,1,1,1,2,1,1,1,1,1,1,1},
		{1,1,2,0,1,1,0,1,0,2,0,2,0,1,1,1,1,1,1,1},
		{1,1,0,2,0,0,2,1,0,0,0,0,0,1,1,1,1,1,1,1},
		{1,0,0,0,1,0,0,0,0,0,0,1,0,1,1,1,1,1,1,1},
		{1,0,0,0,1,1,1,1,1,2,1,1,1,1,1,1,1,1,1,1},
		{1,1,1,1,1,0,0,0,1,0,0,0,1,1,1,1,1,1,1,1},
		{1,1,1,1,1,4,4,4,0,0,2,0,1,1,1,1,1,1,1,1},
		{1,1,1,1,1,4,4,4,4,1,0,0,1,1,1,1,1,1,1,1},
		{1,1,1,1,1,4,4,4,4,1,1,1,1,1,1,1,1,1,1,1},
		{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
		{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
		{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
		{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
		{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
		{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
		{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
	};
	const char* cellSymbol[6] = { "  ", "��", "��", NULL, "��", NULL };;
	static int cntSystem(int mapData[][20]) {
		int a = 0;
		for (int i = 0; i < MAP_HEIGHT; i++)
			for (int j = 0; j < MAP_WIDTH; j++) {
				if (mapData[i][j] == 4)
					a++;
			}
		return a;
	}


	void drawCell(int col, int row) {
		int cell = mapData[row][col];
		textbackground((cell == 1) ? DARKGRAY : YELLOW);
		gotoxy((MAP_X1 + col + 1) * 2, MAP_Y1 + row + 1);
		cout << cellSymbol[cell];
	}
	void drawMap() {
		for (int row = 0; row < MAP_HEIGHT; row++)
			for (int col = 0; col < MAP_WIDTH; col++)
				drawCell(col, row);
	}

	void drawCharacter(int x, int y) {
		textcolor(RED);
		conUnit::xyputstr((MAP_X1 + 1 + x) * 2, MAP_Y1 + 1 + y, "��");
	}
	void drawcnt(int start) {
		textbackground(BLACK);
		textcolor(WHITE);
		gotoxy(80, 3); cout << "������ �ܰ� �Դϴ�";
		gotoxy(80, 5); cout << "�õ� Ƚ��:" << start;
		gotoxy(80, 7); cout << " �ٽ� �ϱ�  RŰ";
		gotoxy(80, 9); cout << " �ߴ��ϱ�  GŰ";
		gotoxy(80, 11); cout << " �ߴ��ϸ� ���ܰ��� �̵�Ƚ����";
		gotoxy(80, 13); cout << " �����˴ϴ�";
		textcolor(RED);
	}
	static int start(int a) {


		int end = 0;
		int cnt = 1;
		int posx = 1, posy = 1;
		int nposx, nposy;
		int oldx, oldy;
		int startx = 1,starty = 1;

		map5 m;

		_setcursortype(_NOCURSOR);
		m.drawMap();
		m.drawCharacter(posx, posy);

		cnt = cntSystem(m.mapData);
		while (1) {

			m.drawcnt(a);
			int key = conUnit::getkey();
			PlaySound(TEXT("�ȴ¹��ڿ�.wav"), NULL, SND_FILENAME | SND_ASYNC);
			if (key == 'q') break;
			oldx = nposx = posx;
			oldy = nposy = posy;
			switch (key)
			{
			case M_LEFTKEY: if (posx > 0) {
				nposx--; a++;
			} break;
			case M_UPKEY: if (posy > 0) {
				nposy--; a++;
			}break;
			case M_DOWNKEY:if (posy < MAP_HEIGHT - 1)
			{
				nposy++; a++;
			}break;
			case M_RIGHTKEY:if (posx < MAP_WIDTH - 1) {
				nposx++; a++;
			}break;
			}
			if (key == 'r') {
				system("cls");
				for (int i = 0; i < MAP_HEIGHT; i++) {
					for (int j = 0; j < MAP_WIDTH; j++)
						m.mapData[i][j] = m.mapData2[i][j];

					a = 0;
				}
				cnt = cntSystem(m.mapData);
				m.drawMap();

				m.drawCharacter(startx, starty);
				nposx = 1, nposy = 1;
			}
			if (key == 'g') {

				end = over::Abort();
				switch (end)
				{
				case 0:
					textbackground(BLACK);
					system("cls");
					m.drawMap();
					m.drawCharacter(posx, posy);
					break;
				case 1:
					a = 0;
					cnt = 0;
					textcolor(WHITE);
					break;
				}

			}

			if (m.mapData[nposy][nposx] == 0) {
				posx = nposx;
				posy = nposy;
			}
			if (m.mapData[nposy][nposx] == 4) {
				posx = nposx;
				posy = nposy;
			}
			if (m.mapData[nposy][nposx] == 2) {
				m.mapData[nposy][nposx] = 0;
				posx = nposx;
				posy = nposy;//oldx oldy �� ��ǥ�� �����ؾ��Ѵ�
				if (oldx == nposx && oldy == nposy + 1)//�����Ͱ� 4�ΰ��� ������ �������� 
				{
					if (m.mapData[nposy - 1][nposx] == 1 || m.mapData[nposy - 1][nposx] == 2) {
						m.mapData[nposy][nposx] = 2;
						posy++;
						m.drawMap();
						m.drawCharacter(posx, posy);

					}


					else if (m.mapData[nposy - 1][nposx] == 4) {
						if (m.mapData2[nposy][nposx] == 4) {
							m.mapData[nposy][nposx] = 4;
							m.mapData[nposy - 1][nposx] = 2;
						}
						else {
							m.mapData[nposy - 1][nposx] = 2;
							cnt--;
						}
						m.drawMap();
						m.drawCharacter(posx, posy);


					}
					else
						m.mapData[nposy - 1][nposx] = 2;
				}
				else if (oldx == nposx && oldy == nposy - 1) {
					if (m.mapData[nposy + 1][nposx] == 1 || m.mapData[nposy + 1][nposx] == 2) {
						m.mapData[nposy][nposx] = 2;
						posy--;
						m.drawMap();
						m.drawCharacter(posx, posy);
					}
					else if (m.mapData[nposy + 1][nposx] == 4) {
						if (m.mapData2[nposy][nposx] == 4) {
							m.mapData[nposy][nposx] = 4;
							m.mapData[nposy + 1][nposx] = 2;
						}
						else {
							m.mapData[nposy + 1][nposx] = 2;
							cnt--;
						}
						m.drawMap();
						m.drawCharacter(posx, posy);


					}


					else
						m.mapData[nposy + 1][nposx] = 2;
				}

				else if (oldx == nposx + 1 && oldy == nposy)
					if (m.mapData[nposy][nposx - 1] == 1 || m.mapData[nposy][nposx - 1] == 2) {
						m.mapData[nposy][nposx] = 2;
						posx++;
						m.drawMap();
						m.drawCharacter(posx, posy);

					}
					else if (m.mapData[nposy][nposx - 1] == 4) {//<- ����
						if (m.mapData2[nposy][nposx] == 4) {
							m.mapData[nposy][nposx] = 4;
							m.mapData[nposy][nposx - 1] = 2;
						}
						else {
							m.mapData[nposy][nposx - 1] = 2;
							cnt--;
						}
						m.drawMap();
						m.drawCharacter(posx, posy);


					}
					else
						m.mapData[nposy][nposx - 1] = 2;


				else if (oldx == nposx - 1 && oldy == nposy)
					if (m.mapData[nposy][nposx + 1] == 1 || m.mapData[nposy][nposx + 1] == 2) {
						m.mapData[nposy][nposx] = 2;
						posx--;
						m.drawMap();
						m.drawCharacter(posx, posy);
					}
					else if (m.mapData[nposy][nposx + 1] == 4) {//->����
						if (m.mapData2[nposy][nposx] == 4) {
							m.mapData[nposy][nposx] = 4;
							m.mapData[nposy][nposx + 1] = 2;
						}
						else {
							m.mapData[nposy][nposx + 1] = 2;
							cnt--;
						}
						m.drawMap();
						m.drawCharacter(posx, posy);


					}
					else
						m.mapData[nposy][nposx + 1] = 2;
			}

			if (oldx != posx || oldy != posy) {
				m.drawMap();
				m.drawCharacter(posx, posy);
			}
			if (cnt == 0) {

				break;
			}
		}

		return a;

	}
};

