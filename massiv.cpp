// Massiv.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "math.h"
#include <locale.h>
#include "conio.h"
#include <clocale>
#include "stdlib.h"
#include "time.h"

void output(int stroka, int stolb, float **massiv)//âûâîä ìàññèâà íà ýêðàí
{

	for (int i = 0; i < stroka; i++)
	{
		printf("\n(%d) ", i);
		for (int g = 0; g < stolb; g++)
		{

			printf("|%10.2f| ", massiv[i][g]);
			printf("     ");

		}
		printf("\n");
	}

}

float work(int stroka, int stolb, float **massiv) //ñîðòèðîâêà ìàññèâà
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
	printf("\n Ïðîèçâåäåíà ñîðòèðîâêà ñòîëáöîâ \n \t__Ìàññèâ ñ îòñîðòèðîâàííûìè ñòîëáöàìè:__ \n");
	output(stroka, stolb, massiv);
	printf("\n Ïðîèçâîæó ñîðòèðîâêó ñòðîê \n");
	printf("\n Ïðîèçâåäåíà ñîðòèðîâêà ñòðîê \n \t__Ïîëíîñòüþ îòñîðòèðîâàííûé ìàññèâ:__ \n");
	
	

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



float random_massiv(int stroka, int stolb, float **massiv)//çàïîëíåíèå ìàññèâà ñëó÷àéíûìè ÷èñëàìè
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

float write_massiv(int stroka, int stolb, float **massiv)//çàïîëíåíèå ìàññèâà âðó÷íóþ
{
	float element;
	for (int i = 0; i < stroka; i++)
	{
		for (int g = 0; g < stolb; g++)
		{
			printf("\n Ââåäèòå ýëåìåíò ìàññèâà ¹ [%d] [%d]: ", i, g);
			scanf("%f", &element);
			massiv[i][g] = element;

		}

	}
	return **massiv;
}

int menu()//ìåíþ ïîëüçîâàòåëÿ
{
	int int_m, int_m1, stroka = 0, stolb = 0;
	float **massiv = NULL;



	do
	{
		printf("\n\t __Ìåíþ ïîëüçîâòåëÿ__\n");
		printf("1. Ââîä äàííûõ \n");
		printf("2. Îáðàáîòêà äàííûõ \n");
		printf("3. Âûâîä ðåçóëüòàòà íà ýêðàí \n");
		printf("4. Âûõîä \n");

		printf("\n \t Ââåäèòå ïóíêò ìåíþ: ");
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
				printf("\n Ââåäèòå êîëè÷åñòâî ñòðîê â ìàññèâå: ");
				scanf("%d", &stroka);
				if (stroka <= 0)
					printf("\n\t__Êîëè÷åñòâî ñòðîê íå ìîæåò áûòü <= 0!__\n");
			} while (stroka <= 0);
			do
			{
				printf("\n Ââåäèòå êîëè÷åñòâî ñòîëáöîâ â ìàññèâå: ");
				scanf("%d", &stolb);
				if (stolb <= 0)
					printf("\n\t__Êîëè÷åñòâî ñòîëáöîâ íå ìîæåò áûòü <= 0!__\n");
			} while (stolb <= 0);

			massiv = new float*[stroka];
			for (int i = 0; i < stroka; i++)
			{
				massiv[i] = new float[stolb];
			}
			do
			{
				printf("\n 1. Çàïîëíèòü ìàññèâ ñëó÷àéíûìè ÷èñëàìè\n");
				printf("\n 2. Ââåñòè ÷èñëà ñàìîñòîÿòåëüíî\n");
				printf("\n \t Ââåäèòå ïóíêò ìåíþ: ");
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
					printf("\t\n__Íå ñóùåñòâóåò òàêîãî ïóíêòà ìåíþ!__\n");
				}
			} while (int_m1 < 1 || int_m1 > 2);
			break;
		case 2:
			if (massiv == NULL)
			{
				printf("\n\t__Ñíà÷àëà ââåäèòå çíà÷åíèÿ ýëåìåíòîâ ìàññèâà!__\n");
			}
			else
			{
				**massiv = work(stroka, stolb, massiv);
			}
			break;
		case 3:
			if (massiv == NULL)
			{
				printf("\n\t__Ñíà÷àëà ââåäèòå çíà÷åíèÿ ýëåìåíòîâ ìàññèâà!__\n");
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
			printf("\t\n__Íå ñóùåñòâóåò òàêãî ïóíêòà ìåíþ!__\n");
		}
	} while (int_m != 4);

}




int _tmain(int argc, _TCHAR* argv[])//âûçûâàåò ôóíêöèþ ñ ìåíþ
{
	setlocale(LC_ALL, "Russian");
	setlocale(LC_ALL, "ru");
	menu();

	return 0;
}



