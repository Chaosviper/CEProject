#pragma once
#include <iostream>

// ** forward declaration
class Player;
// ** END

class DestinyCard
{
	Player* toAttack;
	std::string cardName;
	//TODO: puntatore a funzione

public:
	DestinyCard();
	~DestinyCard();
};

