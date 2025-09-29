/* 学号 姓名 班级 */
#pragma once

/* --- 如果有需要的头文件、命令空间，写于此处 --- */

/* --- 如果有需要的宏定义、只读全局变量等，写于此处 --- */

/* --- 如果有其它全局函数需要声明，写于此处 --- */
bool isLeapYear(int year);
int getNumDays(int year, int month);

/* 补全Date类的定义，所有成员函数均体外实现，不要在此处体内实现 */
class Date {
private:
	int year;
	int month;
	int day;
	/* 不允许添加数据成员 */
	void fix(int& year, int& month, int& day);

public:
	/* 根据需要定义所需的成员函数、友元函数等(不允许添加数据成员) */
	Date() : year(2000), month(1), day(1) {}
	Date(int year, int month, int day);
	Date(int days);
	void set(int year = 2000, int month = 1, int day = 1);
	void get(int &year, int &month, int &day);
	void show();
};
