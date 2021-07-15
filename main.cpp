#include "Game.h"
#include <ctime>

int main() {

	Game game;
	//initialize random seed
	srand(static_cast<unsigned>(time(NULL)));

	while (game.running() == true) {

		//user input
		game.input();
		//logic
		game.logic();
		//render game
		game.render();

	}

	return 0;
}