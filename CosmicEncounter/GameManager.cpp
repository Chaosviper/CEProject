#include "GameManager.h"
#include "Alien.h"
#include "Card.h"
#include <assert.h>

void GameManager::AddPlayer(Player* newPlayer){
	players[NumOfPlayer++] = newPlayer;
}

Player* GameManager::GetPlayer(int index){

	if (index >= NumOfPlayer)
		return players[NumOfPlayer - 1];

	return players[index];
}





void GameManager::GameLoop(){

	// ** Se mi e' stato detto di aspettare e non sono passati 30 sec: controllo eventi
	if (waiting && (clock() - lastTime) / CLOCKS_PER_SEC < 30){
		EventInfo* actualEv = eventInterpreter.GetNextEvent();

		std::cout << "\r" << std::flush << (clock() - lastTime) / CLOCKS_PER_SEC ; // TODO: da rimuovere!! e' di debug!!

		// ** Se si e' verificato un evento..
		if (actualEv != nullptr){
			// ** .. Allora se l'evento e' una carta funzione (vedi riga sopra) e non ci sono eventi attivi settalo come evento attuale processandolo..
			if (actualTempPhase == nullptr && IsInterruptEvent(*actualEv)){

				actualTempPhase = ProcessEvent(*actualEv);
				// TODO: segno potere/carta come: attivato
				lastTime = clock(); // <-- Azzero il timer
			}
			// ** .. Altrimenti, se l'evento e' gia' presente, l'unica cosa che sto aspettando e' un possibile zap, se arriva (ed e' quello giusto) annullo l'azione segnata
			else if (actualTempPhase != nullptr && IsZapperEvent(*actualEv) && IsCorrectZapperType(*actualEv)){
				
				hasBeenZapped = !hasBeenZapped;
				// TODO: Segno la carta come giocata
				lastTime = clock(); // <-- Azzero il timer
			}
		}
	}
	else{
		if (actualTempPhase == nullptr){
			
			using namespace GameplayEnum;

			switch (phase)
			{
			case startturn :
				if (StartTurn()){
					std::cout << "Starting: Regroup phase" << std::endl;
					phase = static_cast<Phases>(1);
				}
				break;
			case regroup:
				if (Regroup()){
					std::cout << "Starting: Destiny phase" << std::endl;
					phase = static_cast<Phases>(static_cast<int>(phase) << 1);
				}
				break;
			case destiny:
				if (Destiny()){
					std::cout << "Starting: Launch phase" << std::endl;
					phase = static_cast<Phases>(static_cast<int>(phase) << 1);
				}
				break;
			case launch:
				if (Launch()){
					std::cout << "Starting: Alliance phase" << std::endl;
					phase = static_cast<Phases>(static_cast<int>(phase) << 1);
				}
				break;
			case alliance:
				if (Alliance()){
					std::cout << "Starting: Planning phase" << std::endl;
					phase = static_cast<Phases>(static_cast<int>(phase) << 1);
				}
				break;
			case planning:
				if (Planning()){
					std::cout << "Starting: Reveal phase" << std::endl;
					phase = static_cast<Phases>(static_cast<int>(phase) << 1);
				}
				break;
			case reveal:
				if (Reveal()){
					std::cout << "Starting: Resolution phase" << std::endl;
					phase = static_cast<Phases>(static_cast<int>(phase) << 1);
				}
				break;
			case resolution:
				if (Resolution()){
					std::cout << "Starting: StartTurn phase" << std::endl;
					phase = startturn; // TODO: non corretto, da sostituire!!
				}
				break;
			default:
				break;
			}

		}
		else{
			if (!hasBeenZapped){
				actualTempPhase();
			}

			//TODO: reset di tutti i parametri degli interrupt
			waiting = false;
			actualTempPhase = nullptr;
			typeOfCall = CallableType::None;
			hasBeenZapped = false;
		}
	}
}

//**************************************************************************************************************************
//*********************************************** TODO: DA IMPLEMENTARE ****************************************************
//**************************************************************************************************************************


bool GameManager::StartTurn(){
	waiting = true;
	lastTime = clock();
	return true;
}
bool GameManager::Regroup(){
	waiting = true;
	lastTime = clock();
	return true;
}
bool GameManager::Destiny(){
	waiting = true;
	lastTime = clock();
	return true;
}
bool GameManager::Launch(){
	waiting = true;
	lastTime = clock();
	return true;
}
bool GameManager::Alliance(){
	waiting = true;
	lastTime = clock();
	return true;
}
bool GameManager::Planning(){
	waiting = true;
	lastTime = clock();
	return true;
}
bool GameManager::Reveal(){
	waiting = true;
	lastTime = clock();
	return true;
}
bool GameManager::Resolution(){
	waiting = true;
	lastTime = clock();
	return true;
}


