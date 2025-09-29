//汤皓宇 计算机 2454307

#include <iostream>
#include <iomanip>

using namespace std;

bool isLeapYear(int year) {
    if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0)
        return true;
    return false;
}

int getDayOfWeek(int y, int m, int d) {
    if (m == 1 || m == 2)
        m += 12, y--;
    int c = y / 100;
    y = y % 100;
    return ((y + y / 4 + c / 4 - 2 * c + 26 * (m + 1) / 10 + d - 1) % 7 + 7) % 7;
}

bool judge(int day[], int maxDay[], int begin, int end) {
    for (int month = begin; month <= end; month++) {
        if (day[month] <= maxDay[month])
            return true;
    }
    return false;
}

int main()
{
    int year, perRow;
    int maxDay[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    int day[13] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
    while (true) {
        cout << "请输入年份[1900-2100]" << endl;
        cin >> year;
        if (cin.good()) {
            if (year >= 1900 && year <= 2100)
                break;
        }
        cin.clear();
        cin.ignore(1024, '\n');
    }
    maxDay[2] += isLeapYear(year) ? 1 : 0;
    while (true) {
        cout << "请输入每行打印的月份数[1/2/3/4/6/12]" << endl;
        cin >> perRow;
        if (cin.good()) {
            if (perRow == 1 || perRow == 2 || perRow == 3 || perRow == 4 || perRow == 6 || perRow == 12)
                break;
        }
        cin.clear();
        cin.ignore(1024, '\n');
    }
    cout << year << "年的日历:" << endl;
    for (int row = 1; row <= 12 / perRow; row++) {
        cout << endl;
        int begin = (row - 1) * perRow + 1;
        int end = row * perRow;
        for (int month = begin; month <= end; month++) {
            cout << setw(11) << " ";
            cout << setw(2) << right << month << "月";
            cout << setw(17) << " ";
        }
        cout << endl;
        for (int month = begin; month <= end; month++) {
            cout << "Sun Mon Tue Wed Thu Fri Sat ";
            cout << setw(4) << " ";
        }
        cout << endl;
        while (judge(day, maxDay, begin, end)) {
            for (int month = begin; month <= end; month++) {
                int dow = 0;
                int init = getDayOfWeek(year, month, day[month]);
                while (dow <= 6) {
                    if (dow >= init)
                        if (day[month] <= maxDay[month])
                            cout << setw(4) << left << day[month]++;
                        else
                            cout << setw(4) << " ";
                    else
                        cout << setw(4) << " ";
                    dow++;
                }
                cout << setw(4) << " ";
            }
            cout << endl;
        }
    }
    cout << endl << endl;
    return 0;
}