#include "AssetManager.hpp"
#include "Player.hpp"
#include "SuicideAction.hpp"
 
bool AssetManager::init()
{
	m_entityList = std::map<std::string, std::unique_ptr<Entity>>();

	// Create player
	m_entityList[Player::PLAYER_NAME] = std::move(std::make_unique<Player>());
	m_isPlayerAlive = true;
	m_playerEntity = getEntity(Player::PLAYER_NAME);
	return true;
}

void AssetManager::update()
{
	auto it = m_entityList.find(Player::PLAYER_NAME);
	if (it != m_entityList.end())
	{
		it->second->printSupportedActions();
		it->second->executeAction("Commit Suicide");
	}
}

Entity* AssetManager::getEntity(std::string entityName) const
{
	if (entityName == Player::PLAYER_NAME)
	{
		return m_playerEntity;
	}
	
	auto it = m_entityList.find(entityName);
	
	if (it != m_entityList.end())
	{
		return it->second.get();
	}
	else
	{
		Logger::warning("AssetManager::getEntity> Failed to find entity with name \"" + entityName + "\"");
		return nullptr;
	}
}

bool AssetManager::isPlayerAlive() const
{
	Entity* player = getEntity(Player::PLAYER_NAME);
	if (player)
		return player->isAlive();
	else
		return false;
}

void AssetManager::clean()
{
}