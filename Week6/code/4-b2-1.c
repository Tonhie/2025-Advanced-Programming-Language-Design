//汤皓宇 计算机 2454307

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int validCheck(int year, int month, int day)
{
    if(year < 1900 || year > 2100) {
        printf("年份不正确，请重新输入\n");
        return 0;
    }
    int tmp = (year % 4 == 0 && year % 100 != 0 || year % 400 == 0);
    if(month > 12 || month < 1) {
        printf("月份不正确, 请重新输入\n");
        return 0;
    }
    switch(month) {
    case 1:
        if(day > 31 || day < 1) {
            printf("日不正确, 请重新输入\n");
            return 0;
        }
        break;
    case 2:
        if(day > 28 + tmp || day < 1) {
            printf("日不正确, 请重新输入\n");
            return 0;
        }
        break;
    case 3:
        if(day > 31 || day < 1) {
            printf("日不正确, 请重新输入\n");
            return 0;
        }
        break;
    case 4:
        if(day > 30 || day < 1) {
            printf("日不正确, 请重新输入\n");
            return 0;
        }
        break;
    case 5:
        if(day > 31 || day < 1) {
            printf("日不正确, 请重新输入\n");
            return 0;
        }
        break;
    case 6:
        if(day > 30 || day < 1) {
            printf("日不正确, 请重新输入\n");
            return 0;
        }
        break;
    case 7:
        if(day > 31 || day < 1) {
            printf("日不正确, 请重新输入\n");
            return 0;
        }
        break;
    case 8:
        if(day > 31 || day < 1) {
            printf("日不正确, 请重新输入\n");
            return 0;
        }
        break;
    case 9:
        if(day > 30 || day < 1) {
            printf("日不正确, 请重新输入\n");
            return 0;
        }
        break;
    case 10:
        if(day > 31 || day < 1) {
            printf("日不正确, 请重新输入\n");
            return 0;
        }
        break;
    case 11:
        if(day > 30 || day < 1) {
            printf("日不正确, 请重新输入\n");
            return 0;
        }
        break;
    case 12:
        if(day > 31 || day < 1) {
            printf("日不正确, 请重新输入\n");
            return 0;
        }
        break;
    }
    return 1;
}

int zeller(int y, int m, int d) {
    if(m == 1 || m == 2) {
        m += 12;
        y--;
    }
    int c = y / 100;
    y = y % 100;
    return (y + y / 4 + c / 4 - 2 * c + 26 * (m + 1) / 10 + d - 1 + 7) % 7;
}

int main()
{
    int year, month, day;
    while(1) {
        printf("请输入年[1900-2100]、月、日：\n");
        if(scanf("%d %d %d", &year, &month, &day) == 3) {
            if(validCheck(year, month, day))
                break;
        } else {
            int ch;
            while((ch = getchar()) != '\n' && ch != EOF);
            printf("输入错误，请重新输入\n");
        }
    }
    switch(zeller(year, month, day)) {
        case 1:
            printf("星期一\n");
            break; 
        case 2:
            printf("星期二\n");
            break;
        case 3:
            printf("星期三\n");
            break;
        case 4:
            printf("星期四\n");
            break;
        case 5:
            printf("星期五\n");
            break;
        case 6:
            printf("星期六\n");
            break;
        case 0:
            printf("星期日\n");
            break;
    }
    return 0;
}
