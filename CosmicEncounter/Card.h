#pragma once

// ** Forward declaration
namespace GameplayEnum{
	enum Phases;
	enum PlayerRole;
}
// ** END

enum CardType{
	Encounter,
	Artifact,
	Flare,
	Reinforcement,
	Hazard,
	SpaceStation
};

enum ZapType{
	CardZap,
	CosmicZap,
	None
};

typedef void(*CardFunc)();

class Card
{
	GameplayEnum::Phases phaseAllowed;
	GameplayEnum::PlayerRole playerRoleAllowed;
	int value; // Valid only on encounter or reinforcement card
	ZapType zapType; // != None only if is a CardZap or a CosmicZap

	CardType type;
	CardFunc activateCard;

public:
	Card();

	GameplayEnum::Phases getPhases() const;
	GameplayEnum::PlayerRole getPlayerRole() const;
	CardFunc getCardFunction() const;
	ZapType getIfZapper() const;

	~Card();
};

