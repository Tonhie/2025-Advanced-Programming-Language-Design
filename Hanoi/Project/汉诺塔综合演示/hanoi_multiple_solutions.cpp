//汤皓宇 计算机 2454307


/* ----------------------------------------------------------------------------------

     本文件功能：
	1、存放被 hanoi_main.cpp 中根据菜单返回值调用的各菜单项对应的执行函数

     本文件要求：
	1、不允许定义外部全局变量（const及#define不在限制范围内）
	2、允许定义静态全局变量（具体需要的数量不要超过文档显示，全局变量的使用准则是：少用、慎用、能不用尽量不用）
	3、静态局部变量的数量不限制，但使用准则也是：少用、慎用、能不用尽量不用
	4、按需加入系统头文件、自定义头文件、命名空间等

   ----------------------------------------------------------------------------------- */

# include "cmd_console_tools.h"
# include "cmd_hdc_tools.h"
# include "hanoi.h"

# include <conio.h>
# include <iomanip>
# include <iostream>
using namespace std;
/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/

int top[3];
int stack[3][11];
int cntAll = 0, delay = -1;

# define showStep option[0]
# define showHor option[1]
# define showVer option[2]
# define showGraph option[3]

int tag(char code) {
    return code - 'A';
}

void func_wait() {
    while (true) {
        char ch = _getch();
        if (ch == 13)
            return;
    }
}

void func_Delay() {
    if (delay == -1)
        return;
    if (delay == 0)
        func_wait();
    else
        Sleep(delay);
}


void info_watchDisks()
{
    for (int t = 0; t < 3; t++) {
		cout << " " << (char)('A' + t) << ":";
        int i = 0;
        while(i < top[t])
			cout << setw(2) << stack[t][i++];
        while(i++ < 10)
            cout << "  ";
    }
    cout << endl;
}

void char_moveDisks(bool option[], int n, char src, char dst) {
    int srcT = top[tag(src)] + 1;
    int dstT = top[tag(dst)] - 1;
    int initx, inity;
    if (showGraph) {
        initx = MenuItem9_Start_X + Underpan_A_X_OFFSET - 1;
        inity = MenuItem9_Start_Y + Underpan_A_Y_OFFSET - 1;
    }
    else {
        initx = MenuItem4_Start_X + Underpan_A_X_OFFSET - 1;
        inity = MenuItem4_Start_Y + Underpan_A_Y_OFFSET - 1;
    }
    cct_gotoxy(initx + Underpan_Distance * tag(src), inity - srcT);
    cout << "  ";
    cct_gotoxy(initx + Underpan_Distance * tag(dst), inity - dstT - 1);
    cout << setw(2) << n;
}

void char_drawDisks(bool option[])
{
    int initx, inity;
    if (showGraph) {
        initx = MenuItem9_Start_X + Underpan_A_X_OFFSET;
        inity = MenuItem9_Start_Y + Underpan_A_Y_OFFSET;
    }
    else {
        initx = MenuItem4_Start_X + Underpan_A_X_OFFSET;
        inity = MenuItem4_Start_Y + Underpan_A_Y_OFFSET;
    }
    cct_gotoxy(initx, inity);
    cout << 'A' << setw(Underpan_Distance) << 'B' << setw(Underpan_Distance) << 'C';
    cct_gotoxy(initx - 2, inity - 1);
    cout << setfill('=') << setw(Underpan_Distance * 2 + 5) << '=' << setfill(' ');
    initx -= 1;
    inity -= 2;
    for (int t = 0; t < 3; t++) {
        for (int i = 0; i < top[t]; i++) {
            cct_gotoxy(initx + t * Underpan_Distance, inity - i);
            cout << setw(2) << stack[t][i];
        }
    }
}

void info_printInfo(bool option[], int n = 0, char src = 0, char dst = 0) {
    if (showVer) {
		if (showGraph)
			cct_gotoxy(MenuItem9_Start_X, MenuItem9_Start_Y);
		else
            cct_gotoxy(MenuItem4_Start_X, MenuItem4_Start_Y);
    }
    if (cntAll) {
        if (showStep)
            cout << "第" << setw(4) << cntAll << " 步( ";
        cout << n << "#: " << src << "-->" << dst;
        if (showStep)
            cout << ") ";
    }
    else
        cout << "初始: ";
    if (showHor)
        info_watchDisks();
    cout << endl;
}

