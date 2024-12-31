#pragma once
#include "Entity.hpp"
#include "Logger.hpp"

class Player : public Entity
{
public:
	static const std::string PLAYER_NAME;
	Player();
	void die() override;
};