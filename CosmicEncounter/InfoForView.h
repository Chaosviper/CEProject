//#include <iosfwd>
#pragma once
#include <vector>
#include <list>
#include <time.h>

// ** FORWARD DECLARATIONS
class Card;
class Planet;
class GameManager;
class Warp;
class Deck;
class DestinyDeck;
class HyperspaceGate;

namespace GameplayEnum{
	enum Color;
	enum Phases;
	enum PlayerRole;
}
// ** End

typedef int(*CallbackFunctionOnEndAnimation)(GameManager&);

// All of the variable are pointer, in this way, once are initialized with the 
//		models values, they're self updated

struct AlienInfoForView{
	const GameplayEnum::Phases* phaseAllowed;
	const GameplayEnum::PlayerRole* playerRoleAllowed;
	const std::string* description;
	const std::string* name;

	const bool* isPowerAlreadyActivated;
};

struct PlayerInfoForView{
	const std::vector<const Card*>* hand;
	const std::vector<Planet*>* homeColonies;
	// Maybe foreign colonies pointer are useless.. Already have all the base Planet for player!
	const std::vector<Planet*>* foreignColonies;
	const std::string* name;
	const GameplayEnum::Color* color;
	// TODO:? Tecnologies and SpaceStation

	AlienInfoForView alienInfo; // it's already all constant inside AlienInfoForView!
};

struct EncounterInfoForView{
	const GameplayEnum::Phases* phase;

	int actual; // Index of PlayerInfoForView list! OWNERSHIP: SELF
	int enemy; // Index of PlayerInfoForView list! OWNERSHIP: SELF
	// NOTA: No info on deck because are sensible information and the view doesn't have knowledge of them
	std::list<int> attackAllies; // Index of PlayerInfoForView list! OWNERSHIP: SELF
	std::list<int> defenseAllies; // Index of PlayerInfoForView list! OWNERSHIP: SELF
	// NOTA: Info of number of ships isn't important!! The information is aready in the Warp, HyperspaceGate and Planet! :D

	// NOTA: ** Forse da rimuovere! ->
	const Card* attackEncounter;
	const Card* defenseEncounter;
	const std::list<const Card*>* otherCardPlayed;
	// ** <- END

	const std::list<const Card*>* cardPlayedInThisEncounter;
};

struct GMStateInfoForView{
	const Warp* warpInfo;
	const Deck* deck;
	const DestinyDeck* destinyDeck;
	const HyperspaceGate* hyperspaceGate;

	EncounterInfoForView encounterInfo;
};

struct InfoForView{
	std::vector<PlayerInfoForView> playerInfo; // 1 for each player
	GMStateInfoForView gmInfo;

	const clock_t* raminingTime; // seconds waiting the event (coutdown)
	
	CallbackFunctionOnEndAnimation onEndAnimation;
};