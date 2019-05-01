#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

/*
	Создать двумерный массив N*N и заполнить его случайными числами от 10 до 99
	Вывести его на экран
	Поменять местами максимальный элемент каждой строки с первым элементом этой строки
*/

int** CreateArray(int size)
{
	int **array = new int*[size];
	for (int i = 0; i < size; i++)
	{
		array[i] = new int[size];
	}
	return array;
}

void FillArray(int size, int** array)
{
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			array[i][j] = 10 + rand() % 89;
		}
	}
}

void PrintArray(int size, int** array)
{
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			cout << array[i][j] << " ";
		}
		cout << endl;
	}
}

void ChangeItems(int size, int** array)
{
	for (int i = 0; i < size; i++)
	{
		int max = INT_MIN;
		int index = 0;
		for (int j = 0; j < size; j++)
		{
			if (array[i][j] > max)
			{
				max = array[i][j];
				index = j;
			}
		}
		swap(array[i][0], array[i][index]);
	}
}

void DeleteArray(int linesCount, int** array)
{
	for (int i = 0; i < linesCount; i++)
	{
		delete[] array[i];
	}
	delete array;
}

void task4()
{
	srand(static_cast<unsigned int>(time(0)));
	int size;
	cout << "Введите размерность массива: " << endl;
	cin >> size;

	int** array = CreateArray(size);
	FillArray(size, array);

	cout << endl;
	cout << "Исходный массив: " << endl;
	PrintArray(size, array);
	cout << endl;

	ChangeItems(size, array);

	cout << "Измененный  массив: " << endl;
	PrintArray(size, array);
	cout << endl;

	DeleteArray(size, array);
}