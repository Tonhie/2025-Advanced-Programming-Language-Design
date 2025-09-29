//汤皓宇 计算机 2454307
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <iomanip>
#include <cmath>
#include "4-b16.h"
using namespace std;

void Solution2(double a, double b, double delta)
{
	double r1 = (-b + sqrt(delta)) / (2 * a);
	double r2 = (-b - sqrt(delta)) / (2 * a);
	r1 = fabs(r1) < 1e-6 ? 0 : r1;
	r2 = fabs(r2) < 1e-6 ? 0 : r2;
	cout << "有两个不等实根：" << endl;
	cout << setprecision(6);
	cout << "x1=" << r1 << endl;
	cout << "x2=" << r2 << endl;
}