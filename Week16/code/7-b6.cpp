//汤皓宇 计算机 2454307
#include <iostream>
#include <conio.h>
#include "7-b6.h"
using namespace std;

/* 给出 Date 类的所有成员函数的体外实现 */
/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
void Date::fix(int& year, int& month, int& day) {
	if (year < 1900 || year > 2099)
		year = 2000;
	if (month < 1 || month > 12)
		month = 1;
	if (day < 1 || day > getNumDays(year, month))
		day = 1;
}

Date::Date(int year, int month, int day)
{
	fix(year, month, day);
	this->year = year;
	this->month = month;
	this->day = day;
}

Date::Date(int days)
{
	year = 1900;
	month = 1;
	while (1) {
		days -= 365 + isLeapYear(year);
		if (days <= 0) {
			days += 365 + isLeapYear(year);
			break;
		}
		year++;
	}
	while (1) {
		days -= getNumDays(year, month);
		if (days <= 0) {
			days += getNumDays(year, month);
			break;
		}
		month++;
	}
	day = days;
	fix(year, month, day);
}

void Date::set(int year, int month, int day)
{
	year = year ? year : this->year;
	month = month ? month : this->month;
	day = day ? day : this->day;
	fix(year, month, day);
	this->year = year;
	this->month = month;
	this->day = day;
}

void Date::get(int &year, int &month, int &day)
{
	year = this->year;
	month = this->month;
	day = this->day;
}

void Date::show()
{
	cout << year << '.' << month << '.' << day << endl;
}

/* 如果有需要的其它全局函数的实现，可以写于此处 */
/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/

bool isLeapYear(int year)
{
	return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

int getNumDays(int year, int month)
{
	switch (month) {
	case 1: case 3: case 5: case 7: case 8: case 10: case 12:
		return 31;
		break;
	case 4: case 6: case 9: case 11:
		return 30;
		break;
	case 2:
		return 28 + isLeapYear(year);
		break;
	default:
		return -1;
		break;
	}
}