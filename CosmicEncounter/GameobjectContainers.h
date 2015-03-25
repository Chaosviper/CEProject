#include <vector>
#include <algorithm>
#pragma once
#include "Ship.h" // Added only for garantee the friend to the function MoveTo

// ** Forward declaration
//class Ship;
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
	friend void Ship::MoveTo(GameobjectContainer<Ship*>*);

protected:
	std::vector<Ship*> ships;

	void RemoveShip(Ship* toRemove){
		std::remove<std::vector<Ship*>::iterator, Ship*>(ships.begin(), ships.end(), toRemove);
	}
	void AddShip(Ship* toAdd){
		ships.push_back(toAdd);
	}

public:
	GameobjectContainer() { }
	virtual ~GameobjectContainer() { }
};



template<typename T>
class DeckContainer {
private:
	void reshuffleGraveyardInDeck(){
		//TODO: Implementing Cosmic Quake!!!

		deck = graveyard;
		graveyard.erase(graveyard.begin(), graveyard.end());
		shuffleDeck();
	}
protected:
	std::vector<T*> deck;
	std::vector<T*> graveyard;
public:
	DeckContainer() { }

	void addToDeck(T* toInsert){ deck.push_back(toInsert); }

	const T* draw(){ 
		
		if (deck.size() <= 0)
			reshuffleGraveyardInDeck();

		const T* x= deck.back();
		deck.pop_back();
		return x;
	}

	void discard(T* toDiscard){ graveyard.push_back(toDiscard); }

	const T* drawFromGraveyard(){
		const T* x = graveyard.back();
		graveyard.pop_back();
		return x;
	}

	void shuffleDeck() { std::random_shuffle(deck.begin(), deck.end()); } // TODO: IMPLEMENTING A REAL SEED!!! IT ISN'T RANDOM AT ALL!!

	virtual ~DeckContainer() { }
};