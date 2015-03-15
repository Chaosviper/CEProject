#pragma once
#include <queue>
#include <mutex>

namespace UIHandler{

	const int ASII_CODE_A = 65;
	const int ASII_CODE_0 = 48;

	class EventHandler
	{
		class RefCounter{
			int count;

		public:
			inline RefCounter() : count(1) { };

			inline void addRef(){ ++count; }
			inline int releaseRef(){ return --count; }
		};


		/* Any int16 contains information about: 
			1 bit most significant = played or not alien power, 
			next 3 bit = playerWhoPlayed,
			last 12 bit = card played (num based on hand of player)

			Example:
			0001 0000 0000 0100 => player 2 played 4th card in his hand!
		*/
		std::queue<__int16>* eventsQueue;
		std::queue<int>* requestedActionQueue;
		RefCounter* rc;

		std::mutex mux;

		bool InterpretInput(char actualInputDetected);
	public:
		// callable function when creating a thread
		void operator()();

		// Get the event, if any, and consume it
		__int16 getNextEvent();
		bool EventHandler::hasNextEvent();
		int getNextRequestedAction();
		bool EventHandler::hasNextAction();

		EventHandler();
		EventHandler(const EventHandler& toCopy);
		EventHandler& operator=(const EventHandler& toAssign);
		~EventHandler();

	};
}