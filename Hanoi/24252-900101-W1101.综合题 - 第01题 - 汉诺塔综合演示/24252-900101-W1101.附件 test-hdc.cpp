/* -----------------------------------------

	 本文件不需要提交、不允许改动

   ----------------------------------------- */

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <conio.h>
#include <Windows.h>
using namespace std;

#include "cmd_hdc_tools.h"
#include "cmd_console_tools.h"

/***************************************************************************
  函数名称：
  功    能：显示提示信息
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
static void to_be_continued(const char prompt[], const int pos_x = 0, const int pos_y = 22)
{
	cct_gotoxy(pos_x, pos_y);
	
	//因为每次都从22行0列，如果本次打印内容比上次短，后面会有残留，因此先用100个空格填充掉（未做准确判断，简单假设打印内容不超过100）
	cout << setw(100) << ' ' << '\r'; //'\r'表示回到本行开头，不换行
	cout << prompt << "，按回车键继续...";

	/* 忽略除回车键外的所有输入（注意：_getch的回车是\r，而getchar是\n）*/
	while (_getch() != '\r')
		;

	return;
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int main(int argc, char** argv)
{
	const int   win_width = 1400, win_high = 900;	//设定屏幕宽度
	const int   win_bgcolor = 7, win_fgcolor = 0;
	const int   color[] = { 0x00FF0000, 0x0000FF00, 0x000000FF }; //R G B

	hdc_init(win_bgcolor, win_fgcolor, win_width, win_high);		//用(背景色，前景色，宽度，高度）初始化窗口
	hdc_cls();

	to_be_continued("1、正常图形显示(先调整cmd窗口字体为新宋体16点阵，屏幕大小30行*120列以上)");
	if (1) {
		/* 正常矩形 */
		hdc_rectangle(100, 101, 400, 20, color[0]);
		hdc_rectangle(100, 121, 400, 20, color[1]);
		hdc_rectangle(100, 141, 400, 20, color[2]);
		to_be_continued("宽度400，高度20的三个矩形显示完成");

		/* 横向的直线，高度为1/2/3 */
		hdc_rectangle(100, 200, 400, 1, color[1]);
		hdc_rectangle(100, 210, 400, 2, color[1]);
		hdc_rectangle(100, 220, 400, 3, color[1]);
		to_be_continued("宽度400，高度1/2/3的横线显示完成");

		/* 纵向的直线，宽度为1/2/3 */
		hdc_rectangle(520, 101, 1, 60, color[1]);
		hdc_rectangle(530, 101, 2, 60, color[1]);
		hdc_rectangle(540, 101, 3, 60, color[1]);
		to_be_continued("宽度1/2/3，高度60的竖线显示完成");

		/* 7个1*1/1*2/2*1/2*2的点 */
		hdc_rectangle(520, 210, 1, 1, color[1]);
		hdc_rectangle(520, 214, 1, 2, color[1]);
		hdc_rectangle(524, 210, 1, 2, color[1]);
		hdc_rectangle(520, 218, 2, 1, color[1]);
		hdc_rectangle(528, 210, 2, 1, color[1]);
		hdc_rectangle(520, 222, 2, 2, color[1]);
		hdc_rectangle(532, 210, 2, 2, color[1]);
		to_be_continued("1*1/1*2/2*1/2*2的7个点显示完成");

		/* 6个1*3/3*1/3*3的点 */
		hdc_rectangle(520, 226, 1, 3, color[1]);
		hdc_rectangle(536, 210, 1, 3, color[1]);
		hdc_rectangle(520, 230, 3, 1, color[1]);
		hdc_rectangle(540, 210, 3, 1, color[1]);
		hdc_rectangle(520, 234, 3, 3, color[1]);
		hdc_rectangle(544, 210, 3, 3, color[1]);
		to_be_continued("1*3/3*1/3*3的6个点显示完成");
	}

	if (1) {
		/* 清除屏幕 */
		cct_cls();
		hdc_cls();

		cct_gotoxy(0, 0);
		cout << "2、图形文字混合：先文字，再图形，再文字" << endl; //0行
		cout << "\t2-1、先上部显示文字" << endl;
		cout << "\t2-2、下部显示图形" << endl;
		cout << "\t2-3、再上部显示文字（不跨越图形区）" << endl;
		to_be_continued("准备开始", 0, 4);

		cct_gotoxy(10, 5);
		cout << "Hello" << endl;
		Sleep(1000);
		hdc_rectangle(100, 200, 400, 60, color[0]);
		Sleep(1000);
		cct_gotoxy(20, 6);
		cout << "World" << endl;
		to_be_continued("测试完成", 0, 7);
	}

	if (1) {
		/* 清除屏幕 */
		cct_cls();
		hdc_cls();

		cct_gotoxy(0, 10);
		cout << "3、图形文字混合：先文字，再图形，再文字" << endl; //10行
		cout << "\t3-1、先下部显示文字" << endl;
		cout << "\t3-2、上部显示图形" << endl;
		cout << "\t3-3、再下部显示文字（不跨越图形区）" << endl;
		to_be_continued("准备开始", 0, 14);

		cct_gotoxy(10, 15);
		cout << "Hello" << endl;
		Sleep(1000);
		hdc_rectangle(100, 50, 400, 60, color[1]);
		Sleep(1000);
		cct_gotoxy(20, 16);
		cout << "World" << endl;
		to_be_continued("测试完成", 0, 17);
	}

	if (1) {
		/* 清除屏幕 */
		cct_cls();
		hdc_cls();

		cct_gotoxy(0, 0);
		cout << "4、图形文字混合：先文字，再图形，再文字" << endl; //0行
		cout << "\t4-1、先显示文字" << endl;
		cout << "\t4-2、和文字重叠的部分显示图形" << endl;
		cout << "\t4-3、再图形重叠位置显示文字" << endl;
		to_be_continued("准备开始", 0, 4);

		cct_gotoxy(0, 8);
		cout << "Hello";
		Sleep(1000); //停顿1秒，方便看清
		hdc_rectangle(100, 101, 400, 80, color[1]);
		Sleep(1000); //停顿1秒，方便看清
		cout << "World" << endl; //在上次光标的位置后面继续显示
		to_be_continued("测试完成");
	}

	if (1) {
		/* 清除屏幕 */
		cct_cls();
		hdc_cls();

		cct_gotoxy(0, 0);
		cout << "5、图形文字混合：先文字，再图形，再文字" << endl; //0行
		cout << "\t5-1、先上部显示文字" << endl;
		cout << "\t5-2、中部显示图形" << endl;
		cout << "\t5-3、再下部显示文字（光标跨越图形区）" << endl;
		to_be_continued("准备开始", 0, 4);

		cct_gotoxy(0, 5);
		cout << "Hello";
		Sleep(1000); //停顿1秒，方便看清
		hdc_rectangle(100, 120, 400, 80, color[1]);
		Sleep(1000); //停顿1秒，方便看清
		cct_gotoxy(20, 15);
		cout << "World";
		Sleep(1000); //停顿1秒，方便看清
		to_be_continued("测试完成", 0, 20);
	}


	to_be_continued("演示全部结束，记住结论：画图区域和文字输出区域不要有任何重叠，包括移动光标.\n\t注：如果测试5的图形没有消除，多跑几遍");
	cout << endl;

	hdc_release();

	return 0;
}
