#include <vector>
#include <algorithm>
#pragma once

// ** Forward declaration
class Ship;
// ** END


template<typename T> 
class GameobjectContainer{
protected:
	std::vector<T> entities;
public:
	GameobjectContainer() { }
	virtual ~GameobjectContainer() { }
};

template<>
class GameobjectContainer<Ship*> {
protected:
	std::vector<Ship*> ships;
public:
	GameobjectContainer() { }
	virtual ~GameobjectContainer() { }
};



template<typename T>
class DeckContainer {
protected:
	std::vector<T*> deck;
	std::vector<T*> graveyard;
public:
	DeckContainer() { }

	void addToDeck(T* toInsert){ deck.push_back(toInsert); }
	const T* draw(){ deck.pop_back(); }
	void discard(T* toDiscard){ graveyard.push_back(toDiscard); }
	const T* drawFromGraveyard(){ graveyard.pop_back(); }
	void shuffleDeck() { std::random_shuffle(deck.begin(), deck.end()); }

	virtual ~DeckContainer() { }
};