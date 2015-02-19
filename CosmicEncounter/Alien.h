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

class Alien
{
	int phaseAllowed;
	int playerRoleAllowed;
	std::string description;
	std::string name;
	AlienDifficulty difficulty;
	GameplayEnum::GameboxSet originSet;
	// TODO: add pointer to function
public:
	Alien();
	~Alien();
};

