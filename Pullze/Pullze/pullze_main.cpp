//汤皓宇 计算机 2454307
# include "pullze.h"

# include <iostream>

using namespace std;

int main()
{
	cct_setconsoletitle("数织游戏 -- By汤皓宇");
	while (true) {
		char mode = Menu();
		if (mode == 'Q')
			break;
		Game game(SizeSelector());
		Interface interface(&game);
		if (mode == 'A') {
			game.toggleCheatMode();
			interface.display(false, false);
		}
		if (mode == 'B') {
			game.toggleCheatMode();
			interface.display(false, true);
		}
		if (mode == 'C') {
			interface.display(false, true);
			CommandLine(game, interface);
		}
		if (mode == 'D') {
			game.markAllBalls();
			interface.display(true, false);
		}
		if (mode == 'E') {
			game.markAllBalls();
			interface.display(true, true);
		}
		if (mode == 'F') {
			game.markAllBalls();
			interface.display(true, true);
			EventResponder(game, interface, true);
		}
		if (mode == 'G') {
			interface.display(true, true);
			EventResponder(game, interface);
		}
		if (mode == 'H') {
			game.markAllBalls();
			interface.display(true, false, true);
		}
		if (mode == 'I') {
			game.markAllBalls();
			interface.display(true, true, true);
		}
		if (mode == 'J') {
			game.markAllBalls();
			interface.display(true, true, true);
			EventResponder(game, interface, true);
		}
		if (mode == 'K') {
			interface.display(true, true, true);
			EventResponder(game, interface);
		}
		Endle();
	}
	return 0;
}