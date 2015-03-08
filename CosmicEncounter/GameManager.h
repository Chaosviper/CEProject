#pragma once
#include <vector>
#include "Player.h"
#include "EventInterpreter.h"
#include <time.h>
#include "GameplayEnum.h"

typedef void(*Callable)();


class GameManager
{
public:
	const static int MAX_NUM_PLAYERS = 8;

	inline static GameManager& GetGameManager(){
		static GameManager singleton;

		return singleton;
	}

	void AddPlayer(Player* newPlayer);
	Player* GetPlayer(int index);

	void GameLoop();

	~GameManager();

private:
	int NumOfPlayer;
	Player* players[MAX_NUM_PLAYERS];

	EventInterpreter eventInterpreter;
	

	GameplayEnum::Phases phase;
	Player* actual;
	Player* enemy;
	std::list<Player*> attackAllies;
	std::list<Player*> defenseAllies;

	bool waiting;// setted by phase function
	clock_t lastTime; // setted by phase function
	
	enum CallableType{
		Artifact,
		Flare,
		AlienPower,
		None
	};

	Callable actualTempPhase;
	CallableType typeOfCall;
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
	bool IsInterruptEvent(const EventInfo& toProcess);
	bool IsZapperEvent(const EventInfo& toProcess); 
	bool IsCorrectZapperType(const EventInfo& toCheck);

	GameplayEnum::PlayerRole getPlayerRole(const Player& player);

	// Costruttore, ctor e opertore assegnamento private, cosi' da isolare il singleton
	GameManager() : actualTempPhase(nullptr), phase(GameplayEnum::startturn), waiting(false), hasBeenZapped(false) { }
	GameManager(const GameManager&);
	GameManager& operator=(const GameManager&);



};

