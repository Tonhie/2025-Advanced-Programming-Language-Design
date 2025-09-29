//汤皓宇 计算机 2454307

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
//可按需增加需要的头文件

const char chnstr[] = "零壹贰叁肆伍陆柒捌玖"; /* 所有输出大写 "零" ~ "玖" 的地方，只允许从这个数组中取值 */
char result[256];  /* 除result外，不再允许定义任何形式的全局变量 */

/* --允许添加需要的函数 --*/

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int main()
{
    /* --允许添加需要的内容 --*/
    double n;
    while (1) {
        printf("请输入[0-100亿)之间的数字:\n");
        int ret = scanf("%lf", &n);
        n += 0.001;
        if (ret == 1) {
            if (n >= 0 && n < 1e10)
                break;
        }
        else
            while (getchar() != '\n')
                ;
    }

    int tmp1 = 0, tmp2 = 0, tmp3 = 0, tmp4 = 0, pre = 0;
    tmp3 = (int)(n / (int)1e9);
    n -= (int)(n / (int)1e9) * 1e9;
    tmp4 = (int)(n / (int)1e8);
    n -= (int)(n / (int)1e8) * 1e8;

    if (tmp3) {
        strncat(result, chnstr + tmp3 * 2, 2);
        strcat(result, "拾");
    }
    pre = pre | tmp3;
    if(tmp4)
        strncat(result, chnstr + tmp4 * 2, 2);
    pre = pre | tmp4;
    if (tmp3 || tmp4)
        strcat(result, "亿");
    tmp1 = (int)(n / (int)1e7);
    n -= (int)(n / (int)1e7) * 1e7;
    tmp2 = (int)(n / (int)1e6);
    n -= (int)(n / (int)1e6) * 1e6;
    tmp3 = (int)(n / (int)1e5);
    n -= (int)(n / (int)1e5) * 1e5;
    tmp4 = (int)(n / (int)1e4);
    n -= (int)(n / (int)1e4) * 1e4;
    if (tmp1) {
        strncat(result, chnstr + tmp1 * 2, 2);
        strcat(result, "仟");
    }
    else if(pre && tmp2) {
        strncat(result, chnstr, 2);
        pre = 0;
    }
    pre = pre | tmp1;
    if (tmp2) {
        strncat(result, chnstr + tmp2 * 2, 2);
        strcat(result, "佰");
    }
    else if(pre && tmp3) {
        pre = 0;
        strncat(result, chnstr, 2);
    }
    pre = pre | tmp2;
    if (tmp3) {
        strncat(result, chnstr + tmp3 * 2, 2);
        strcat(result, "拾");
    }
    else if(pre && tmp4) {
        pre = 0;
        strncat(result, chnstr, 2);
    }
    pre = pre | tmp3;
    if(tmp4)
        strncat(result, chnstr + tmp4 * 2, 2);
    pre = pre | tmp4;
    if (tmp1 || tmp2 || tmp3 || tmp4)
        strcat(result, "万");
    pre = pre | tmp4;

    tmp1 = (int)(n / (int)1e3);
    n -= (int)(n / (int)1e3) * 1e3;
    tmp2 = (int)(n / (int)1e2);
    n -= (int)(n / (int)1e2) * 1e2;
    tmp3 = (int)(n / (int)1e1);
    n -= (int)(n / (int)1e1) * 1e1;
    tmp4 = (int)(n);
    n -= (int)(n);

    if (tmp1) {
        strncat(result, chnstr + tmp1 * 2, 2);
        strcat(result, "仟");
    }
    else if (pre && tmp2) {
        strncat(result, chnstr, 2);
        pre = 0;
    }
    pre = pre | tmp1;
    if (tmp2) {
        strncat(result, chnstr + tmp2 * 2, 2);
        strcat(result, "佰");
    }
    else if (pre && tmp3) {
        strncat(result, chnstr, 2);
        pre = 0;
    }
    pre = pre | tmp2;
    if (tmp3) {
        strncat(result, chnstr + tmp3 * 2, 2);
        strcat(result, "拾");
    }
    else if (pre && tmp4) {
        strncat(result, chnstr, 2);
        pre = 0;
    }
    pre = pre | tmp3;
    if(tmp4)
        strncat(result, chnstr + tmp4 * 2, 2);
    pre = pre | tmp4;
    if (pre)
        strcat(result, "圆");
    tmp1 = (int)(n * 10);
    n -= (int)(n * 10) * 0.1;
    tmp2 = (int)(n * 100);
    if (!tmp1 && !tmp2) {
        if (!pre)
            strcat(result, "零圆");
        strcat(result, "整");
    }
    if (tmp1) {
        strncat(result, chnstr + tmp1 * 2, 2);
        strcat(result, "角");
        if(!tmp2) 
            strcat(result, "整");
    }
    if (tmp2) {
        if (!tmp1 && pre)
            strncat(result, chnstr, 2);
        strncat(result, chnstr + tmp2 * 2, 2);
        strcat(result, "分");
    }

    printf("大写结果是:\n");
    printf("%s\n", result);  /* 转换得到的大写结果，只允许用本语句输出，其它地方不允许以任何形式对大写结果进行全部/部分输出 */
    return 0;
}