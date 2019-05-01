#include "SignedLinkedList.cpp"

//�������� �� ������ ��������� � ������� ��������

template<typename T>
void task1(SignedLinkedList<T> & list)
{
	int count = list.GetSize() % 2 == 0 ? list.GetSize() / 2 : list.GetSize() / 2 + 1;
	for (int i = 0; i < count; i++)
	{
		list.RemoveAt(i);
	}
}