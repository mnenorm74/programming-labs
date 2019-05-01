#include <iostream>
using namespace std;

void task1()
{
	int **p;
	p = new int*;
	*p = new int;
	**p = 2;
	cout << **p << endl;
	cout << endl;
	delete *p;
	delete p;
}