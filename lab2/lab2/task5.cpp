#include <iostream>
#include <cstdlib>
#include <ctime>
#include "task7.h"
using namespace std;

/*
	Утечка памяти
*/

void IncreaseArray(int *&array, int size, int value)
{
	int *increasedArray = new int[size + 1];
	for (int i = 0; i < size; i++)
	{
		increasedArray[i] = array[i];
	}
	increasedArray[size] = value;
	array = increasedArray;
}



void task5()
{
	srand(static_cast<unsigned int>(time(0)));
	int value, size = 1;
	int *array = new int{1};

	while (true)
	{
		value = rand() % 100;
		cout << "Новое значение: " << value << endl;
		IncreaseArray(array, size, value);
		size++;
		cout << "Размер: " << size << endl;
	}
}