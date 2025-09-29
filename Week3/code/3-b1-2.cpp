//软件 汤皓宇 2454307

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    double R, H;
    const double Pi = 3.14159;
    cout << "请输入半径和高度" << endl;
    cin >> R >> H;
    cout << setiosflags(ios::fixed) << setprecision(2);
    cout << "圆周长     : " << 2 * Pi * R << endl;
    cout << "圆面积     : " << Pi * R * R << endl;
    cout << "圆球表面积 : " << 4 * Pi * R * R << endl;
    cout << "圆球体积   : " << 4 * Pi * R * R * R / 3 << endl;
    cout << "圆柱体积   : " << Pi * R * R * H << endl;
    return 0;
}
