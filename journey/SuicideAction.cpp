#include "SuicideAction.hpp"

std::string SuicideAction::getActionName()
{
	return "Commit Suicide";
}

void SuicideAction::execute(Entity& entity)
{
	entity.die();
}