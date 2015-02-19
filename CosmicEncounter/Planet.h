#include <vector>

// ** forward declaration
class Player;
class Ship;
// ** END

class Planet
{
	Player* owner;
	std::vector<Player*> colonies;
	std::vector<Ship*> shipsOnPlanet;
	bool countAsHome; // bool for fast check if the planet count as home or is loss

public:
	Planet();
	~Planet();
};

