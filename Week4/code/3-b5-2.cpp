//汤皓宇 计算机 2454307

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

int main ()
{
    int year, month, day, ans = 0;
    cout << "请输入年，月，日" << endl;
    cin >> year >> month >> day;
    int tmp = (year % 4 == 0 && year % 100 != 0 || year % 400 == 0);
    if(month > 12 || month < 1) {
        cout << "输入错误-月份不正确" << endl;
        return 0;
    }
    switch(month) {
    case 1:
        if(day > 31 || day < 1) {
            cout << "输入错误-日与月的关系非法" << endl;
            return 0;
        }
        ans = day;
        break;
    case 2:
        if(day > 28 + tmp || day < 1) {
            cout << "输入错误-日与月的关系非法" << endl;
            return 0;
        }
        ans = 31 + day;
        break;
    case 3:
        if(day > 31 || day < 1) {
            cout << "输入错误-日与月的关系非法" << endl;
            return 0;
        }
        ans = 59 + tmp + day;
        break;
    case 4:
        if(day > 30 || day < 1) {
            cout << "输入错误-日与月的关系非法" << endl;
            return 0;
        }
        ans = 90 + tmp + day;
        break;
    case 5:
        if(day > 31 || day < 1) {
            cout << "输入错误-日与月的关系非法" << endl;
            return 0;
        }
        ans = 120 + tmp + day;
        break;
    case 6:
        if(day > 30 || day < 1) {
            cout << "输入错误-日与月的关系非法" << endl;
            return 0;
        }
        ans = 151 + tmp + day;
        break;
    case 7:
        if(day > 31 || day < 1) {
            cout << "输入错误-日与月的关系非法" << endl;
            return 0;
        }
        ans = 181 + tmp + day;
        break;
    case 8:
        if(day > 31 || day < 1) {
            cout << "输入错误-日与月的关系非法" << endl;
            return 0;
        }
        ans = 212 + tmp + day;
        break;
    case 9:
        if(day > 30 || day < 1) {
            cout << "输入错误-日与月的关系非法" << endl;
            return 0;
        }
        ans = 243 + tmp + day;
        break;
    case 10:
        if(day > 31 || day < 1) {
            cout << "输入错误-日与月的关系非法" << endl;
            return 0;
        }
        ans = 273 + tmp + day;
        break;
    case 11:
        if(day > 30 || day < 1) {
            cout << "输入错误-日与月的关系非法" << endl;
            return 0;
        }
        ans = 304 + tmp + day;
        break;
    case 12:
        if(day > 31 || day < 1) {
            cout << "输入错误-日与月的关系非法" << endl;
            return 0;
        }
        ans = 334 + tmp + day;
        break;
    }
    cout << year << "-" << month << "-" << day << "是" << year << "年的第" << ans << "天" << endl;
    
    return 0;
}