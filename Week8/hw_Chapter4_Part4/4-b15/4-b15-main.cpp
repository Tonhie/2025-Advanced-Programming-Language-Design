//汤皓宇 计算机 2454307
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cmath>
using namespace std;

void Solution1();
void Solution2(double, double, double);
void Solution3(double, double, double);
void Solution4(double, double, double);

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
