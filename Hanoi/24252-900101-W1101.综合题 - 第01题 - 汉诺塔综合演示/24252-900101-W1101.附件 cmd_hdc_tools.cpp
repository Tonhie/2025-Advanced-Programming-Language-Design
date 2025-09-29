/* -----------------------------------------

	 本文件不需要提交、不允许改动

   ----------------------------------------- */

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <Windows.h>
#include "cmd_hdc_tools.h"
#include "cmd_console_tools.h"
//using namespace std;

extern "C" WINBASEAPI HWND WINAPI GetConsoleWindow(); //VS中此处会有波浪线，不影响正常使用

/* 已定义的静态全局变量 */
static HWND hWnd = GetConsoleWindow();
static HDC hdc = NULL;
static int _BgColor_, _FgColor_, _Width_, _High;

/***************************************************************************
  函数名称：
  功    能：在(x1,y1)-(x2,y2)之间画出一个像素点的连线
  输入参数：const int x1：起点x坐标，左上角为(0,0)
		   const int y1：起点y坐标，左上角为(0,0)
		   const int x2：终点y坐标，左上角为(0,0)
		   const int y2：终点y坐标，左上角为(0,0)
  返 回 值：
  说    明：颜色直接用当前设定
***************************************************************************/
static void hdc_base_line(int x1, int y1, const int x2, const int y2)
{
	MoveToEx(hdc, x1, y1, NULL);
	LineTo(hdc, x2 + 1, y2 + 1);
#if 0
	if (x1 == x2 && y1 == y2) { //一个点的情况
		LineTo(hdc, x2 + 1, y2 + 1);
	}
	else if (x1 == x2 && abs(y1 - y2) == 1) { // 上下两个点的情况
		LineTo(hdc, x2 + 1, y2 + 1);
	}
	else if (abs(x1-x2)==1 && y1 == y2) {	//左右两个点的情况
		LineTo(hdc, x2 + 1, y2 + 1);
	}
	else
		LineTo(hdc, x2 + 1, y2 + 1);
#endif
}

/***************************************************************************
  函数名称：
  功    能：初始化
  输入参数：const int bgcolor：背景色
            const int fgcolor：前景色
			const int width  ：屏幕宽度（点阵）
			const int high   ：屏幕高度（点阵）
  返 回 值：
  说    明：
***************************************************************************/
void hdc_init(const int bgcolor, const int fgcolor, const int width, const int high)
{
	/* 先释放，防止不release而再次init（hdc_release可重入） */
	hdc_release();

	/* 窗口init后，用一个静态全局量记录，后续hdc_cls()会用到 */
	_BgColor_ = bgcolor;
	_FgColor_ = fgcolor;
	_Width_ = width;
	_High = high;

	hdc = GetDC(hWnd);
//	cct_setcursor(CURSOR_INVISIBLE);
//	cct_setcolor(bgcolor, fgcolor);
//	cct_setfontsize("新宋体", 16);
//	cct_setconsoleborder(width / 8 + !!(width % 8), high / 16 + !!(high % 16)); //将点阵的宽度及高度转换为特定字体的行列数，!!的含义：如果不是8/16的倍数，行列多+1
//	cct_cls();
}
/***************************************************************************
  函数名称：
  功    能：释放画图资源
  输入参数：
  返 回 值：
  说    明：可重入
***************************************************************************/
void hdc_release()
{
	if (hdc) {
		ReleaseDC(hWnd, hdc);
		hdc = NULL;
//		cct_setcursor(CURSOR_VISIBLE_NORMAL);
	}
}

/***************************************************************************
  函数名称：
  功    能：设置画笔颜色，传入RGB值
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
void hdc_set_pencolor(const int RGB_value)
{
	SelectObject(hdc, GetStockObject(DC_PEN));
	SetDCPenColor(hdc, RGB_value);
}

/***************************************************************************
  函数名称：
  功    能：设置画笔颜色，传入RGB三色，值0-255
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
void hdc_set_pencolor(const unsigned char red, const unsigned char green, const unsigned char blue)
{
	hdc_set_pencolor(RGB(red, green, blue));
}

/***************************************************************************
  函数名称：
  功    能：清除屏幕上现有的图形
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/

void hdc_cls()
{
    /* 发现一定要换一种颜色初始化才能清除像素点，找到更简便方法的同学可以通知我 */
	hdc_init(_BgColor_, (_FgColor_ + 1)%16, _Width_, _High);

	/* 在thdc_init中会修改_FgColor_的值，因此先+1，再+15，正好保持thdc_cls前的颜色 */
	hdc_init(_BgColor_, (_FgColor_ + 15)%16, _Width_, _High);

	/* 部分机器上运行demo时，会出现hdc_cls()后第一根线有缺线的情况，加延时即可
	   如果部分机器运行还有问题，调高此延时值 */
	Sleep(30);
}

/***************************************************************************
  函数名称：
  功    能：给出左上角坐标及宽度、高度，画出一个长方形
  输入参数：const int left_up_x			：左上角x
			const int left_up_y			：左上角y
		   const int width			：宽度
		   const int high				：高度
		   bool filled				：是否需要填充（默认填充）
		   const int RGB_value			：颜色（默认值则不改变）
  返 回 值：
  说    明：
***************************************************************************/
void hdc_rectangle(const int x1, const int y1, const int width, const int high, const int RGB_value)
{
	const int x2 = x1 + (width < 1 ? 1 : width) - 1;	//最小宽度为1
	const int y2 = y1 + (high < 1 ? 1 : high) -1;		//最小高度为1

	/* 如果坐标没有在 hdc_init 初始化的区间内，则直接返回 */
	if (x1 < 0 || x1 >= _Width_ || x2 < 0 || x2 >= _Width_ || y1 < 0 || y1 >= _High || y2 < 0 || y2 >= _High)
		return;

	/* 如果给了新的颜色，则需要设置 */
	if (RGB_value != INVALID_RGB)
		hdc_set_pencolor(RGB_value);

#if 1
	for (int y = y1; y <= y2; y++) {
		MoveToEx(hdc, x1, y, NULL);
		LineTo(hdc, x2+1, y);
	}
#elif 0
	if (abs(x1-x2)<=abs(y1-y2)) {
		/* 用y1~y2条竖线模拟画出矩形 */
		for (int i = x1; i <= x2; i++) {
			MoveToEx(hdc, x1, y1, NULL);
			LineTo(hdc, x2 + 1, y2 + 1);
//			hdc_base_line(i, y1, i, y2);
		}
	}
	else {
		/* 用y1~y2条横线模拟画出矩形 */
		for (int i = y1; i <= y2; i++) {
			MoveToEx(hdc, x1, y1, NULL);
			LineTo(hdc, x2 + 1, y2 + 1);
//			hdc_base_line(x1, i, x2, i);
		}
	}
#elif 0
	/* 如果x1==x2，此时矩形变为一个宽度为1的直线，要特殊处理 */
	if (x1 == x2) {
		hdc_base_line(x1, y1, x2, y2);
	}
	else {
		/* 用y1~y2条横线模拟画出矩形 */
		for (int i = y1; i <= y2; i++)
			hdc_base_line(x1, i, x2, i);
	}
#endif
}
