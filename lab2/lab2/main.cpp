#include <iostream>
#include "task1.h"
#include "task2.h"
#include "task3.h"
#include "task4.h"
#include "task5.h"
#include "task6.h"
#include "task7.h"
using namespace std;
void restart();

void start()
{
	int number;
	cout << "�������� ����� ������� (1-7) ��� ������� 0, ����� �����" << endl;
	cin >> number;
	switch (number)
	{
	case 0:
		break;
	case 1:
		task1();
		restart();
		break;
	case 2:
		task2();
		restart();
		break;
	case 3:
		task3();
		restart();
		break;
	case 4:
		task4();
		restart();
		break;
	case 5:
		task5();
		restart();
		break;
	case 6:
		task6();
		restart();
		break;
	case 7:
		task7();
		restart();
		break;
	default:
		system("cls");
		cout << "������� ��������� �����. ���������� ��� ���." << endl;
		start();
		break;
	}
}

void restart()
{
	int number;
	cout << "��� �������?" << endl;
	cout << "1. ��" << endl;
	cout << "2. ���" << endl;
	cin >> number;
	switch (number)
	{
	case 1:
		system("cls");
		start();
		break;
	case 2:
		break;
	default:
		system("cls");
		cout << "������� ��������� �����. ���������� ��� ���." << endl;
		restart();
		break;
	}
}

int main()
{
	setlocale(LC_ALL, "Russian");
	start();
	system("pause");
}