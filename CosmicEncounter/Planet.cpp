#include "Planet.h"


Planet::Planet(Player* playerOwner):
	owner(playerOwner),
	countAsHome(true) { }


Planet::~Planet()
{
}
