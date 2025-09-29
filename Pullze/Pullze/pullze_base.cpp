//ÌÀð©Óî ¼ÆËã»ú 2454307

# include "pullze.h"
# include <cstdlib>
# include <cstring>
# include <ctime>


Game::Game(int size) 
{
	srand(static_cast<unsigned int>(time(0)));
	this->size = size;
	this->numBalls = size * size / 2 + (size % 2 == 1);
	memset(map, false, sizeof(map));
	placeBalls(numBalls);
	memset(markings, NONE, sizeof(markings));
	memset(row_numseg, 0, sizeof(row_numseg));
	memset(col_numseg, 0, sizeof(col_numseg));
	for (int i = 0; i < size; i++) {
		row_cntSegments(i);
		col_cntSegments(i);
	}
}

Game::~Game()
{

}

void Game::placeBalls(int num)
{
	while (num) {
		int row = rand() % size;
		int col = rand() % size;
		if (map[row][col])
			continue;
		map[row][col] = true;
		--num;
	}
}

int Game::getSize()
{
	return size;
}

void Game::toggleCheatMode()
{
	hideBalls = !hideBalls;
}

bool Game::isOuted(int row, int col)
{
	if (row < 0 || row >= size || col < 0 || col >= size) {
		return true;
	}
	return false;
}

bool Game::isBall(int row, int col)
{
	if (row < 0 || row >= size || col < 0 || col >= size)
		return false;
	return map[row][col];
}

void Game::row_cntSegments(int row)
{
	int cnt, col = 0;
	while (col < size) {
		cnt = 0;
		while (col < size && !map[row][col])
			++col;
		while (col < size && map[row][col])
			cnt++, col++;
		if (cnt == 0)
			continue;
		row_seg[row][row_numseg[row]++] = cnt;
	}
	if (row_maxnumseg < row_numseg[row])
		row_maxnumseg = row_numseg[row];
}

void Game::col_cntSegments(int col)
{
	int cnt, row = 0;
	while (row < size) {
		cnt = 0;
		while (row < size && !map[row][col])
			++row;
		while (row < size && map[row][col])
			cnt++, row++;
		if (cnt == 0)
			continue;
		col_seg[col][col_numseg[col]++] = cnt;
	}
	if (col_maxnumseg < col_numseg[col])
		col_maxnumseg = col_numseg[col];
}

int Game::get_rowMaxNumSeg()
{
	return row_maxnumseg;
}

int Game::get_colMaxNumSeg() 
{
	return col_maxnumseg;
}

void Game::get_rowSeg(int row, int arr[]) 
{
	int k = row_maxnumseg - row_numseg[row];
	int i = 0;
	while (i < k)
		arr[i++] = 0;
	while (i < row_maxnumseg)
		arr[i++] = row_seg[row][i - k];
}

void Game::get_colSeg(int col, int arr[]) 
{
	int k = col_maxnumseg - col_numseg[col];
	int i = 0;
	while (i < k)
		arr[i++] = 0;
	while (i < col_maxnumseg)
		arr[i++] = col_seg[col][i - k];
}

bool Game::isCheating() 
{
	return !hideBalls;
}

void Game::markO(int row, int col) 
{
	markings[row][col] = markings[row][col] == MARK_O ? NONE : MARK_O;
}

void Game::markX(int row, int col) 
{
	markings[row][col] = markings[row][col] == MARK_X ? NONE : MARK_X;
}

void Game::markAllBalls() 
{
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++)
			if (isBall(i, j))
				markings[i][j] = MARK_O;
	}
}

Mark Game::getMarking(int row, int col) 
{
	return markings[row][col];
}

bool Game::isCorrect(int row, int col) 
{
	if (markings[row][col] == MARK_O)
		return isBall(row, col);
	if (markings[row][col] == MARK_X)
		return !isBall(row, col);
	if (markings[row][col] == NONE)
		return !isBall(row, col);
	return false;
}

bool Game::submmit() 
{
	bool numCorrect = true;
	for (int row = 0; row < size; row++) {
		int col = 0;
		for (int k = 0; k < row_numseg[row]; k++) {
			int cnt = 0;
			while (markings[row][col] != MARK_O && col < size)
				col++;
			while (markings[row][col] == MARK_O && col < size)
				col++, cnt ++;
			if (cnt != row_seg[row][k])
				numCorrect = false;
		}
	}
	for (int col = 0; col < size; col++) {
		int row = 0;
		for (int k = 0; k < col_numseg[col]; k++) {
			int cnt = 0;
			while (markings[row][col] != MARK_O && row < size)
				row++;
			while (markings[row][col] == MARK_O && row < size)
				row++, cnt++;
			if (cnt != col_seg[col][k])
				numCorrect = false;
		}
	}
	return numCorrect;
}

int Game::get_rowWrong() 
{
	return wrong_row;
}

int Game::get_colWrong() 
{
	return wrong_col;
}