#include <vector>
#include "GameobjectContainers.h"

// ** forward declaration
class Player;
class Ship;
// ** END

class Planet: GameobjectContainer<Ship*>
{
	Player* owner;
	std::vector<Player*> colonies;
	bool countAsHome; // bool for fast check if the planet count as home or is loss

public:
	Planet(Player* playerOwner);
	~Planet();
};

