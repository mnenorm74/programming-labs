#include <iostream>
using namespace std;

/*
	���� ��������� �� ������ � ����� ���������
	������������ ������ �����, ���� ��� ������ 0, �� ���������� � ������
	������������ ������ �����, ������� ����������� � ����������� ������ �� ��� ���, ���� �� ����� ������� ������������� �����
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
	cout << "�������� �������: ";
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

	cout << "������� ��������: ";
	cin >> value;

	if (AddFirstValue(value, array))
	{
		PrintArray(array, size);
		while (true)
		{
			cout << "������� ��������: ";
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