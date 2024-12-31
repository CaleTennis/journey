#include "TextureLoader.hpp"

SDL_Texture* TextureLoader::loadTexture(std::string path)
{
	std::unique_ptr<SDL_Surface, 
		decltype(&SDL_FreeSurface)> surface(IMG_Load(path.c_str()), SDL_FreeSurface); 

	if (!surface)
	{
		Logger::error("Texture::Texture> Cannot find texture file \"" + path + "\", texture initialization failed");
		return nullptr;
	}

	return SDL_CreateTextureFromSurface(WindowManager::m_renderer.get(), surface.get());
}