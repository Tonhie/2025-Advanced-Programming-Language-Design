//汤皓宇 计算机 2454307
# include "cmd_console_tools.h"
# include "pullze.h"

# include <iostream>
# include <conio.h>
# include <cstring>
# include <iomanip>
using namespace std;

char Menu()
{
	cct_setconsoleborder(DEFAULT_COLS, DEFAULT_LINES);
	cct_setfontsize(DEFAULT_FONT, DEFAULT_FONTSIZE);

	cout << "---------------------------------------------------------" << endl;
	cout << "A.内部数组，原样输出" << endl;
	cout << "B.内部数组，生成提示行列并输出" << endl;
	cout << "C.内部数组，游戏版" << endl;
	cout << "---------------------------------------------------------" << endl;
	cout << "D.n * n的框架(无分隔线)，原样输出" << endl;
	cout << "E.n * n的框架(无分隔线)，含提示行列" << endl;
	cout << "F.n * n的框架(无分隔线)，显示初始状态，鼠标移动可显示坐标" << endl;
	cout << "G.cmd图形界面完整版(无分隔线)" << endl;
	cout << "---------------------------------------------------------" << endl;
	cout << "H.n * n的框架(有分隔线)，原样输出" << endl;
	cout << "I.n * n的框架(有分隔线)，含提示行列" << endl;
	cout << "J.n * n的框架(有分隔线)，显示初始状态，鼠标移动可显示坐标" << endl;
	cout << "K.cmd图形界面完整版(有分隔线)" << endl;
	cout << "---------------------------------------------------------" << endl;
	cout << "Q.退出" << endl;
	cout << "---------------------------------------------------------" << endl;
	
	cout << "[请选择:] ";
	char mode;
	while (true) {
		mode = _getch();
		if (mode >= 'a' && mode <= 'z')
			mode -= 'a' - 'A';
		if (mode >= 'A' && mode <= 'K' || mode == 'Q')
			break;

	}
	return mode;
}

int SizeSelector()
{
	cct_cls();
	int size;
	while (true) {
		cout << "请输入区域大小(5/10/15) ：";
		cin >> size;
		cin.clear();
		cin.ignore(1024, '\n');
		if (!cin.good())
			continue;
		if (size == 5 || size == 10 || size == 15)
			break;
	}
	return size;
}

void CommandLine(Game &game, Interface &interface)
{
	char maxUpCh = game.getSize() - 1 + 'A';
	char maxLwCh = game.getSize() - 1 + 'a';
	while (true) {
		cout << endl << endl;
		cout << "命令形式：Aa = 等价于图形游戏中鼠标左键选择Aa位(区分大小写)" << endl;
		cout << "不需要支持图形界面的右键打叉，再次输入Aa相当于清除" << endl;
		cout << "X / x = 退出(新行仅有X / x，不分大小写)" << endl;
		cout << "Y / y = 提交(新行仅有Y / y，不分大小写)" << endl;
		cout << "Z / z = 作弊(新行仅有Z / z，不分大小写)" << endl;
		cout << "Ctrl + c 强制退出" << endl;
		cout << "请输入 : ";

		bool goodInput = false;
		char row, col;
		cin >> row;
		if (row == 'X' || row == 'x')
			break;
		if (row == 'Y' || row == 'y') {
			goodInput = true;
			if (game.submmit()) {
				cout << "提交成功，游戏结束" << endl;
				break;
			}
			else {
				char Idx1 = game.get_rowWrong() + 'A';
				char Idx2 = game.get_colWrong() + 'a';
				cout << "提交错误, [";
				cout << Idx1 << "]行[";
				cout << Idx2 << "]列不符合要求" << endl;
			}
		}
		if (row == 'Z' || row == 'z') {
			goodInput = true;
			cout << "输入Z/z后：" << endl;
			game.toggleCheatMode();
			interface.display(false, true);
		}
		if (goodInput)
			continue;

		cin >> col;
		cin.clear();
		cin.ignore(1024, '\n');

		if ('A' <= row && row <= maxUpCh && 'a' <= col && col <= maxLwCh) {
			goodInput = true;
			cout << "输入" << row << col << "后：" << endl;
			game.markO(row - 'A', col - 'a');
			interface.display(false, true);
		}
		else
			cout << "输入错误" << endl;
	}
}

