#include "GameManager.h"

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
		if (actualEv != nullptr){ // TODO: implementare una funzione che controlla: se e' nullptr o se e' una carta funzione (flare o artifact non zap)
			// ** .. Allora se l'evento e' una carta funzione (vedi riga sopra) e non ci sono eventi attivi settalo come evento attuale processandolo..
			if (actualTempPhase != nullptr){
				actualTempPhase = ProcessEvent(*actualEv);
				// TODO: segno potere/carta come: attivato
				lastTime = clock(); // <-- Azzero il timer
			}
			// ** .. Altrimenti, se l'evento e' gia' presente, l'unica cosa che sto aspettando e' un possibile zap, se arriva (ed e' quello giusto) annullo l'azione segnata
			else if(/* TODO: controllo se e' uno zap la carta giocata */ false){
				hasBeenZapped = !hasBeenZapped;
				// TODO: Segno la carta come giocata
				lastTime = clock(); // <-- Azzero il timer
			}
		}
	}
	else{
		if (actualTempPhase == nullptr){

			switch (phase)
			{
			case startturn :
				if (StartTurn())
					phase = static_cast<Phases>(static_cast<int>(phase) + 1);
				break;
			case regroup:
				if (Regroup())
					phase = static_cast<Phases>(static_cast<int>(phase)+1);
				break;
			case destiny:
				if (Destiny())
					phase = static_cast<Phases>(static_cast<int>(phase)+1);
				break;
			case launch:
				if (Launch())
					phase = static_cast<Phases>(static_cast<int>(phase)+1);
				break;
			case alliance:
				if (Alliance())
					phase = static_cast<Phases>(static_cast<int>(phase)+1);
				break;
			case planning:
				if (Planning())
					phase = static_cast<Phases>(static_cast<int>(phase)+1);
				break;
			case reveal:
				if (Reveal())
					phase = static_cast<Phases>(static_cast<int>(phase)+1);
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
	return true;
}
bool GameManager::Regroup(){
	return true;
}
bool GameManager::Destiny(){
	return true;
}
bool GameManager::Launch(){
	return true;
}
bool GameManager::Alliance(){
	return true;
}
bool GameManager::Planning(){
	return true;
}
bool GameManager::Reveal(){
	return true;
}
bool GameManager::Resolution(){
	return true;
}


Callable GameManager::ProcessEvent(const EventInfo& info){
	// TODO: implementare il process event! (CHIAMERA' LA FUNZIONE E, PROBABILMENTE, LA RESTITUIRA')
	return nullptr;
}

GameManager::~GameManager()
{
}
