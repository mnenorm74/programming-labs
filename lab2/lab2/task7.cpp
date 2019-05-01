#include <iostream>
using namespace std;

/*
	Есть указатель на массив с одним элементом
	Пользователь воодит число, если оно больше 0, то записываем в массив
	Пользователь вводит числа, которые добавляются в расширенный массив до тех пор, пока не будет введено отрицательное число
*/

bool AddFirstValue(int value, int* array)
{
	if (value > 0)
	{
		array[0] = value;
		return true;
	}
	return false;
}

void AddValue(int *&array, int size, int value)
{
	int *increasedArray = new int[size + 1];
	for (int i = 0; i < size; i++)
	{
		increasedArray[i] = array[i];
	}
	increasedArray[size] = value;
	delete[] array;
	array = increasedArray;
}

void PrintArray(int* array, int size)
{
	cout << "Элементы массива: ";
	for (int i = 0; i < size; i++)
	{
		cout << array[i] << " ";
	}
	cout << endl;
}

void task7()
{
	int value, size = 1;
	int *array = new int[size];

	cout << "Введите значение: ";
	cin >> value;

	if (AddFirstValue(value, array))
	{
		PrintArray(array, size);
		while (true)
		{
			cout << "Введите значение: ";
			cin >> value;
			if (value < 0)
				break;
			AddValue(array, size, value);
			size++;
			PrintArray(array, size);
		}
	}

	delete[] array;
}