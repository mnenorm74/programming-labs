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
	cout << "Выполнить еще действие?" << endl;
	cout << "1. Да" << endl;
	cout << "2. Нет" << endl;
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
		cout << "Введен неправильный номер. Попробуйте еще раз!" << endl;
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
		cout << "Введите значение добавляемого элемента: ";
		cin >> value;
		list.AddFirst(value);
		break;
	case 2:
		cout << "Введите значение добавляемого элемента: ";
		cin >> value;
		list.AddCenter(value);
		break;
	case 3: 
		cout << "Введите значение добавляемого элемента: ";
		cin >> value;
		list.AddLast(value);
		break;
	case 4:
		cout << "Введите значение добавляемого элемента: ";
		cin >> value;
		cout << "Введите индекс: ";
		cin >> index;
		if (index < 0)
		{
			cout << "Невозможно добавить элемент по указанному индексу! Индекс не может быть отрицательным!" << endl;
		}
		else
		{
			list.AddAt(value, index);
		}
		break;
	case 5:
		if (list.GetSize() < 1)
		{
			cout << "Удаление невозможно! В списке нет элементов!" << endl;
		}
		else
		{
			list.RemoveFirst();
		}
		break;
	case 6:
		if (list.GetSize() < 1)
		{
			cout << "Удаление невозможно! В списке нет элементов!" << endl;
		}
		else
		{
			list.RemoveLast();
		}
		break;
	case 7:
		cout << "Введите индекс: ";
		cin >> index;
		if (index > list.GetSize() - 1 || index < 0)
		{
			cout << "Удаление невозможно! В списке нет элемента с таким индексом!" << endl;
		}
		else
		{
			list.RemoveAt(index);
		}
		break;
	case 8:
		cout << "Введите значение элемента: ";
		cin >> value;
		index = list.GetIndex(value);
		if (index == -1)
		{
			cout << "Такого элемента нет в списке" << endl;
		}
		else 
		{ 
			cout << "Индекс первого вхождения: " << index << endl;
		}
		break;
	case 9:
		cout << "Введите индекс: ";
		cin >> index;
		if (index > list.GetSize() - 1 || index < 0)
		{
			cout << "Элемента по такому индексу нет" << endl;
		}
		else
		{
			cout << "Элемент: " << list[index] << endl;
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
		cout << "Элементов в списке: " << list.GetSize() << endl;
		cout << "Максимальный индекс элемента: " << list.GetSize() - 1 << endl;
		cout << endl;
		break;
	case 15:
		cout << "Введите значение элемента: ";
		cin >> value;
		cout << "Количество элементов " << value << " в списке: " << list.GetCount(value) << endl;
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
		cout << "Введен неправильный номер. Попробуйте еще раз! " << endl;
		ChooseAction(list);
		break;
	}
}

void ChooseAction(SignedLinkedList<int> & list)
{
	cout << "Выберите действие" << endl;
	cout << "1. Добавить элемент в начало" << endl;
	cout << "2. Добавить элемент в середину" << endl;
	cout << "3. Добавить элемент в конец" << endl;
	cout << "4. Добавить элемент по указанному индексу" << endl;
	cout << "5. Удалить первый элемент" << endl;
	cout << "6. Удалить последний элемент" << endl;
	cout << "7. Удалить элемент по указанному индексу" << endl;
	cout << "8. Поиск элемента по значению" << endl;
	cout << "9. Поиск элемента по индексу" << endl;
	cout << "10. Вывести список" << endl;
	cout << "11. Вывести адреса элементов" << endl;
	cout << "12. Вывести список элементов и их адресов" << endl;
	cout << "13. УДАЛИТЬ ЭЛЕМЕНТЫ С ЧЕТНЫМИ ИНДЕКСАМИ" << endl;
	cout << "14. Узнать количество элементов в списке" << endl;
	cout << "15. Узнать количество элементов по указанному значению в списке" << endl;
	cout << "16. ПЕРЕНЕСТИ ПЕРВЫЙ ЭЛЕМЕНТ СПИСКА В ЕГО КОНЕЦ" << endl;
	cout << "17. НАЙТИ СРЕДНЕЕ АРИФМЕТИЧЕСКОЕ ЭЛЕМЕНТОВ СПИСКА" << endl;
	cout << "18. ЦИКЛИЧЕСКИЙ СДВИГ ЭЛЕМЕНТОВ СПИСКА" << endl;
	cout << "19. Выход " << endl;

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
	cout << "Данные считаны из файла" << endl;
	cout << endl;
	ChooseAction(list);
	list.Delete();
}

int main()
{
	setlocale(LC_ALL, "Russian");
	Start();
}