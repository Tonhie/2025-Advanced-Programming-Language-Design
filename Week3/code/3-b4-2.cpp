//软件 汤皓宇 2454307

#define _CRT_SECURE_NO_WARNINGS
# include <iostream>
# include <cmath>
# include <iomanip>
using namespace std;

int main()
{
    cout << "请输入三角形的两边及其夹角(角度)" << endl;
    int a, b, angle;
    const double pi = 3.14159;
    cin >> a >> b >> angle;
    cout << setiosflags(ios::fixed) << setprecision(3);
    cout << "三角形的面积为 : " << (float) 0.5 * a * b * sin(angle * pi / 180) << endl;
    return 0;
}
