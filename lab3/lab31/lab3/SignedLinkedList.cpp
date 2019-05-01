#include "SignedLinkedList.h"


//�����������
template<typename T>
SignedLinkedList<T>::SignedLinkedList()
{
	Size = 0;
	head = nullptr;
}

//����������
template<typename T>
SignedLinkedList<T>::~SignedLinkedList()
{
	Delete();
}

//���������� �������� � ������ ������
template<typename T>
void SignedLinkedList<T>::AddFirst(T value)
{
	head = new Node<T>(value, head);
	Size++;
}

//���������� �������� � ����� ������
template<typename T>
void SignedLinkedList<T>::AddLast(T value)
{
	if (head == nullptr)
	{
		head = new Node<T>(value);
	}
	else
	{
		Node<T> *currentElement = this->head;
		while (currentElement->nextNode != nullptr)
		{
			currentElement = currentElement->nextNode;
		}
		currentElement->nextNode = new Node<T>(value);
	}
	Size++;
}

//���������� � ��������
template<typename T>
void SignedLinkedList<T>::AddCenter(T value)
{
	int index = (Size % 2 == 0) ? Size / 2 : Size / 2 + 1;
	AddAt(value, index);
}

//���������� �������� � ������ �� ���������� �������
template<typename T>
void SignedLinkedList<T>::AddAt(T value, int index)
{
	if (index == 0)
	{
		AddFirst(value);
	}
	else
	{
		Node<T> *previousElement = this->head;

		for (int i = 0; i < index - 1; i++)
		{
			previousElement = previousElement->nextNode;
		}

		Node<T> *newNode = new Node<T>(value, previousElement->nextNode);
		previousElement->nextNode = newNode;

		Size++;
	}
}

//�������� ������� �������� � ������
template<typename T>
void SignedLinkedList<T>::RemoveFirst()
{
	Node<T> *firstElement = head;
	head = head->nextNode;
	delete firstElement;
	Size--;
}

//�������� ���������� �������� � ������
template<typename T>
void SignedLinkedList<T>::RemoveLast()
{
	RemoveAt(Size - 1);
}

//�������� �������� �� �������
template<typename T>
void SignedLinkedList<T>::RemoveAt(int index)
{
	if (index == 0)
	{
		RemoveFirst();
	}
	else
	{
		Node<T> *previousElement = this->head;
		for (int i = 0; i < index - 1; i++)
		{
			previousElement = previousElement->nextNode;
		}

		Node<T> *element = previousElement->nextNode;
		previousElement->nextNode = element->nextNode;
		delete element;
		Size--;
	}

}


//������ ������
template<typename T>
int SignedLinkedList<T>::GetSize()
{
	return Size;
}

//�������� ������
template<typename T>
void SignedLinkedList<T>::Delete()
{
	while (Size > 0)
	{
		RemoveFirst();
	}
}


//����� ������� �� ��������
template<typename T>
int SignedLinkedList<T>::GetIndex(T value)
{
	int counter = 0;
	auto currentElement = this->head;

	while (currentElement != nullptr)
	{
		if (currentElement->value == value)
		{
			return counter;
		}
		currentElement = currentElement->nextNode;
		counter++;
	}

	return -1;
}


// ���������� ��������� �� ���������� �������� � ������
template<typename T>
int SignedLinkedList<T>::GetCount(T value)
{
	int counter = 0;
	int count = 0;
	auto currentElement = this->head;

	while (currentElement != nullptr)
	{
		if (currentElement->value == value)
		{
			count++;
		}
		currentElement = currentElement->nextNode;
		counter++;
	}

	return count;
}

//��������� �� �������
template<typename T>
T & SignedLinkedList<T>::operator[](const int index)
{
	int counter = 0;
	Node<T> *currentElement = this->head;

	while (currentElement != nullptr)
	{
		if (counter == index)
		{
			return currentElement->value;
		}
		currentElement = currentElement->nextNode;
		counter++;
	}

	throw out_of_range{ "SignedLinkedList<T>::operator[]" };
}

//����� ������
template <typename T>
void PrintValues(SignedLinkedList<T> & list)
{
	int size = list.GetSize();
	cout << "�������� ������: " << endl;
	for (int i = 0; i < size; i++)
	{
		cout << list[i] << endl;
	}
	cout << endl;
}

//����� �������
template <typename T>
void PrintAdresses(SignedLinkedList<T> & list)
{
	int size = list.GetSize();
	cout << "������ ��������� ������: " << endl;
	for (int i = 0; i < size; i++)
	{
		cout << &list[i] << endl;
	}
	cout << endl;
}

//����� ������ � �������
template <typename T>
void PrintValuesAdresses(SignedLinkedList<T> & list)
{
	int size = list.GetSize();
	cout << "C����� ��������� � �������: " << endl;
	for (int i = 0; i < size; i++)
	{
		cout << list[i] << "\t" << &list[i] << endl;
	}
	cout << endl;
}