Callable GameManager::ProcessEvent(const EventInfo& info){
	Callable toReturn = nullptr;

	if (info.alienPowerPlayed != nullptr){
		typeOfCall = CallableType::AlienPower;
		toReturn = info.alienPowerPlayed->getPower();
	}
	else{
		if (info.cardPlayed->getCardType() == CardType::Artifact){
			typeOfCall = CallableType::Artifact;
			toReturn = info.cardPlayed->getCardFunction();
		}
		else if (info.cardPlayed->getCardType() == CardType::Flare){
			typeOfCall = CallableType::Flare;
			toReturn = info.cardPlayed->getCardFunction();
		}
		else{
			assert(typeOfCall != CallableType::None);
		}
	}

	return toReturn;
}

bool GameManager::IsInterruptEvent(const EventInfo& toProcess){
	
	// Check dell'alieno
	const Alien* x = toProcess.alienPowerPlayed;
	GameplayEnum::Phases allowedPhase;
	GameplayEnum::PlayerRole allowedPlayer;

	if (x != nullptr){
		allowedPhase = x->getPhases();
		allowedPlayer = x->getPlayerRole();

		// If the phase is contained in the phases allowed and also the player type is in the playerRole allowed, so it's a valid interrupt
		if ((allowedPhase & phase) != 0 && (getPlayerRole(toProcess.playerWhoPlayed) & allowedPlayer) != 0){
			return true;
		}
	}

	// Check della carta
	const Card* y = toProcess.cardPlayed;

	if (y != nullptr){
		allowedPhase = y->getPhases();
		allowedPlayer = y->getPlayerRole();
		// TODO: Controllo che sia un'artifact o una flare

		// If the phase is contained in the phases allowed and also the player type is in the playerRole allowed, so it's a valid interrupt
		if ((allowedPhase & phase) != 0 && (getPlayerRole(toProcess.playerWhoPlayed) & allowedPlayer) != 0){
			if (y->getIfZapper() == ZapType::None){
				return true;
			}
		}
	}

	return false;
}

bool GameManager::IsZapperEvent(const EventInfo& toProcess){
	// TODO: per ora l'alieno non necesita di avere il check dello zapper!
	const Card* y = toProcess.cardPlayed;
	GameplayEnum::Phases allowedPhase;
	GameplayEnum::PlayerRole allowedPlayer;

	if (y != nullptr){
		allowedPhase = y->getPhases();
		allowedPlayer = y->getPlayerRole();
		// TODO: Controllo che sia un'artifact (Superfluo forse)

		// If the phase is contained in the phases allowed and also the player type is in the playerRole allowed, so it's a valid interrupt
		if ((allowedPhase & phase) != 0 && (getPlayerRole(toProcess.playerWhoPlayed) & allowedPlayer) != 0 ){
			if (y->getIfZapper() != ZapType::None){
				return true;
			}
		}
	}

	return false;
}

bool GameManager::IsCorrectZapperType(const EventInfo& toCheck){
	// Check if has been played a power and the card played for zap is a cosmicZap
	if (toCheck.cardPlayed->getIfZapper() == ZapType::CosmicZap && typeOfCall == CallableType::AlienPower)
		return true;
	// Otherwise, check if has been played an artifact or flare card and the card played for zap is a cardZap
	else if (toCheck.cardPlayed->getIfZapper() == ZapType::CardZap && (typeOfCall == CallableType::Artifact || typeOfCall == CallableType::Flare))
		return true;
	// Otherwise the zapper isn't corrected
	return false;
}

GameplayEnum::PlayerRole GameManager::getPlayerRole(const Player& player){
	
	using namespace GameplayEnum;
	typedef std::list<Player*>::iterator myIter;

	// Check if attack or defense
	if (&player == actual)
		return Attack;
	else if (&player == enemy)
		return Defense;

	// Check if attack ally
	myIter end = attackAllies.end();
	
	for (myIter start = attackAllies.begin(); start != end; ++start){
		if ((*start) == actual)
			return AttackAlly;
	}

	// Check if defense ally
	end = defenseAllies.end();

	for (myIter start = defenseAllies.begin(); start != end; ++start){
		if ((*start) == actual)
			return DefenseAlly;
	}

	// Else return that is a any possible player.
	return PlayerRole::None;
}

GameManager::~GameManager()
{
}
