#include "Ship.h"
#include "GameobjectContainers.h"


void Ship::MoveTo(GameobjectContainer<Ship*>* newLandingPlace){
	if (landingPlace != nullptr){
		landingPlace->RemoveShip(this);
		landingPlace = newLandingPlace;
		newLandingPlace->AddShip(this);
	}
}

Ship::~Ship()
{
}
