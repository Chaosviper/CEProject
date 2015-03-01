#include "GameManager.h"


GameManager::GameManager()
{
}

void GameManager::AddPlayer(const Player& newPlayer){
	players[NumOfPlayer++] = newPlayer;
}

GameManager::~GameManager()
{
}
