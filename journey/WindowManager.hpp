#pragma once
#include "SDL.h"
#include "SDL_image.h"
#include "Game.hpp"
#include "Logger.hpp"
//#include "TextureLoader.hpp"

class TextureLoader;

class WindowManager
{
	friend class TextureLoader;

public:
	WindowManager();

	bool init();
	void update();
	void render();

private:
	const char* WINDOW_TITLE = "Journey";
	const int WINDOW_STARTING_POS = SDL_WINDOWPOS_CENTERED;
	const int WINDOW_WIDTH = 1280;
	const int WINDOW_HEIGHT = 720;
	const bool WINDOW_IS_FULLSCREEN = false;
	const int WINDOW_FLAGS = SDL_WindowFlags::SDL_WINDOW_SHOWN;

	const int RENDERER_FLAGS = 0; 

	const int TILE_SIZE = 16;
	const int TILE_SCALE = 4;

	static std::unique_ptr<SDL_Window, decltype(&SDL_DestroyWindow)> m_window;
	static std::unique_ptr<SDL_Renderer, decltype(&SDL_DestroyRenderer)> m_renderer;
};