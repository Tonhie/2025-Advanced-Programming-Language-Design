//汤皓宇 计算机 2454307
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

void Solution1()
{
	cout << "不是一元二次方程" << endl;
}

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

void Solution3(double a, double b, double delta)
{
	double r = -b / (2 * a);
	r = fabs(r) < 1e-6 ? 0 : r;
	cout << "有两个相等实根：" << endl;
	cout << setprecision(6) << "x1=x2=" << r << endl;
}

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

int main()
{
	cout << "请输入一元二次方程的三个系数a,b,c:" << endl;
	double a, b, c;
	cin >> a >> b >> c;
	double delta = b * b - 4 * a * c;
	a = fabs(a) < 1e-6 ? 0 : a;
	b = fabs(b) < 1e-6 ? 0 : b;
	c = fabs(c) < 1e-6 ? 0 : c;
	delta = fabs(delta) < 1e-6 ? 0 : delta;
	if (a == 0)
		Solution1();
	else {
		if (delta > 0)
			Solution2(a, b, delta);
		else if (delta == 0)
			Solution3(a, b, delta);
		else
			Solution4(a, b, delta);
	}
}