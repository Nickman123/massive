// Massiv.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "math.h"
#include <locale.h>
#include "conio.h"
#include <clocale>
#include "stdlib.h"
#include "time.h"

void output(int stroka, int stolb, float **massiv)//вывод массива на экран
{

	for (int i = 0; i < stroka; i++)
	{
		printf("\n(%d) ", i);
		for (int g = 0; g < stolb; g++)
		{

			printf("|%.2f| ", massiv[i][g]);
			printf("     ");

		}
		printf("\n");
	}

}

float work(int stroka, int stolb, float **massiv) //сортировка массива
{
	float x;
	for (int i = 0; i < stroka; i++)
	{
		for (int g = stolb - 1; g >=0 ; g--)
		{
			for (int j = 0; j < g; j++)
			{
				if (massiv[i][j] > massiv[i][j + 1])
				{
					x = massiv[i][j];
					massiv[i][j] = massiv[i][j + 1];
					massiv[i][j + 1] = x;
					
			    }
			}
		}
	}
	printf("\n Произведена сортировка столбцов \n \t__Массив с отсортированными столбцами:__ \n");
	output(stroka, stolb, massiv);
	printf("\n Произвожу сортировку строк \n");
	printf("\n Произведена сортировка строк \n \t__Полностью отсортированный массив:__ \n");
	
	

	for (int j = 0; j < stolb; j++)
	{
		for (int g = stroka - 1; g >= 0; g--)
		{
			for (int i = 0; i < g; i++)
			{
				if (massiv[i][j] > massiv[i+1][j])
				{
					x = massiv[i][j];
					massiv[i][j] = massiv[i+1][j];
					massiv[i+1][j] = x;
				}
			}
		}
	}
	output(stroka, stolb, massiv);
	return **massiv;
}



float random_massiv(int stroka, int stolb, float **massiv)//заполнение массива случайными числами
{

	srand(time(NULL));
	for (int i = 0; i < stroka; i++)
	{
		for (int g = 0; g < stolb; g++)
		{

			massiv[i][g] = rand();

		}

	}
	return **massiv;
}

float write_massiv(int stroka, int stolb, float **massiv)//заполнение массива вручную
{
	float element;
	for (int i = 0; i < stroka; i++)
	{
		for (int g = 0; g < stolb; g++)
		{
			printf("\n Введите элемент массива № [%d] [%d]: ", i, g);
			scanf("%f", &element);
			massiv[i][g] = element;

		}

	}
	return **massiv;
}

int menu()//меню пользователя
{
	int int_m, int_m1, stroka = 0, stolb = 0;
	float **massiv = NULL;



	do
	{
		printf("\n\t __Меню пользовтеля__\n");
		printf("1. Ввод данных \n");
		printf("2. Обработка данных \n");
		printf("3. Вывод результата на экран \n");
		printf("4. Выход \n");

		printf("\n \t Введите пункт меню: ");
		scanf("%d", &int_m);
		switch (int_m)
		{
		case 1:
			if (massiv != NULL)
			{
				for (int i = 0; i < stroka; i++)
				{
					delete[] massiv[i];
				}
				delete[] massiv;
			}

			do
			{
				printf("\n Введите количество строк в массиве: ");
				scanf("%d", &stroka);
				if (stroka <= 0)
					printf("\n\t__Количество строк не может быть <= 0!__\n");
			} while (stroka <= 0);
			do
			{
				printf("\n Введите количество столбцов в массиве: ");
				scanf("%d", &stolb);
				if (stolb <= 0)
					printf("\n\t__Количество столбцов не может быть <= 0!__\n");
			} while (stolb <= 0);

			massiv = new float*[stroka];
			for (int i = 0; i < stroka; i++)
			{
				massiv[i] = new float[stolb];
			}
			do
			{
				printf("\n 1. Заполнить массив случайными числами\n");
				printf("\n 2. Ввести числа самостоятельно\n");
				printf("\n \t Введите пункт меню: ");
				scanf("%d", &int_m1);
				switch (int_m1)
				{
				case 1:
					**massiv = random_massiv(stroka, stolb, massiv);
					break;
				case 2:
					**massiv = write_massiv(stroka, stolb, massiv);
					break;

				default:
					printf("\t\n__Не существует такого пункта меню!__\n");
				}
			} while (int_m1 < 1 || int_m1 > 2);
			break;
		case 2:
			if (massiv == NULL)
			{
				printf("\n\t__Сначала введите значения элементов массива!__\n");
			}
			else
			{
				**massiv = work(stroka, stolb, massiv);
			}
			break;
		case 3:
			if (massiv == NULL)
			{
				printf("\n\t__Сначала введите значения элементов массива!__\n");
			}
			else
			{
				output(stroka, stolb, massiv);
			}
			break;
		case 4:

			if (massiv != NULL)
			{
				for (int i = 0; i < stroka; i++)
				{
					delete[] massiv[i];
				}
				delete[] massiv;
			}

			return 0;
			break;
		default:
			printf("\t\n__Не существует такго пункта меню!__\n");
		}
	} while (int_m != 4);

}




int _tmain(int argc, _TCHAR* argv[])//вызывает функцию с меню
{
	setlocale(LC_ALL, "Russian");
	setlocale(LC_ALL, "ru");
	menu();

	return 0;
}



