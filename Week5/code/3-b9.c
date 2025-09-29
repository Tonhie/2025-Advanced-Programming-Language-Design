//ÌÀğ©Óî ¼ÆËã»ú 2454307

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
    for(int i = 1; i <= 9; i ++) {
        for(int a = 1; a <= i; a ++)
            printf("%dx%d=%-3d", a, i, a * i);
        printf("\n");
    }
    return 0;
}
