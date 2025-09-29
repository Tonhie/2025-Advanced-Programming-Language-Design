//汤皓宇 计算机 2454307


/* ----------------------------------------------------------------------------------

     本文件功能：
	1、放main函数
	2、初始化屏幕
	3、调用菜单函数（hanoi_menu.cpp中）并返回选项
	4、根据选项调用菜单各项对应的执行函数（hanoi_multiple_solutions.cpp中）

     本文件要求：
	1、不允许定义全局变量（含外部全局和静态全局，const及#define不在限制范围内）
	2、静态局部变量的数量不限制，但使用准则也是：少用、慎用、能不用尽量不用
	3、按需加入系统头文件、自定义头文件、命名空间等

   ----------------------------------------------------------------------------------- */

# include "hanoi.h"

# include <iostream>
# include <conio.h>
using namespace std;

# define showStep option[0]
# define showHor option[1]
# define showVer option[2]
# define showGraph option[3]

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int main()
{
	cout << "请确认当前cmd窗口的大小为40行*120列以上，字体为新宋体/16，按C继续，Q退出" << endl;
	while (1) {
		char ch = _getch();
		if (ch == 'C' || ch == 'c')
			break;
		if (ch == 'Q' || ch == 'q')
			return 0;
	}
	
	while (true) {
		switch (Menu()) {
		case 0:
			return 0;
		case 1:
			hanoi_basic();
			break;
		case 2:
			hanoi_basic_step_record();
			break;
		case 3:
			hanoi_array_display_horizontal();
			break;
		case 4:
			hanoi_array_display_vertical_horizontal();
			break;
		case 5:
			hanoi_graphics_prepare_draw_cylinders();
			break;
		case 6:
			hanoi_graphics_prepare_draw_disks();
			break;
		case 7:
			hanoi_graphics_first_move();
			break;
		case 8:
			hanoi_graphics_auto_move();
			break;
		case 9:
			hanoi_graphics_game();
			break;
		}
	}
	return 0;
}