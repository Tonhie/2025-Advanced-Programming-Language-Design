//汤皓宇 计算机 2454307
# include <iostream>
# include <ctime>
using namespace std;

static const char other[] = "!@#$%^&*-_=+,.?";

int main() {
	srand(static_cast<unsigned int>(time(0)));
	int len, nUp, nLo, nNu, nOt;
	cout << "请输入密码长度(12-16)， 大写字母个数(≥2)， 小写字母个数(≥2)， 数字个数(≥2)， 其它符号个数(≥2)" << endl;
	cin >> len >> nUp >> nLo >> nNu >> nOt;
	if (!cin.good()) {
		cout << "输入非法" << endl;
		return 0;
	}
	if (len < 12 || len > 16) {
		cout << "密码长度[" << len << "]不正确" << endl;
		return 0;
	}
	if (nUp < 2) {
		cout << "大写字母个数[" << nUp << "]不正确" << endl;
		return 0;
	}
	if (nLo < 2) {
		cout << "小写字母个数[" << nLo << "]不正确" << endl;
		return 0;
	}
	if (nNu < 2) {
		cout << "数字个数[" << nNu << "]不正确" << endl;
		return 0;
	}
	if (nOt < 2) {
		cout << "其它符号个数[" << nOt << "]不正确" << endl;
		return 0;
	}
	int d = len - (nUp + nLo + nNu + nOt);
	if (d < 0) {
		cout << "所有字符类型之和[" <<
				nUp << "+" << nLo << "+" << 
				nNu << "+" << nOt << 
				"]大于总密码长度[" << len << "]" << endl;
		return 0;
	}
	cout << len << ' ' << nUp << ' ' << nLo << ' ' << nNu << ' ' << nOt << endl;;
	char passwd[10][17];
	for (int i = 0; i < 10; i++) {
		int cnt = 0;
		for (int k = 0; k < nUp + (d > 0); k++)
			passwd[i][cnt++] = 'a' + rand() % 26;
		for (int k = 0; k < nLo + (d > 1); k++)
			passwd[i][cnt++] = 'A' + rand() % 26;
		for (int k = 0; k < nNu + (d > 2); k++)
			passwd[i][cnt++] = '0' + rand() % 9;
		for (int k = 0; k < nOt + (d > 3); k++)
			passwd[i][cnt++] = other[rand() % 15];
		for (int x = 0; x < len; x++) {
			int y = x + rand() % (len - x);
			char tmp = passwd[i][x];
			passwd[i][x] = passwd[i][y];
			passwd[i][y] = tmp;
		}
		passwd[i][cnt] = '\0';
	}
	for (int i = 0; i < 10; i++)
		printf("%s\n", passwd[i]);
	return 0;
}