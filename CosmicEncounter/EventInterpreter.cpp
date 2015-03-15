#include "EventInterpreter.h"
#include "GameManager.h"


EventInterpreter::EventInterpreter()
{
	eventHandler = UIHandler::EventHandler();

	eventHandlerThread = std::thread(eventHandler);
}

bool EventInterpreter::HasNextEvent(){
	return eventHandler.hasNextEvent();
}

// NOTA: lo faccio con la copia dell'oggetto perche' altrimenti dovrei allocarlo qui e deallocarlo fuori.. Bad pratice
EventInfo EventInterpreter::GetNextEvent(){

	EventInfo toReturn;

	__int16 nextEvent = eventHandler.getNextEvent();

	if (nextEvent != 0){
		GameManager& GM = GameManager::GetGameManager();

		// mask for player: 0111 0000 0000 0000 => mask: 7000
		int player = (nextEvent & 0x7000) >> 12;
		// mask for alien power 1000 0000 0000 0000. Put the most significant bit in the less significant bit and mask it
		int activatedAlienPower = (nextEvent >> 15) & 0x1;
		// mask for card played 0000 1111 1111 1111 => mask: fff
		int cardPlayed = nextEvent & 0xfff;

		Player* whoPlayed = GM.GetPlayer(player);

		toReturn.playerWhoPlayed = whoPlayed;
		if (activatedAlienPower > 0){
			toReturn.alienPowerPlayed = &(whoPlayed->GetAlien());
		}
		else{
			toReturn.cardPlayed = whoPlayed->GetCardPlayed(cardPlayed);
		}
	}

	return toReturn;
}


EventInterpreter::~EventInterpreter()
{
	eventHandlerThread.detach();
}
