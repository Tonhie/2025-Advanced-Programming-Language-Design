//汤皓宇 计算机 2454307

#include <iostream>
#include <iomanip>
using namespace std;

int cnt = 0;

int top[3] = { 0, 0, 0 };
int stack[3][10];

void push(char code, int num)
{
    if (code == 'A')
		stack[0][top[0]++] = num;
    if (code == 'B')
		stack[1][top[1]++] = num;
    if (code == 'C')
		stack[2][top[2]++] = num;
}

void pop(char code)
{
    if (code == 'A')
		top[0]--;
    if (code == 'B')
		top[1]--;
	if (code == 'C')
		top[2]--;
}

void formatOutput(int stack[], int top)
{
    int cnt = 0;
    while (cnt < top)
		cout << setw(2) << stack[cnt++];
    while (cnt++ < 10)
		cout << "  ";
}

void listABC()
{
	cout << "A:";
    formatOutput(stack[0], top[0]);
	cout << " B:";
	formatOutput(stack[1], top[1]);
	cout << " C:";
	formatOutput(stack[2], top[2]);
	cout << endl;
}

void hanoi(int n, char src, char tmp, char dst)
{
    if (n == 0)
        return;
    hanoi(n - 1, src, dst, tmp);
    pop(src);
    push(dst, n);
	cout << "第" << setw(4) << ++cnt << " 步(" << setw(2) << n << "): " << src << "-->" << dst << " ";
    listABC();
    hanoi(n - 1, tmp, src, dst);
}

int main()
{
    int n;
    char src, tmp, dst;
    while (true) {
        cout << "请输入汉诺塔的层数(1-10)" << endl;
        cin >> n;
        bool ret = cin.good();
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        if (ret) {
            if (n >= 1 && n <= 10)
                break;
        }
    }
    while (true) {
        cout << "请输入起始柱(A-C)" << endl;
        cin >> src;
        bool ret = cin.good();
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        if (ret) {
            if (src >= 'a' && src <= 'c')
                src -= 32;
            if (src >= 'A' && src <= 'C')
                break;
        }
    }
    while (true) {
        cout << "请输入目标柱(A-C)" << endl;
        cin >> dst;
        bool ret = cin.good();
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        if (ret) {
            if (dst >= 'a' && dst <= 'c')
                dst -= 32;
            if (dst >= 'A' && dst <= 'C' && dst != src)
                break;
        }
    }
    tmp = 'A' + 'B' + 'C' - src - dst;
    for (int i = n; i > 0; i--)
        push(src, i);
	cout << "初始:                ";
    listABC();
    hanoi(n, src, tmp, dst);
    return 0;
}
