#include "Entity.hpp"

// Supported Actions
#include "SuicideAction.hpp"


Entity::Entity(std::string entityName) : 
	m_isAlive(true),
	m_entityName(entityName),
	m_entityTexture(std::make_unique<Texture>("assets/character_noanimation.png"))
{
	addAction("Commit Suicide", std::make_unique<SuicideAction>());
}

const std::string& Entity::getName() const
{
	return m_entityName;
}

void Entity::addAction(const std::string& actionName, std::unique_ptr<Action> action)
{
	m_supportedActions[actionName] = std::move(action);
}

void Entity::executeAction(const std::string& actionName)
{
	auto it = m_supportedActions.find(actionName);
	if (it != m_supportedActions.end())
	{
		Logger::info("Entity{" + m_entityName + "}::executeAction> executed action \"" + actionName + "\"");
		it->second->execute(*this);
	}
	else
	{
		Logger::error("Entity{" + m_entityName + "}::executeAction> attempted unsupported execution of \"" + actionName + "\"");
	}
}

SDL_Texture* Entity::getTexture() const
{
	return m_entityTexture->getTexture();
}

bool Entity::isAlive() const
{
	return m_isAlive;
}

void Entity::setIsAlive(bool isAlive)
{
	m_isAlive = isAlive;
}

void Entity::printSupportedActions() const
{
	Logger::game("Entity{" + m_entityName + "} supports the following actions:");
	auto it = m_supportedActions.begin();
	while (it != m_supportedActions.end())
	{
		Logger::game(it->first);
		it++;
	}
}