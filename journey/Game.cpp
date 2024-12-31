#include "Game.hpp"

bool Game::m_isRunning = false;
std::unique_ptr<WindowManager> Game::m_windowManager(std::make_unique<WindowManager>());
std::unique_ptr<AssetManager> Game::m_assetManager(std::make_unique<AssetManager>());

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
	
	if (m_assetManager->init())
	{
		Logger::success("Game::init::AssetManager::init> AssetManager successfully initialized");
	}
	else
	{
		// use error message from AssetManager::init
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
		Logger::info("Game::processEvents> SDL_Event::SDL_QUIT was received, exiting");
		m_isRunning = false;
		break;
	default:
		break;
	}

	if (!m_assetManager->isPlayerAlive())
	{
		m_isRunning = false;
	}
}

void Game::update()
{
	m_assetManager->update();
	m_windowManager->update();
}

void Game::render()
{
	m_windowManager->render();
}

void Game::clean()
{
	// Has SDL elements, so must be called before SDL_Quit
	m_windowManager.reset(); 
	m_assetManager->clean();

	// Finish cleanup
	SDL_Quit();
	Logger::success("Game::clean> Game cleanup successfully completed");
}