#include "Card.h"


Card::Card()
{
}

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

Card::~Card()
{
}
