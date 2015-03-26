#pragma once
#include <iostream>
#include <list>

// ** Forward declaration
namespace GameplayEnum{
	enum GameboxSet;
	enum Phases;
	enum PlayerRole;
}
// ** END

enum AlienDifficulty{
	Easy,
	Medium,
	Hard
};

typedef void(*AlienPowerFunc)();

class Alien
{
	GameplayEnum::Phases phaseAllowed;
	GameplayEnum::PlayerRole playerRoleAllowed;
	std::string description; // Power text description
	std::string name;
	AlienDifficulty difficulty;
	GameplayEnum::GameboxSet originSet;
	AlienPowerFunc activatePower;

	bool isPowerAlreadyActivated;

public:
	Alien(std::string alienName, std::string alienDesc, AlienDifficulty diff, 
			GameplayEnum::GameboxSet set, GameplayEnum::Phases phase, GameplayEnum::PlayerRole role, AlienPowerFunc powerFunc);

	const GameplayEnum::Phases& getPhases() const;
	const GameplayEnum::PlayerRole& getPlayerRole() const;
	const bool& isPowerActive_REF() const;
	const std::string& getName() const;
	const std::string& getDescription() const;
	AlienPowerFunc getPower() const;
	void setPowerActive(bool isActive);

	~Alien();
};

