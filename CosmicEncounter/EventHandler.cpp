#include "EventHandler.h"
#include <iostream>

namespace UIHandler{

	void EventHandler::operator()(){

		while (!isStopped){
			std::cin >> actualInput;
			InterpretInput();
			// TODO: gestire parole lunghe (es p1 gioca carta 2:"p1 2"). Soluzione temporale
		}
	}

	EventHandler::EventHandler()
	{
		std::cout << "COSTRUCT!" << std::endl;
		isStopped = false;
		actualInput = -1;
	}


	EventHandler::~EventHandler()
	{
	}

	void EventHandler::StopReading(){
		isStopped = true;
	}

	void EventHandler::InterpretInput(){
		// TODO: implementare gestione input in maschera di bit
		std::cout << actualInput;
	}

}