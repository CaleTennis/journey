#include "Texture.hpp"

Texture::Texture(std::string path) : m_texture(nullptr, SDL_DestroyTexture)
{
	m_texture.reset(TextureLoader::loadTexture(path));
	if (!m_texture)
	{
		Logger::error("Texture::Texture> Failed to load texture \"" + path + "\", returning... ");
		return;
	}

	Logger::success("Texture::Texture> \"" + path + "\" loaded successfully");
}

SDL_Texture* Texture::getTexture() const
{
	return m_texture.get();
}