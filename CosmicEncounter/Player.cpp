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


Alien& Player::GetAlien(){
	return alienPower;
}

const std::vector<Planet*>& Player::GetHomeColonies() const{
	return homeColonies;
}

const std::vector<Planet*>& Player::GetForeignColonies() const{
	return foreignColonies;
}

const std::string& Player::GetName() const{
	return name;
}

const GameplayEnum::Color& Player::GetColor() const{
	return color;
}

const std::vector<const Card*>& Player::GetHand() const{
	return hand;
}

const Card* Player::GetCardPlayed(int index){
	const Card* toReturn = nullptr;

	if (index < hand.size()){
		toReturn = hand[index];
		hand.erase(hand.begin() + index);
	}

	return toReturn;
}

void Player::AddCard(const Card* cardGetted){
	hand.push_back(cardGetted);
}


Player::~Player()
{
}
