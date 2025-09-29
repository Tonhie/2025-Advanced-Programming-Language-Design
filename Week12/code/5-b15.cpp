//汤皓宇 计算机 2454307

# include <iostream>
using namespace std;

int main() {
	char str[3][128];
	cout << "请输入第1行" << endl;
	cin.getline(str[0], 128, '\n');
	cout << "请输入第2行" << endl;
	cin.getline(str[1], 128, '\n');
	cout << "请输入第3行" << endl;
	cin.getline(str[2], 128, '\n');
	int cntUp = 0, cntDn = 0, cntNu = 0, cntEm = 0, cntOt = 0;
	for (int i = 0; i < 3; i++) {
		int p = 0;
		while (str[i][p] != '\0' && p < 128) {
			if (str[i][p] >= 'A' && str[i][p] <= 'Z')
				cntUp++;
			else if (str[i][p] >= 'a' && str[i][p] <= 'z')
				cntDn++;
			else if (str[i][p] >= '0' && str[i][p] <= '9')
				cntNu++;
			else if (str[i][p] == ' ')
				cntEm++;
			else
				cntOt++;
			p++;
		}
	}
	cout << "大写 : " << cntUp << endl;
	cout << "小写 : " << cntDn << endl;
	cout << "数字 : " << cntNu << endl;
	cout << "空格 : " << cntEm << endl;
	cout << "其它 : " << cntOt << endl;
	return 0;
}