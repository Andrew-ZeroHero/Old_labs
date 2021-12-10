#include "stdafx.h"
#include "locale"
#include "iostream"
using namespace std;

struct ban
{
	char name[100];
	string adres;
	int proc;
	int time1;
	int time2;
	string fil;
};

void show(ban obj)
{
	int i = 1;
	char **mas = new char *[1000];
	cout << "Название банка: " << obj.name << endl;
	cout << "Адрес филиала: " << obj.adres << endl;
	cout << "Процент вклада: " << obj.proc << "%" << endl;
	cout << "Время работы: " << obj.time1 << " - " << obj.time2 << endl;
	cout << "Есть ли филиал: " << obj.fil << endl;
}

int main()
{
	setlocale(LC_ALL,"RUS");
	int i, n, d = 1 ;
	string k;
	char **mas = new char *[1000];
	cout << "Введите количество вводимых банков: ";
	cin >> n;
	ban j[1000];
	for(i = 1; i <= n; i++)
	{
		cout << "Введите данные " << i << " банка(назвние, адрес, процент вклада, время открытия и закрытия, наличие филиала): " << endl;
		cin >> j[i].name;
		cin >> j[i].adres;
		cin >> j[i].proc;
		cin >> j[i].time1;
		cin >> j[i].time2;
		cin >> j[i].fil;
	}
	cout << endl;
	cout << "Наличие филиалов: ";
	cin >> k;
	cout << endl;
	cout << "Вывод данных: " << endl;
	for(i = 1; i <= n; i++)
	{
		if(k == j[i].fil)
		{
			show(j[i]);
			cout << "\n";
		}
	}
	system("pause");
}
