#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

/*
	������� ��� ������������ ������� x1 � x2
	��������� �������� ����������, �������� �������� x2 �������, ��� ������ ��������� x1
*/

void FillArray(int size, int* array)
{
	for (int i = 0; i < size; i++)
	{
		array[i] = rand() % 10;
	}
}

void PrintArray(int size, int* array)
{
	for (int i = 0; i < size; i++)
	{
		cout << array[i] << "\t";
	}
	cout << endl;
}

void PrintData(int size, int* x1, int* x2)
{
	cout << "������ ������: " << endl;
	PrintArray(size, x1);
	cout << "������ ������: " << endl;
	PrintArray(size, x2);
	cout << endl;
}

void ChangeArray(int size, int* x1, int* x2)
{
	for (int i = 0; i < size; i++)
	{
		*(x2 + i) += *(x1 + i);
	}
}

void task6()
{
	srand(static_cast<unsigned int>(time(0)));
	int size;
	cout << "������� ������ ��������: ";
	cin >> size;

	int* x1 = new int[size];
	int* x2 = new int[size];
	FillArray(size, x1);
	FillArray(size, x2);

	PrintData(size, x1, x2);
	ChangeArray(size, x1, x2);
	PrintData(size, x1, x2);

	delete[] x1;
	delete[] x2;
}