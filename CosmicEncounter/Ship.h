#pragma once

// ** forward declaration
class Player;
// ** END

class Ship
{
	Player* owner;

public:
	inline Ship(Player* playerOwner) : owner(playerOwner) { }
	~Ship();
};

