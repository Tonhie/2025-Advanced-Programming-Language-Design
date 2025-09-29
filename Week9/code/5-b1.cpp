//汤皓宇 计算机 2454307

# include <iostream>
using namespace std;

int main()
{
	cout << "请输入任意个正整数（升序，最多20个），0或负数结束输入" << endl;
	int n = 0, nums[20];
	while (n < 20) {
		int tmp;
		cin >> tmp;
		if (tmp <= 0)
			break;
		nums[n++] = tmp;
	}
	cin.clear();
	cin.ignore(1024, '\n');
	if (n == 0) {
		cout << "无有效输入" << endl;
		return 0;
	}
	cout << "原数组为：" << endl;
	for (int i = 0; i < n; i++)
		cout << nums[i] << " ";
	cout << endl;
	cout << "请输入要插入的正整数" << endl;
	int ins;
	cin >> ins;
	cout << "插入后的数组为：" << endl;
	if (ins < nums[0])
		cout << ins << " ";
	cout << nums[0] << " ";
	for (int i = 1; i < n; i++) {
		if (nums[i - 1] < ins && ins < nums[i])
			cout << ins << " ";
		cout << nums[i] << " ";
	}
	cout << endl;
	return 0;
}