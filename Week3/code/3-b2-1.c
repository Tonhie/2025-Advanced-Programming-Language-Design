//软件 汤皓宇 2454307

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
    int n;
    printf("请输入一个[1..30000]间的整数:\n");
    scanf("%d", &n);
    printf("万位 : %d\n", n / 10000);
    n %= 10000;
    printf("千位 : %d\n", n / 1000);
    n %= 1000;
    printf("百位 : %d\n", n / 100);
    n %= 100;
    printf("十位 : %d\n", n / 10);
    n %= 10;
    printf("个位 : %d\n", n);
    return 0;
}
