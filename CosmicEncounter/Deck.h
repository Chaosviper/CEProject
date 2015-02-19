#pragma once
#include "GameobjectContainers.h"

// ** forward declaration
class Card;
// ** END

class Deck: DeckContainer<Card*>
{

public:
	Deck();
	~Deck();
};

