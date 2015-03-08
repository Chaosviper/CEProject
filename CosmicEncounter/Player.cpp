#include "Player.h"
#include "Planet.h"


Player::Player(std::string playerName, GameplayEnum::Color col, const Alien& alienPow) :
	name(playerName),
	color(col),
	alienPower(alienPow) 
{
	// TODO: da sostiturire con un allocator! (e poi gestione delle risorse!! delete!!)
	for (int i = 0; i < 5; i++){
		homeColonies.push_back(new Planet(this));
	}

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
