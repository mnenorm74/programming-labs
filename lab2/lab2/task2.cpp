#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

/*
	������� ������������ ������ �� 7 ��������� ����� ����� �� ������� [0,9]
	���� ������ ����� ������, ��������� ������ �� 2 �������� � �����
	���� �������� ����� ������, ��������� ������ �� 2 �������� � ������
*/

void task2()
{
	srand(static_cast<unsigned int>(time(0)));
	int evenNumberCount = 0;
	int *numbers = new int[7];

	cout << "�������� ������: " << endl;
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
		cout << "������ ����� ������" << endl;
		for (int i = 0; i < 5; i++)
		{
			finishNumbers[i] = numbers[i];
		}
	}
	else
	{
		cout << "�������� ����� ������" << endl;
		for (int i = 0; i < 5; i++)
		{
			finishNumbers[i] = numbers[i+2];
		}
	}
	delete[] numbers;

	cout << "�������� ������: " << endl;
	for (int i = 0; i < 5; i++)
	{
		cout << finishNumbers[i] << " ";
	}
	cout << endl;

	delete[] finishNumbers; 
}