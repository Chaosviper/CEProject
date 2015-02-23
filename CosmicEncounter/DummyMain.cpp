#include "EventHandler.h"
#include <thread>
#include <iostream>

int main(){
	UIHandler::EventHandler e;

	std::thread t1(e);

	int i = 0;
	while (true){
		i = e.getNextEvent();
		if (i != 0)
			std::cout << i << std::endl;
	}
	return 0;
}