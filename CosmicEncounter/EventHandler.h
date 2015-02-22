#pragma once
#include <vector>
namespace UIHandler{

	const int ASII_CODE_A = 65;
	const int ASII_CODE_0 = 48;

	class EventHandler
	{
		bool isStopped;

		/* Any int16 contains information about: 
			1 bit most significant = played or not alien power, 
			next 3 bit = playerWhoPlayed,
			last 12 bit = card played (num based on hand of player)

			Example:
			0001 0000 0000 0100 => player 2 played 4th card in his hand!
		*/
		std::vector<__int16> eventsQueue;

		bool InterpretInput(char actualInputDetected);
	public:
		void operator()();
		EventHandler();
		~EventHandler();
		void StopReading();
	};
}