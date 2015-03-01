#include "EventInterpreter.h"
#include "Player.h"


EventInterpreter::EventInterpreter()
{
	eventHandler = UIHandler::EventHandler();

	eventHandlerThread = std::thread(eventHandler);
}

EventInfo* EventInterpreter::GetNextEvent(){

	__int16 nextEvent = eventHandler.getNextEvent();

	// TODO: parsa il nextEvent interrogando il GM per creare un EVENTINFO da poi restituire!

	return new EventInfo(*(new Player())); // <-- TODO: da rimuovere
}


EventInterpreter::~EventInterpreter()
{
	eventHandlerThread.detach();
}
