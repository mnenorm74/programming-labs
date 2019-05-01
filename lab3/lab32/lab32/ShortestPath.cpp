#include <iostream>
#include <vector>
#include <fstream>
#include <string>
using namespace std;

void Initialize(int size, int *weights, bool *visitedVertex, int *parents, int startVertex)
{
	for (int i = 0; i < size; i++)
	{
		weights[i] = INT32_MAX;
		visitedVertex[i] = false;
	}

	weights[startVertex] = 0;

	for (int i = 0; i < size; i++)
	{
		parents[i] = -1;
	}
}

void DijkstraAlgorithm(int **matrix, int size, bool *visitedVertex, int *weights, int *parents)
{
	for (int i = 0; i < size - 1; i++)	//����� ���������� �����
	{
		int edgeWeight = INT32_MAX;	//��� �����
		int neighboringVertex; //������ �������� �������, ����������� ���������� ��������� ������

		for (int j = 0; j < size; j++)	//����� �������� ������� � ����� �������� ������
		{
			if (visitedVertex[j] == false && weights[j] <= edgeWeight)
			{
				edgeWeight = weights[j];
				neighboringVertex = j;
			}
		}

		visitedVertex[neighboringVertex] = true;	//�������� ������� ��� ����������

		for (int i = 0; i < size; i++)	//������������� ��� ������������ ������
		{
			if (!visitedVertex[i] && matrix[neighboringVertex][i] > 0 && edgeWeight + matrix[neighboringVertex][i] < weights[i])
			{
				weights[i] = edgeWeight + matrix[neighboringVertex][i];
				parents[i] = neighboringVertex;
			}
		}
	}
}

vector<int> GetPath(int startVertex, int finishVertex, int *parents)
{
	vector<int> path;
	for (int i = finishVertex; i != startVertex; i = parents[i])
	{
		path.push_back(i);
	}
	path.push_back(startVertex);
	reverse(path.begin(), path.end());
	return path;
}

void PrintResult(vector<int> path, int *weights, int finishVertex)
{
	cout << "����:" << endl;
	for (auto i = path.begin(); i != path.end(); ++i)
		cout << *i << " ";
	cout << endl;
	cout << "����� ����: " << endl;
	cout << weights[finishVertex] << endl;
}

void FindShortPath(int **matrix, int size, int startVertex, int finishVertex)	//���������� ���� ����� ��������� ���������
{
	int *weights = new int[size];
	bool *visitedVertex = new bool[size];
	int *parents = new int[size];
	Initialize(size, weights, visitedVertex, parents, startVertex);

	DijkstraAlgorithm(matrix, size, visitedVertex, weights, parents);
	if (parents[finishVertex] == -1)
	{
		cout << "���� �� ����������";
	}
	else
	{
		vector<int> path = GetPath(startVertex, finishVertex, parents);
		PrintResult(path, weights, finishVertex);
	}	
}
