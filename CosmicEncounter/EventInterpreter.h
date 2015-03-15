#pragma once
#include <thread>
#include "EventHandler.h"

// ** Forward declaration
class Player;
class Alien;
class Card;
// ** END

struct EventInfo{
	Player* playerWhoPlayed;
	const Card* cardPlayed;
	Alien* alienPowerPlayed;

	EventInfo(): playerWhoPlayed(nullptr), cardPlayed(nullptr), alienPowerPlayed(nullptr) { }
	void flush() { playerWhoPlayed = nullptr; cardPlayed = nullptr; alienPowerPlayed = nullptr; }
	EventInfo(Player* whoPlayed): playerWhoPlayed(whoPlayed), cardPlayed(nullptr), alienPowerPlayed(nullptr) { }
	~EventInfo() { }
	// --> No Distructor because is only a containter, doesn't have the ownership of the resources <--
};

class EventInterpreter
{
	UIHandler::EventHandler eventHandler;
	std::thread eventHandlerThread;
public:
	EventInterpreter();

	bool HasNextEvent();
	EventInfo GetNextEvent();

	~EventInterpreter();
};

