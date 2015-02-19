#pragma once
#include "GameobjectContainers.h"

// ** forward declaration
class DestinyCard;
// ** END

class DestinyDeck: DeckContainer<DestinyCard*>
{
public:
	DestinyDeck();
	~DestinyDeck();
};

