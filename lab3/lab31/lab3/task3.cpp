#include "task2.cpp"


// ����� ������� �������������� ��������� ������
template<typename T>
float GetAverage(SignedLinkedList<T> & list)
{
	auto size = list.GetSize();
	auto sum = 0;
	for (auto i = 0; i < size; i++)
	{
		sum += list[i];
	}
	return (float)sum / size;
}


template<typename T>
void task3(SignedLinkedList<T> & list)
{
	cout << "������� �������������� ��������� ������: " << GetAverage(list) << endl;
}