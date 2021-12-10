#include "iostream"
#include "string"
#include "windows.h"
#include "conio.h"
#include "math.h"
#include "locale"
using namespace std;
int main()
{
	int x;
	setlocale(LC_ALL, "RUS");
	cout << "\n" << "\n" << "\n" << "\n" << "\n" << "\n" << "\n" << "\n" << "\n" << "\n" << "\n" << "\n";
	cout << "Введите число квадратов: ";


	HDC hDC = GetDC(GetConsoleWindow());
	HPEN Pen1 = CreatePen(PS_SOLID, 2, RGB(255, 255, 0));
	HPEN Pen2 = CreatePen(PS_SOLID, 2, RGB(255, 255, 255));
	HPEN Pen3 = CreatePen(PS_SOLID, 2, RGB(255, 0, 255));
	HPEN Pen4 = CreatePen(PS_SOLID, 2, RGB(0, 255, 255));
	HPEN Pen5 = CreatePen(PS_SOLID, 2, RGB(0, 255, 0));
	while (true)
	{
		cin >> x;
		if (x == 1)
		{
			MoveToEx(hDC, 0, 0, NULL);
			SelectObject(hDC, Pen1);

			LineTo(hDC, 100, 0);
			LineTo(hDC, 100, 100);
			LineTo(hDC, 0, 100);
			LineTo(hDC, 0, 0);
		}
		else if (x == 2)
		{
			x = 1;
			MoveToEx(hDC, 0, 0, NULL);
			SelectObject(hDC, Pen1);

			LineTo(hDC, 100, 0);
			LineTo(hDC, 100, 100);
			LineTo(hDC, 0, 100);
			LineTo(hDC, 0, 0);
			x = 2;
			MoveToEx(hDC, 0, 0, NULL);
			SelectObject(hDC, Pen2);

			LineTo(hDC, 100 / x, 0);
			LineTo(hDC, 100 / x, 100 / x);
			LineTo(hDC, 0, 100 / x);
			LineTo(hDC, 0, 0);
		}
		else if (x == 3)
		{
			x = 1;
			MoveToEx(hDC, 0, 0, NULL);
			SelectObject(hDC, Pen1);

			LineTo(hDC, 100, 0);
			LineTo(hDC, 100, 100);
			LineTo(hDC, 0, 100);
			LineTo(hDC, 0, 0);
			x = 2;
			MoveToEx(hDC, 0, 0, NULL);
			SelectObject(hDC, Pen2);

			LineTo(hDC, 100 / x, 0);
			LineTo(hDC, 100 / x, 100 / x);
			LineTo(hDC, 0, 100 / x);
			LineTo(hDC, 0, 0);
			x = 3;
			SelectObject(hDC, Pen3);
			MoveToEx(hDC, 50, 0, NULL);

			LineTo(hDC, 50 + 100 / x, 0);
			LineTo(hDC, 50 + 100 / x, 100 / x);
			LineTo(hDC, 50, 100 / x);
			LineTo(hDC, 50, 0);

		}
		else if (x == 4)
		{
			x = 1;
			MoveToEx(hDC, 0, 0, NULL);
			SelectObject(hDC, Pen1);

			LineTo(hDC, 100, 0);
			LineTo(hDC, 100, 100);
			LineTo(hDC, 0, 100);
			LineTo(hDC, 0, 0);
			x = 2;
			MoveToEx(hDC, 0, 0, NULL);
			SelectObject(hDC, Pen2);

			LineTo(hDC, 100 / x, 0);
			LineTo(hDC, 100 / x, 100 / x);
			LineTo(hDC, 0, 100 / x);
			LineTo(hDC, 0, 0);
			x = 3;
			SelectObject(hDC, Pen3);
			MoveToEx(hDC, 50, 0, NULL);

			LineTo(hDC, 50 + 100 / x, 0);
			LineTo(hDC, 50 + 100 / x, 100 / x);
			LineTo(hDC, 50, 100 / x);
			LineTo(hDC, 50, 0);
			x = 4;
			SelectObject(hDC, Pen4);
			MoveToEx(hDC, 0, 50, NULL);

			LineTo(hDC, 100 / x, 50);
			LineTo(hDC, 100 / x, 50 + 100 / x);
			LineTo(hDC, 0, 50 + 100 / x);
			LineTo(hDC, 0, 50);

		}
		else if (x == 5)
		{
			x = 1;
			MoveToEx(hDC, 0, 0, NULL);
			SelectObject(hDC, Pen1);

			LineTo(hDC, 100, 0);
			LineTo(hDC, 100, 100);
			LineTo(hDC, 0, 100);
			LineTo(hDC, 0, 0);
			x = 2;
			MoveToEx(hDC, 0, 0, NULL);
			SelectObject(hDC, Pen2);

			LineTo(hDC, 100 / x, 0);
			LineTo(hDC, 100 / x, 100 / x);
			LineTo(hDC, 0, 100 / x);
			LineTo(hDC, 0, 0);
			x = 3;
			SelectObject(hDC, Pen3);
			MoveToEx(hDC, 50, 0, NULL);

			LineTo(hDC, 50 + 100 / x, 0);
			LineTo(hDC, 50 + 100 / x, 100 / x);
			LineTo(hDC, 50, 100 / x);
			LineTo(hDC, 50, 0);
			x = 4;
			SelectObject(hDC, Pen4);
			MoveToEx(hDC, 0, 50, NULL);

			LineTo(hDC, 100 / x, 50);
			LineTo(hDC, 100 / x, 50 + 100 / x);
			LineTo(hDC, 0, 50 + 100 / x);
			LineTo(hDC, 0, 50);
			x = 5;
			SelectObject(hDC, Pen5);
			MoveToEx(hDC, 25, 50, NULL);

			LineTo(hDC, 25 + 100 / x, 50);
			LineTo(hDC, 25 + 100 / x, 50 + 100 / x);
			LineTo(hDC, 25, 50 + 100 / x);
			LineTo(hDC, 25, 50);
		}
		else break;
	}
	_getch();
	return 0;
}
