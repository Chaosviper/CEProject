#pragma once

enum CardType{
	Encounter,
	Artifact,
	Flare,
	Reinforcement,
	Hazard,
	SpaceStation
};

typedef void(*CardFunc)();

class Card
{
	int phaseAllowed;
	int playerRoleAllowed;
	int value; // Valid only on encounter or reinforcement card
	CardType type;
	CardFunc activateCard;

public:
	Card();
	~Card();
};

