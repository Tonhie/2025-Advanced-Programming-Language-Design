//陈书玥 2454308 交通
#include <iostream>
#include <ctime>
using namespace std;

int main() {
	srand((unsigned int)(time(0)));
	int i, j;
	int length, upper, lower, num, other_2;
	static const char other[] = "!@#$%^&*-_=+,.?";
	cout << "请输入密码长度(12-16)， 大写字母个数(≥2)， 小写字母个数(≥2)， 数字个数(≥2)， 其它符号个数(≥2)" << endl;
	cin >> length >> upper >> lower >> num >> other_2;
	if (cin.good() == 0) {
		cout << "输入非法" << endl;
		return 0;
	}
	if ((length > 16) || (length < 12)) {
		cout << "密码长度[" << length << "]不正确" << endl;
		return 0;
	}
	if ((upper < 2) || (upper > length)) {
		cout << "大写字母个数[" << upper << "]不正确" << endl;
		return 0;
	}
	if ((lower < 2) || (lower > length)) {
		cout << "小写字母个数[" << lower << "]不正确" << endl;
		return 0;
	}
	if ((num < 2) || (num > length)) {
		cout << "数字个数[" << num << "]不正确" << endl;
		return 0;
	}
	if ((other_2 < 2) || (other_2 > length)) {
		cout << "其它符号个数[" << other_2 << "]不正确" << endl;
		return 0;
	}
	if ((upper + lower + num + other_2) > length) {
		cout << "所有字符类型之和[" << upper << '+' << lower << '+' << num << '+' << other_2 << "]大于总密码长度[" << length << "]" << endl;
		return 0;
	}
	cout << length << ' ' << upper << ' ' << lower << ' ' << num << ' ' << other_2 << endl;
	for(int x=0;x<10;x++)
	{
		char code[16] = { 0 };
		int arror = 0;
		for (i = 0; i < upper; i++) {
			j = rand() % 26;
			j = j + 'A';
			code[arror] = char(j);
			arror++;
		}
		for (i = 0; i < lower; i++) {
			j = rand() % 26;
			j = j + 'a';
			code[arror] = char(j);
			arror++;
		}
		for (i = 0; i < num; i++) {
			j = rand() % 10;
			j = j + '0';
			code[arror] = char(j);
			arror++;
		}
		for (i = 0; i < other_2; i++) {
			j = rand() % 15;
			code[arror] = other[j];
			arror++;
		}
		for (i = 0; i < (length - upper - lower - num - other_2); i++) {
			j = rand() % 94;
			j = j + 33;
			code[arror] = char(j);
			arror++;
		}
		for (int i = length-1; i > 0; i--) {
			int j = rand() % (i + 1);
			swap(code[i], code[j]);
		}
		for (i = 0; i < length; i++)
			cout << code[i];
		cout << endl;
	}
	return 0;
}