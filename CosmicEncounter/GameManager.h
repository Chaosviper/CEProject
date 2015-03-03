#pragma once
#include <vector>
#include "Player.h"
#include "EventInterpreter.h"
#include <time.h>

typedef void(*Callable)();


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

	void GameLoop();

	~GameManager();

private:
	int NumOfPlayer;
	Player players[MAX_NUM_PLAYERS];

	EventInterpreter eventInterpreter;
	
	enum Phases{
		startturn = 0,
		regroup,
		destiny,
		launch,
		alliance,
		planning,
		reveal,
		resolution
	};

	Phases phase;
	Player* actual;

	bool waiting;// setted by phase function
	clock_t lastTime; // setted by phase function
	
	Callable actualTempPhase;
	bool hasBeenZapped;

	bool StartTurn();
	bool Regroup();
	bool Destiny();
	bool Launch();
	bool Alliance();
	bool Planning();
	bool Reveal();
	bool Resolution();

	Callable ProcessEvent(const EventInfo& info);

	// Costruttore, ctor e opertore assegnamento private, cosi' da isolare il singleton
	GameManager(): actualTempPhase(nullptr), phase(startturn), waiting(false), hasBeenZapped(false) { }
	GameManager(const GameManager&);
	GameManager& operator=(const GameManager&);



};

