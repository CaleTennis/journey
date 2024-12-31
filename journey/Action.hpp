#pragma once
#include <string>

class Entity;

class Action
{
public:
	virtual ~Action() = default;
	virtual std::string getActionName() = 0;
	virtual void execute(Entity& entity) = 0;
};