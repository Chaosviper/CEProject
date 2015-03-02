#include "GameManager.h"
#include "EventInterpreter.h"

void GameManager::AddPlayer(const Player& newPlayer){
	players[NumOfPlayer++] = newPlayer;
}

Player& GameManager::GetPlayer(int index){

	if (index >= NumOfPlayer)
		return players[NumOfPlayer - 1];

	return players[index];
}





void GameManager::GameLoop(){
	EventInfo* actualEv = eventInterpreter.GetNextEvent();

	if (actualEv != nullptr){
		actualTempPhase = ProcessEvent(*actualEv);
	}

	// TODO: implementare timer 30 secondi!!

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
		actualTempPhase();
		// TODO: trovare un modo di settare la funzione actualTempPhase a null!!!
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
