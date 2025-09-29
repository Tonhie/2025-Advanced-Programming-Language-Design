//汤皓宇 计算机 2454307

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <limits>
using namespace std;

int main()
{
    int year, month, whatday, days;
    while(1) {
    	cout << "请输入年份(2000-2030)和月份(1-12) : ";
        if(cin >> year >> month) {
	        if(year >= 2000 && year <= 2030 && month >= 1 && month <= 12)
	            break;
        } else {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
        printf("输入非法，请重新输入\n");
    }
    while(1) {
        cout << "请输入" << year << "年" << month << "月1日的星期(0-6表示星期日-星期六) : ";
        if(cin >> whatday) {
        	if(whatday >= 0 && whatday <= 6)
            	break;
        } else {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
        cout << "输入非法，请重新输入\n";
    }
    if(whatday == 0)
        whatday = 7;
    switch (month) {
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
            days = 31;
            break;
        case 4:
        case 6:
        case 9:
        case 11:
            days = 30;
            break;
        case 2:
            if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
                days = 29;
            else
                days = 28;
            break;
    }
    cout << "星期一  星期二  星期三  星期四  星期五  星期六  星期日\n";
    int cnt = 0, day = 0;
    while(day < days) {
        if(++ cnt < whatday) {
            cout << "        ";
            continue;
        } else {
            cout << setw(4) << ++day << "    ";
            if(cnt % 7 == 0)
                cout << endl;
        }
    }
}
