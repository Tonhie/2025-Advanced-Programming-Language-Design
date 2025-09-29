//软件 汤皓宇 2454307

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

int main()
{
    double n;
    printf("请输入[0-100亿)之间的数字:\n");
    scanf("%lf", &n);
    n += 0.009;
    printf("十亿位 : %d\n", (int)(n / (int)1e9));
    n -= (int)(n / (int)1e9) * 1e9;
    printf("亿位   : %d\n", (int)(n / (int)1e8));
    n -= (int)(n / (int)1e8) * 1e8;
    printf("千万位 : %d\n", (int)(n / (int)1e7));
    n -= (int)(n / (int)1e7) * 1e7;
    printf("百万位 : %d\n", (int)(n / (int)1e6));
    n -= (int)(n / (int)1e6) * 1e6;
    printf("十万位 : %d\n", (int)(n / (int)1e5));
    n -= (int)(n / (int)1e5) * 1e5;
    printf("万位   : %d\n", (int)(n / (int)1e4));
    n -= (int)(n / (int)1e4) * 1e4;
    printf("千位   : %d\n", (int)(n / (int)1e3));
    n -= (int)(n / (int)1e3) * 1e3;
    printf("百位   : %d\n", (int)(n / (int)1e2));
    n -= (int)(n / (int)1e2) * 1e2;
    printf("十位   : %d\n", (int)(n / (int)1e1));
    n -= (int)(n / (int)1e1) * 1e1;
    printf("圆     : %d\n", (int)n);
    n -= (int)(n);
    printf("角     : %d\n", (int)(n * 10));
    n -= (int)(n * 10) * 0.1;
    printf("分     : %d\n", (int)(n * 100));

    return 0;
}
