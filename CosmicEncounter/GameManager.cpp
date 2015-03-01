#include "GameManager.h"

void GameManager::AddPlayer(const Player& newPlayer){
	players[NumOfPlayer++] = newPlayer;
}

Player& GameManager::GetPlayer(int index){

	if (index >= NumOfPlayer)
		return players[NumOfPlayer - 1];

	return players[index];
}

GameManager::~GameManager()
{
}
