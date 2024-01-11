
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <conio.h>
#include <time.h>
#include"conUnit.h"
#include"keyboard.h"
#include"map.h"
#include"map2.h"
#include"map3.h"
#include"end.h"
#include"FirstPrint.h"
#include"map4.h"
#include"map5.h"




using namespace std;



int main()
{
	int a = 0, b = 0, total = 0,fin=0;
	int finish, test = 0, test2 = 0;;
	time_t start=0.0, end=0.0;
	finish=FirstPrint::first();
	
	while (1)
	{


		if (finish == 1) {
			textbackground(BLACK);
			system("cls");
			if (test == 0) {
				start = time(NULL);
				b = map::start(a);
				total += b;
				if(b!=0)
				test++;
			else
				test = 0;
			}
			else if (test == 1) {
				b = 0;

				b = map2::start(a);
				total += b;
				if (b != 0)
					test++;
				else
					test = 0;
			}
			else if (test == 2) {
				b = 0;
				b = map3::start(a);
				total += b;
				if (b != 0)
				test++;
				else
					test = 0;
			}
			else if (test == 3) {
				b = 0;
				b = map4::start(a);
				total += b;
				if (b != 0)
				test++;
			}
			else if (test == 4) {
				b = 0;
				b = map5::start(a);
				total += b;
				if (b != 0)
				test++;
				else
					test = 0;
			}
		}
		 if (finish == 2) {
			test2 = FirstPrint::second();
			if (test2 == 1) {
				b=1;
				finish = FirstPrint::first();
			}
		}
			if(b == 0)
				finish= FirstPrint::first();

		 if (test == 5|| finish == 3) {

			break;
		} 

		}
		end = time(NULL);
		double result = double(end - start);
		if (test == 5)
			fin = end::endprint(result, total);

		if (fin == 3||finish==3) {
			system("cls");
			return 0;
		}
	}
