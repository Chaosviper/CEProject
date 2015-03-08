#include "GameManager.h"
#include <thread>
#include <iostream>

int main(){
	/*UIHandler::EventHandler e;

	std::thread t1(e);

	int i = 0;
	while (true){
		i = e.getNextEvent();
		if (i != 0)
			std::cout << i << std::endl;
	}
	return 0;*/

	GameManager& gm = GameManager::GetGameManager();

	Alien alien1("alien1", "", AlienDifficulty::Easy, GameplayEnum::Base, 
				GameplayEnum::Phases::planning, GameplayEnum::PlayerRole::MainPlayer, nullptr);
	Player a("Player1", GameplayEnum::Color::Black, alien1), b("Player2", GameplayEnum::Color::Red, alien1);
	gm.AddPlayer(&a);
	gm.AddPlayer(&b);
	
	while (1)
	gm.GameLoop();
}