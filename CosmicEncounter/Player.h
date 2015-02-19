#include <vector>
#include "Alien.h"

// ** forward declaration
class Card;
class Ship;
class Planet;
namespace GameplayEnum{
	enum Color;
}
// ** END

class Player
{
	static const int MAX_NUMBER_OF_SHIP = 20;

	Ship* ships[MAX_NUMBER_OF_SHIP];
	std::vector<Card*> hand;
	std::vector<Planet*> homeColonies;
	std::vector<Planet*> foreignColonies;
	std::string name;
	GameplayEnum::Color color;
	
	Alien alienPower;

public:
	Player();
	~Player();
};
