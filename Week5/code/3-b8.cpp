//汤皓宇 计算机 2454307

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main()
{
    int x;
    while(true) {
        cout << "请输入x的值[-10 ~ +65]" << endl;
        cin >> x;
        if (x < -10 || x > 65)
            cout << "输入非法，请重新输入" << endl;
        else
            break;
    }
    double ans = 0, xn = 1, ns = 1, cnt = 1;
    while(fabs(xn / ns) >= 1e-6) {
        ans += xn / ns;
        xn *= x;
        ns *= cnt ++;
    }
    cout << "e^" << x << "=" << setprecision(10) << ans << endl;
    return 0;
}
