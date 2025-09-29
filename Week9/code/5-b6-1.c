//汤皓宇 计算机 2454307
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int cnt = 0;

int topA = 0, topB = 0, topC = 0;
int A[10], B[10], C[10];

void push(char code, int num)
{
	if (code == 'A')
		A[topA++] = num;
	if (code == 'B')
		B[topB++] = num;
	if (code == 'C')
		C[topC++] = num;
}

void pop(char code)
{
	if (code == 'A')
		topA--;
	if (code == 'B')
		topB--;
	if (code == 'C')
		topC--;
}

void formatOutput(int stack[], int top)
{
    int cnt = 0;
    while(cnt < top)
		printf("%2d", stack[cnt++]);
    while(cnt++ < 10)
		printf("  ");
}

void listABC()
{
	printf("A:");
	formatOutput(A, topA);
	printf(" B:");
	formatOutput(B, topB);
	printf(" C:");
	formatOutput(C, topC);
	printf("\n");
}

void hanoi(int n, char src, char tmp, char dst)
{
    if (n == 0)
        return;
    hanoi(n - 1, src, dst, tmp);
    pop(src);
	push(dst, n);
    printf("第%4d 步(%2d): %c-->%c ", ++cnt, n, src, dst);
    listABC();
    hanoi(n - 1, tmp, src, dst);
}

int main()
{
    int n;
    char src, tmp, dst;
    while (1) {
        printf("请输入汉诺塔的层数(1-10)\n");
        int ret = scanf("%d", &n);
        while (getchar() != '\n')
            ; // 清空输入缓冲区
        if (ret == 1) {
            if (n >= 1 && n <= 10)
                break;
        }
    }
    while (1) {
        printf("请输入起始柱(A-C)\n");
        int ret = scanf(" %c", &src);
        while (getchar() != '\n')
            ; // 清空输入缓冲区
        if (ret == 1) {
            if (src >= 'a' && src <= 'c')
                src -= 32;
            if (src >= 'A' && src <= 'C')
                break;
        }
    }
    while (1) {
        printf("请输入目标柱(A-C)\n");
        int ret = scanf(" %c", &dst);
        while (getchar() != '\n')
            ; // 清空输入缓冲区
        if (ret == 1) {
            if (dst >= 'a' && dst <= 'c')
                dst -= 32;
            if (dst >= 'A' && dst <= 'C' && dst != src)
                break;
        }
    }
    tmp = 'A' + 'B' + 'C' - src - dst;
    for (int i = n; i > 0; i--)
        push(src, i);
    printf("初始:                ");
	listABC();
    hanoi(n, src, tmp, dst);
    return 0;
}
