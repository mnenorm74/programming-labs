#include "task1.cpp"


//������� ������� �������� ������ � ��� �����

template<typename T>
void task2(SignedLinkedList<T>& list)
{
	auto firstValue = list[0];
	list.AddLast(firstValue);
	list.RemoveFirst();
}