#include <iostream>
#include <fstream>
#include <string>
#include "task4.cpp"
using namespace std; 
void ChooseAction(SignedLinkedList<int> & list);

void Restart(SignedLinkedList<int> &list)
{
	int number;
	cout << endl;
	cout << "��������� ��� ��������?" << endl;
	cout << "1. ��" << endl;
	cout << "2. ���" << endl;
	cin >> number;

	switch (number)
	{
	case 1:
		ChooseAction(list);
		break;
	case 2:
		break;
	default:
		system("cls");
		cout << "������ ������������ �����. ���������� ��� ���!" << endl;
		Restart(list);
		break;
	}
}

void DoAction(int number, SignedLinkedList<int> &list)
{
	int value, index;

	switch (number)
	{
	case 1:
		cout << "������� �������� ������������ ��������: ";
		cin >> value;
		list.AddFirst(value);
		break;
	case 2:
		cout << "������� �������� ������������ ��������: ";
		cin >> value;
		list.AddCenter(value);
		break;
	case 3: 
		cout << "������� �������� ������������ ��������: ";
		cin >> value;
		list.AddLast(value);
		break;
	case 4:
		cout << "������� �������� ������������ ��������: ";
		cin >> value;
		cout << "������� ������: ";
		cin >> index;
		if (index < 0)
		{
			cout << "���������� �������� ������� �� ���������� �������! ������ �� ����� ���� �������������!" << endl;
		}
		else
		{
			list.AddAt(value, index);
		}
		break;
	case 5:
		if (list.GetSize() < 1)
		{
			cout << "�������� ����������! � ������ ��� ���������!" << endl;
		}
		else
		{
			list.RemoveFirst();
		}
		break;
	case 6:
		if (list.GetSize() < 1)
		{
			cout << "�������� ����������! � ������ ��� ���������!" << endl;
		}
		else
		{
			list.RemoveLast();
		}
		break;
	case 7:
		cout << "������� ������: ";
		cin >> index;
		if (index > list.GetSize() - 1 || index < 0)
		{
			cout << "�������� ����������! � ������ ��� �������� � ����� ��������!" << endl;
		}
		else
		{
			list.RemoveAt(index);
		}
		break;
	case 8:
		cout << "������� �������� ��������: ";
		cin >> value;
		index = list.GetIndex(value);
		if (index == -1)
		{
			cout << "������ �������� ��� � ������" << endl;
		}
		else 
		{ 
			cout << "������ ������� ���������: " << index << endl;
		}
		break;
	case 9:
		cout << "������� ������: ";
		cin >> index;
		if (index > list.GetSize() - 1 || index < 0)
		{
			cout << "�������� �� ������ ������� ���" << endl;
		}
		else
		{
			cout << "�������: " << list[index] << endl;
		}
		break;
	case 10: 
		PrintValues(list);
		break;
	case 11:
		PrintAdresses(list);
		break;
	case 12:
		PrintValuesAdresses(list);
		break;
	case 13:
		task1(list);
		break;
	case 14:
		cout << "��������� � ������: " << list.GetSize() << endl;
		cout << "������������ ������ ��������: " << list.GetSize() - 1 << endl;
		cout << endl;
		break;
	case 15:
		cout << "������� �������� ��������: ";
		cin >> value;
		cout << "���������� ��������� " << value << " � ������: " << list.GetCount(value) << endl;
		break;
	case 16:
		task2(list);
		break;
	case 17:
		task3(list);
		break;
	case 18:
		task4(list);
		break;
	default:
		system("cls");
		cout << "������ ������������ �����. ���������� ��� ���! " << endl;
		ChooseAction(list);
		break;
	}
}

void ChooseAction(SignedLinkedList<int> & list)
{
	cout << "�������� ��������" << endl;
	cout << "1. �������� ������� � ������" << endl;
	cout << "2. �������� ������� � ��������" << endl;
	cout << "3. �������� ������� � �����" << endl;
	cout << "4. �������� ������� �� ���������� �������" << endl;
	cout << "5. ������� ������ �������" << endl;
	cout << "6. ������� ��������� �������" << endl;
	cout << "7. ������� ������� �� ���������� �������" << endl;
	cout << "8. ����� �������� �� ��������" << endl;
	cout << "9. ����� �������� �� �������" << endl;
	cout << "10. ������� ������" << endl;
	cout << "11. ������� ������ ���������" << endl;
	cout << "12. ������� ������ ��������� � �� �������" << endl;
	cout << "13. ������� �������� � ������� ���������" << endl;
	cout << "14. ������ ���������� ��������� � ������" << endl;
	cout << "15. ������ ���������� ��������� �� ���������� �������� � ������" << endl;
	cout << "16. ��������� ������ ������� ������ � ��� �����" << endl;
	cout << "17. ����� ������� �������������� ��������� ������" << endl;
	cout << "18. ����������� ����� ��������� ������" << endl;
	cout << "19. ����� " << endl;

	int number;
	cin >> number;
	cout << endl;
	if (number == 19)
	{
		return;
	}
	DoAction(number, list);
	Restart(list);
}

void ReadValues(SignedLinkedList<int> &list)
{
	int value;
	ifstream file("values.txt");

	while (!file.eof())
	{
		file >> value;
		list.AddLast(value);
	}
}

void Start()
{
	SignedLinkedList<int> list;
	ReadValues(list);
	cout << "������ ������� �� �����" << endl;
	cout << endl;
	ChooseAction(list);
	list.Delete();
}

int main()
{
	setlocale(LC_ALL, "Russian");
	Start();
}