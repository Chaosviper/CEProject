#include "Card.h"
#include "GameplayEnum.h"


Card::Card(int val):
	phaseAllowed(GameplayEnum::Phases::planning),
	playerRoleAllowed(GameplayEnum::PlayerRole::MainPlayer),
	zapType(None),
	type(Encounter),
	activateCard(nullptr),
	value(val) { }

Card::Card(GameplayEnum::Phases phase, GameplayEnum::PlayerRole prole, ZapType zapTy, CardType ty, CardFunc func) :
	phaseAllowed(phase),
	playerRoleAllowed(prole),
	zapType(zapTy),
	type(ty),
	activateCard(func),
	value(0) { }

Card::Card(GameplayEnum::Phases phase, GameplayEnum::PlayerRole prole, int val, ZapType zapTy, CardType ty, CardFunc func) :
	phaseAllowed(phase),
	playerRoleAllowed(prole),
	zapType(zapTy),
	type(ty),
	activateCard(func),
	value(val) { }

GameplayEnum::Phases Card::getPhases() const{
	return phaseAllowed;
}

GameplayEnum::PlayerRole Card::getPlayerRole() const{
	return playerRoleAllowed;
}

CardFunc Card::getCardFunction() const{
	return activateCard;
}

ZapType Card::getIfZapper() const{
	return zapType;
}

CardType Card::getCardType() const {
	return type;
}

Card::~Card()
{
}
