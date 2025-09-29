//ÌÀð©Óî ¼ÆËã»ú 2454307

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

int main()
{
    double n;
    printf("ÇëÊäÈë[0-100ÒÚ)Ö®¼äµÄÊý×Ö:\n");
    scanf("%lf", &n);
    printf("´óÐ´½á¹ûÊÇ:\n");
    n += 0.009;
    int tmp1 = 0, tmp2 = 0, tmp3 = 0, tmp4 = 0, pre = 0;
    tmp3 = (int)(n / (int)1e9);
    n -= (int)(n / (int)1e9) * 1e9;
    tmp4 = (int)(n / (int)1e8);
    n -= (int)(n / (int)1e8) * 1e8;
    switch (tmp3) {
    case 1:
        printf("Ò¼");
        break;
    case 2:
        printf("·¡");
        break;
    case 3:
        printf("Èþ");
        break;
    case 4:
        printf("ËÁ");
        break;
    case 5:
        printf("Îé");
        break;
    case 6:
        printf("Â½");
        break;
    case 7:
        printf("Æâ");
        break;
    case 8:
        printf("°Æ");
        break;
    case 9:
        printf("¾Á");
        break;
    }
    if (tmp3)
        printf("Ê°");
    pre = pre || tmp3 ? 1 : 0;
    switch (tmp4) {
    case 1:
        printf("Ò¼");
        break;
    case 2:
        printf("·¡");
        break;
    case 3:
        printf("Èþ");
        break;
    case 4:
        printf("ËÁ");
        break;
    case 5:
        printf("Îé");
        break;
    case 6:
        printf("Â½");
        break;
    case 7:
        printf("Æâ");
        break;
    case 8:
        printf("°Æ");
        break;
    case 9:
        printf("¾Á");
        break;
    }
    pre = pre || tmp4 ? 1 : 0;
    if (tmp3 || tmp4)
        printf("ÒÚ");
    tmp1 = (int)(n / (int)1e7);
    n -= (int)(n / (int)1e7) * 1e7;
    tmp2 = (int)(n / (int)1e6);
    n -= (int)(n / (int)1e6) * 1e6;
    tmp3 = (int)(n / (int)1e5);
    n -= (int)(n / (int)1e5) * 1e5;
    tmp4 = (int)(n / (int)1e4);
    n -= (int)(n / (int)1e4) * 1e4;
    switch (tmp1) {
    case 1:
        printf("Ò¼");
        break;
    case 2:
        printf("·¡");
        break;
    case 3:
        printf("Èþ");
        break;
    case 4:
        printf("ËÁ");
        break;
    case 5:
        printf("Îé");
        break;
    case 6:
        printf("Â½");
        break;
    case 7:
        printf("Æâ");
        break;
    case 8:
        printf("°Æ");
        break;
    case 9:
        printf("¾Á");
        break;
    }
    if (tmp1)
        printf("Çª");
    if (!tmp1 && pre && tmp2) {
        printf("Áã");
        pre = 0;
    }
    pre = pre || tmp1 ? 1 : 0;
    switch (tmp2) {
    case 1:
        printf("Ò¼");
        break;
    case 2:
        printf("·¡");
        break;
    case 3:
        printf("Èþ");
        break;
    case 4:
        printf("ËÁ");
        break;
    case 5:
        printf("Îé");
        break;
    case 6:
        printf("Â½");
        break;
    case 7:
        printf("Æâ");
        break;
    case 8:
        printf("°Æ");
        break;
    case 9:
        printf("¾Á");
        break;
    }
    if (tmp2)
        printf("°Û");
    if (!tmp2 && pre && tmp3) {
        pre = 0;
        printf("Áã");
    }
    pre = pre || tmp2 ? 1 : 0;
    switch (tmp3) {
    case 1:
        printf("Ò¼");
        break;
    case 2:
        printf("·¡");
        break;
    case 3:
        printf("Èþ");
        break;
    case 4:
        printf("ËÁ");
        break;
    case 5:
        printf("Îé");
        break;
    case 6:
        printf("Â½");
        break;
    case 7:
        printf("Æâ");
        break;
    case 8:
        printf("°Æ");
        break;
    case 9:
        printf("¾Á");
        break;
    }
    if (tmp3)
        printf("Ê°");
    if (!tmp3 && pre && tmp4) {
        pre = 0;
        printf("Áã");
    }
    pre = pre || tmp3 ? 1 : 0;
    switch (tmp4) {
    case 1:
        printf("Ò¼");
        break;
    case 2:
        printf("·¡");
        break;
    case 3:
        printf("Èþ");
        break;
    case 4:
        printf("ËÁ");
        break;
    case 5:
        printf("Îé");
        break;
    case 6:
        printf("Â½");
        break;
    case 7:
        printf("Æâ");
        break;
    case 8:
        printf("°Æ");
        break;
    case 9:
        printf("¾Á");
        break;
    }
    pre = pre || tmp4 ? 1 : 0;
    if (tmp1 || tmp2 || tmp3 || tmp4)
        printf("Íò");
    pre = pre || tmp4 ? 1 : 0;
    tmp1 = (int)(n / (int)1e3);
    n -= (int)(n / (int)1e3) * 1e3;
    tmp2 = (int)(n / (int)1e2);
    n -= (int)(n / (int)1e2) * 1e2;
    tmp3 = (int)(n / (int)1e1);
    n -= (int)(n / (int)1e1) * 1e1;
    tmp4 = (int)(n);
    n -= (int)(n);
    switch (tmp1) {
    case 1:
        printf("Ò¼");
        break;
    case 2:
        printf("·¡");
        break;
    case 3:
        printf("Èþ");
        break;
    case 4:
        printf("ËÁ");
        break;
    case 5:
        printf("Îé");
        break;
    case 6:
        printf("Â½");
        break;
    case 7:
        printf("Æâ");
        break;
    case 8:
        printf("°Æ");
        break;
    case 9:
        printf("¾Á");
        break;
    }
    if (tmp1)
        printf("Çª");
    if (!tmp1 && pre && tmp2) {
        printf("Áã");
        pre = 0;
    }
    pre = pre || tmp1 ? 1 : 0;
    switch (tmp2) {
    case 1:
        printf("Ò¼");
        break;
    case 2:
        printf("·¡");
        break;
    case 3:
        printf("Èþ");
        break;
    case 4:
        printf("ËÁ");
        break;
    case 5:
        printf("Îé");
        break;
    case 6:
        printf("Â½");
        break;
    case 7:
        printf("Æâ");
        break;
    case 8:
        printf("°Æ");
        break;
    case 9:
        printf("¾Á");
        break;
    }
    if (tmp2)
        printf("°Û");
    if (!tmp2 && pre && tmp3) {
        printf("Áã");
        pre = 0;
    }
    pre = pre || tmp2 ? 1 : 0;
    switch (tmp3) {
    case 1:
        printf("Ò¼");
        break;
    case 2:
        printf("·¡");
        break;
    case 3:
        printf("Èþ");
        break;
    case 4:
        printf("ËÁ");
        break;
    case 5:
        printf("Îé");
        break;
    case 6:
        printf("Â½");
        break;
    case 7:
        printf("Æâ");
        break;
    case 8:
        printf("°Æ");
        break;
    case 9:
        printf("¾Á");
        break;
    }
    if (tmp3)
        printf("Ê°");
    if (!tmp3 && pre && tmp4) {
        printf("Áã");
        pre = 0;
    }
    pre = pre || tmp3 ? 1 : 0;
    switch (tmp4) {
    case 1:
        printf("Ò¼");
        break;
    case 2:
        printf("·¡");
        break;
    case 3:
        printf("Èþ");
        break;
    case 4:
        printf("ËÁ");
        break;
    case 5:
        printf("Îé");
        break;
    case 6:
        printf("Â½");
        break;
    case 7:
        printf("Æâ");
        break;
    case 8:
        printf("°Æ");
        break;
    case 9:
        printf("¾Á");
        break;
    }
    pre = pre || tmp4 ? 1 : 0;
    if (pre)
        printf("Ô²");
    tmp1 = (int)(n * 10);
    n -= (int)(n * 10) * 0.1;
    tmp2 = (int)(n * 100);
    if (!tmp1 && !tmp2) {
        if (!pre)
            printf("ÁãÔ²");
        printf("Õû");
    }
    switch (tmp1) {
    case 1:
        printf("Ò¼");
        break;
    case 2:
        printf("·¡");
        break;
    case 3:
        printf("Èþ");
        break;
    case 4:
        printf("ËÁ");
        break;
    case 5:
        printf("Îé");
        break;
    case 6:
        printf("Â½");
        break;
    case 7:
        printf("Æâ");
        break;
    case 8:
        printf("°Æ");
        break;
    case 9:
        printf("¾Á");
        break;
    }
    if (tmp1)
        printf("½Ç");
    if (tmp1 && !tmp2)
        printf("Õû");
    if (!tmp1 && pre && tmp2)
        printf("Áã");
    switch (tmp2) {
    case 1:
        printf("Ò¼");
        break;
    case 2:
        printf("·¡");
        break;
    case 3:
        printf("Èþ");
        break;
    case 4:
        printf("ËÁ");
        break;
    case 5:
        printf("Îé");
        break;
    case 6:
        printf("Â½");
        break;
    case 7:
        printf("Æâ");
        break;
    case 8:
        printf("°Æ");
        break;
    case 9:
        printf("¾Á");
        break;
    }
    if (tmp2)
        printf("·Ö");
    printf("\n");
    return 0;
}