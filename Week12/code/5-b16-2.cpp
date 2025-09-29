//汤皓宇 计算机 2454307

#define _CRT_SECURE_NO_WARNINGS
# include <cstring>
# include <iostream>
using namespace std;

void input(string code[], string name[], int score[]) {
	for (int i = 0; i < 10; i++) {
		cout << "请输入第" << i + 1 << "个人的学号、姓名、成绩" << endl;
		cin >> code[i] >> name[i] >> score[i];
	}
}

void arrange(string code[], string name[], int score[]) {
	for (int i = 0; i < 10; i++) {
		int min = i;
		for (int j = i + 1; j < 10; j++) {
			if (score[min] > score[j])
				min = j;
		}
		if (min != i) {
			string tmp = code[min];
			code[min] = code[i];
			code[i] = tmp;

			tmp = name[min];
			name[min] = name[i];
			name[i] = tmp;

			int tmps = score[min];
			score[min] = score[i];
			score[i] = tmps;
		}
	}
}

void output(string code[], string name[], int score[]) {
	cout << "不及格名单(成绩升序):" << endl;;
	for (int i = 0; i < 10; i++) {
		if (score[i] >= 60)
			continue;
		cout << name[i] << ' ' << code[i] << ' ' << score[i] << endl;
	}
}

int main() {
	string name[10], code[10];
	int score[10] = { 0 };
	input(code, name, score);
	arrange(code, name, score);
	output(code, name, score);
	return 0;
}