#include "Alien.h"


Alien::Alien()
{
}

GameplayEnum::Phases Alien::getPhases() const{
	return phaseAllowed;
}

GameplayEnum::PlayerRole Alien::getPlayerRole() const{
	return playerRoleAllowed;
}

AlienPowerFunc Alien::getPower() const{
	return activatePower;
}

Alien::~Alien()
{
}
