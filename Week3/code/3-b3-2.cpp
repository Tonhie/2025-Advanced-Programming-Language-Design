//软件 汤皓宇 2454307

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

int main()
{
    double n;
    cout << "请输入[0-100亿)之间的数字:" << endl;
    cin >> n;
    n += 0.009;
    cout << "十亿位 : " << (int)(n / (int)1e9) << endl;
    n -= (int)(n / (int)1e9) * 1e9;
    cout << "亿位   : " << (int)(n / (int)1e8) << endl;
    n -= (int)(n / (int)1e8) * 1e8;
    cout << "千万位 : " << (int)(n / (int)1e7) << endl;
    n -= (int)(n / (int)1e7) * 1e7;
    cout << "百万位 : " << (int)(n / (int)1e6) << endl;
    n -= (int)(n / (int)1e6) * 1e6;
    cout << "十万位 : " << (int)(n / (int)1e5) << endl;
    n -= (int)(n / (int)1e5) * 1e5;
    cout << "万位   : " << (int)(n / (int)1e4) << endl;
    n -= (int)(n / (int)1e4) * 1e4;
    cout << "千位   : " << (int)(n / (int)1e3) << endl;
    n -= (int)(n / (int)1e3) * 1e3;
    cout << "百位   : " << (int)(n / (int)1e2) << endl;
    n -= (int)(n / (int)1e2) * 1e2;
    cout << "十位   : " << (int)(n / (int)1e1) << endl;
    n -= (int)(n / (int)1e1) * 1e1;
    cout << "圆     : " << (int)n << endl;
    n -= (int)(n);
    cout << "角     : " << (int)(n * 10) << endl;
    n -= (int)(n * 10) * 0.1;
    cout << "分     : " << (int)(n * 100) << endl;
    return 0;
}
