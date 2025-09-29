//汤皓宇 计算机 2454307
#include <iostream>
using namespace std;

/* 1、不允许定义任何类型的全局变量，包括常变量及宏定义等
   2、不允许给出任何形式的全局函数
*/

/* --- 将类的定义补充完整 --- */
class Days {
private:
	int year;
	int month;
	int day;
	//除上面的三个private数据成员外，不再允许添加任何类型的数据成员

	/* 下面可以补充需要的类成员函数的定义（不提供给外界，仅供本类的其它成员函数调用，因此声明为私有，数量不限，允许不定义） */

public:
	int calc_days();     //计算是当年的第几天

	/* 下面可以补充其它需要的类成员函数的定义(体外实现)，数量不限，允许不定义 */
	Days(int year, int month, int day);
};

/* --- 此处给出类成员函数的体外实现 --- */

Days::Days(int year, int month, int day)
{
	this->year = year;
	this->month = month;
	this->day = day;
}

int Days::calc_days()
{
	if (year < 1 || month < 1 || month > 12)
		return -1;
	bool is_leap_year = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
	int days_in_month[] = { 31, is_leap_year ? 29 : 28, 31, 30, 31, 30,
							 31, 31, 30, 31, 30, 31 };
	if (day < 1 || day > days_in_month[month - 1])
		return -1;
	int total_days = day;
	for (int m = 0; m < month - 1; ++m)
		total_days += days_in_month[m];
	return total_days;
}
/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：main函数不准动
 ***************************************************************************/
int main()
{
	if (1) {
		Days d1(2024, 3, 18);
		cout << "应该输出78， 实际是：" << d1.calc_days() << endl;
	}

	if (1) {
		Days d1(2023, 3, 18);
		cout << "应该输出77， 实际是：" << d1.calc_days() << endl;
	}

	if (1) {
		Days d1(2024, 12, 31);
		cout << "应该输出366，实际是：" << d1.calc_days() << endl;
	}

	if (1) {
		Days d1(2023, 12, 31);
		cout << "应该输出365，实际是：" << d1.calc_days() << endl;
	}

	if (1) {
		Days d1(2024, 2, 29);
		cout << "应该输出60， 实际是：" << d1.calc_days() << endl;
	}

	if (1) {
		Days d1(2023, 2, 29);
		cout << "应该输出-1， 实际是：" << d1.calc_days() << endl;
	}

	return 0;
}
