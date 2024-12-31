#include "Game.hpp"

Game::Game() : 
	m_isRunning(false), 
	m_windowManager(std::make_unique<WindowManager>())
{}

bool Game::init()
{
	if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
	{
		Logger::success("Game::init::SDL_Init> SDL subsystems successfully initialized");
	}
	else
	{
		Logger::error("Game::init::SDL_Init> Could not initialize SDL subsystems, returning...");
		return false;
	}

	if (m_windowManager->init())
	{
		Logger::success("Game::init::WindowManager::init> WindowManager successfully initialized");
	}
	else
	{
		// use error message from WindowManager::init
		return false;
	}

	m_isRunning = true;
	return true;
}

void Game::processEvents()
{
	SDL_Event event;
	SDL_PollEvent(&event);
	switch (event.type) {
	case SDL_QUIT:
		Logger::success("Game::processEvents> SDL_Event::SDL_QUIT was received, exiting");
		m_isRunning = false;
		break;
	default:
		break;
	}
}

void Game::update()
{

}

void Game::render()
{
	m_windowManager->render();
}

void Game::clean()
{
	m_windowManager.reset(); // Has SDL elements, so must be called before SDL_Quit
	SDL_Quit();
	Logger::success("Game::clean> Game cleanup successfully completed");
}