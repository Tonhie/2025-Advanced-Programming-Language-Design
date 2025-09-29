//汤皓宇 计算机 2454307

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

int main()
{
    float money;
    cout << "请输入找零值：" << endl;
    cin >> money;
    money += 0.001f;
    int v50, v20, v10, v5, v1, v05, v01, v005, v002, v001;
    v50 = (int)(money / 50);
    money -= v50 * 50;
    v20 = (int)(money / 20);
    money -= v20 * 20;
    v10 = (int)(money / 10);
    money -= v10 * 10;
    v5 = (int)(money / 5);
    money -= v5 * 5;
    v1 = (int)(money);
    money -= v1;
    v05 = (int)(money / 0.5f);
    money -= v05 * 0.5f;
    v01 = (int)(money / 0.1f);
    money -= v01 * 0.1f;
    v005 = (int)(money / 0.05f);
    money -= v005 * 0.05f;
    v002 = (int)(money / 0.02f);
    money -= v002 * 0.02f;
    v001 = (int)(money / 0.01f);
    cout << "共" << v50 + v20 + v10 + v5 + v1 + v05 + v01 + v005 + v002 + v001 << "张找零，具体如下：" << endl;
    if (v50)
        cout << "50元 : " << v50 << endl;
    if (v20)
        cout << "20元 : " << v20 << endl;
    if (v10)
        cout << "10元 : " << v10 << endl;
    if (v5)
        cout << "5元  : " << v5 << endl;
    if (v1)
        cout << "1元  : " << v1 << endl;
    if (v05)
        cout << "5角  : " << v05 << endl;
    if (v01)
        cout << "1角  : " << v01 << endl;
    if (v005)
        cout << "5分  : " << v005 << endl;
    if (v002)
        cout << "2分  : " << v002 << endl;
    if (v001)
        cout << "1分  : " << v001 << endl;
    return 0;
}