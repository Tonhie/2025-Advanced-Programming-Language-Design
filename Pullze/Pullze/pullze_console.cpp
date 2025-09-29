//ÌÀð©Óî ¼ÆËã»ú 2454307

# include "pullze.h"
# include "cmd_console_tools.h"

# include <iostream>
# include <iomanip>

using namespace std;

Interface::Interface(Game* game)
{
	this->game = game;
	size = game->getSize();
	xsegN = game->get_rowMaxNumSeg();
	ysegN = game->get_colMaxNumSeg();
	POSX_LU = NOT_SET;
	POSY_LU = NOT_SET;
	POSX_RD = NOT_SET;
	POSY_RD = NOT_SET;
	openGUI = false;
	showNumBar = false;
	showDividingLine = false;
}

void Interface::adjustConsole()
{
	//cct_setconsoleborder(200, 200);
	if (!openGUI)
		cct_setfontsize(DEFAULT_FONT, DEFAULT_FONTSIZE);
	if (showDividingLine) {
		if (size == 5) {
			cct_setfontsize(DEFAULT_FONT, FONTSIZE_BIG);
			if (showNumBar) {
				cct_setconsoleborder(49 + 2 * xsegN, 27 + ysegN);
			}
			else cct_setconsoleborder(45, 25);
		}
		if (size == 10) {
			cct_setfontsize(DEFAULT_FONT, FONTSIZE_MEDIUM);
			if (showNumBar) {
				cct_setconsoleborder(89 + 2 * xsegN, 47 + ysegN);
			}
			else
				cct_setconsoleborder(85, 45);
		}
		if (size == 15){
			cct_setfontsize(DEFAULT_FONT, FONTSIZE_SMALL);
			if (showNumBar) {
				cct_setconsoleborder(129 + 2 * xsegN, 67 + ysegN);
			}
			else
				cct_setconsoleborder(125, 65);
		}
	}
	else {
		if (size == 5) {
			if (showNumBar) {
				cct_setconsoleborder(29 + 2 * xsegN, 13 + ysegN);
			}
			else cct_setconsoleborder(17, 10);
		}
		if (size == 10) {
			if (showNumBar) {
				cct_setconsoleborder(31 + 2 * xsegN, 18 + ysegN);
			}
			else
				cct_setconsoleborder(27, 15);
		}
		if (size == 15) {
			if (showNumBar) {
				cct_setconsoleborder(41 + 2 * xsegN, 23 + ysegN);
			}
			else
				cct_setconsoleborder(37, 20);
		}
		cct_setfontsize(DEFAULT_FONT, GUI_FONTSIZE);
	}
}

void Interface::printNstr(const char str[], int times, bool onBoard, const int BCOLOR, const int FCOLOR)
{
	int x, y;
	cct_getxy(x, y);
	if (onBoard)
		cct_showstr(x, y, str, BOARD_BCOLOR, BOARD_FCOLOR, times);
	else cct_showstr(x, y, str, BCOLOR, FCOLOR, times);
	cct_setcolor(DEFAULT_BCOLOR, DEFAULT_FCOLOR);
}

void Interface::printnum(int num, bool onBoard)
{
	int x, y;
	cct_getxy(x, y);
	if (num > 9)
		x--;
	if (onBoard)
		cct_showint(x, y, num, BOARD_BCOLOR, BOARD_FCOLOR);
	else 
		cct_showint(x, y, num, DEFAULT_BCOLOR, DEFAULT_FCOLOR);
	cct_setcolor(DEFAULT_BCOLOR, DEFAULT_FCOLOR);
}

