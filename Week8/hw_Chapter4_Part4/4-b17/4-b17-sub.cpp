//汤皓宇 计算机 2454307
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

extern double a, b, c;

void Solution1()
{
	cout << "不是一元二次方程" << endl;
}

void Solution2()
{
	double delta = b * b - 4 * a * c;
	double r1 = (-b + sqrt(delta)) / (2 * a);
	double r2 = (-b - sqrt(delta)) / (2 * a);
	r1 = fabs(r1) < 1e-6 ? 0 : r1;
	r2 = fabs(r2) < 1e-6 ? 0 : r2;
	cout << "有两个不等实根：" << endl;
	cout << setprecision(6);
	cout << "x1=" << r1 << endl;
	cout << "x2=" << r2 << endl;
}

void Solution3()
{
	double r = -b / (2 * a);
	r = fabs(r) < 1e-6 ? 0 : r;
	cout << "有两个相等实根：" << endl;
	cout << setprecision(6) << "x1=x2=" << r << endl;
}

void Solution4()
{
	double delta = b * b - 4 * a * c;
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
