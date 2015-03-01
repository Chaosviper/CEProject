#include "Player.h"


Player::Player()
{
}


const Alien& Player::GetAlien() const{
	return alienPower;
}

const Card* Player::GetCardPlayed(int index) const{
	Card* toReturn = nullptr;

	if (index < hand.size()){
		toReturn = hand[index];
	}

	return toReturn;
}

Player::~Player()
{
}
