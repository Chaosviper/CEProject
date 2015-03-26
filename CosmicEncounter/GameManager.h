#pragma once
#include <vector>
#include "Player.h"
#include "EventInterpreter.h"
#include <time.h>
#include "GameplayEnum.h"
#include "Deck.h"
#include "DestinyDeck.h"
#include "HyperspaceGate.h"
#include "Warp.h"
// Include for view
#include "ViewMiddleLayer.h"
#include "ConsoleView.h"
// End

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

	void InitGame(); // <-- TO CALL AFTER THE ADDITION OF ALL PLAYER!
	void GameLoop();

	~GameManager();

private:
	int NumOfPlayer;
	Player* players[MAX_NUM_PLAYERS];

	Deck deck;
	DestinyDeck destinyDeck;
	HyperspaceGate hyperspaceGate;
	Warp warp;

	// Event Input Handler
	EventInterpreter eventInterpreter;
	// View Manager
	ViewMiddleLayer<ConsoleView> viewManager;

	GameplayEnum::Phases phase;
	Player* actual;
	Player* enemy;
	std::list<Player*> attackAllies;
	std::list<Player*> defenseAllies;
	std::list<const Card*> cardPlayedInThisEncounter;

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
	EventInfo infoOfFlarePlayed;

	bool StartTurn();
	bool Regroup();
	bool Destiny();
	bool Launch();
	bool Alliance();
	bool Planning();
	bool Reveal();
	bool Resolution();

	Callable ProcessEvent(EventInfo& info);
	bool IsInterruptEvent(const EventInfo& toProcess);
	bool IsZapperEvent(const EventInfo& toProcess); 
	bool IsCorrectZapperType(const EventInfo& toCheck);

	// Funzioni di supporto
	GameplayEnum::PlayerRole getPlayerRole(const Player& player);
	void dealNewHand(Player& player);

	// Costruttore, ctor e opertore assegnamento private, cosi' da isolare il singleton
	GameManager();
	GameManager(const GameManager&);
	GameManager& operator=(const GameManager&);



};

// Callback functions

// this function "Mention" GameManager and "Supplied with" GameManager. => OnANimationEnded is "part of" GameManager. 
//	it's outside GameManager because can be implemented with only the "pubblic interface" of GameManager
int OnAnimationEnded(GameManager&);
