#pragma once
#include <map>
#include "Texture.hpp"
#include "Entity.hpp"

class Texture;
class Entity;

class AssetManager
{
public:
	bool init();
	void update();
	void clean();

	Entity* getEntity(std::string entityName) const;
	bool isPlayerAlive() const;

private:
	Entity* m_playerEntity; // accessed often so make another ptr
	bool m_isPlayerAlive;
	std::unique_ptr<Texture> m_playerTexture;
	std::map<std::string, std::unique_ptr<Entity>> m_entityList;
};