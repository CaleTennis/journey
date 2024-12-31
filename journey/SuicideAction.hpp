#pragma once
#include <iostream>
#include "Action.hpp"
#include "Entity.hpp"

class Entity;

class SuicideAction : public Action
{
public:
	std::string getActionName() override;
	void execute(Entity& entity) override;
};