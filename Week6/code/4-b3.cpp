//汤皓宇 计算机 2454307

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <limits>
#include <iomanip>
using namespace std;

bool validCheck(int year, int month)
{
    if(year < 1900 || year > 2100) {
        cout << "年份不正确，请重新输入" << endl;
        return false;
    }
    if(month > 12 || month < 1) {
        cout << "月份不正确, 请重新输入" << endl;
        return false;
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

int getDay(int year, int month)
{
    int day = 0;
    switch(month) {
        case 1: case 3: case 5: case 7: case 8: case 10: case 12:
            day = 31;
            break;
        case 4: case 6: case 9: case 11:
            day = 30;
            break;
        case 2:
            if(year % 4 == 0 && year % 100 != 0 || year % 400 == 0)
                day = 29;
            else
                day = 28;
            break;
    }
    return day;
}

void calendar(int year, int month)
{
	/* 按需添加代码 */ 
    int week = zeller(year, month, 1);
	cout << year << "年" << month << "月" << endl;
	/* 头部分隔线，不算打表 */ 
	cout << "======================================================" << endl;
	cout << "星期日  星期一  星期二  星期三  星期四  星期五  星期六" << endl;
	cout << "======================================================" << endl;

    for(int i = 0; i < week; ++ i)
        cout << "        ";
    int day = getDay(year, month), cnt = 0;
    while(++ cnt <= day) {
        cout << setw(4) << cnt << "  ";
        if((cnt + week) % 7 == 0 || cnt == day)
            cout << endl;
        else cout << "  ";
    }

	/* 尾部分隔线，不算打表 */ 
	cout << "======================================================" << endl;
}

int main()
{
    int year, month, day;
    while(true) {
    	cout << "请输入年[1900-2100]、月" << endl;
    	if(cin >> year >> month) {
    		if(validCheck(year, month))
    			break;
		} else {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "输入错误，请重新输入" << endl; 
        }
    }
    calendar(year, month);
    return 0;
}
