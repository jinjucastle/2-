#pragma once
#include <iostream>
#include <conio.h>
#include"conUnit.h"
#include"keyboard.h"
#include<windows.h>
#include <mmsystem.h>
#include"over.h"
#define MAP_X1	10
#define MAP_Y1	4
#define MAP_HEIGHT	10
#define MAP_WIDTH	10
class map {
public : 
	int mapData[10][10] = {
	{1,1,1,1,1,1,1,1,1,1},
	{1,1,1,1,1,1,1,1,1,1},
	{1,1,1,1,4,1,1,1,1,1},
	{1,1,1,1,0,1,1,1,1,1},
	{1,1,1,1,2,0,2,4,1,1},
	{1,1,4,0,2,0,1,1,1,1},
	{1,1,1,1,1,2,1,1,1,1},
	{1,1,1,1,1,4,1,1,1,1},
	{1,1,1,1,1,1,1,1,1,1},
	{1,1,1,1,1,1,1,1,1,1}
	};
	int mapData2[10][10] = {
	{1,1,1,1,1,1,1,1,1,1},
	{1,1,1,1,1,1,1,1,1,1},
	{1,1,1,1,4,1,1,1,1,1},
	{1,1,1,1,0,1,1,1,1,1},
	{1,1,1,1,2,0,2,4,1,1},
	{1,1,4,0,2,0,1,1,1,1},
	{1,1,1,1,1,2,1,1,1,1},
	{1,1,1,1,1,4,1,1,1,1},
	{1,1,1,1,1,1,1,1,1,1},
	{1,1,1,1,1,1,1,1,1,1}
	};
	    const char* cellSymbol[6]= { "  ", "▒", "●", NULL, "※", NULL };;
		static int cntSystem(int mapData[][10]) {
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
		gotoxy((MAP_X1 + col + 1)*2 , MAP_Y1 + row + 1);
		cout << cellSymbol[cell];
	}
	 void drawMap() {
		for (int row = 0; row < MAP_HEIGHT; row++)
			for (int col = 0; col < MAP_WIDTH; col++)
				drawCell(col, row);
	}

	 void drawCharacter(int x, int y) {
		textcolor(RED);
		conUnit::xyputstr((MAP_X1 + 1 + x) * 2, MAP_Y1 + 1 + y, "★");
	}
	 void drawstage(int start) {
		 textbackground(BLACK);
		 textcolor(WHITE);
		 gotoxy(80, 3); cout << "1단계 입니다";
		 gotoxy(80, 5); cout << "시도 횟수:" << start;
		 gotoxy(80, 7); cout << " 다시 하기  R키";
		 gotoxy(80, 9); cout << " 중단하기  G키";
		 gotoxy(80, 11); cout << " 중단하면 모든단계의 이동횟수가" ;
		 gotoxy(80, 13); cout << " 삭제됩니다";
		 textcolor(RED);

	 }



	 static int start(int a) {
		 int end = 0;
		 int cnt = 1;
		 int posx = 5, posy = 5;
		 int nposx, nposy;
		 int oldx, oldy;
		 int startx = 5, starty = 5;

		 map m;

		 _setcursortype(_NOCURSOR);
		 m.drawMap();
		 m.drawCharacter(posx, posy);

		 cnt = cntSystem(m.mapData);
		 while (1) {

			 m.drawstage(a);
			 int key = conUnit::getkey();
			 PlaySound(TEXT("걷는발자욱.wav"), NULL, SND_FILENAME | SND_ASYNC);
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
				 nposx = 5, nposy = 5;
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
				 posy = nposy;//oldx oldy 로 좌표를 점검해야한다
				 if (oldx == nposx && oldy == nposy + 1)//데이터가 4로가면 끝나게 만들어야함 
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
					 else if (m.mapData[nposy][nposx - 1] == 4) {//<- 방향
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
					 else if (m.mapData[nposy][nposx + 1] == 4) {//->방향
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
