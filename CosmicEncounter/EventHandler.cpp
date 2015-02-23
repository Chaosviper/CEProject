#include "EventHandler.h"
#include <iostream>
#include <string>
#include <queue>

namespace UIHandler{

	void EventHandler::operator()(){
		char actualInputDetected;
		while (!isStopped){
			std::cin >> actualInputDetected;
			InterpretInput(actualInputDetected);
		}
	}

	EventHandler::EventHandler() : isStopped(false)
	{
		std::cout << "COSTRUCT!" << std::endl;

		rc = new RefCounter();
		eventsQueue = new std::queue<__int16>();
	}

	EventHandler::EventHandler(const EventHandler& toCopy){
		std::cout << "COPYED!" << std::endl;
		
		// Incrementing refCounter
		toCopy.rc->addRef(); //NOTA: perche' mi consente di modificare se non e' const "addRef()"???

		// Shallow copy of the queue because when creating a new thread, the thread copy by value!
		eventsQueue = toCopy.eventsQueue;

		isStopped = false;
		rc = toCopy.rc;
	}

	EventHandler& EventHandler::operator=(const EventHandler& toAssign){

		// Check if isn't it self
		if (this != &toAssign){
			std::cout << "ASSIGNED" << std::endl;

			// Decrese old refCounter and check if is the last instance of the class that will be overritten, in order to relese the object!
			if (rc->releaseRef() <= 0){
				delete eventsQueue;
				delete rc;
			}

			// Incrementing new refCounter
			toAssign.rc->addRef(); //NOTA: perche' mi consente di modificare se non e' const "addRef()"???

			// Shallow copy of the queue because when creating a new thread, the thread copy by value!
			eventsQueue = toAssign.eventsQueue;

			isStopped = toAssign.isStopped;
			rc = toAssign.rc;
		}

		return *(this);
	}

	EventHandler::~EventHandler()
	{
		std::cout << "DESTROYED" << std::endl;

		// Decrese refCounter and check if is the last instance of the class in order to relese the object!
		if (rc->releaseRef() <= 0){
			delete eventsQueue;
			delete rc;
		}
	}

	void EventHandler::StopReading(){
		isStopped = true;
	}

	bool EventHandler::InterpretInput(char actualInputDetected){
		bool toReturn = false;
		int playerWhoPlayed = -1;
		int actualNumber = -1;
		int cardPlayed = -1;
		int loopsNum = 0;
		std::string tempNum;

		__int16 inputBitMaskResult = 0;

		if (actualInputDetected == 'P' && std::cin.peek() != '\n'){
			std::cin >> actualInputDetected;

			playerWhoPlayed = static_cast<int>(actualInputDetected) - ASII_CODE_0;

			if (playerWhoPlayed >= 0 && playerWhoPlayed < 10 && std::cin.peek() != '\n'){
				std::cin >> actualInputDetected;

				if (actualInputDetected == '-' && std::cin.peek() != '\n'){
					std::cin >> actualInputDetected;

					// Alien power activated
					if (actualInputDetected == 'X'){
						inputBitMaskResult = 1 << 15; // bit of alien power activated
						inputBitMaskResult = inputBitMaskResult | (playerWhoPlayed << 12); // bits of player who played

						eventsQueue->push(inputBitMaskResult);

						toReturn = true;
					}
					// Card played
					else{
						// ** Check if isn't a number exit from the while
						actualNumber = static_cast<int>(actualInputDetected)-ASII_CODE_0;
						if (actualNumber < 0 && actualNumber >= 10){
							
							return toReturn;
						}
						// ** END
						tempNum += actualInputDetected;
						
						while (std::cin.peek() != '\n'){
							std::cin >> actualInputDetected;

							// ** Check if isn't a number exit from the while
							actualNumber = static_cast<int>(actualInputDetected)-ASII_CODE_0;
							if (actualNumber < 0 && actualNumber >= 10){
								return toReturn;
							}
							// ** END

							tempNum += actualInputDetected;
							
						};
						
						cardPlayed = std::stoi(tempNum);
						
						if (cardPlayed >= 0 && cardPlayed < 0xfff){
							inputBitMaskResult = playerWhoPlayed << 12; // bits of player who played
							inputBitMaskResult = inputBitMaskResult | cardPlayed;

							eventsQueue->push(inputBitMaskResult);

							toReturn = true;
						}
					}
				}
			}
		}

		return toReturn;
	}

	__int16 EventHandler::getNextEvent(){
		__int16 toReturn = 0;

		// Consuming the event
		if (!eventsQueue->empty()){
			toReturn = eventsQueue->front();
			eventsQueue->pop();
		}

		return toReturn;
	}
}

