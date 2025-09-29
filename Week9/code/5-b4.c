//汤皓宇 计算机 2454307
# define _CRT_SECURE_NO_WARNINGS
# include <stdio.h>

void clearBuffer()
{
	char ch;
	while ((ch = getchar()) != '\n' && ch != EOF)
		;
}

int main()
{
	printf("请输入成绩（最多1000个），负数结束输入\n");
	int n = 0, score[1000], cnt[101];
	for(int i = 0; i <= 100; i ++)
		cnt[i] = 0;
	while (n < 1000) {
		int tmp;
		scanf("%d", &tmp);
		if (tmp < 0)
			break;
		score[n++] = tmp;
		cnt[tmp]++;
	}
	clearBuffer();
	if (n == 0) {
		printf("无有效输入\n");
		return 0;
	}
	printf("输入的数组为:");
	for (int i = 0; i < n; i++) {
		if (i % 10 == 0)
			printf("\n");
		printf("%d ", score[i]);
	}
	printf("\n");
	printf("分数与人数的对应关系为:\n");
	for (int i = 100; i >= 0; i--) {
		if (cnt[i] == 0)
			continue;
		printf("%d %d\n", i, cnt[i]);
	}
	return 0;
}