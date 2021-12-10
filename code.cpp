#include <stdio.h>
#include <locale>

int main()
{
    setlocale(LC_ALL, "RUS");
    int n, m, a[255][255], k = 0;
    printf("Размер матрицы m*n(>0):\n");
    do
    {
        printf("n = ");
        scanf_s("%d", &n);
        printf("m = ");
        scanf_s("%d", &m);
        if (n <= 0||m <= 0)
        {
            if (m <= 0)
            {
                printf("Неверное значение m\n");
            }
            if (n <= 0)
            {
                printf("Неверное значение n\n");
            }
            printf("Введите значения заново!\n");
        }
    } while (n <= 0 || m <= 0 || n > 255 || m > 255);
            printf("Ввод матрицы(1 и 0):\n");
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < m; j++)
                {
                    do
                    {
                        printf("a[%d][%d] = ", i, j);
                        scanf_s("%d", &a[i][j]);
                        if (a[i][j] != 0 && a[i][j] != 1)
                        {
                            printf("Введите значения заново (0 или 1)!\n\n");
                        }
                    } while (a[i][j] != 0 && a[i][j] != 1);
                }
                printf("\n");
            }
            printf("\n\n\n");
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < m; j++)
                {
                    printf(" %4d", a[i][j]);
                    if (a[i][j] == 0 && a[i][j + 1] == 1 && a[i][j + 2] == 0 && a[i + 1][j] == 1 && a[i + 1][j + 1] == 0 && a[i + 1][j + 2] == 1 && a[i + 2][j] == 0 && a[i + 2][j + 1] == 1 && a[i + 2][j + 2] == 0)
                    {
                        k++;
                    }
                }
                printf("\n\n\n");
            }
            printf("Всего фрагментов заданного вида\n");
            printf(" 0  1  0 \n\n"); 
            printf(" 1  0  1 \n\n");
            printf(" 0  1  0 \n\n\n");
            printf(" %d\n\n", k);
            system("pause");
}
