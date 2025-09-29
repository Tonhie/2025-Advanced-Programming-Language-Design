//汤皓宇 计算机 2454307
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cmath>
using namespace std;

double a, b, c;

void Solution1();
void Solution2();
void Solution3();
void Solution4();

int main()
{
	cout << "请输入一元二次方程的三个系数a,b,c:" << endl;
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
			Solution2();
		else if (delta == 0)
			Solution3();
		else
			Solution4();
	}
}