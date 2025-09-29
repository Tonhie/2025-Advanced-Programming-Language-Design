//汤皓宇 计算机 2454307

#define _CRT_SECURE_NO_WARNINGS
# include <string.h>
# include <stdio.h>

void input(char code[][8], char name[][9], int score[]) {
	for (int i = 0; i < 10; i++) {
		printf("请输入第%d个人的学号、姓名、成绩\n", i + 1);
		int ret = scanf("%s %s %d", code[i], name[i], &score[i]);
	}
}

int cmp(char a[], char b[]) {
	int end1 = 0, end2 = 0;
	while (a[end1] != '\0')
		end1++;
	while (b[end2] != '\0')
		end2++;
	if (end1 != end2)
		return end1 > end2 ? 1 : -1;
	for(int i = 0; i < end1; i ++)
		if (a[i] != b[i])
			return a[i] > b[i] ? 1 : -1;
	return 0;
}

void arrange(char code[][8], char name[][9], int score[]) {
	for (int i = 0; i < 10; i++) {
		int max = i;
		for (int j = i + 1; j < 10; j++) {
			if (cmp(code[max], code[j]) < 0)
				max = j;
		}
		if (max != i) {
			char tmpc[8];
			strcpy(tmpc, code[max]);
			strcpy(code[max], code[i]);
			strcpy(code[i], tmpc);
			char tmpn[9];
			strcpy(tmpn, name[max]);
			strcpy(name[max], name[i]);
			strcpy(name[i], tmpn);
			int tmps = score[max];
			score[max] = score[i];
			score[i] = tmps;
		}
	}
}

void output(char code[][8], char name[][9], int score[]) {
	printf("及格名单(学号降序):\n");
	for (int i = 0; i < 10; i++) {
		if (score[i] < 60)
			continue;
		printf("%s %s %d\n", name[i], code[i], score[i]);
	}
}

int main() {
	char name[10][9], code[10][8];
	int score[10] = { 0 };
	input(code, name, score);
	arrange(code, name, score);
	output(code, name, score);
	return 0;
}