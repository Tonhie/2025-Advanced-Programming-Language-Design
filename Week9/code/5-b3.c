//汤皓宇 计算机 2454307

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int isLeapYear(int year) {
	return (year % 4 == 0 && year % 100 != 0 || year % 400 == 0);
}

int getDay(int month, int day, int days[]) {
	int ans = 0;
	for (int i = 1; i < month; i++)
		ans += days[i];
	ans += day;
	return ans;
}

int main()
{
	int days[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    int year, month, day;
    printf("请输入年，月，日\n");
    scanf("%d %d %d", &year, &month, &day);
    if (month > 12 || month < 1) {
        printf("输入错误-月份不正确\n");
        return 0;
    }
	days[2] += isLeapYear(year);
	if (day > days[month] || day < 1) {
		printf("输入错误-日与月的关系非法\n");
		return 0;
	}
    printf("%d-%d-%d是%d年的第%d天\n", year, month, day, year, getDay(month, day, days));

    return 0;
}