void Interface::printMarking(Mark MARKING, int X, int Y, bool isCorrect)
{
	if (X == -1 || Y == -1)
		cct_getxy(X, Y);
	int BCOLOR = NOT_SET, FCOLOR = NOT_SET;
	if (MARKING == MARK_O) {
		BCOLOR = isCorrect ? MARKING_O_BCOLOR : WRONG_O_BCOLOR;
		FCOLOR = isCorrect ? MARKING_O_FCOLOR : WRONG_O_FCOLOR;
	}
	if (MARKING == MARK_X) {
		BCOLOR = isCorrect ? MARKING_X_BCOLOR : WRONG_X_BCOLOR;
		FCOLOR = isCorrect ? MARKING_X_FCOLOR : WRONG_X_FCOLOR;
	}
	if (MARKING == NONE) {
		BCOLOR = isCorrect ? BOARD_BCOLOR : MISSING_O_BCOLOR;
		FCOLOR = isCorrect ? BOARD_FCOLOR : MISSING_O_FCOLOR;
	}
	if (showDividingLine) {
		if (MARKING == NONE && isCorrect) {
			cct_showstr(X, Y, "      ", BCOLOR, FCOLOR);
			cct_showstr(X, Y + 1, "      ", BCOLOR, FCOLOR);
			cct_showstr(X, Y + 2, "      ", BCOLOR, FCOLOR);
		}
		else {
			cct_showstr(X, Y, "¨X¨T¨[", BCOLOR, FCOLOR);
			cct_showstr(X, Y + 1, "¨U  ¨U", BCOLOR, FCOLOR);
			cct_showstr(X, Y + 2, "¨^¨T¨a", BCOLOR, FCOLOR);
		}
		X += 1 * 2, Y += 1;
	}
	if (MARKING == MARK_O) {
		cct_showstr(X, Y, MARKING_O, BCOLOR, FCOLOR);
	}
	if (MARKING == MARK_X) {
		cct_showstr(X, Y, MARKING_X, BCOLOR, FCOLOR);
	}
	if (MARKING == NONE) {
		cct_showstr(X, Y, isCorrect ? "  " : MARKING_O, BCOLOR, FCOLOR);
	}
	cct_gotoxy(POSX_RD, POSY_RD);
	cct_setcolor(DEFAULT_BCOLOR, DEFAULT_FCOLOR);
}

void Interface::printMap()
{
	if (showNumBar) {
		cout << setfill('-');
		printNstr("-", xsegN * 2 + 1);
		cout << "--+";
		printNstr("-", size * 2 + 1);
		cout << "+" << endl;
		cout << setfill(' ');

		int yseg[MAX_SIZE][MAX_NUMSEG];
		for (int i = 0; i < size; ++i)
			game->get_colSeg(i, yseg[i]);
		for (int i = 0; i < ysegN; ++i) {
			printNstr(" ", xsegN * 2 + 1);
			cout << "  |";
			for (int k = 0; k < size; ++k) {
				cout << ' ';
				if (yseg[k][i] == 0)
					cout << ' ';
				else
					cout << yseg[k][i];
			}
			cout << " |" << endl;
		}

		printNstr("-", xsegN * 2 + 1);
		cout << "--+";
		printNstr("-", size * 2 + 1);
		cout << "+" << endl;

		printNstr(" ", xsegN * 2 + 1);
		cout << "  |";
		for (int i = 0; i < size; i++)
			cout << ' ' << static_cast<char>('a' + i);
		cout << " |" << endl;

		printNstr("-", xsegN * 2 + 1);
		cout << "+-+";
		printNstr("-", size * 2 + 1);
		cout << "+" << endl;
	}
	else {
		cout << "+-+";
		printNstr("-", size * 2 + 1);
		cout << '+' << endl;

		cout << "| |";
		for (int i = 0; i < size; i++)
			cout << ' ' << static_cast<char>('a' + i);
		cout << " |" << endl;

		cout << "+-+";
		printNstr("-", size * 2 + 1);
		cout << '+' << endl;
	}

	for (int i = 0; i < size; i++) {
		if (showNumBar) {
			int xseg[MAX_NUMSEG];
			game->get_rowSeg(i, xseg);
			for (int k = 0; k < xsegN; ++k) {
				cout << ' ';
				if (xseg[k] == 0)
					cout << ' ';
				else
					cout << xseg[k];
			}
			printNstr(" ");
		}
		cout << "|" << static_cast<char>('A' + i) << "|";
		for (int j = 0; j < size; j++) {
			cout << ' ';
			if (game->isCheating()) {
				if (game->isBall(i, j)) {
					if (game->getMarking(i, j) == MARK_O)
						printNstr("O", 1, false, CHAR_MARKINGS_BCOLOR, CHAR_MARKINGS_FCOLOR);
					else
						printNstr("O");
				}
				else if (game->getMarking(i, j) == MARK_O)
					printNstr("X", 1, false, CHAR_MARKINGS_BCOLOR, CHAR_MARKINGS_FCOLOR);
				else printNstr(" ", 1);
			} else {
				if (game->getMarking(i, j) == MARK_O)
					printNstr("O", 1, false, CHAR_MARKINGS_BCOLOR, CHAR_MARKINGS_FCOLOR);
				else
					cout << ' ';
			}
		}
			
		cout << " |" << endl;
	}
	if (showNumBar) {
		printNstr("-", xsegN * 2 + 1);
		cout << "+-+";
		printNstr("-", size * 2 + 1);
		cout << "+" << endl;
	}
	else {
		cout << "+-+";
		printNstr("-", size * 2 + 1);
		cout << '+' << endl;
	}
}

