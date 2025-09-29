//汤皓宇 计算机 2454307
/* 2454308 陈书玥 2451751 周晋烜 2451747 赵信博 2453200 王何君 2454326 李一芃 2451752 李镕琪 */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	char map[10][26];

	for (int i = 0; i < 10; ) {
		int j = 0;
		while(j < 26) {
			char ch = getchar();
			if(ch != ' ' && ch != '\n')
				map[i][j++] = ch;
		}
		i++;
	}

	int cntAll = 0;
	int dir[8][2] = { {0, 1}, {1, 0}, {1, 1}, {0, -1}, {-1, 0}, {-1, -1}, {-1, 1}, {1, -1} };
	int wrong = 0;
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 26; j++) {
			if (map[i][j] == '*') {
				cntAll++;
				continue;
			}
			int cnt = 0;
			for (int k = 0; k < 8; k++) {
				int i1 = i + dir[k][0];
				int j1 = j + dir[k][1];
				if (i1 < 0 || i1 >= 10)
					continue;
				if (j1 < 0 || j1 >= 26)
					continue;
				cnt += (map[i1][j1] == '*');
			}
			if (cnt != map[i][j] - '0')
				wrong = 1;
		}
	}
	if (cntAll != 50) {
		printf("错误1\n");
		return 0;
	}
	if (wrong) {
		printf("错误2\n");
		return 0;
	}
	printf("正确\n");
	return 0;
}