#include "GameManager.h"
#include "Alien.h"
#include "Card.h"

void GameManager::AddPlayer(const Player& newPlayer){
	players[NumOfPlayer++] = newPlayer;
}

Player& GameManager::GetPlayer(int index){

	if (index >= NumOfPlayer)
		return players[NumOfPlayer - 1];

	return players[index];
}





void GameManager::GameLoop(){

	// ** Se mi e' stato detto di aspettare e non sono passati 30 sec: controllo eventi
	if (waiting && (clock() - lastTime) / CLOCKS_PER_SEC > 30){
		EventInfo* actualEv = eventInterpreter.GetNextEvent();

		// ** Se si e' verificato un evento..
		if (actualEv != nullptr){
			// ** .. Allora se l'evento e' una carta funzione (vedi riga sopra) e non ci sono eventi attivi settalo come evento attuale processandolo..
			if (actualTempPhase != nullptr && IsInterruptEvent(*actualEv)){
				actualTempPhase = ProcessEvent(*actualEv);
				// TODO: segno potere/carta come: attivato
				lastTime = clock(); // <-- Azzero il timer
			}
			// ** .. Altrimenti, se l'evento e' gia' presente, l'unica cosa che sto aspettando e' un possibile zap, se arriva (ed e' quello giusto) annullo l'azione segnata
			else if(IsZapperEvent(*actualEv)){ // TODO: controllare che lo zap sia quello di tipo corretto
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
				if (StartTurn())
					phase = static_cast<Phases>(static_cast<int>(phase) << 1);
				break;
			case regroup:
				if (Regroup())
					phase = static_cast<Phases>(static_cast<int>(phase) << 1);
				break;
			case destiny:
				if (Destiny())
					phase = static_cast<Phases>(static_cast<int>(phase) << 1);
				break;
			case launch:
				if (Launch())
					phase = static_cast<Phases>(static_cast<int>(phase) << 1);
				break;
			case alliance:
				if (Alliance())
					phase = static_cast<Phases>(static_cast<int>(phase) << 1);
				break;
			case planning:
				if (Planning())
					phase = static_cast<Phases>(static_cast<int>(phase) << 1);
				break;
			case reveal:
				if (Reveal())
					phase = static_cast<Phases>(static_cast<int>(phase) << 1);
				break;
			case resolution:
				if (Resolution())
					phase = startturn; // TODO: non corretto, da sostituire!!
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
			hasBeenZapped = false;
		}
	}
}

//**************************************************************************************************************************
//*********************************************** TODO: DA IMPLEMENTARE ****************************************************
//**************************************************************************************************************************


bool GameManager::StartTurn(){
	waiting = true;
	return true;
}
bool GameManager::Regroup(){
	waiting = true;
	return true;
}
bool GameManager::Destiny(){
	waiting = true;
	return true;
}
bool GameManager::Launch(){
	waiting = true;
	return true;
}
bool GameManager::Alliance(){
	waiting = true;
	return true;
}
bool GameManager::Planning(){
	waiting = true;
	return true;
}
bool GameManager::Reveal(){
	waiting = true;
	return true;
}
bool GameManager::Resolution(){
	waiting = true;
	return true;
}


Callable GameManager::ProcessEvent(const EventInfo& info){
	// TODO: implementare il process event! (CHIAMERA' LA FUNZIONE E, PROBABILMENTE, LA RESTITUIRA')
	return nullptr;
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
		// TODO: Controllo che sia un'artifact

		// If the phase is contained in the phases allowed and also the player type is in the playerRole allowed, so it's a valid interrupt
		if ((allowedPhase & phase) != 0 && (getPlayerRole(toProcess.playerWhoPlayed) & allowedPlayer) != 0 ){
			if (y->getIfZapper() != ZapType::None){
				return true;
			}
		}
	}

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

	// Else return that is an any player.
	return AnyPlayer;
}

GameManager::~GameManager()
{
}
