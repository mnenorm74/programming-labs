#include <iostream>
using namespace std;
void task3();

/*
	��������� ������
	������������ ������ ����������� ���� ������ � ��������� �� �������
*/

void CheckData(int firstLinesCount, int firstColumnsCount, int secondLinesCount, int secondColumnsCount)
{
	if (firstColumnsCount != secondLinesCount || firstLinesCount < 1 ||
		firstColumnsCount < 1 || secondLinesCount< 1 || secondColumnsCount <1)
	{
		system("cls");
		cout << "����� ������� ������ �����������" << endl;
		cout << "���������� ��� ���!" << endl;
		task3();
	}
}

int** CreateMatrix(int linesCount, int columnsCount)
{
	int **matrix = new int*[linesCount];
	for (int i = 0; i < linesCount; i++)
	{
		matrix[i] = new int[columnsCount];
	}
	return matrix;
}

void FillMatrix(int linesCount, int columnsCount, int **matrix)
{
	for (int i = 0; i < linesCount; i++)
	{
		for (int j = 0; j < columnsCount; j++)
		{
			cin >> matrix[i][j];
		}
	}
}

int** CalculateResult(int** firstMatrix, int** secondMatrix, int firstLinesCount, int firstColumnsCount, int secondColumnsCount)
{
	int **resultMatrix = new int*[firstLinesCount];
	for (int i = 0; i < firstLinesCount; i++)
	{
		resultMatrix[i] = new int[secondColumnsCount];
		for (int j = 0; j<secondColumnsCount; j++)
		{
			resultMatrix[i][j] = 0;
			for (int k = 0; k < firstColumnsCount; k++)
			{
				resultMatrix[i][j] += firstMatrix[i][k] * secondMatrix[k][j];
			}
		}
	}
	return resultMatrix;
}

void PrintMatrix(int linesCount, int columnsCount, int** matrix)
{
	for (int i = 0; i < linesCount; i++)
	{
		for (int j = 0; j < columnsCount; j++)
		{
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}
}

void PrintResults(int firstLinesCount, int firstColumnsCount, int** firstMatrix, 
	int secondLinesCount, int secondColumnsCount, int** secondMatrix, int** resultMatrix)
{
	cout << endl;
	cout << "������ �������: " << endl;
	PrintMatrix(firstLinesCount, firstColumnsCount, firstMatrix);
	cout << endl;
	cout << "������ �������: " << endl;
	PrintMatrix(secondLinesCount, secondColumnsCount, secondMatrix);
	cout << endl;
	cout << "���������: " << endl;
	PrintMatrix(firstLinesCount, secondColumnsCount, resultMatrix);
	cout << endl;
}

void DeleteMatrix(int linesCount, int** matrix)
{
	for (int i = 0; i < linesCount; i++)
	{
		delete[] matrix[i];
	}
	delete matrix;
}

void task3()
{
	int firstLinesCount, firstColumnsCount, secondLinesCount, secondColumnsCount;
	cout << "���������� ����� ������ �������: ";
	cin >> firstLinesCount;
	cout << "���������� �������� ������ �������: ";
	cin >> firstColumnsCount;
	cout << "���������� ����� ������ �������: ";
	cin >> secondLinesCount;
	cout << "���������� �������� ������ �������: ";
	cin >> secondColumnsCount;
	CheckData(firstLinesCount, firstColumnsCount, secondLinesCount, secondColumnsCount);

	int **firstMatrix = CreateMatrix(firstLinesCount, firstColumnsCount);
	int **secondMatrix = CreateMatrix(secondLinesCount, secondColumnsCount);

	cout << "������� �������� ������ ������� " << firstLinesCount << " * " << firstColumnsCount << ":" << endl;
	FillMatrix(firstLinesCount, firstColumnsCount, firstMatrix);
	cout << "������� �������� ������ ������� " << secondLinesCount << " * " << secondColumnsCount << ":" << endl;
	FillMatrix(secondLinesCount, secondColumnsCount, secondMatrix);

	int **resultMatrix = CalculateResult(firstMatrix, secondMatrix, firstLinesCount, firstColumnsCount, secondColumnsCount);
	PrintResults(firstLinesCount, firstColumnsCount, firstMatrix, secondLinesCount, secondColumnsCount, secondMatrix, resultMatrix);

	DeleteMatrix(firstLinesCount, firstMatrix);
	DeleteMatrix(secondLinesCount, secondMatrix);
	DeleteMatrix(firstLinesCount, resultMatrix);
}