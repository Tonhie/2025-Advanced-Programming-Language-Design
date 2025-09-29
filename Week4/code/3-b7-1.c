//汤皓宇 计算机 2454307

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main ()
{
    float money;
    printf("请输入找零值：\n");
    scanf("%f", &money);
    money += 0.001f;
    int v50, v20, v10, v5, v1, v05, v01, v005, v002, v001;
    v50 = (int)(money / 50);
    money -= v50 * 50;
    v20 = (int)(money / 20);
    money -= v20 * 20;
    v10 = (int)(money / 10);
    money -= v10 * 10;
    v5 = (int)(money / 5);
    money -= v5 * 5;
    v1 = (int)(money);
    money -= v1;
    v05 = (int)(money / 0.5f);
    money -= v05 * 0.5f;
    v01 = (int)(money / 0.1f);
    money -= v01 * 0.1f;
    v005 = (int)(money / 0.05f);
    money -= v005 * 0.05f;
    v002 = (int)(money / 0.02f);
    money -= v002 * 0.02f;
    v001 = (int)(money / 0.01f);
    printf("共%d张找零，具体如下：\n", v50 + v20 + v10 + v5 + v1 + v05 + v01 + v005 + v002 + v001);
    if(v50)
        printf("50元 : %d\n", v50);
    if(v20)
        printf("20元 : %d\n", v20);
    if(v10)
        printf("10元 : %d\n", v10);
    if(v5)
        printf("5元  : %d\n", v5);
    if(v1)
        printf("1元  : %d\n", v1);
    if(v05)
        printf("5角  : %d\n", v05);
    if(v01)
        printf("1角  : %d\n", v01);
    if(v005)
        printf("5分  : %d\n", v005);
    if(v002)
        printf("2分  : %d\n", v002);
    if(v001)
        printf("1分  : %d\n", v001);
    return 0;
}
