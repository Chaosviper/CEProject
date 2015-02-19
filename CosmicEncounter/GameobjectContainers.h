#include <vector>

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
	std::vector<T> deck;
	std::vector<T> graveyard;
public:
	DeckContainer() { }
	virtual ~DeckContainer() { }
};