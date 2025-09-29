//汤皓宇 计算机 2454307

#include <iostream>
#include <iomanip>
using namespace std;

bool judge(int matrix[9][9]) {
	bool ans = true;
	for (int i = 0; i < 9; i++) {
		bool flagx[10], flagy[10];
		for (int k = 1; k <= 9; k++)
			flagx[k] = flagy[k] = false;
		for (int j = 0; j < 9; j++) {
			if (flagx[matrix[i][j]] || flagy[matrix[j][i]]) {
				ans = false;
				break;
			}
			flagx[matrix[i][j]] = true;
			flagy[matrix[j][i]] = true;
		}
	}
	return ans;
}

int main()
{
	cout << "请输入9*9的矩阵，值为1-9之间" << endl;
	int matrix[9][9];
	for (int i = 0; i < 9; i++)
		for (int j = 0; j < 9; j++) {
			while (true) {
				cin >> matrix[i][j];
				if (cin.good()) {
					if (matrix[i][j] >= 1 && matrix[i][j] <= 9)
						break;
				} else {
					cin.clear();
					cin.ignore(1024, '\n');
					cout << "请重新输入第" << i + 1 << "行" << "第" << j + 1 << "列(行列均从1开始计数)的值" << endl;
				}
				
			}
		}
	cout << (judge(matrix) ? "是数独的解" : "不是数独的解") << endl;
	return 0;
}