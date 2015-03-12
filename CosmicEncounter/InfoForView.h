//#include <iosfwd>
#include <vector>
#include <time.h>

// ** FORWARD DECLARATIONS
class Card;
class Planet;
class GameManager;

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
	const std::vector<const Card>* hand;
	const std::vector<Planet*>* homeColonies;
	// Maybe foreign colonies pointer are useless.. Already have all the base Planet for player!
	const std::vector<Planet*>* foreignColonies;
	const std::string* name;
	const GameplayEnum::Color* color;
	// TODO:? Tecnologies and SpaceStation

	AlienInfoForView alienInfo; // it's already all constant inside AlienInfoForView!
};

struct InfoForView{
	std::vector<PlayerInfoForView> playerInfo; // 1 for each player

	const clock_t* lastClockSet;
	//TODO: GameManagerInformationForView (warpStatus, Deck/Graveyard, encounterInfo, CarteGiocateInQuestoEncounter?)
	
	CallbackFunctionOnEndAnimation onEndAnimation;
};