void Interface::GUI_showMap()
{
	cct_gotoxy(0, GUI_STARTLINE);
	if (showNumBar) {
		//cct_setconsoleborder(142, 72);
		//cct_setconsoleborder(11 + 2 * size + 2 * xsegN + 10, DEFAULT_LINES);
		printNstr(" ", 6 + 2 * xsegN);
		printNstr("¨X", 1, true);
		if (showDividingLine)
			printNstr("¨T", size * 4 - 1, true);
		else
			printNstr("¨T", size, true);
		printNstr("¨[", 1, true);
		printNstr(" \n", 1);

		int yseg[MAX_SIZE][MAX_NUMSEG];
		for (int i = 0; i < size; ++i)
			game->get_colSeg(i, yseg[i]);
		for (int i = 0; i < ysegN; i++) {
			printNstr(" ", 6 + 2 * xsegN);
			printNstr("¨U", 1, true);
			for (int k = 0; k < size; k++) {
				if (showDividingLine)
					printNstr(" ", 2, true);
				if (yseg[k][i] != 0)
					printnum(yseg[k][i], true);
				else
					printNstr(" ", 1, true);
				if (showDividingLine) {
					printNstr(" ", 3, true);
					if (k < size - 1)
						printNstr(" ", 2, true);
				} else
					printNstr(" ", 1, true);
			}
			printNstr("¨U", 1, true);
			printNstr(" \n", 1);
		}

		printNstr(" ", 6 + 2 * xsegN);
		printNstr("¨d", 1, true);
		if (showDividingLine)
			printNstr("¨T", size * 4 - 1, true);
		else
			printNstr("¨T", size, true);
		printNstr("¨g", 1, true);
		printNstr(" \n", 1);


		printNstr(" ", 6 + 2 * xsegN);
		printNstr("¨U", 1, true);
		for (int k = 0; k < size; k++) {
			if (showDividingLine)
				printNstr(" ", 2, true);
			char ch[3] = { static_cast<char>('a' + k) , ' '};
			printNstr(ch, 1, true);
			if (showDividingLine) {
				printNstr(" ", 2, true);
				if (k < size - 1)
					printNstr(" ", 2, true);
			}
		}
		printNstr("¨U", 1, true);
		printNstr(" \n", 1);


		printNstr("¨X", 1, true);
		printNstr("¨T", xsegN, true);
		printNstr("¨j¨T", 1, true);

		cct_getxy(POSX_LU, POSY_LU);
		POSX_LU += 2, POSY_LU += 1;

		printNstr("¨p", 1, true);
		if (showDividingLine) {
			for (int i = 0; i < size; i++) {
				printNstr("¨T", 3, true);
				if (i < size - 1)
					printNstr("¨j", 1, true);
			}
		}
		else
			printNstr("¨T", size, true);
		printNstr("¨g", 1, true);
		printNstr(" \n", 1);
	}
	else {
		printNstr(" ", 2);
		printNstr(" ", 2);
		for (int i = 0; i < size; ++i) {
			if (showDividingLine)
				printNstr(" ", 3);
			cout << static_cast<char>('a' + i) << ' ';
			if (showDividingLine)
				printNstr(" ", 3);
		}
		cout << endl;

		printNstr(" ", 2);

		cct_getxy(POSX_LU, POSY_LU);
		POSX_LU += 2, POSY_LU += 1;

		printNstr("¨X", 1, true);
		if (showDividingLine) {
			for (int i = 0; i < size; i++) {
				printNstr("¨T", 3, true);
				if (i < size - 1)
					printNstr("¨j", 1, true);
			}
		}
		else
			printNstr("¨T", size, true);
		printNstr("¨[", 1, true);
		printNstr("\n", 1);
	}

	for (int i = 0; i < size; i++) {
		if (showDividingLine) {
			int lines = i < size - 1 ? 4 : 3;
			for (int t = 0; t < lines; t++) {
				if (showNumBar) {
					int xseg[MAX_NUMSEG];
					game->get_rowSeg(i, xseg);

					printNstr("¨U", 1, true);
					for (int i = 0; i < xsegN; ++i) {
						if (xseg[i] != 0 && t == 1)
							printnum(xseg[i], true);
						else
							printNstr(" ", 1, true);
						printNstr(" ", 1, true);
					}
					printNstr("¨U", 1, true);
					if (t == 1) {
						char ch[3] = { ' ', static_cast<char>('A' + i) };
						printNstr(ch, 1, true);
					}
					else
						printNstr(" ", 2, true);
				}
				else {
					if (t == 1)
						cout << static_cast<char>('A' + i) << ' ';
					else
						printNstr(" ", 2);
				}
				if (t < 3) {
					printNstr("¨U", 1, true);
					for (int k = 0; k < size; k++) {
						printNstr("  ", 3, true);
						printNstr("¨U", 1, true);
					}
					printNstr("\n", 1);
				}
				else {
					printNstr("¨d", 1, true);
					for (int k = 0; k < size; k++) {
						printNstr("¨T", 3, true);
						if (k < size - 1)
							printNstr("¨p", 1, true);
					}
					printNstr("¨g", 1, true);
					printNstr("\n", 1);
				}
			}
		}
		else {
			if (showNumBar) {
				int xseg[MAX_NUMSEG];
				game->get_rowSeg(i, xseg);

				printNstr("¨U", 1, true);
				for (int i = 0; i < xsegN; ++i) {
					if (xseg[i] != 0)
						printnum(xseg[i], true);
					else
						printNstr(" ", 1, true);
					printNstr(" ", 1, true);
				}
				printNstr("¨U", 1, true);

				char ch[3] = { ' ', static_cast<char>('A' + i) };
				printNstr(ch, 1, true);
			}
			else
				cout << static_cast<char>('A' + i) << ' ';
			printNstr("¨U", 1, true);
			printNstr("  ", size, true);
			printNstr("¨U", 1, true);
			printNstr(" \n", 1);
		}
	}

	if (showNumBar) {
		printNstr("¨^", 1, true);
		printNstr("¨T", xsegN, true);
		printNstr("¨m¨T¨m", 1, true);
	}
	else {
		printNstr(" ", 2);
		printNstr("¨^", 1, true);
	}
	if (showDividingLine) {
		for (int i = 0; i < size; i++) {
			printNstr("¨T", 3, true);
			if (i < size - 1)
				printNstr("¨m", 1, true);
		}
	}
	else
		printNstr("¨T", size, true);

	cct_getxy(POSX_RD, POSY_RD);
	POSX_RD -= 1, POSY_RD -= 1;
	printNstr("¨a", 1, true);
	printNstr(" \n", 1);

	GUI_update();
}

