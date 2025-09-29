//汤皓宇 计算机 2454307
#include <iostream>
using namespace std;

int max(int num1, int num2)
{
    return (num1 > num2) ? num1 : num2;
}
int max(int num1, int num2, int num3)
{
    return max(max(num1, num2), num3);
}
int max(int num1, int num2, int num3, int num4)
{
    return max(max(num1, num2, num3), num4);
}

int main()
{
    while(true) {
        cout << "请输入个数num和num个正整数：" << endl;
        int num;
        cin >> num;
        if(!cin.good()) {
            cin.clear();
            cin.ignore(1024, '\n');
            continue;
        }
        if(num < 2 || num > 4) {
            cout << "个数输入错误" << endl;
            break;
        }
        switch (num)
        {
        case 2:
            int num1, num2;
            cin >> num1 >> num2;
            if(!cin.good() || num1 <= 0 || num2 <= 0) {
                cin.clear();
                cin.ignore(1024, '\n');
                continue;
            }
            cout << "max=" << max(num1, num2) << endl;
            break;
        case 3:
            int num3;
            cin >> num1 >> num2 >> num3;
            if(!cin.good() || num1 <= 0 || num2 <= 0 || num3 <= 0) {
                cin.clear();
                cin.ignore(1024, '\n');
                continue;
            }
            cout << "max=" << max(num1, num2, num3) << endl;
            break;
        case 4:
            int num4;
            cin >> num1 >> num2 >> num3 >> num4;
            if(!cin.good() || num1 <= 0 || num2 <= 0 || num3 <= 0 || num4 <= 0) {
                cin.clear();
                cin.ignore(1024, '\n');
                continue;
            }
            cout << "max=" << max(num1, num2, num3, num4) << endl;
            break;
        }
        break;
    }
    return 0;
}
