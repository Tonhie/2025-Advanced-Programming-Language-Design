//汤皓宇 计算机 2454307

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <limits>
using namespace std;

bool validCheck(int year, int month, int day)
{
    if(year < 1900 || year > 2100) {
        cout << "年份不正确，请重新输入" << endl;
        return false;
    }
    int tmp = (year % 4 == 0 && year % 100 != 0 || year % 400 == 0);
    if(month > 12 || month < 1) {
        cout << "月份不正确, 请重新输入" << endl;
        return false;
    }
    switch(month) {
    case 1:
        if(day > 31 || day < 1) {
            cout << "日不正确, 请重新输入" << endl;
            return false;
        }
        break;
    case 2:
        if(day > 28 + tmp || day < 1) {
            cout << "日不正确, 请重新输入" << endl;
            return false;
        }
        break;
    case 3:
        if(day > 31 || day < 1) {
            cout << "日不正确, 请重新输入" << endl;
            return false;
        }
        break;
    case 4:
        if(day > 30 || day < 1) {
            cout << "日不正确, 请重新输入" << endl;
            return false;
        }
        break;
    case 5:
        if(day > 31 || day < 1) {
            cout << "日不正确, 请重新输入" << endl;
            return false;
        }
        break;
    case 6:
        if(day > 30 || day < 1) {
            cout << "日不正确, 请重新输入" << endl;
            return false;
        }
        break;
    case 7:
        if(day > 31 || day < 1) {
            cout << "日不正确, 请重新输入" << endl;
            return false;
        }
        break;
    case 8:
        if(day > 31 || day < 1) {
            cout << "日不正确, 请重新输入" << endl;
            return false;
        }
        break;
    case 9:
        if(day > 30 || day < 1) {
            cout << "日不正确, 请重新输入" << endl;
            return false;
        }
        break;
    case 10:
        if(day > 31 || day < 1) {
            cout << "日不正确, 请重新输入" << endl;
            return false;
        }
        break;
    case 11:
        if(day > 30 || day < 1) {
            cout << "日不正确, 请重新输入" << endl;
            return false;
        }
        break;
    case 12:
        if(day > 31 || day < 1) {
            cout << "日不正确, 请重新输入" << endl;
            return false;
        }
        break;
    }
    return true;
}

int zeller(int y, int m, int d)
{
    if(m == 1 || m == 2)
        m += 12, y --;
    int c = y / 100;
    y = y % 100;
    return (y + y / 4 + c / 4 - 2 * c + 26 * (m + 1) / 10 + d - 1 + 7) % 7;
}

int main()
{
    int year, month, day;
    while(true) {
    	cout << "请输入年[1900-2100]、月、日：" << endl;
    	if(cin >> year >> month >> day) {
    		if(validCheck(year, month, day))
    			break;
		} else {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "输入错误，请重新输入" << endl; 
        }
    }
    switch(zeller(year, month, day)) {
        case 1:
            cout << "星期一" << endl;
            break; 
        case 2:
            cout << "星期二" << endl;
            break;
        case 3:
            cout << "星期三" << endl;
            break;
        case 4:
            cout << "星期四" << endl;
            break;
        case 5:
            cout << "星期五" << endl;
            break;
        case 6:
            cout << "星期六" << endl;
            break;
        case 0:
            cout << "星期日" << endl;
            break;
    }
    return 0;
}
