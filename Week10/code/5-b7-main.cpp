//汤皓宇 计算机 2454307

# include "5-b7.h"

#include <iostream>
#include <iomanip>
#include <windows.h>
#include <conio.h>
#include <limits>
using namespace std;

int cnt = 0;

int topA = 0, topB = 0, topC = 0;
int stackA[10], stackB[10], stackC[10];

bool showStack;
int delay;

void Delay()
{
    const int delays[6] = { -1, 1000, 500, 200, 50, 0 };
    if (delay == 0) {
        while (true) {
            char ch = _getch();
            if (ch == 13)
                return;
        }
    }
    Sleep(delays[delay]);
}

void push(char code, int num)
{
    if (code == 'A')
        stackA[topA++] = num;
    if (code == 'B')
        stackB[topB++] = num;
    if (code == 'C')
        stackC[topC++] = num;
}

void pop(char code)
{
    if (code == 'A')
        topA--;
    if (code == 'B')
        topB--;
    if (code == 'C')
        topC--;
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
    formatOutput(stackA, topA);
    cout << " B:";
    formatOutput(stackB, topB);
    cout << " C:";
    formatOutput(stackC, topC);
    cout << endl;
}

void printInit()
{
    if (!showStack)
        return;
    int initx = 0, inity = 20;
    cct_gotoxy(initx, inity + 4);
    cout << "初始:                ";
    listABC();
    Delay();
}

void printInfo(int n, char src, char dst)
{
    int initx = 0, inity = 20;
    cct_gotoxy(initx, inity + 4);
    cout << "第" << setw(4) << ++cnt << " 步(" << setw(2) << n << "): " << src << "-->" << dst << " ";
    if (showStack)
        listABC();
    Delay();
}

void graphABC()
{
    int initx = 10, inity = 15;
    cct_gotoxy(initx, inity + 1);
    cout << "=====================";
    cct_gotoxy(initx, inity + 2);
    cout << "   A      B      C   ";
    for (int i = 0; i < 10; i++) {
        cct_gotoxy(initx + 2, inity - i);
        if (i < topA)
            cout << setw(2) << stackA[i];
        else
            cout << "  ";
    }
    for (int i = 0; i < 10; i++) {
        cct_gotoxy(initx + 9, inity - i);
        if (i < topB)
            cout << setw(2) << stackB[i];
        else
            cout << "  ";
    }
    for (int i = 0; i < 10; i++) {
        cct_gotoxy(initx + 16, inity - i);
        if (i < topC)
            cout << setw(2) << stackC[i];
        else
            cout << "  ";
    }
    Delay();
}

void hanoi(int n, char src, char tmp, char dst)
{
    if (n == 0)
        return;
    hanoi(n - 1, src, dst, tmp);
    pop(src);
    push(dst, n);
    printInfo(n, src, dst);
    graphABC();
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
        cin.ignore(1024, '\n');
        if (ret && n >= 1 && n <= 10)
            break;
    }
    while (true) {
        cout << "请输入起始柱(A-C)" << endl;
        cin >> src;
        bool ret = cin.good();
        cin.clear();
        cin.ignore(1024, '\n');
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
        cin.ignore(1024, '\n');
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
    while (true) {
        cout << "请输入移动速度(0-5: 0-按回车单步演示 1-延时最长 5-延时最短)" << endl;
        cin >> delay;
        bool ret = cin.good();
        cin.clear();
        cin.ignore(1024, '\n');
        if (ret && 0 <= delay && delay <= 5)
            break;
    }
    while (true) {
        cout << "请输入是否显示内部数组值(0-不显示 1-显示)" << endl;
        int tmp;
        cin >> tmp;
        bool ret = cin.good();
        cin.clear();
        cin.ignore(1024, '\n');
        if (ret && (0 == tmp || tmp == 1)) {
            showStack = tmp;
            break;
        }
    }
    cct_cls();
    cout << "从 " << src << " 移动到 " << dst << "，";
    cout << "共 " << n << " 层，";
    cout << "延时设置为 " << delay << "，";
    cout << (showStack ? "显示" : "不显示") << "内部数组值";
    printInit();
    graphABC();
    hanoi(n, src, tmp, dst);
    system("pause");
    return 0;
}
