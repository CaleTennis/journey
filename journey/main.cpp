#include "Game.hpp"

//#undef DEBUG // comment for debug mode

int main(int argc, char *argv[])
{
	if (Game::init())
	{
		while (Game::isRunning())
		{
			Game::update();
			Game::render();
			Game::processEvents();
		}

		Game::clean();
		return 0;
	}

	Logger::warning("main> Uh oh, something unexpected happened");
	return 1;
}