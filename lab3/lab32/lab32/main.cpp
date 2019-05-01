#include "ShortestPath.h"
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
using namespace std;
void Start(int size, int **matrix);


int GetMatrixSize()
{
	int value, count = 0;
	ifstream file("values.txt");
	while (!file.eof())
	{
		file >> value;
		count++;
	}
	return  sqrt(count);
}

int** CreateMatrix(int size)
{
	int **matrix = new int*[size];
	for (int i = 0; i < size; i++)
	{
		matrix[i] = new int[size];
	}
	return matrix;
}

void FillMatrix(int size, int **matrix)
{
	ifstream file("values.txt");
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			file >> matrix[i][j];
		}
	}
}

void PrintMatrix(int size, int **matrix)
{
	cout << "Матрица смежности:" << endl;
	cout << "\t";
	for (int i = 0; i < size; i++)
	{
		cout << i << "\t";
	}
	cout << endl;
	for (int i = 0; i < size + 1; i++)
	{
		cout << "-\t";
	}
	cout << endl;
	
	for (int i = 0; i < size; i++)
	{
		cout << i << " |\t";
		for (int j = 0; j < size; j++)
		{
			cout << matrix[i][j] << "\t";
		}
		cout << endl;
	}
	cout << endl;
}

void DeleteMatrix(int size, int** matrix)
{
	for (int i = 0; i < size; i++)
	{
		delete[] matrix[i];
	}
	delete matrix;
}

void Restart(int size, int **matrix)
{
	int number;
	cout << "Еще?" << endl;
	cout << "1. Да" << endl;
	cout << "2. Нет" << endl;
	cin >> number;
	if (number == 1)
	{
		system("cls");
		Start(size, matrix);
	}
}

void Start(int size, int **matrix)
{
	PrintMatrix(size, matrix);

	int firstVertex, secondVertex;
	cout << "Введите номера вершин: ";
	cin >> firstVertex >> secondVertex;

	if (firstVertex > size - 1 || secondVertex > size - 1 || firstVertex < 0 || secondVertex < 0)
	{
		system("cls");
		cout << "Неверно введен номер. В графе всего " << size << " вершин. Максимальный номер вершины " << size - 1 << endl;
		Start(size, matrix);
	}

	FindShortPath(matrix, size, firstVertex, secondVertex);
	cout << endl;
	cout << endl;
	Restart(size, matrix);
}

int main()
{
	setlocale(LC_ALL, "Russian");
	int size = GetMatrixSize();
	int **matrix = CreateMatrix(size);
	FillMatrix(size, matrix);
	
	Start(size, matrix);
	DeleteMatrix(size, matrix);
}
