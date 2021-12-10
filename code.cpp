#include <iostream>
#include <windows.h>
#include <math.h>
#include <conio.h>
#include <locale>
using namespace std;
int main()
{
	setlocale(LC_ALL, "RUS");
	float x=10;
	int n, k=0, l=0, m=0;
	HDC hDC = GetDC(GetConsoleWindow());
	cout << "Выберите фигуру(1-ромб, 2-куб, 3-трапеция): ";
	cin >> n;
	if (n == 1)
	{
		HPEN Pen1 = CreatePen(PS_SOLID, 2, RGB(255, 255, 0));
		SelectObject(hDC, Pen1);
		MoveToEx(hDC, x*x, x*x, NULL);
		LineTo(hDC, x*x + 50, x*x + 100);
		LineTo(hDC, x*x, x*x + 200);
		LineTo(hDC, x*x - 50, x*x + 100);
		LineTo(hDC, x*x, x*x);
	}
	else
	{
		if (n == 2)
		{
			HPEN Pen2 = CreatePen(PS_SOLID, 2, RGB(255, 0, 255));
			SelectObject(hDC, Pen2);
			MoveToEx(hDC, x*x, x*x, NULL);
			LineTo(hDC, x*x +400, x*x); 
			LineTo(hDC, x*x +400, x*x +200); 
			LineTo(hDC, x*x +360, x*x +240); 
			LineTo(hDC, x*x -40, x*x +240); 
			LineTo(hDC, x*x -40, x*x +40); 
			LineTo(hDC, x*x, x*x);
			MoveToEx(hDC, x*x - 40, x*x + 40, NULL);
			LineTo(hDC, x*x +360, x*x +40);
			LineTo(hDC, x*x + 400, x*x);
			MoveToEx(hDC, x*x + 360, x*x + 40, NULL);
			LineTo(hDC, x*x + 360, x*x + 240);
			MoveToEx(hDC, x*x, x*x, NULL);
			LineTo(hDC, x*x, x*x + 200);
			LineTo(hDC, x*x - 40, x*x + 240);
			MoveToEx(hDC, x*x, x*x + 200, NULL);
			LineTo(hDC, x*x + 400, x*x + 200);
		}
		else
		{
			if (n == 3)
			{
				HPEN Pen3 = CreatePen(PS_SOLID, 2, RGB(0, 255, 255));
				SelectObject(hDC, Pen3);
				MoveToEx(hDC, x*x, x*x, NULL);
				LineTo(hDC, x*x + 200, x*x);
				LineTo(hDC, x*x + 250, x*x + 150);
				LineTo(hDC, x*x - 50, x*x + 150);
				LineTo(hDC, x*x, x*x);
			}
			else
			{
				if (n = 1337) //Пасхалочка на 1337
				{
					HPEN Pen4 = CreatePen(PS_SOLID, 5, RGB(255, 255, 255));
					SelectObject(hDC, Pen4);
					MoveToEx(hDC, x*x, x*x, NULL);
					LineTo(hDC, x*x +200, x*x);
					MoveToEx(hDC, x*x + 100, x*x, NULL);
					LineTo(hDC, x*x + 100, x*x +250);
					MoveToEx(hDC, x*x + 220, x*x, NULL);
					LineTo(hDC, x*x + 220, x*x + 250);
					LineTo(hDC, x*x + 299, x*x + 250);
					LineTo(hDC, x*x + 299, x*x + 200);
					LineTo(hDC, x*x + 220, x*x + 200);
					MoveToEx(hDC, x*x + 320, x*x, NULL);
					LineTo(hDC, x*x + 320, x*x + 250);
					MoveToEx(hDC, x*x + 400, x*x +250, NULL);
					LineTo(hDC, x*x + 400, x*x);
					LineTo(hDC, x*x + 500, x*x);
					LineTo(hDC, x*x + 500, x*x +250);
					MoveToEx(hDC, x*x + 520, x*x, NULL);
					LineTo(hDC, x*x + 520, x*x +250);
					LineTo(hDC, x*x + 620, x*x);
					LineTo(hDC, x*x + 620, x*x +250);
					MoveToEx(hDC, x*x + 640, x*x +250, NULL);
					LineTo(hDC, x*x + 640, x*x + 225);
					LineTo(hDC, x*x + 740, x*x + 225);
					LineTo(hDC, x*x + 740, x*x + 250);
					MoveToEx(hDC, x*x + 665, x*x + 225, NULL);
					LineTo(hDC, x*x + 665, x*x);
					LineTo(hDC, x*x + 715, x*x);
					LineTo(hDC, x*x + 715, x*x + 225);
					MoveToEx(hDC, x*x + 760, x*x, NULL);
					LineTo(hDC, x*x + 760, x*x + 250);
					LineTo(hDC, x*x + 860, x*x + 250);
					LineTo(hDC, x*x + 860, x*x);
					LineTo(hDC, x*x + 760, x*x);
					MoveToEx(hDC, x*x + 880, x*x +250, NULL);
					LineTo(hDC, x*x + 880, x*x);
					LineTo(hDC, x*x + 950, x*x);
					LineTo(hDC, x*x + 950, x*x +100);
					LineTo(hDC, x*x + 880, x*x +100);
				}
				else
					cout << "Введено неверное значение!" << endl;
			}
		}
	}
	_getch();
	return 0;
}
