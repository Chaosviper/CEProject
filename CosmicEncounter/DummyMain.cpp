#include "EventHandler.h"
#include <thread>
#include <iostream>

int main(){
	UIHandler::EventHandler e;

	std::thread t1(e);
	while (true){
		;
	}
	return 0;
}