//汤皓宇 计算机 2454307

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <limits>
using namespace std;

int main()
{
	int x;

	while (1) {
		cout << "请输入x的值[0-100] : ";
        if(cin >> x) {
            if (x >= 0 && x <= 100)
                break;
        } else {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
	}

	cout << "cin.good()=" << cin.good() <<  " x=" << x << endl; //此句不准动，并且要求输出时good为1

	return 0;
}
