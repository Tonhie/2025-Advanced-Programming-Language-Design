//软件 汤皓宇 2454307

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

int main()
{
    int n;
    cout << "请输入一个[1..30000]间的整数:" << endl;
    cin >> n;
    cout << "万位 : " << n / 10000 << endl;
    n %= 10000;
    cout << "千位 : " << n / 1000 << endl;
    n %= 1000;
    cout << "百位 : " << n / 100 << endl;
    n %= 100;
    cout << "十位 : " << n / 10 << endl;
    n %= 10;
    cout << "个位 : " << n << endl;
    return 0;
}
