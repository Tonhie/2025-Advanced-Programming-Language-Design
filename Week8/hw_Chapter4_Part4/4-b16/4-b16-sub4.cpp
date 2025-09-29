//汤皓宇 计算机 2454307
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <iomanip>
#include <cmath>
#include "4-b16.h"
using namespace std;

void Solution4(double a, double b, double delta)
{
	double r = -b / (2 * a), i = fabs(sqrt(-delta) / (2 * a));
	r = fabs(r) < 1e-6 ? 0 : r;
	i = i < 1e-6 ? 0 : i;
	i = fabs(i - 1) < 1e-6 ? 1 : i;
	cout << "有两个虚根：" << endl;
	cout << setprecision(6);
	cout << "x1=";
	if (r != 0)
		cout << r;
	if (i != 0) {
		cout << "+";
		if (i != 1)
			cout << i;
		cout << "i" << endl;
	}
	cout << "x2=";
	if (r != 0)
		cout << r;
	if (i != 0) {
		cout << "-";
		if (i != 1)
			cout << i;
		cout << "i" << endl;
	}
}