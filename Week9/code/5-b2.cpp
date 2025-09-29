//ÌÀğ©Óî ¼ÆËã»ú 2454307

# include <iostream>
using namespace std;

int main() {
	bool lamp[101];
	int ans[100], len = 0;
	for(int i = 1; i <= 100; i ++)
		lamp[i] = false;
	for (int i = 1; i <= 100; i++)
		for (int j = i; j <= 100; j += i)
			lamp[j] = !lamp[j];
	for (int i = 1; i <= 100; i++)
		if (lamp[i])
			ans[len++] = i;
	for (int i = 0; i < len - 1; i++)
		cout << ans[i] << " ";
	cout << ans[len - 1] << endl;
	return 0;
}