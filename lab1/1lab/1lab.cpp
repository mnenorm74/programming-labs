#include "stdafx.h"
#include <iostream>
#include <string>
using namespace std;

int main()
{
	cout << 1;
    return 0;
}

double GetFunctionValue(double x, double y)
{
	return x - y > 0 ? abs(x) + abs(y) : abs(y) - abs(x);
}

void IsCorrectOrder(string firstDate, string secondDate)
{
	string firstYear = firstDate.substr(6, 4);
	string secondYear = secondDate.substr(6, 4);
}


