#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

/*
	Создать динамический массив из 7 случайных целых чисел из отрезка [0,9]
	Если четных чисел больше, укоротить массив на 2 элемента с конца
	Если нечетных чисел больше, укоротить массив на 2 элемента с начала
*/

void task2()
{
	srand(static_cast<unsigned int>(time(0)));
	int evenNumberCount = 0;
	int *numbers = new int[7];

	cout << "Исходный массив: " << endl;
	for (int i = 0; i < 7; i++)
	{
		numbers[i] = rand() % 9;
		cout << numbers[i] << " ";
		if (numbers[i] % 2 == 0)
		{
			evenNumberCount++;
		}
	}
	cout << endl;

	int *finishNumbers = new int[5];
	if (evenNumberCount > 7 - evenNumberCount)
	{
		cout << "Четных чисел больше" << endl;
		for (int i = 0; i < 5; i++)
		{
			finishNumbers[i] = numbers[i];
		}
	}
	else
	{
		cout << "Нечетных чисел больше" << endl;
		for (int i = 0; i < 5; i++)
		{
			finishNumbers[i] = numbers[i+2];
		}
	}
	delete[] numbers;

	cout << "Итоговый массив: " << endl;
	for (int i = 0; i < 5; i++)
	{
		cout << finishNumbers[i] << " ";
	}
	cout << endl;

	delete[] finishNumbers; 
}