void info_showStauts(int n, char src, char dst, bool showDelays = true) {
	cct_gotoxy(Status_Line_X, Status_Line_Y);
    cout << "从 " << src << " 移动到 " << dst;
    cout << "，共 " << n << " 层";
    if (!showDelays)
        return;
    cout << "，";
    if (delay == 0) {
        cout << "按回车单步演示";
        return;
    }
    cout << "延时设置为 ";
    if (delay == -1)
        cout << 0;
    else
        cout << delay;
	cout << "ms";
}

void push(char code, int num)
{
    stack[tag(code)][top[tag(code)]++] = num;
}

void pop(char code)
{
    top[tag(code)]--;
}

void gui_drawCylinders() {
	int initx = HDC_Start_X;
	int inity = HDC_Start_Y;
    int width = HDC_Base_Width * 23;
    int high = HDC_Base_High * (10 + 2);
	int disNext = width + HDC_Underpan_Distance;
    for (int i = 0; i < 3; i++) {
        hdc_rectangle(initx + i * disNext, inity, width, HDC_Base_High, HDC_COLOR[11]);
        Sleep(HDC_Init_Delay);
    }
	for (int i = 0; i < 3; i++) {
        int mid = initx + width / 2 + i * disNext;
        hdc_rectangle(mid - HDC_Base_Width / 2, inity - high, HDC_Base_Width, high, HDC_COLOR[11]);
		Sleep(HDC_Init_Delay);
	}
}

void gui_drawDisks() {
    int widthPlate = HDC_Base_Width * 23;
	int initx = HDC_Start_X + widthPlate / 2 - HDC_Base_Width / 2;
	int inity = HDC_Start_Y;
	int disNext = widthPlate + HDC_Underpan_Distance;
    for (int t = 0; t < 3; t++) {
        for (int i = 0; i < top[t]; i++) {
            int width = (2 * stack[t][i] + 1) * HDC_Base_Width;
            int X = initx - stack[t][i] * HDC_Base_Width;
            int Y = inity - (i + 1) * HDC_Base_High;
            hdc_rectangle(X, Y, width, HDC_Base_High, HDC_COLOR[stack[t][i]]);
            Sleep(HDC_Init_Delay);
        }
        initx += disNext;
    }
}

void gui_moveDisk(char src, char dst) {
    int srcT = top[tag(src)];
    int dstT = top[tag(dst)] - 1;
	int srcN = stack[tag(src)][srcT];
	int width = (2 * srcN + 1) * HDC_Base_Width;
    int high = HDC_Base_High;
    int widthPlate = HDC_Base_Width * 23;
	int highPlate = HDC_Base_High * (10 + 2);
    int disNext = widthPlate + HDC_Underpan_Distance;
    int baseX = HDC_Start_X + widthPlate / 2 - HDC_Base_Width / 2;
    int baseY = HDC_Start_Y;
	int srcX = baseX + tag(src) * disNext - srcN * HDC_Base_Width;
	int srcY = baseY - (srcT + 1) * HDC_Base_High;
	int dstX = baseX + tag(dst) * disNext - srcN * HDC_Base_Width;
    int dstY = baseY - (dstT + 1) * HDC_Base_High;
	int srcPillarX = baseX + tag(src) * disNext;
    int dstPillarX = baseX + tag(dst) * disNext;
	int PillarY = baseY - HDC_Base_High * (10 + 2);

    int posX = srcX, posY = srcY;
    while (posY > HDC_Top_Y) {
        posY -= HDC_Step_Y;
        hdc_rectangle(posX, posY + high, width, HDC_Step_Y, HDC_COLOR[0]);
        if (posY >= PillarY - HDC_Base_High)
            hdc_rectangle(srcPillarX, posY + high, HDC_Base_Width, HDC_Step_Y, HDC_COLOR[11]);
        hdc_rectangle(posX, posY, width, HDC_Step_Y, HDC_COLOR[srcN]);
        func_Delay();
    }
    while (posX != dstX) {
        if (srcX < dstX) {
            hdc_rectangle(posX, posY, HDC_Step_X, high, HDC_COLOR[0]);
            hdc_rectangle(posX + width, posY, HDC_Step_X, high, HDC_COLOR[srcN]);
            posX += HDC_Step_X;
        }
        else {
			posX -= HDC_Step_X;
			hdc_rectangle(posX + width, posY, HDC_Step_X, high, HDC_COLOR[0]);
			hdc_rectangle(posX, posY, HDC_Step_X, high, HDC_COLOR[srcN]);
        }
        func_Delay();
    }
    while (posY < dstY) {
        hdc_rectangle(posX, posY, width, HDC_Step_Y, HDC_COLOR[0]);
        if (posY >= PillarY)
            hdc_rectangle(dstPillarX, posY, HDC_Base_Width, HDC_Step_Y, HDC_COLOR[11]);
        hdc_rectangle(posX, posY + high, width, HDC_Step_Y, HDC_COLOR[srcN]);
        posY += HDC_Step_Y;
        func_Delay();
    }
}

