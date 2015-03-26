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

const GameplayEnum::Phases& Alien::getPhases() const{
	return phaseAllowed;
}

const GameplayEnum::PlayerRole& Alien::getPlayerRole() const{
	return playerRoleAllowed;
}

const bool& Alien::isPowerActive_REF() const{
	return isPowerAlreadyActivated;
}

const std::string& Alien::getName() const{
	return name;
}

const std::string& Alien::getDescription() const{
	return description;
}

AlienPowerFunc Alien::getPower() const{
	return activatePower;
}

void Alien::setPowerActive(bool isActive){
	isPowerAlreadyActivated = isActive;
}

Alien::~Alien()
{
}
