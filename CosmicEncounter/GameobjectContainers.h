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

	void shuffleDeck() { std::random_shuffle(deck.begin(), deck.end()); }

	virtual ~DeckContainer() { }
};