void hanoi(int n, char src, char tmp, char dst, bool option[], bool demo = false)
{
    if (n == 0)
        return;
    hanoi(n - 1, src, dst, tmp, option);
    pop(src);
    push(dst, n);
    cntAll++;
    info_printInfo(option, n, src, dst);
    if(showVer)
        char_moveDisks(option, n, src, dst);
    if(showGraph)
		gui_moveDisk(src, dst);
    func_Delay();
    hanoi(n - 1, tmp, src, dst, option);
}

char upper(char ch) {
    if (ch >= 'a' && ch <= 'z')
        return ch - 32;
    return ch;
}

void info_Input(int &n, char &src, char &tmp, char &dst, int maxDelay = 0)
{
    while (true) {
        cout << "请输入汉诺塔的层数(1-10)" << endl;
        cin >> n;
        cin.clear();
        cin.ignore(1024, '\n');
        if (cin.good() && n >= 1 && n <= 10)
            break;
    }
    while (true) {
        cout << "请输入起始柱(A-C)" << endl;
        cin >> src;
        cin.clear();
        cin.ignore(1024, '\n');
        if (cin.good()) {
            src = upper(src);
            if (src >= 'A' && src <= 'C')
                break;
        }
    }
    while (true) {
        cout << "请输入目标柱(A-C)" << endl;
        cin >> dst;
        cin.clear();
        cin.ignore(1024, '\n');
        if (cin.good()) {
            dst = upper(dst);
            if (dst >= 'A' && dst <= 'C' && dst != src)
                break;
        }
    }
    tmp = 'A' + 'B' + 'C' - src - dst;
    if (maxDelay == 0)
        return;
    while (true) {
        cout << "请输入移动速度(0-" << maxDelay << ": 0-按回车单步演示 ";
        cout << (maxDelay == 1 ? "" : "1-") << maxDelay << ":延时" << maxDelay << "ms)" << endl;;
        cin >> delay;
        bool ret = cin.good();
        cin.clear();
        cin.ignore(1024, '\n');
        if (ret && 0 <= delay && delay <= 200)
            break;
    }
}

void info_Init(int n, int src) {
    cntAll = 0;
    top[0] = top[1] = top[2] = 0;
    for (int i = n; i > 0; i--)
        push(src, i);
}

void func_Ending(bool option[]) {
    if (showVer || showGraph)
        cct_gotoxy(Status_Line_X, Status_Line_Y + 1);
    cout << "按回车键继续";
    func_wait();
}

void info_readCommand(char& from, char& to) {
    while (true) {
        cct_gotoxy(Status_Line_X, Status_Line_Y - 1);
        cout << setw(100) << ' ' << '\r';
        cout << "请输入移动的柱号(命令形式：AC=A顶端的盘子移动到C，Q=退出) ： ";
        while (true) {
            from = _getch();
            putchar(from);
            from = upper(from);
            if (from == 'Q')
                return;
            if (from >= 'A' && from <= 'C')
                break;
        }
        while (true) {
            to = _getch();
            putchar(to);
            to = upper(to);
            if (from >= 'A' && from <= 'C') 
                break;
        }
        if (from < 'A' || from > 'C' || to < 'A' || to > 'C')
            continue;
        if (from == to)
            continue;
        if (top[tag(from)] == 0) {
            cout << "\n源柱为空!";
            func_wait();
            cout << '\r' << setw(100) << ' ';
            continue;
        }
		int fromN = stack[tag(from)][top[tag(from)] - 1];
		int toN = stack[tag(to)][top[tag(to)] - 1];
        if (fromN > toN && top[tag(to)]) {
            cout << "大盘压小盘，非法移动!";
            func_wait();
            cout << '\r' << setw(100) << ' ';
            continue;
        }
        break;
    }
}

