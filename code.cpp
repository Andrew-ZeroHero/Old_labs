#define _CRT_SECURE_NO_WARNINGS
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <locale.h>
#include <stdio.h>
using namespace std;
struct wrdchain
{
	char word[256];
	struct wrdchain* next;
};
wrdchain* add_wrd_head(char* nword, wrdchain* head)
{
	wrdchain* tmp = new wrdchain;
	strcpy(tmp->word, nword);
	tmp->next = head;
	return(tmp);
}
wrdchain* add_wrd_end(char* nword, wrdchain* const head)
{
	wrdchain* tmp = head;
	wrdchain* last = new wrdchain;
	strcpy(last->word, nword);
	last->next = NULL;
	if (head == NULL)
		return last;
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = last;
	return head;
}
wrdchain* kill_list(wrdchain* head)
{
	wrdchain* point = NULL;
	while (head)
	{
		point = head;
		head = head->next;
		free(point);
	}
	return NULL;
}
wrdchain* del_wrd(wrdchain* head, unsigned num)
{
	int i = 1;
	printf("\n");
	if (head == NULL)
	{
		printf(" Список пуст!\n");
		getchar();
		return NULL;
	}
	wrdchain* tmp = head;
	wrdchain* point = NULL;
	while ((tmp) && (i != num))
	{
		point = tmp;
		tmp = tmp->next;
		i++;
	}
	if (tmp == head)
	{
		point = tmp->next;
		free(head);
		return point;
	}
	if (!tmp)
	{
		getchar();
		printf("Такого элемента в списке нет!\n");
		return head;
	}
	point->next = tmp->next;
	free(tmp);
	return head;
}
void print_wrds(wrdchain* head)
{
	printf("\n");
	if (head == NULL)
		printf(" Список пуст!\n");
	else
	{
		while (head)
		{
			printf(" [%s] ->", head->word);
			head = head->next;
		}
		printf(" NULL\n");
	}
}
bool check_input_wrd(wrdchain* w1)
{
	int check = 0;
	char* str = NULL;
	str = w1->word;
	if (strlen(str) > 32)
	{
		return false;
	}
	char alphabet[] = "абвгдеёжзийклмнопрстуфхцчшщъыьэюяАБВГДЕЁЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯ\n";
	for (int i = 0; i < strlen(str); i++)
	{
		if (strchr(alphabet, *(str + i)) == NULL)
			return false;
	}
	return true;
}
bool check_input_def(char mask[256])
{
	int check = 0;
	char* str = NULL;
	str = mask;
	if (strlen(str) > 30)
	{
		return false;
	}
	char alphabet[] = "абвгдеёжзийклмнопрстуфхцчшщъыьэюяАБВГДЕЁЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯ*";
	for (int i = 0; i < strlen(str); i++)
	{
		if (strchr(alphabet, *(str + i)) == NULL)
			return false;
	}
	return true;
}
int get_key()
{
	int key = _getch();
	if ((key == 0) || (key == 224)) key = _getch();
	return key;
}
wrdchain* new_list(wrdchain* head, const size_t size)
{
	for (size_t i = 0; i < size; ++i)
	{
		char str[256];
		gets_s(str);
		head = add_wrd_end(str, head);
	}
	return head;
}
int main_menu(int checker)
{
	if (checker != 0)
	{
		printf("\n");
		printf(" Обработка по маске была выполнена, чтобы повторить - Tab\n Новая последовательность - Space\n Добавить слово в конец - 1\n Добавить слово в начало - 2\n Удалить слово - 3\n Удалить все слова - 4\n Выход - Esc\n");
		while (true)
		{
			int key = get_key();
			if ((key == 9) || (key == 32) || (key == 49) || (key == 50) || (key == 51) || (key == 52) || (key == 27)) return key;
		}
	}
	printf("\n");
	printf(" Выполнить обработку по маске - Tab\n Новая последовательность - Space\n Добавить слово в конец - 1\n Добавить слово в начало - 2\n Удалить слово - 3\n Удалить все слова - 4\n Выход - Esc\n");
	while (true)
	{
		int key = get_key();
		if ((key == 9) || (key == 32) || (key == 49) || (key == 50) || (key == 51) || (key == 52) || (key == 27)) return key;
	}
}
static bool mask_check(const char* wrd, const char* mask)
{
	const char* s2 = mask + strlen(mask);
	const char* d = wrd;
	if (strlen(mask) != strlen(wrd))
		return false;
	while (mask < s2) //битовое сравнение
	{
		if (*d == 0) return false;
		unsigned char c = *mask;
		if (c == '*')
		{
			mask++;
			if (mask == s2) return true;
			while (*d)
			{
				if (*d == *mask) break;
				d++;
			}
		}
		else
			if (*d++ != *mask++) return false;
	}
	return true;
}
wrdchain* mask_off(wrdchain* word)
{
	wrdchain* tmp = word;
	char mask[256];
	char mask_wrd[256];
	system("cls");
	printf(" Введите маску: ");
	gets_s(mask);
	while (check_input_def(mask) == false)
	{
		printf("Некорректный ввод данных. Нажмите Enter и попробуйте снова.\n");
		gets_s(mask);
	}
	printf("\n");
	printf(" Введите слово для замены: ");
	gets_s(mask_wrd);
	while (check_input_def(mask_wrd) == false)
	{
		printf("Некорректный ввод данных. Нажмите Enter и попробуйте снова.\n");
		gets_s(mask_wrd);
	}
	while (tmp)
	{
		if (mask_check(tmp->word, mask))
			strcpy(tmp->word, mask_wrd);
		tmp = tmp->next;
	}
	return word;
}
int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	setlocale(LC_ALL, "");
	wrdchain* chain = NULL;
	int checker = 0;
	char nword[256];
	int size = 0;
	int repeat = 1;
	while (repeat != 0)
	{
		system("cls");
		if (&chain)
			print_wrds(chain);
		int m3 = main_menu(checker);
		if (m3 == 9)
		{
			mask_off(chain);
			checker++;
			system("cls");
		}
		if (m3 == 32)
		{
			if (chain != NULL)
				chain = kill_list(chain);
			system("cls");
			printf("Введите количество элементов списка: ");
			scanf("%d", &size);
			getchar();
			printf("Введите элементы списка: ");
			chain = new_list(chain, size);
			if (checker != 0)
				checker--;
		}
		if (m3 == 49)
		{
			system("cls");
			printf("\n Введите слово: ");
			gets_s(nword);
			while (check_input_def(nword) == false)
			{
				printf(" Некорректный ввод данных. Нажмите Enter и попробуйте снова.\n");
				gets_s(nword);
			}
			chain = add_wrd_end(nword, chain);
		}
		if (m3 == 50)
		{
			system("cls");
			printf("\n Введите слово: ");
			gets_s(nword);
			while (check_input_def(nword) == false)
			{
				printf(" Некорректный ввод данных. Нажмите Enter и попробуйте снова.\n");
				gets_s(nword);
			}
			chain = add_wrd_head(nword, chain);
		}
		if (m3 == 51)
		{
			unsigned num;
			printf("\n Введите номер позиции слова: ");
			scanf("%u", &num);
			chain = del_wrd(chain, num);
			system("cls");
			getchar();
		}
		if (m3 == 52)
		{
			chain = kill_list(chain);
			system("cls");
		}
		if (m3 == 27) repeat = 0;
	}
	return 0;
}
