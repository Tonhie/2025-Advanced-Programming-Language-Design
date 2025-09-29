//汤皓宇 计算机 2454307
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <iomanip>
#include <cmath>
#include "4-b16.h"
using namespace std;

void Solution3(double a, double b, double delta)
{
	double r = -b / (2 * a);
	r = fabs(r) < 1e-6 ? 0 : r;
	cout << "有两个相等实根：" << endl;
	cout << setprecision(6) << "x1=x2=" << r << endl;
}