void EventResponder(Game &game, Interface &interface, bool testmode)
{
	if (testmode)
		TipLine("测试键盘/鼠标左键/右键，按回车退出");
	else
		TipLine("左键选〇/右键选×,Y/y提交,Z/z作弊,Q/q结束");
	int row, col;
	int maction, keycode1, keycode2;
	cct_enable_mouse();
	cct_setcursor(CURSOR_INVISIBLE);
	while (true) {
		int EVENT = cct_read_keyboard_and_mouse(col, row, maction, keycode1, keycode2);
		//cout << row << ' ' << col << ' ' << maction << ' ' << keycode1 << ' ' << keycode2 << endl;
		if (EVENT == CCT_KEYBOARD_EVENT) {
			if (!testmode) {
				if (keycode1 == 'Q' || keycode1 == 'q') {
					StatusLine("[读到Q/q，游戏结束]");
					break;
				}
				if (keycode1 == 'Z' || keycode1 == 'z') {
					if (!game.isCheating()) {
						StatusLine("[作弊模式开]");
						game.toggleCheatMode();
						interface.GUI_update();
						continue;
					}
					else {
						StatusLine("[作弊模式关]");
						game.toggleCheatMode();
						interface.GUI_update();
						continue;
					}
				}
				if (keycode1 == 'Y' || keycode1 == 'y') {
					StatusLine("[读到提交键]");
					if (game.submmit()) {
						StatusLine("[提交成功]");
						break;
					}
					else {
						StatusLine("提交错误，可用作弊模式查看");
						continue;
					}
				}
			}
			if (keycode1 == 13) {
				if (testmode) {
					StatusLine("读到回车键");
					break;
				}
			}
			if (keycode1 == 224) {
				if (keycode2 == 72)
					StatusLine("读到上箭头");
				if (keycode2 == 80)
					StatusLine("读到下箭头");
				if (keycode2 == 75)
					StatusLine("读到左箭头");
				if (keycode2 == 77)
					StatusLine("读到右箭头");
			}
			else {
				StatusLine("[读到键码] ");
				cout << keycode1 << '/' << keycode2;
			}
		}
		if (EVENT == CCT_MOUSE_EVENT) {
			bool outed = !interface.GUI_get_relativePoint(row, col);
			if (!testmode && !outed) {
				if (maction == MOUSE_LEFT_BUTTON_CLICK) {
					game.markO(row, col);
					interface.GUI_updatePoint(row, col);
				}
				if (maction == MOUSE_RIGHT_BUTTON_CLICK) {
					game.markX(row, col);
					interface.GUI_updatePoint(row, col);
				}
			}
			switch (maction) {
			case MOUSE_LEFT_BUTTON_CLICK:
				StatusLine("[读到左键] ");
				break;
			case MOUSE_RIGHT_BUTTON_CLICK:
				StatusLine("[读到右键] ");
				break;
			default:
				StatusLine("[当前光标] ");
				break;
			}
			if (!outed) {
				cout << (char)(row + 'A') << "行";
				cout << (char)(col + 'a') << "列";
			}
			else
				cout << "位置非法";
		}
	}
	cct_setcursor(CURSOR_VISIBLE_FULL);
	cct_disable_mouse();
}

void StatusLine(const char content[])
{
	int cols, lines, bf_cols, bf_lines;
	cct_getconsoleborder(cols, lines, bf_cols, bf_lines);
	cct_gotoxy(0, lines - 2);
	cout << setfill(' ') << setw(30) << ' ';
	cct_gotoxy(0, lines - 2);
	cout << content;
}

void TipLine(const char content[])
{
	cct_gotoxy(0, 0);
	cout << content;
}

void Endle()
{
	int cols, lines, bf_cols, bf_lines;
	cct_getconsoleborder(cols, lines, bf_cols, bf_lines);
	cct_gotoxy(0, lines - 1);
	cout << "本小题结束，请输入End继续...";
	int endx, endy;
	cct_getxy(endx, endy);
	char str[4];
	while (true) {
		cct_gotoxy(endx, endy);
		cout << setw(5) << setfill(' ') << ' ';
		cct_gotoxy(endx, endy);
		cin.getline(str, 4, '\n');
		if (!cin.good()) {
			cin.clear();
			cin.ignore(1024, '\n');
		}
		for(int i = 0; i < 3; ++ i)
			str[i] = toupper(str[i]);
		if (strcmp(str, "END") == 0)
			break;
		cout << "输入错误，请重新输入";
	}
	cct_cls();
}