void hanoi_basic() {
	bool option[4] = { false, false, false, false };
	int n;
	char src, tmp, dst;
	info_Input(n, src, tmp, dst);
    cntAll = 0;
	hanoi(n, src, tmp, dst, option);
    func_Ending(option);
}

void hanoi_basic_step_record() {
	bool option[4] = { true, false, false, false };
	int n;
	char src, tmp, dst;
	info_Input(n, src, tmp, dst);
    info_Init(n, src);
	hanoi(n, src, tmp, dst, option);
    func_Ending(option);
}

void hanoi_array_display_horizontal() {
	bool option[4] = { true, true, false, false };
	int n;
	char src, tmp, dst;
	info_Input(n, src, tmp, dst);
    info_Init(n, src);
	hanoi(n, src, tmp, dst, option);
    func_Ending(option);
}

void hanoi_array_display_vertical_horizontal() {
	bool option[4] = { true, true, true, false };
	int n;
	char src, tmp, dst;
	info_Input(n, src, tmp, dst, 200);
    info_Init(n, src);
    cct_cls();
    char_drawDisks(option);
	info_printInfo(option);
    info_showStauts(n, src, dst);
    func_Delay();
	hanoi(n, src, tmp, dst, option);
    func_Ending(option);
}

void hanoi_graphics_prepare_draw_cylinders() {
    bool option[4] = { false, false, false, true };
    cct_cls();
    hdc_cls();
    hdc_init();
    gui_drawCylinders();
    func_Ending(option);
}

void hanoi_graphics_prepare_draw_disks() {
    bool option[4] = { false, false, false, true };
    int n;
    char src, tmp, dst;
    info_Input(n, src, tmp, dst);
    info_Init(n, src);
    cct_cls();
    hdc_cls();
    hdc_init();
    info_showStauts(n, src, dst, false);
    gui_drawCylinders();
    gui_drawDisks();
    func_Ending(option);
}

void hanoi_graphics_first_move() {
    bool option[4] = { false, false, false, true };
    int n;
    char src, tmp, dst;
    info_Input(n, src, tmp, dst, 20);
    info_Init(n, src);
    cct_cls();
    hdc_cls();
    hdc_init();
    info_showStauts(n, src, dst, false);
    gui_drawCylinders();
    gui_drawDisks();
    if (n % 2 == 0) {
        pop(src);
        push(tmp, n);
        gui_moveDisk(src, tmp);
    }
    else {
        pop(src);
        push(dst, n);
        gui_moveDisk(src, dst);
    }
    func_Ending(option);
}

void hanoi_graphics_auto_move() {
    bool option[4] = { true, true, true, true };
    int n;
    char src, tmp, dst;
    info_Input(n, src, tmp, dst, 20);
    info_Init(n, src);
    cct_cls();
    hdc_cls();
    hdc_init();
    info_printInfo(option);
    info_showStauts(n, src, dst, false);
    char_drawDisks(option);
    gui_drawCylinders();
    gui_drawDisks();
	hanoi(n, src, tmp, dst, option);
    func_Ending(option);
}

void hanoi_graphics_game() {
    bool option[4] = { true, true, true, true };
    int n;
    char src, tmp, dst;
    info_Input(n, src, tmp, dst, 20);
    info_Init(n, src);
    cct_cls();
    hdc_cls();
    hdc_init();
    info_printInfo(option);
    info_showStauts(n, src, dst, false);
    char_drawDisks(option);
    gui_drawCylinders();
    gui_drawDisks();
    while (top[tag(dst)] < n) {
        char from, to;
        info_readCommand(from, to);
        if (from == 'Q')
            break;
		int fromT = stack[tag(from)][top[tag(from)] - 1];
        push(to, fromT);
        pop(from);
        cntAll++;
        info_printInfo(option, fromT, from, to);
        if (showVer)
            char_moveDisks(option, fromT, from, to);
        if (showGraph)
            gui_moveDisk(from, to);
    }
    func_Ending(option);
}