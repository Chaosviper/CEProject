#pragma once
#include <iostream>

// ** Forward declaration
namespace GameplayEnum{
	enum GameboxSet;
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
	int phaseAllowed;
	int playerRoleAllowed;
	std::string description;
	std::string name;
	AlienDifficulty difficulty;
	GameplayEnum::GameboxSet originSet;
	AlienPowerFunc activatePower;

public:
	Alien();
	~Alien();
};

