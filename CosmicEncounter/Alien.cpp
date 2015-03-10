#include "Alien.h"

Alien::Alien(std::string alienName, std::string alienDesc, AlienDifficulty diff,
			GameplayEnum::GameboxSet set, GameplayEnum::Phases phase, GameplayEnum::PlayerRole role, AlienPowerFunc powerFunc):
				name(alienName),
				description(alienDesc),
				phaseAllowed(phase),
				playerRoleAllowed(role),
				difficulty(diff),
				originSet(set),
				activatePower(powerFunc),
				isPowerAlreadyActivated(false) { }

GameplayEnum::Phases Alien::getPhases() const{
	return phaseAllowed;
}

GameplayEnum::PlayerRole Alien::getPlayerRole() const{
	return playerRoleAllowed;
}

AlienPowerFunc Alien::getPower() const{
	return activatePower;
}

void Alien::isPowerActive(bool isActive){
	isPowerAlreadyActivated = isActive;
}

Alien::~Alien()
{
}
