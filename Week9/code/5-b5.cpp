//汤皓宇 计算机 2454307
# include <iostream>
using namespace std;
int main()
{
	cout << "请输入成绩（最多1000个），负数结束输入" << endl;
	int n = 0, score[1000], cnt[101];
	for (int i = 0; i <= 100; i++)
		cnt[i] = 0;
	while (n < 1000) {
		int tmp;
		cin >> tmp;
		if (tmp < 0)
			break;
		score[n++] = tmp;
		cnt[tmp]++;
	}
	cin.clear();
	cin.ignore(10000, '\n');
	if (n == 0) {
		cout << "无有效输入" << endl;
		return 0;
	}
	cout << "输入的数组为:";
	for (int i = 0; i < n; i++) {
		if (i % 10 == 0)
			cout << endl;
		cout << score[i] << " ";
	}
	cout << endl << "分数与名次的对应关系为:" << endl;
	int rank = 0;
	for (int i = 100; i >= 0; i--) {
		if (cnt[i] == 0)
			continue;
		for (int j = 0; j < cnt[i]; j++)
			cout << i << " " << rank + 1 << endl;
		rank += cnt[i];
	}
	return 0;
}