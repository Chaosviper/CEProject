#include "EventHandler.h"
#include <iostream>
#include <string>

namespace UIHandler{

	void EventHandler::operator()(){
		char actualInputDetected;
		while (!isStopped){
			std::cin >> actualInputDetected;
			InterpretInput(actualInputDetected);
		}
	}

	EventHandler::EventHandler()
	{
		std::cout << "COSTRUCT!" << std::endl;
		isStopped = false;
	}


	EventHandler::~EventHandler()
	{
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

		std::cout << std::cin.peek();
		if (actualInputDetected == 'P' && std::cin.peek() != '\n'){
			std::cin >> actualInputDetected;

			playerWhoPlayed = static_cast<int>(actualInputDetected) - ASII_CODE_0;

			if (playerWhoPlayed >= 0 && playerWhoPlayed < 10 && std::cin.peek() != '\n'){
				std::cin >> actualInputDetected;

				if (actualInputDetected == '-' && std::cin.peek() != '\n'){
					std::cin >> actualInputDetected;

					// Alien power activated
					if (actualInputDetected == 'X'){
						//TODO: Bit mask for alien power
						inputBitMaskResult = 1 << 15; // bit of alien power activated
						inputBitMaskResult = inputBitMaskResult | (playerWhoPlayed << 12); // bits of player who played

						eventsQueue.push_back(inputBitMaskResult);

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
							//TODO: Bit mask for card played
							inputBitMaskResult = playerWhoPlayed << 12; // bits of player who played
							inputBitMaskResult = inputBitMaskResult | cardPlayed;

							eventsQueue.push_back(inputBitMaskResult);

							toReturn = true;
						}
					}
				}
			}
		}

		return toReturn;
	}

}