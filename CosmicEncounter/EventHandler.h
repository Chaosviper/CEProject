#pragma once
#include <vector>
namespace UIHandler{

	class EventHandler
	{
		bool isStopped;
		char actualInput;

		/* Any int16 contains information about: 
			1 bit most significant = played or not alien power, 
			next 3 bit = playerWhoPlayed,
			last 12 bit = card played (num based on hand of player)

			Example:
			0001 0000 0000 0100 => player 2 played 4th card in his hand!
		*/
		std::vector<__int16> eventsQueue;

		void InterpretInput();
	public:
		void operator()();
		EventHandler();
		~EventHandler();
		void StopReading();
	};
}