#include <iostream>
#include <stdlib.h>
#include <windows.h>
#include <vector>
#include <algorithm>
#include <locale>
#include <conio.h>
#include <fstream>
using namespace std;

int main()
{
	setlocale(LC_ALL, "RUS");
	vector <vector<int>> gg;
	int i, n, k, j;
	ofstream fileo;
	cout << "Введите ограничение: ";
	cin >> n;
	fileo.open("C:\\Users\\Andrey\\Documents\\Файл.txt");
	fileo << "Вывод массива:" << endl;
	for (i = 0; i < n; i++)
	{
		vector <int> a;
		for (j = 0; j < n; j++)
		{
			k = rand() % 150 - 50;
			a.push_back(k);
		}
		gg.push_back(a);
	}
	cout << "Вывод массива:" << endl;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			std::cout.width(4);
			std::cout << gg[i][j];
			fileo.width(4);
			fileo << gg[i][j];
		}
		std::cout << endl;
		fileo << endl;
	}
	fileo << endl << endl;
	system("pause");
}
