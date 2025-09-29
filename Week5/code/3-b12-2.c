//汤皓宇 计算机 2454307

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int ret, x;

	while (1) {
		printf("请输入x的值[0-100] : ");
		if (scanf("%d", &x)) {
			if(x >= 0 && x <= 100)
				break;
		} else {
			char ch;
			while ((ch = getchar()) != '\n' && ch != EOF)
				;
		}
		printf("输入有错[ret=%d x=%d],请重新输入\n", ret, x); //确认一下，ret的值（即scanf的返回值）是什么含义？ 
	}

	printf("ret=%d x=%d\n", ret, x);

	return 0;
}

