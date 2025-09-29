//软件 汤皓宇 2454307

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
    double R, H;
    const double Pi = 3.14159;
    printf("请输入半径和高度\n");
    scanf("%lf %lf", &R, &H);
    printf("圆周长     : %.2f\n", 2 * Pi * R);
    printf("圆面积     : %.2f\n", Pi * R * R);
    printf("圆球表面积 : %.2f\n", 4 * Pi * R * R);
    printf("圆球体积   : %.2f\n", 4 * Pi * R * R * R / 3);
    printf("圆柱体积   : %.2f\n", Pi * R * R * H);
    return 0;
}
