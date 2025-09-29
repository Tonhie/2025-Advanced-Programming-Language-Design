//汤皓宇 计算机 2454307

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <windows.h> //取系统时间
using namespace std;

int main()
{
	LARGE_INTEGER tick, begin, end;

	QueryPerformanceFrequency(&tick);	//获得计数器频率
	QueryPerformanceCounter(&begin);	//获得初始硬件计数器计数

	/* 此处是你的程序开始 */
	int cnt = 0;
	for(int n1 = 1; n1 <= 9; n1 ++) {
		for(int n2 = 1; n2 <= 9; n2 ++) {
			if(n2 == n1)
				continue;
			for(int n3 = 1; n3 <= 9; n3 ++) {
				if(n3 == n1 || n3 == n2)
					continue;
				int sum1 = n1 * 100 + n2 * 10 + n3;
				for(int p1 = n1 + 1; p1 <= 9; p1 ++) {
					if(p1 == n1 || p1 == n2 || p1 == n3)
						continue;
					for(int p2 = 1; p2 <= 9; p2 ++) {
						if(p2 == p1 || p2 == n1 || p2 == n2 || p2 == n3)
							continue;
						for(int p3 = 1; p3 <= 9; p3 ++) {
							if(p3 == p1 || p3 == p2 || p3 == n1 || p3 == n2 || p3 == n3)
								continue;
							int sum2 = p1 * 100 + p2 * 10 + p3;
							for(int q1 = p1 + 1; q1 <= 9; q1 ++) {
								if(q1 == p1 || q1 == p2 || q1 == p3 || q1 == n1 || q1 == n2 || q1 == n3)
									continue;
								for(int q2 = 1; q2 <= 9; q2 ++) {
									if(q2 == q1 || q2 == p1 || q2 == p2 || q2 == p3 || q2 == n1 || q2 == n2 || q2 == n3) continue;
									for(int q3 = 1; q3 <= 9; q3 ++) {
										if(q3 == q1 || q3 == q2 || q3 == p1 || q3 == p2 || q3 == p3 || q3 == n1 || q3 == n2 || q3 == n3) continue;
										int sum3 = q1 * 100 + q2 * 10 + q3;
										if(sum1 + sum2 + sum3 == 1953)
											cout << "No." << setw(3) << ++cnt << " : " << sum1 << "+" << sum2 << "+" << sum3 << "=1953" << endl;
									}
								}
							}
						}
					}
				}
			}
		}
	}
	/* 此处是你的程序结束 */

	QueryPerformanceCounter(&end);		//获得终止硬件计数器计数

	cout << "计数器频率 : " << tick.QuadPart << "Hz" << endl;
	cout << "计数器计数 : " << end.QuadPart - begin.QuadPart << endl;
	cout << setiosflags(ios::fixed) << setprecision(6) << double(end.QuadPart - begin.QuadPart) / tick.QuadPart << "秒" << endl;

	return 0;
}
