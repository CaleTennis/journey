#include "Player.hpp"

const std::string Player::PLAYER_NAME = "Player";

Player::Player() : Entity(PLAYER_NAME)
{}

void Player::die() 
{
	Logger::info("Player::die> Player has died");
	setIsAlive(false);
}