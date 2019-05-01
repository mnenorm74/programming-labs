#include "SignedLinkedList.h"


//конструктор
template<typename T>
SignedLinkedList<T>::SignedLinkedList()
{
	Size = 0;
	head = nullptr;
}

//деструктор
template<typename T>
SignedLinkedList<T>::~SignedLinkedList()
{
	Delete();
}

//добавление элемента в начало списка
template<typename T>
void SignedLinkedList<T>::AddFirst(T value)
{
	head = new Node<T>(value, head);
	Size++;
}

//добавление элемента в конец списка
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

//добавление в середину
template<typename T>
void SignedLinkedList<T>::AddCenter(T value)
{
	int index = (Size % 2 == 0) ? Size / 2 : Size / 2 + 1;
	AddAt(value, index);
}

//добавление элемента в список по указанному индексу
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

//удаление первого элемента в списке
template<typename T>
void SignedLinkedList<T>::RemoveFirst()
{
	Node<T> *firstElement = head;
	head = head->nextNode;
	delete firstElement;
	Size--;
}

//удаление последнего элемента в списке
template<typename T>
void SignedLinkedList<T>::RemoveLast()
{
	RemoveAt(Size - 1);
}

//удаление элемента по индексу
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


//размер списка
template<typename T>
int SignedLinkedList<T>::GetSize()
{
	return Size;
}

//удаление списка
template<typename T>
void SignedLinkedList<T>::Delete()
{
	while (Size > 0)
	{
		RemoveFirst();
	}
}


//поиск индекса по значению
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


// Количество элементов по указанному значению в списке
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

//обращение по индексу
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

//вывод списка
template <typename T>
void PrintValues(SignedLinkedList<T> & list)
{
	int size = list.GetSize();
	cout << "Элементы списка: " << endl;
	for (int i = 0; i < size; i++)
	{
		cout << list[i] << endl;
	}
	cout << endl;
}

//вывод адресов
template <typename T>
void PrintAdresses(SignedLinkedList<T> & list)
{
	int size = list.GetSize();
	cout << "Адреса элементов списка: " << endl;
	for (int i = 0; i < size; i++)
	{
		cout << &list[i] << endl;
	}
	cout << endl;
}

//вывод списка и адресов
template <typename T>
void PrintValuesAdresses(SignedLinkedList<T> & list)
{
	int size = list.GetSize();
	cout << "Cписок элементов и адресов: " << endl;
	for (int i = 0; i < size; i++)
	{
		cout << list[i] << "\t" << &list[i] << endl;
	}
	cout << endl;
}


