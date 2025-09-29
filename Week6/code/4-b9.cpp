//汤皓宇 计算机 2454307

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
//#include <Windows.h>
using namespace std;

long long cnt = 0; // 统计函数调用次数
/***************************************************************************
  函数名称：
  功    能：返回fibonacci数列的第n项的值
  输入参数：
  返 回 值：
  说    明：不允许任何形式的循环出现
***************************************************************************/
int fibonacci(int n)
{
  cnt ++;
    if(n == 1 || n == 2)
        return 1;
    return fibonacci(n - 1) + fibonacci(n - 2);
}
/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：main函数不允许修改
***************************************************************************/
int main()
{/*
	int n, f;
	cout << "请输入Fibonacci数列的项数[1-46]" << endl;
	cin >> n;

	LARGE_INTEGER tick, begin, end;
	QueryPerformanceFrequency(&tick);	//获得时钟频率
	QueryPerformanceCounter(&begin);	//获得初始硬件定时器计数
	f = fibonacci(n);
	cout << "Fibonacci数列第" << n << "项的值 : " << f << endl;

	QueryPerformanceCounter(&end);//获得终止硬件定时器计数
	cout << "计数器频率 : " << tick.QuadPart << "Hz" << endl;
	cout << "计数器计数 : " << end.QuadPart - begin.QuadPart << endl;
	cout << setiosflags(ios::fixed) << setprecision(6) << double(end.QuadPart - begin.QuadPart) / tick.QuadPart << "秒" << endl;
*/
  for(int i = 1; i <= 46; i ++) {
    cnt = 0;
    fibonacci(i);
    cout << "n=" << i << "时候，函数调用" << cnt << "次" << endl;
  }
  
	return 0;
}
