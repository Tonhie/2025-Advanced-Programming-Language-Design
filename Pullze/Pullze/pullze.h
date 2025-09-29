//汤皓宇 计算机 2454307

#pragma once
#include "cmd_console_tools.h"

const int DEFAULT_COLS = 120;
const int DEFAULT_LINES = 30;
const int DEFAULT_FONTSIZE = 16;
const char DEFAULT_FONT[7] = "新宋体";
const int DEFAULT_FCOLOR = COLOR_HWHITE;
const int DEFAULT_BCOLOR = COLOR_BLACK;

const int GUI_FONTSIZE = 30;
const int FONTSIZE_SMALL = 11;
const int FONTSIZE_MEDIUM = 16;
const int FONTSIZE_BIG = 22;

const int MAX_SIZE = 15;
const int MAX_NUMSEG = MAX_SIZE / 2 + 1;

const int CHAR_MARKINGS_BCOLOR = COLOR_HYELLOW;
const int CHAR_MARKINGS_FCOLOR = COLOR_BLUE;

const char MARKING_O[3] = "〇";
const char MARKING_X[3] = "×";

const int BOARD_BCOLOR = COLOR_HWHITE;
const int BOARD_FCOLOR = COLOR_BLACK;
const int MARKING_O_BCOLOR = COLOR_HBLUE;
const int MARKING_O_FCOLOR = COLOR_BLACK;
const int MARKING_X_BCOLOR = COLOR_HRED;
const int MARKING_X_FCOLOR = COLOR_BLACK;
const int WRONG_O_BCOLOR = COLOR_HRED;
const int WRONG_O_FCOLOR = COLOR_BLACK;
const int WRONG_X_BCOLOR = COLOR_HBLUE;
const int WRONG_X_FCOLOR = COLOR_BLACK;
const int MISSING_O_BCOLOR = COLOR_WHITE;
const int MISSING_O_FCOLOR = COLOR_BLACK;

const int NOT_SET = -1;

enum Mark
{
	NONE = 0,
	MARK_O = 1,
	MARK_X = 2,
};

// pullze_base
class Game
{
private:
	int size;
	int numBalls;
	bool map[MAX_SIZE][MAX_SIZE];

	int row_maxnumseg = 0;
	int col_maxnumseg = 0;
	int row_numseg[MAX_SIZE];
	int col_numseg[MAX_SIZE];
	int row_seg[MAX_SIZE][MAX_NUMSEG];
	int col_seg[MAX_SIZE][MAX_NUMSEG];

	Mark markings[MAX_SIZE][MAX_SIZE];

	bool correct = false;
	int wrong_row;
	int wrong_col;

	bool hideBalls = true;
	// Display Options

	void placeBalls(int num);
	void row_cntSegments(int row);
	void col_cntSegments(int col);
public:
	Game(int size);

	int getSize();
	bool isOuted(int row, int col);
	bool isBall(int row, int col);

	int get_rowMaxNumSeg();
	int get_colMaxNumSeg();
	void get_rowSeg(int row, int arr[]);
	void get_colSeg(int col, int arr[]);

	void toggleCheatMode();
	bool isCheating();

	void markO(int row, int col);
	void markX(int row, int col);
	void markAllBalls();
	Mark getMarking(int row, int col);
	bool isCorrect(int row, int col);

	bool submmit();
	int get_rowWrong();
	int get_colWrong();

	~Game();
};


// pullze_console
class Interface
{
private:
	Game* game;
	int size;
	int xsegN, ysegN;
	int POSX_LU, POSY_LU;
	int POSX_RD, POSY_RD;

	const int GUI_STARTLINE = 1;

	bool openGUI;
	bool showNumBar;
	bool showDividingLine;

	void adjustConsole();

	void printNstr(const char str[], int times = 1, bool onBoard = false, 
		const int BCOLOR = DEFAULT_BCOLOR, const int FCOLOR = DEFAULT_FCOLOR);
	void printnum(int num, bool onBoard = false);
	void printMarking(Mark MARKING, int X = NOT_SET, int Y = NOT_SET, bool isCorrect = true);

	void printMap();
	void GUI_showMap();
public:
	Interface(Game* game);
	void display(bool openGUI, bool showNumBar = false, bool showDividingLine = false);

	void GUI_updatePoint(int col, int row);
	void GUI_update();
	bool GUI_get_relativePoint(int& absRow, int& absCol);
};

// pullze_tools
char Menu();
int SizeSelector();
void CommandLine(Game& game, Interface& interface);
void EventResponder(Game &game, Interface &interface, bool testmode = false);
void StatusLine(const char content[]);
void TipLine(const char content[]);
void Endle();