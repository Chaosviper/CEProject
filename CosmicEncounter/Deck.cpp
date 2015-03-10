#include "Deck.h"
#include "Card.h"
#include "GameplayEnum.h"


Deck::Deck()
{
	//TODO: Sositituire con chiamate ad un allocator!!!!
	deck.push_back(new Card(8));
	deck.push_back(new Card(8));
	deck.push_back(new Card(6));
	deck.push_back(new Card(6));
	deck.push_back(new Card(6));
	deck.push_back(new Card(4));
	deck.push_back(new Card(4));
	deck.push_back(new Card(2));
	deck.push_back(new Card(0));
	deck.push_back(new Card(GameplayEnum::allphase, GameplayEnum::AnyPlayer, ZapType::CosmicZap, CardType::Artifact, nullptr));
	deck.push_back(new Card(GameplayEnum::allphase, GameplayEnum::AnyPlayer, ZapType::CardZap, CardType::Artifact, nullptr));
	deck.push_back(new Card(20));
	deck.push_back(new Card(30));
	deck.push_back(new Card(40));
	deck.push_back(new Card(11));
	deck.push_back(new Card(10));
	deck.push_back(new Card(10));

	shuffleDeck();
}


Deck::~Deck()
{
}
