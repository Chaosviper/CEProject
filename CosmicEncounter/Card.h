#pragma once

enum CardType{
	Encounter,
	Artifact,
	Flare,
	Reinforcement,
	Hazard,
	SpaceStation
};

class Card
{
	int phaseAllowed;
	int playerRoleAllowed;
	int value; // Valid only on encounter or reinforcement card
	CardType type;

public:
	Card();
	~Card();
};

