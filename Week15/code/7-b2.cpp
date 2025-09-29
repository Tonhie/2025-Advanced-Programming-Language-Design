//汤皓宇 计算机 2454307

/* 1、按需加入头文件
   2、不允许定义全局变量，包括静态全局，但不限制const及define
   3、允许定义需要的结构体、函数等，但仅限本源程序文件使用 */
# include "7-b2.h"
# include "cmd_console_tools.h"
# include <cstring>
# include <iostream>

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：定义仅本源程序文件需要的函数，设置为static即可
***************************************************************************/
static int max(int a, int b)
{
	return a > b ? a : b;
}
static int min(int a, int b)
{
	return a < b ? a : b;
}
static void cutString(char line[], int len) {
	int cntWideCh = 0, i = 0;
	for (int i = 0; i < len; i++) {
		if (line[i] < 0 || line[i] > 127)
			cntWideCh++;
	}
	if (cntWideCh % 2 == 1)
		line[len - 1] = '\0';
	else
		line[len] = '\0';
}
static void updateMenu(const char menu[][MAX_ITEM_LEN], const struct PopMenu* original_para, int start_row, int end_row, int selected, bool changed = false) {
	static int last_selected = 0;
	int high = end_row - start_row + 1;
	int width = original_para->width + original_para->width % 2;
	int width_title = strlen(original_para->title);
	width_title += width_title % 2;
	width = max(width, width_title);
	if (changed) {
		for (int i = 0; i < high; i++) {
			char line[MAX_ITEM_LEN] = "";
			if (start_row + i <= end_row)
				strcpy_s(line, sizeof(line), menu[start_row + i]);
			if (width < MAX_ITEM_LEN)
				cutString(line, width);
			if (start_row + i == selected) {
				cct_showstr(original_para->start_x + 2, original_para->start_y + i + 1, " ", original_para->fg_color, original_para->bg_color, width);
				cct_showstr(original_para->start_x + 2, original_para->start_y + i + 1, line, original_para->fg_color, original_para->bg_color);
			}
			else {
				cct_showstr(original_para->start_x + 2, original_para->start_y + i + 1, " ", original_para->bg_color, original_para->fg_color, width);
				cct_showstr(original_para->start_x + 2, original_para->start_y + i + 1, line, original_para->bg_color, original_para->fg_color);
			}
		}
	}
	else {
		int i = selected - start_row;
		char line[MAX_ITEM_LEN] = "";
		strcpy_s(line, sizeof(line), menu[start_row + i]);
		if (width < MAX_ITEM_LEN)
			cutString(line, width);
		cct_showstr(original_para->start_x + 2, original_para->start_y + i + 1, " ", original_para->fg_color, original_para->bg_color, width);
		cct_showstr(original_para->start_x + 2, original_para->start_y + i + 1, line, original_para->fg_color, original_para->bg_color);
		
		i = last_selected - start_row;
		strcpy_s(line, sizeof(line), menu[start_row + i]);
		if (width < MAX_ITEM_LEN)
			cutString(line, width);
		cct_showstr(original_para->start_x + 2, original_para->start_y + i + 1, " ", original_para->bg_color, original_para->fg_color, width);
		cct_showstr(original_para->start_x + 2, original_para->start_y + i + 1, line, original_para->bg_color, original_para->fg_color);

	}
	last_selected = selected;
}

/***************************************************************************
  函数名称：
  功    能：供测试用例调用的函数，函数声明在头文件中
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int pop_menu(const char menu[][MAX_ITEM_LEN], const struct PopMenu* original_para)
{
	int default_bcolor, default_fcolor;
	cct_getcolor(default_bcolor, default_fcolor);
	cct_setcursor(CURSOR_INVISIBLE);
	int rowMenu = 0;
	while (menu[rowMenu][0] != '\0')
		rowMenu++;
	int high = min(rowMenu, original_para->high);

	int width = original_para->width + original_para->width % 2;
	int width_title = strlen(original_para->title);
	width_title += width_title % 2;
	width = max(width, width_title);

	cct_showstr(original_para->start_x, original_para->start_y, "╔", original_para->bg_color, original_para->fg_color);
	cct_showstr(original_para->start_x + 2, original_para->start_y, "═", original_para->bg_color, original_para->fg_color, width / 2);
	cct_showstr(original_para->start_x + 2 + width, original_para->start_y, "╗", original_para->bg_color, original_para->fg_color);
	
	for (int i = 1; i <= high; i++) {
		cct_showstr(original_para->start_x, original_para->start_y + i, "║", original_para->bg_color, original_para->fg_color);
		cct_showstr(original_para->start_x + 2, original_para->start_y + i, " ", original_para->bg_color, original_para->fg_color, width);		
		cct_showstr(original_para->start_x + 2 + width, original_para->start_y + i, "║", original_para->bg_color, original_para->fg_color);
	}

	cct_showstr(original_para->start_x, original_para->start_y + high + 1, "╚", original_para->bg_color, original_para->fg_color);
	cct_showstr(original_para->start_x + 2, original_para->start_y + high + 1, "═", original_para->bg_color, original_para->fg_color, width / 2);
	cct_showstr(original_para->start_x + 2 + width, original_para->start_y + high + 1, "╝", original_para->bg_color, original_para->fg_color);
	
	int title_x = original_para->start_x + 2 + (width - width_title) / 2;
	title_x -= title_x % 2;
	cct_showstr(title_x, original_para->start_y, original_para->title, original_para->bg_color, original_para->fg_color);


	int start_row = 0, end_row = high - 1, selected = 0;
	int mouse_row, mouse_col;
	int maction, keycode1, keycode2;
	updateMenu(menu, original_para, start_row, end_row, selected, true);
	while (true) {
		int EVENT = cct_read_keyboard_and_mouse(mouse_col, mouse_row, maction, keycode1, keycode2);
		if (EVENT == CCT_KEYBOARD_EVENT) {
			if (keycode1 == 224 && rowMenu != 0) {
				if (keycode2 == 72) {
					if (selected == start_row) {
						if (start_row != 0) {
							start_row--;
							end_row--;
							selected--;
							updateMenu(menu, original_para, start_row, end_row, selected, true);
						}
					}
					else {
						selected--;
						updateMenu(menu, original_para, start_row, end_row, selected);
					}
				}
				if (keycode2 == 80) {
					if (selected == end_row) {
						if (end_row != rowMenu - 1) {
							start_row++;
							end_row++;
							selected++;
							updateMenu(menu, original_para, start_row, end_row, selected, true);
						}
					}
					else {
						selected++;
						updateMenu(menu, original_para, start_row, end_row, selected);
					}
				}
			}
			if (keycode1 == 13) {
				break;
			}
		}
	}

	cct_setcursor(CURSOR_VISIBLE_NORMAL);
	cct_setcolor(default_bcolor, default_fcolor);

	if (rowMenu == 0)
		return 0;
	return selected + 1;
}