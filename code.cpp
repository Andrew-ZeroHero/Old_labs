#include "stdafx.h"
#include "iostream"
#include "locale"
#include "bits.h"
#include "string"
using namespace std;

int main()
{
	setlocale(LC_ALL,"RUS");
	int n, i, j;
	cout << "Введите размер матрицы(1-99): ";
	cin >> n;
	int*arr = new int[n];
	double*sum = new double[n];
	double**a = new double*[n];
	for(i = 1; i <= n; i++) 
		a[i] = new double[n];
	cout.precision(2);
	cout << endl;
	if(n < 99)
	{
		cout << "Ввод матрицы:\n";
        	for(i = 1; i <= n; i++) 
		{
			for(j = 1; j <= n; j++) 
				cin >> a[i][j];
			cout << "\n";
        	}
        	for(i = 1; i <= n; i++) 
		{
			for(j = 1; j <= n; j++) 
			{
				cout.width(6);
				cout << fixed << a[i][j] << " ";
				arr[j] = j + 1;
			}
			cout << "\n";
       		}
		cout << "\n";
		for(i = 1; i <= n; i++) 
		{
			sum[i] = 0;
			for(j = 1; j <= n; j++) 
				sum[i] += a[i][j];
        	}
        	for(j = 1; j <= n; j++) 
		{
			for(i = n-1; i > j; i--) 
			{
				if(sum[i] > sum[i-1]) 
				{
					swap(sum[i-1], sum[i]);
                    			swap(arr[i-1], arr[i]);
				}
			}
		}
		cout << "Сортировка:\n";
        	for(i = 1; i <= n; i++)
			cout << "Столбец #" << arr[i] << " => " << sum[i] << "\n";
        	for(i = 1; i <= n; i++) 
			delete[] a[i];
        	delete[] a;
        	delete[] sum;
        	delete[] arr;
	}
	else
		cout << "Недопустимое значение!" << endl;
	system("pause");
}
