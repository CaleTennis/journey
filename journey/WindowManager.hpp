#pragma once
#include "SDL.h"
#include "Logger.hpp"

class WindowManager
{
public:
	WindowManager();

	bool init();
	void render();
private:

	const char* WINDOW_TITLE = "Journey";
	const int WINDOW_STARTING_POS = SDL_WINDOWPOS_CENTERED;
	const int WINDOW_WIDTH = 1280;
	const int WINDOW_HEIGHT = 720;
	const bool WINDOW_IS_FULLSCREEN = true;
	const int WINDOW_FLAGS = SDL_WindowFlags::SDL_WINDOW_SHOWN;
	
	const int RENDERER_FLAGS = 0; 

	std::unique_ptr<SDL_Window, decltype(&SDL_DestroyWindow)> m_window;
	std::unique_ptr<SDL_Renderer, decltype(&SDL_DestroyRenderer)> m_renderer;
};