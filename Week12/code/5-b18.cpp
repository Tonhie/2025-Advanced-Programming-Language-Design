//ÌÀğ©Óî ¼ÆËã»ú 2454307
# include <iostream>
# include <ctime>
using namespace std;

static const char other[] = "!@#$%^&*-_=+,.?";

int main() {
	srand(static_cast<unsigned int>(time(0)));
	char str[256];
	cin.getline(str, 256, '\n');
	int len, nUp, nLo, nNu, nOt;
	cin >> len >> nUp >> nLo >> nNu >> nOt;
	cin.ignore(256, '\n');
	if (!cin.good()) {
		cout << "´íÎó" << endl;
		return 0;
	}
	if (len < 12 || len > 16) {
		cout << "´íÎó" << endl;
		return 0;
	}
	if (nUp < 2) {
		cout << "´íÎó" << endl;
		return 0;
	}
	if (nLo < 2) {
		cout << "´íÎó" << endl;
		return 0;
	}
	if (nNu < 2) {
		cout << "´íÎó" << endl;
		return 0;
	}
	if (nOt < 2) {
		cout << "´íÎó" << endl;
		return 0;
	}
	if (nUp + nLo + nNu + nOt > len) {
		cout << "´íÎó" << endl;
		return 0;
	}
	char passwd[10][17];
	bool isCorrect = true;
	for (int i = 0; i < 10; i++)
		cin.getline(passwd[i], 17, '\n');
	for (int i = 0; i < 10; i++) {
		if (strlen(passwd[i]) != len) {
			isCorrect = false;
			break;
		}
		int cntUp = 0, cntLo = 0, cntNu = 0, cntOt = 0;
		for (int j = 0; j < len; j++) {
			if (passwd[i][j] >= char('A') && passwd[i][j] <= char('Z'))
				cntUp++;
			if (passwd[i][j] >= char('a') && passwd[i][j] <= char('z'))
				cntLo++;
			if (passwd[i][j] >= char('0') && passwd[i][j] <= char('9'))
				cntNu++;
			for (size_t k = 0; k < strlen(other); k++) {
				if (passwd[i][j] == other[k])
					cntOt++;
			}
		}
		if (cntUp < nUp || cntLo < nLo || cntNu < nNu || cntOt < nOt) {
			isCorrect = false;
			break;
		}
	}
	cout << (isCorrect ? "ÕıÈ·" : "´íÎó") << endl;
	return 0;
}