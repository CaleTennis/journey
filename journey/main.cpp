#include "Game.hpp"

//#undef DEBUG // comment for debug mode

int main(int argc, char *argv[])
{
	Game game = Game();

	if (game.init())
	{
		while (game.isRunning())
		{
			game.processEvents();
			game.update();
			game.render();
		}

		game.clean();
		return 0;
	}

	Logger::warning("main> Uh oh, something unexpected happened");
	return 1;
}