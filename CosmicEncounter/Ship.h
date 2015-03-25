#pragma once

// ** forward declaration
class Player;
class Ship;

template<typename x> class GameobjectContainer;
template<> class GameobjectContainer<Ship*>;
// ** END

class Ship
{
	Player* owner;
	GameobjectContainer<Ship*>* landingPlace;

public:
	inline Ship(Player* playerOwner) : owner(playerOwner) { }
	
	void MoveTo(GameobjectContainer<Ship*>* destination);

	~Ship();
};

