#pragma once

#include <string>
#include <memory>
#include "SDL_image.h"
#include "WindowManager.hpp"

class TextureLoader
{
public:
	TextureLoader() = delete;
	static SDL_Texture* loadTexture(std::string path);
};