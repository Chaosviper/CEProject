#pragma once
#include <vector>
#include "Player.h"

class GameManager
{
public:
	const static int MAX_NUM_PLAYERS = 8;

private:
	int NumOfPlayer;
	Player players[MAX_NUM_PLAYERS];

public:

	GameManager();
	void AddPlayer(const Player& newPlayer);

	//TODO: implementare tutte le varie fasi!!!!

	~GameManager();
};

