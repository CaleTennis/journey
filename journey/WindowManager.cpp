#include "WindowManager.hpp"

std::unique_ptr<SDL_Window, decltype(&SDL_DestroyWindow)> WindowManager::m_window(nullptr, SDL_DestroyWindow);
std::unique_ptr<SDL_Renderer, decltype(&SDL_DestroyRenderer)> WindowManager::m_renderer(nullptr, SDL_DestroyRenderer);

SDL_Rect destRect = SDL_Rect();

WindowManager::WindowManager()
{}

bool WindowManager::init()
{
	m_window.reset(
				SDL_CreateWindow(
					WINDOW_TITLE,
					WINDOW_STARTING_POS,
					WINDOW_STARTING_POS,
					WINDOW_WIDTH,
					WINDOW_HEIGHT,
					WINDOW_FLAGS 
					| (WINDOW_IS_FULLSCREEN ? SDL_WINDOW_FULLSCREEN : 0)));
	if (!m_window)
	{
		Logger::error("WindowManager::init::SDL_CreateWindow> SDL window creation failed, returning...");
		return false;
	}
	else
	{
		Logger::success("WindowManager::init::SDL_CreateWindow> SDL window succesfully created");
	}
	m_renderer.reset(
					SDL_CreateRenderer(
						m_window.get(), 
						-1,
						RENDERER_FLAGS));
	if (!m_renderer)
	{
		Logger::error("WindowManager::init::SDL_CreateRenderer> SDL renderer creation failed, returning...");
		return false;
	}
	else
	{
		Logger::success("WindowManager::init::SDL_CreateRenderer> SDL renderer succesfully created");
	}


	// init player texture


	return true;
}

void WindowManager::update()
{
	destRect.h = TILE_SIZE * TILE_SCALE;
	destRect.w = TILE_SIZE * TILE_SCALE;
}

void WindowManager::render()
{
	SDL_SetRenderDrawColor(m_renderer.get(), 255, 255, 255, 255);
	SDL_RenderClear(m_renderer.get());
	// Elements to be rendered
	// Depth of rendering is backgroud items first and foreground items last
	Entity* playerTexture = Game::m_assetManager->getEntity("Player");
	if (playerTexture)
	{
		SDL_RenderCopy(m_renderer.get(),
			playerTexture->getTexture(),
			NULL,
			&destRect);
	}

	
	SDL_RenderPresent(m_renderer.get());
}
