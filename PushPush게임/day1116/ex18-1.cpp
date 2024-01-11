// day1116.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <conio.h>
#include"conUnit.h"
#include"keyboard.h"
using namespace std;



int main()
{
	int posx = 10, posy = 10;
	int x1 = 10, y1 = 5, x2 = 60, y2 = 20;
	int oldx, oldy;
	conUnit::fillbox(x1 - 2, y1 - 1, x2 + 2, y2 + 1, DARKGRAY);
	textcolor(RED);
	conUnit::fillbox(x1, y1, x2, y2, YELLOW);
	conUnit::xyputstr(posx, posy, "★");
	_setcursortype(_NOCURSOR);
	while (1) {
		int key = conUnit::getkey();
		oldx = posx;
		oldy = posy;
		switch (key)
		{
		case M_LEFTKEY: if (posx > 0)posx -= 2; break;
		case M_UPKEY: if (posy > 0)posy--; break;
		case M_DOWNKEY:if (posy < y2 - y1-1)posy++; break;
		case M_RIGHTKEY:if (posx < x2 - x1 - 2)posx += 2; break;
		}
		if (oldx != posx || oldy != posy) {
			conUnit::xyputstr(oldx, oldy,"  ");
			conUnit::xyputstr(posx, posy, "★");
		}
	}
}

// 프로그램 실행: <Ctrl+F5> 또는 [디버그] > [디버깅하지 않고 시작] 메뉴
// 프로그램 디버그: <F5> 키 또는 [디버그] > [디버깅 시작] 메뉴

// 시작을 위한 팁: 
//   1. [솔루션 탐색기] 창을 사용하여 파일을 추가/관리합니다.
//   2. [팀 탐색기] 창을 사용하여 소스 제어에 연결합니다.
//   3. [출력] 창을 사용하여 빌드 출력 및 기타 메시지를 확인합니다.
//   4. [오류 목록] 창을 사용하여 오류를 봅니다.
//   5. [프로젝트] > [새 항목 추가]로 이동하여 새 코드 파일을 만들거나, [프로젝트] > [기존 항목 추가]로 이동하여 기존 코드 파일을 프로젝트에 추가합니다.
//   6. 나중에 이 프로젝트를 다시 열려면 [파일] > [열기] > [프로젝트]로 이동하고 .sln 파일을 선택합니다.
