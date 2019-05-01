#include "task3.cpp"


//Циклический сдвиг элементов списка

template<typename T>
void task4(SignedLinkedList<T> & list)
{
	list.AddLast(list[0]);
	auto size = list.GetSize();

	for (int i = size; i > 1; i--)
	{
		list[i - 1] = list[i - 2];
	}

	list[0] = list[size - 1];
	list.RemoveLast();
}