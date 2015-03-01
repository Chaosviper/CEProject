#pragma once
#include <vector>
#include "Player.h"

class GameManager
{
public:
	const static int MAX_NUM_PLAYERS = 8;

	inline static GameManager& GetGameManager(){
		static GameManager singleton;

		return singleton;
	}

	void AddPlayer(const Player& newPlayer);
	Player& GetPlayer(int index);

	//TODO: implementare tutte le varie fasi!!!!

	~GameManager();

private:
	int NumOfPlayer;
	Player players[MAX_NUM_PLAYERS];

	// Costruttore, ctor e opertore assegnamento private, cosi' da isolare il singleton
	GameManager() { }
	GameManager(const GameManager&);
	GameManager& operator=(const GameManager&);


public:



};

