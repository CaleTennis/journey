#include "WindowManager.hpp"

WindowManager::WindowManager() : 
	m_window(nullptr,SDL_DestroyWindow), 
	m_renderer(nullptr,SDL_DestroyRenderer)
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
					WINDOW_FLAGS));
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

	return true;
}

void WindowManager::render()
{
	SDL_SetRenderDrawColor(m_renderer.get(), 0, 255, 0, 255);
	SDL_RenderClear(m_renderer.get());
	// Elements to be rendered

	SDL_RenderPresent(m_renderer.get());
}