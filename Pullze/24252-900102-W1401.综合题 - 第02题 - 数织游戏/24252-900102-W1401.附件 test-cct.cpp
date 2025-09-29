/* -----------------------------------------

     本文件不需要提交、不允许改动

   ----------------------------------------- */
#include <iostream>
#include <iomanip>
#include <ctime>
#include <cmath>
#include <cstdio>
#include <conio.h>
#include <Windows.h>
#include "cmd_console_tools.h"
using namespace std;

/***************************************************************************
  函数名称：
  功    能：显示提示信息
  输入参数：
  返 回 值：
  说    明：如果读不懂，暂时放着，等指针和引用学习完成后再阅读
***************************************************************************/
static void to_be_continued(const char *prompt, const int X = 0, const int Y = 22)
{
	cct_setcolor(); //恢复缺省颜色
	cct_gotoxy(X, Y);

	if (prompt)
		cout << prompt << "，按回车键继续...";
	else
		cout << "按回车键继续...";

	/* 忽略除回车键外的所有输入（注意：_getch的回车是\r，而getchar是\n）*/
	while (_getch() != '\r')
		;

	cct_cls();

	return;
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：如果读不懂，暂时放着，等指针和引用学习完成后再阅读
***************************************************************************/
static void display_border(const char *prompt, int &cols, int &lines, int &buffer_cols, int &buffer_lines)
{
	int i;

	/* 取现有窗口的大小
	窗口的行列  ：显示窗口的大小
	缓冲区的行列：缓冲区的大小，当超过窗口行列时，会出现横向和纵向的滚动杆）*/
	cct_getconsoleborder(cols, lines, buffer_cols, buffer_lines);

	/* 显示0~5行 */
	cout << prompt << endl;
	cout << "  窗口的行  ：" << lines << endl;
	cout << "  窗口的列  ：" << cols << endl;
	cout << "  缓冲区的行：" << buffer_lines << endl;
	cout << "  缓冲区的列：" << buffer_cols << endl;
	cout << endl;

	/* 显示第6行：打印 01234567890123456789... */
	for (i = 0; i < buffer_cols; i++)
		cout << i % 10;

	/* 显示第7行：打印 0         1         ... */
	for (i = 0; i < buffer_cols; i += 10) {
		if (i < 100)
			cout << i / 10 << "         "; //9个空格
		else
			cout << i / 10 << "        "; //8个空格
	}

	/* 前面已显示0~7共8行，从第9行（编号8）开始
	   如果窗口有30行（0-29），最后一行是中文输入状态栏，如果是打开状态，则需要关闭 */
	for (i = 8; i < buffer_lines; i++) {
		cout << endl << "# " << i;		//先打印回车再打印行号，目的：1、和上面的内容空一行 2、最后一行后不能加回车，否则到中文输入栏就会滚屏
		if (i == buffer_lines - 1) //最后一行
			cout << " (编号是缓冲区行数-1)";
	}

	cct_gotoxy(0, 0);//光标回到窗口最左上方（此句不能省略，否则显示位置不正确）
	/* 如果有滚动条，给出提示 */
	if (cols < buffer_cols || lines < buffer_lines) {
		cct_gotoxy(10, 13);
		cout << "可以拖动滚动条来查看行号及列号";
	}

	return;
}

/***************************************************************************
  函数名称：
  功    能：先输出当前字体的信息，再随便输出一些内容
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int output_something()
{
	cout << "**************************" << endl;
	cout << "abcdefghijklmnopqrstuvwxyz" << endl;
	cout << "今天天气真好" << endl;
	cout << "**************************" << endl;
	return 0;
}

/***************************************************************************
  函数名称：
  功    能：在指定位置，用指定颜色，显示一个字符若干次
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int main()
{
	/* 初始设置：新字体，16点阵，窗口120*30
	   注意：如果既要设置窗口大小，又要设置字体，则必须先窗口再字体 */
	cct_setfontsize("新宋体", 16); //Truetype字体只需要给出一个参数高度即可
	cct_setconsoleborder(120, 30);
	to_be_continued("cmd_console_tools函数集演示开始", 0, 0);

	if (1) {
		int x, y;

		/* 显示16*16的配色框，每个字符之间加一个空格 */
		for (y = 0; y < 16; y++) {
			for (x = 0; x < 16; x++)
				cct_showch(x * 2, y, 'x', y, x, 2);	//在xy位置显示x，用x坐标的值做前景色，y坐标的值做背景色（显示两个x是为了使比例协调，可以换成一个x后观察效果）
			cout << endl; //16个前景色变换完成后，换一行
			Sleep(100);  //延时0.1秒（以毫秒为单位，1000=1秒）
		} //end of for

		to_be_continued("配色显示演示完成");
	}

	if (1) {
		const int MAX_X = 50;
		const int Y = 2;
		const int bg_color = COLOR_HYELLOW;	//背景为亮黄色
		const int fg_color = COLOR_HBLUE;		//前景为亮蓝色
		const char ch = '*';        //字符为*(注意：如果是空格，则前景色无法显示)
		const int LENGTH = 10;
		int x;

		/* 将一串字符从左向右移动 */
		for (x = 0; x < MAX_X; x++) {
			/* 在坐标(x,2)位置处连续打印10个字符 */
			cct_showch(x, Y, ch, bg_color, fg_color, LENGTH);

			/* 延时0.1秒 */
			Sleep(100);

			if (x < MAX_X - 1) {
				/* 清除显示(最后一次保留)，清除方法为用正常颜色+空格重画一遍刚才的位置 */
				cct_showch(x, Y, ' ', COLOR_BLACK, COLOR_WHITE, LENGTH);
			}
		} //end of for

		to_be_continued("右移特效完成");
	}

	if (1) {
		const int MAX_Y = 12;
		const int X = 2;
		const int bg_color = COLOR_HYELLOW;	//背景为亮黄色
		const int fg_color = COLOR_HBLUE;	//前景为亮蓝色
		const char ch = '*';        //字符为*(注意：如果是空格，则前景色无法显示)
		const int LENGTH = 10;
		int y;

		/* 将一串字符从上向下移动 */
		for (y = 2; y < MAX_Y; y++) {
			/* 在坐标(x,2)位置处连续打印10个字符 */
			cct_showstr(X, y, "ABCDE", bg_color, fg_color, 2);

			/* 延时0.3秒 */
			Sleep(300);

			if (y < MAX_Y - 1) {
				/* 清除显示(最后一次保留)，清除方法为用正常颜色+空格重画一遍刚才的位置 */
				cct_showch(X, y, ' ', COLOR_BLACK, COLOR_WHITE, LENGTH);
			}
		} //end of for

		to_be_continued("下移特效完成");
	}

	if (1) {
		/* 在屏幕的[0,0]-[60,20]区域内随机显示100个字符，值随机，颜色随机
		说明：未判断位置重复，可能最终字符数少于100
		未判断前景色/背景色重复，可能某些位置只看到颜色，看不到字符 */
		const int MAX_X = 60, MAX_Y = 20;
		int x, y, fg_color, bg_color, num;
		char ch;

		srand((unsigned int)(time(0))); //生成种子

		for (num = 0; num < 100; num++) {
			x = rand() % (MAX_X + 1);
			y = rand() % (MAX_Y + 1);
			fg_color = rand() % 16;
			bg_color = rand() % 16;
			ch = 33 + rand() % 94;   //ASCII码表中33-126为可见图形字符

			/* 显示一个1 */
			cct_showch(x, y, ch, bg_color, fg_color, 1);

			/* 延时0.05秒 */
			Sleep(50);
		}  //end of for

		to_be_continued("随机字符演示完成");
	}

	if (1) {
		int cur_cols, cur_lines, cur_buffer_cols, cur_buffer_lines;
		int cols, lines, buffer_cols, buffer_lines;
		//		int i;

		to_be_continued("为保证显示正确，如果窗口最下方的中文输入法处于打开状态，则用CTRL+SPACE关闭", 0, 0);

		/* 恢复为初始颜色 */
		cct_setcolor();
		/* 取现有窗口的大小
			窗口的行列  ：显示窗口的大小
			缓冲区的行列：缓冲区的大小，当超过窗口行列时，会出现横向和纵向的滚动杆）*/
		display_border("读取的现窗口的宽度与高度值（与\"属性\"菜单-\"布局\"卡片中的值相同）", cols, lines, buffer_cols, buffer_lines);

		/* 保留现值，用于恢复 */
		cur_cols = cols;
		cur_lines = lines;
		cur_buffer_cols = buffer_cols;
		cur_buffer_lines = buffer_lines;

		to_be_continued("改变窗口的宽度与高度-显示现窗口值完成", 10, 15);

		/* 改变输出窗口的大小 */
		cct_setconsoleborder(100, 45);
		display_border("设置新窗口的宽度与高度（45行*100列，缓冲区值相同，此时横向和纵向滚动杆均无）", cols, lines, buffer_cols, buffer_lines);
		to_be_continued("改变窗口的宽度与高度-设置新值1完成", 10, 15);

		/* 改变输出窗口的大小 */
		cct_setconsoleborder(80, 25, 80, 250);
		display_border("设置新窗口的宽度与高度（25行*80列，缓冲区250行*80列，此时应仅有纵向滚动杆）", cols, lines, buffer_cols, buffer_lines);
		to_be_continued("改变窗口的宽度与高度-设置新值2完成", 10, 15);

		/* 改变输出窗口的大小 */
		cct_setconsoleborder(85, 33, 120, 150);
		display_border("设置新窗口的宽度与高度（33行*85列，缓冲区150行*120列，横向和纵向滚动杆均有）", cols, lines, buffer_cols, buffer_lines);
		to_be_continued("改变窗口的宽度与高度-设置新值3完成", 10, 15);

		cct_setconsoleborder(cur_cols, cur_lines, cur_buffer_cols, cur_buffer_lines);
		to_be_continued("改变窗口的宽度与高度完成，已恢复为初始值");
	}

	if (1) {
		cct_setcursor(CURSOR_VISIBLE_FULL);
		to_be_continued("光标显示为全高色块", 0, 2);

		cct_setcursor(CURSOR_VISIBLE_HALF);
		to_be_continued("光标显示为半高色块", 0, 4);

		cct_setcursor(CURSOR_INVISIBLE);
		to_be_continued("关闭光标显示", 0, 6);

		cct_setcursor(CURSOR_VISIBLE_NORMAL);
		to_be_continued("光标显示为正常", 0, 8);

		to_be_continued("光标形状演示完成");
	}

	if (1) {
		char cur_title[256];
		cct_getconsoletitle(cur_title, sizeof(cur_title));
		cout << endl << endl << "当前窗口标题：" << cur_title << endl;
		to_be_continued("窗口标题读取完成");

		cct_setconsoletitle("测试标题名Hello");
		to_be_continued("窗口标题设置完成");

		cct_setconsoletitle(cur_title);
		to_be_continued("窗口标题读取与设置完成，已恢复初始值");
	}

	if (1) {
		int X = 0, Y = 0;
		int ret, maction;
		int keycode1, keycode2;
		int loop = 1;

		cct_enable_mouse();

		/* 打印初始光标位置[0,0] */
		cct_setcursor(CURSOR_INVISIBLE);	//关闭光标
		cout << "鼠标单击cmd窗口的左上角，打开的菜单中选择\"属性\" - \"选项\"卡片中进行如下操作：" << endl;
		cout << "    取消\"使用旧版控制台\"" << endl;
		cout << "    取消\"快速编辑模式\"" << endl;
		cout << "    取消\"插入模式\"" << endl;
		cout << endl << endl;
		cout << "可测试左键单/双击,右键单/双击,左右键同时单击五种，其中右键双击/ESC键结束测试" << endl;
		//		cout << "[当前鼠标位置] X:0  Y:0"; //打印初始鼠标位置

		while (loop) {
			/* 读鼠标/键盘，返回值为下述操作中的某一种, 当前鼠标位置在<X,Y>处 */
			ret = cct_read_keyboard_and_mouse(X, Y, maction, keycode1, keycode2);

			if (ret == CCT_MOUSE_EVENT) {
				/* 转到第7行进行打印 */
				cct_gotoxy(0, 7);
				cout << "[当前鼠标位置] X:" << setw(2) << X << " Y:" << setw(2) << Y << " 操作:";

				switch (maction) {
					case MOUSE_ONLY_MOVED:
						cout << "移动          " << endl;
						//showch(X, Y, '*');不打印任何内容
						break;
					case MOUSE_LEFT_BUTTON_CLICK:			//按下左键
						cout << "按下左键      " << endl;
						cct_showch(X, Y, '1');			//在鼠标指针位置显示1
						break;
					case MOUSE_LEFT_BUTTON_DOUBLE_CLICK:	//双击左键
						cout << "双击左键      " << endl;
						cct_showch(X, Y, '2');			//在鼠标指针位置显示2
						break;
					case MOUSE_RIGHT_BUTTON_CLICK:			//按下右键
						cout << "按下右键      " << endl;
						cct_showch(X, Y, '3');			//在鼠标指针位置显示3
						break;
					case MOUSE_RIGHT_BUTTON_DOUBLE_CLICK:	//双击右键
						cout << "双击右键      " << endl;
						cct_showch(X, Y, '4');			//在鼠标指针位置显示4
						loop = 0;
						break;
					case MOUSE_LEFTRIGHT_BUTTON_CLICK:		//同时按下左右键
						cout << "同时按下左右键" << endl;
						cct_showch(X, Y, '5');			//在鼠标指针位置显示5
						break;
					case MOUSE_WHEEL_CLICK:
						cout << "按下滚轮      " << endl;
						break;
					case MOUSE_WHEEL_MOVED_UP:
						cout << "滚轮向上移动  " << endl;
						break;
					case MOUSE_WHEEL_MOVED_DOWN:
						cout << "滚轮向下移动  " << endl;
						break;
					case MOUSE_NO_ACTION:
					default:
						cout << "其它操作" << endl;
						cct_showch(X, Y, '0');			//在鼠标指针位置显示0
						break;
				} //end of switch(maction)
			} //end of if (CCT_MOUSE_EVENT)
			else if (ret == CCT_KEYBOARD_EVENT) {
				/* 转到第9行进行打印 */
				cct_gotoxy(0, 9);
				cout << "[当前按键] : ";

				switch (keycode1) {
					case 27:	//ESC键
						loop = 0;
						cout << "ESC       ";
						break;
					case 32:	//SPACE键
						loop = 0;
						cout << "SPACE     ";
						break;
					case 224:
						switch (keycode2) {
							case KB_ARROW_UP:
								cout << "上箭头    ";
								break;
							case KB_ARROW_DOWN:
								cout << "下箭头    ";
								break;
							case KB_ARROW_LEFT:
								cout << "左箭头    ";
								break;
							case KB_ARROW_RIGHT:
								cout << "右箭头    ";
								break;
						}
						break;
					default:	//其他键直接打印ASCII值
						if (keycode2)
							cout << "Keycode=" << keycode1 << '/' << keycode2 << endl;
						else
							cout << "Keycode=" << keycode1 << endl;
						break;
				}//end of swicth(keycode1)
			}//end of else if(ret == CCT_KEYBOARD_EVENT）
		} //end of while(1)

		cct_disable_mouse();	//禁用鼠标
		cct_setcursor(CURSOR_VISIBLE_NORMAL);	//打开光标
		to_be_continued("鼠标键盘操作演示完成");
	}

	if (1) {
		/* 显示当前系统字体的信息 */
		cout << "鼠标点击cmd窗口左上角，打开的菜单中选择\"属性\"，再选择\"字体\"卡片，可以看到cmd窗口可支持的字体的种类" << endl;
		cout << "    MS Gothic、SimSun-ExtB、SimSun-ExtG、点阵字体(Terminal)、仿宋、黑体、楷体、隶书、新宋体、幼圆" << endl;
		cout << endl;
		cct_getfontinfo();
		to_be_continued("显示当前窗口字体信息完成");

		/* 设置 MS Gothic，28点阵 */
		cct_setconsoleborder(60, 25);
		cct_setfontsize("MS Gothic", 28); //Truetype字体只需要给出一个参数高度即可
		cout << "设置字体为 MS Gothic 28" << endl;
		cout << "部分中文显示不对是因为这种字体的字库中没有这个字的信息，此处仅为演示，后续作业不要选择这种字体" << endl << endl;
		cct_getfontinfo();
		/* 随便输出一些内容 */
		output_something();
		to_be_continued("设置为MS Gothic 28完成");

		/* 设置 SimSun-ExtB，28点阵 */
		cct_setconsoleborder(60, 25);
		cct_setfontsize("SimSun-ExtB", 28); //Truetype字体只需要给出一个参数高度即可
		cout << "设置字体为SimSun-ExtB 28" << endl << endl;
		cout << "每个中文字的宽度比两个英文字母的宽度小，导致中文字之间有间隙，是这种字体的特性，此处仅为演示，后续作业不要选择这种字体" << endl << endl;
		cct_getfontinfo();
		/* 随便输出一些内容 */
		output_something();
		to_be_continued("设置为SimSun-ExtB 28完成");

		/* 设置 SimSun-ExtG，28点阵 */
		cct_setconsoleborder(60, 25);
		cct_setfontsize("SimSun-ExtG", 28); //Truetype字体只需要给出一个参数高度即可
		cout << "设置字体为SimSun-ExtG 28" << endl << endl;
		cout << "每个中文字的宽度比两个英文字母的宽度小，导致中文字之间有间隙，是这种字体的特性，此处仅为演示，后续作业不要选择这种字体" << endl << endl;
		cct_getfontinfo();
		/* 随便输出一些内容 */
		output_something();
		to_be_continued("设置为SimSun-ExtG 28完成");

		/* 设置点阵字体(Terminal)，10*20点阵 */
		cct_setfontsize("Terminal", 20, 10); //点阵字体的名字是Terminal，因为不是Truetype字体，必须给出高度和宽度
		cct_setconsoleborder(60, 25);
		cout << "设置字体为Terminal 20*10" << endl << endl;
		cct_getfontinfo();
		/* 随便输出一些内容 */
		output_something();
		to_be_continued("设置为Terminal 20*10完成");

		/* 设置点阵字体(Terminal)，8*16点阵 */
		cct_setconsoleborder(60, 25);
		cct_setfontsize("Terminal", 16, 8); //点阵字体的名字是Terminal，因为不是Truetype字体，必须给出高度和宽度
		cout << "设置字体为Terminal 16*8" << endl << endl;
		cout << "因为新版控制台自身的问题，初始显示可能会横向被拉伸" << endl;
		cout << "    鼠标单击cmd窗口的左上角，打开的菜单中选择\"属性\"，\n再选择\"字体\"卡片，直接按\"确定\"即可恢复正常显示" << endl << endl;
		cout << "因为默认会被拉宽，此处仅为演示，后续作业不要选择这种字体" << endl << endl;
		cct_getfontinfo();
		/* 随便输出一些内容 */
		output_something();
		to_be_continued("设置为Terminal 16*8完成");

		/* 设置仿宋，28点阵 */
		cct_setconsoleborder(60, 25);
		cct_setfontsize("仿宋", 28); //Truetype字体只需要给出一个参数高度即可
		cout << "设置字体为仿宋28" << endl << endl;
		cct_getfontinfo();
		/* 随便输出一些内容 */
		output_something();
		to_be_continued("设置为仿宋28完成");

		/* 设置黑体，28点阵 */
		cct_setconsoleborder(60, 25);
		cct_setfontsize("黑体", 28); //Truetype字体只需要给出一个参数高度即可
		cout << "设置字体为黑体28" << endl << endl;
		cct_getfontinfo();
		/* 随便输出一些内容 */
		output_something();
		to_be_continued("设置为黑体28完成");

		/* 设置楷体，28点阵 */
		cct_setconsoleborder(60, 25);
		cct_setfontsize("楷体", 28); //Truetype字体只需要给出一个参数高度即可
		cout << "设置字体为楷体28" << endl << endl;
		cct_getfontinfo();
		/* 随便输出一些内容 */
		output_something();
		to_be_continued("设置为楷体28完成");

		/* 设置隶书，28点阵 */
		cct_setconsoleborder(60, 25);
		cct_setfontsize("隶书", 28); //Truetype字体只需要给出一个参数高度即可
		cout << "设置字体为隶书28" << endl << endl;
		cct_getfontinfo();
		/* 随便输出一些内容 */
		output_something();
		to_be_continued("设置为隶书28完成");

		/* 设置新宋体，28点阵 */
		cct_setconsoleborder(60, 25);
		cct_setfontsize("新宋体", 28); //Truetype字体只需要给出一个参数高度即可
		cout << "设置字体为新宋体28" << endl << endl;
		cct_getfontinfo();
		/* 随便输出一些内容 */
		output_something();
		to_be_continued("设置为新宋体28完成");

		/* 设置幼圆，28点阵 */
		cct_setconsoleborder(60, 25);
		cct_setfontsize("幼圆", 28); //Truetype字体只需要给出一个参数高度即可
		cout << "设置字体为幼圆28" << endl << endl;
		cct_getfontinfo();
		/* 随便输出一些内容 */
		output_something();
		to_be_continued("设置为幼圆28完成");

		/* 设置非法字体，会默认为“新宋体”，28点阵 */
		cct_setconsoleborder(60, 25);
		cct_setfontsize("同济", 28); //设置非法字体，会默认为“新宋体”
		cout << "设置字体为非法，会默认为新宋体" << endl << endl;
		cout << "    鼠标单击cmd窗口的左上角，打开的菜单中选择'属性'，\n再选择'字体'卡片，可以看到当前的字体设置" << endl << endl;
		cct_getfontinfo();
		/* 随便输出一些内容 */
		output_something();
		to_be_continued("设置为非法字体28完成");

		/* 设置新宋体，12点阵 */
		cct_setfontsize("新宋体", 12);
		cout << "设置字体为新宋体12" << endl << endl;
		cct_getfontinfo();
		/* 随便输出一些内容 */
		output_something();
		to_be_continued("设置为新宋体12完成");//缺省在22行打印，本窗口只有15行，所以在第10行打印

		/* 设置宋体，1*1 */
		cct_cls();
		to_be_continued("预告：设置宋体1*1会看不清", 0, 0); //预告信息
		/* 设置字体为 1*1 大小*/
		cct_setfontsize("新宋体", 1);

		/* 设置窗口大小 */
		int w = 600, h = 300;
		int i;

		cct_setconsoleborder(w, h);		//说明：屏幕显示横高比大约2:1，因此600*300像正方形

		/* 画一个正方形（看起来像正方形，实际画的是(10,10)-(590,290)的长方形） */
		cct_setcolor(COLOR_HYELLOW, COLOR_HRED);
		for (i = 10; i < w - 10; i++) { //横向两条边(10,10-590,10  /  10,290-590,290)
			cct_gotoxy(i, 10);
			cout << '*';
			cct_gotoxy(i, 290);
			cout << '*';
			Sleep(1);
		}
		for (i = 10; i < h - 10; i++) { //纵向两条边(10,10-290,10  /  590,10-590,290)
			cct_gotoxy(10, i);
			cout << '*';
			cct_gotoxy(590, i);
			cout << '*';
			Sleep(1);
		}

		/* 再画一个圆 */
		const int point_x = 300, point_y = 150, r = 100;
		int angle, x, y;
		const double pi = 3.14159;

		/* 画X轴 */
		for (i = 30; i < w - 30; i++) {//X轴的线
			cct_gotoxy(i, point_y);
			cout << '*';
			Sleep(1);
		}
		for (i = 20; i > 0; i -= 2) { //X轴的箭头
			cct_gotoxy(w - 30 - i, point_y - i / 2);
			cout << '*';
			cct_gotoxy(w - 30 - i, point_y + i / 2);
			cout << '*';
			Sleep(1);
		}

		/* 画Y轴 */
		for (i = 30; i < h - 30; i++) {//Y轴的线
			cct_gotoxy(point_x, i);
			cout << '*';
			Sleep(1);
		}
		for (i = 10; i > 0; i --) { //Y轴的箭头
			cct_gotoxy(point_x - i, 30 + i);
			cout << '*';
			cct_gotoxy(point_x + i, 30 + i);
			cout << '*';
			Sleep(1);
		}

		/* 画圆 */
		for (angle = 0; angle < 360; angle++) {//角度从0-360循环
			x = int(r * cos(angle * pi / 180));
			y = -int(r * sin(angle * pi / 180)); //取负数是因为cmd窗口的坐标轴y向下，为保持和数学一直，反一下
			cct_gotoxy(point_x + x * 2, point_y + y); //x*2是因为长宽比
			cout << '*';
			Sleep(1);
		}

		cct_setcolor(); //恢复初始颜色
		to_be_continued("设置为宋体1*1完成", 0, 295);

		/* 新字体，16点阵，窗口120*30
		   注意：如果既要设置窗口大小，又要设置字体，则必须先窗口再字体 */
		cct_setfontsize("新宋体", 16); //Truetype字体只需要给出一个参数高度即可
		cct_setconsoleborder(120, 30);
	}

	to_be_continued("cmd_console_tools函数集演示结束", 0, 0);

	return 0;
}
