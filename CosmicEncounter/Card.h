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
	// Encounter Card
	Card(int val);
	// Flare & Artifact
	Card(GameplayEnum::Phases phase, GameplayEnum::PlayerRole prole, ZapType zapTy, CardType ty, CardFunc func);
	// Generic Card Costructor (es: Reinforcement)
	Card(GameplayEnum::Phases phase, GameplayEnum::PlayerRole prole,
		int val, ZapType zapTy, CardType ty, CardFunc func);

	GameplayEnum::Phases getPhases() const;
	GameplayEnum::PlayerRole getPlayerRole() const;
	CardFunc getCardFunction() const;
	ZapType getIfZapper() const;
	CardType getCardType() const;

	~Card();
};

