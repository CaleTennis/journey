#pragma once
#include <string>
#include <unordered_map>
#include <memory>
#include "SDL_image.h"
#include "Texture.hpp"
#include "Action.hpp"
#include "Logger.hpp"

// avoid circular dependencies
class Texture; 

// supported actions
class SuicideAction;

class Entity
{
public:
	Entity(std::string entityName);
	virtual ~Entity() = default;
	const std::string& getName() const;
	void executeAction(const std::string& actionName);
	virtual void die() = 0;

	SDL_Texture* getTexture() const;
	bool isAlive() const;

	void printSupportedActions() const;
protected:
	void addAction(const std::string& actionName, std::unique_ptr<Action> action);
	void setIsAlive(bool isAlive);
private:
	bool m_isAlive;
	std::string m_entityName;
	std::unique_ptr<Texture> m_entityTexture;
	std::unordered_map<std::string, std::unique_ptr<Action>> m_supportedActions;
};