#pragma once
#include <thread>
#include "EventHandler.h"

// ** Forward declaration
class Player;
class Alien;
class Card;
// ** END

struct EventInfo{
	Player& playerWhoPlayed;
	const Card* cardPlayed;
	const Alien* alienPowerPlayed;

	EventInfo(Player& whoPlayed): playerWhoPlayed(whoPlayed), cardPlayed(nullptr), alienPowerPlayed(nullptr) { }
	// --> No Distructor because is only a containter, doesn't have the ownership of the resources <--
};

class EventInterpreter
{
	UIHandler::EventHandler eventHandler;
	std::thread eventHandlerThread;
public:
	EventInterpreter();

	EventInfo* GetNextEvent();

	~EventInterpreter();
};

