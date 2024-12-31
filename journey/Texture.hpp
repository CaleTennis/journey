#pragma once
#include <memory>
#include <string>
#include "SDL_image.h"
#include "Logger.hpp"
#include "TextureLoader.hpp"

class Texture
{
public:
	Texture(std::string path);
	SDL_Texture* getTexture() const;
private:
	std::unique_ptr<SDL_Texture, decltype(&SDL_DestroyTexture)> m_texture;
};