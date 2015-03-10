#pragma once
#include "GameobjectContainers.h"

// ** forward declaration
class Card;
// ** END

class Deck: public DeckContainer<Card>
{

public:
	Deck();
	~Deck();
};