void Interface::display(bool openGUI, bool showNumBar, bool showDividingLine)
{
	this->openGUI = openGUI;
	this->showNumBar = showNumBar;
	this->showDividingLine = showDividingLine;
	if (openGUI) {
		adjustConsole();
		GUI_showMap();
	}
	else
		printMap();
}

void Interface::GUI_updatePoint(int row, int col)
{
	int X = POSX_LU + (showDividingLine ? col * 4 : col) * 2;
	int Y = POSY_LU + (showDividingLine ? row * 4 : row);
	if (game->isCheating())
		printMarking(game->getMarking(row, col), X, Y, game->isCorrect(row, col));
	else
		printMarking(game->getMarking(row, col), X, Y);
}

void Interface::GUI_update()
{
	for (int i = 0; i < game->getSize(); i++)
		for (int j = 0; j < game->getSize(); j++)
			GUI_updatePoint(i, j);
}

bool Interface::GUI_get_relativePoint(int& absRow, int& absCol)
{
	absRow -= POSY_LU;
	absCol -= POSX_LU;
	absCol /= 2;
	if (showDividingLine) {
		if (absRow % 4 == 3 || absCol % 4 == 3)
			return false;
		absRow /= 4;
		absCol /= 4;
	}
	return !game->isOuted(absRow, absCol);
}