#include <iostream>
#include "Intro.h"

int main()
{
	std::string player_name;
	int earth = 0;
	int water = 0;
	int fire = 0;
	int air = 0;

	Print_Intro();
	enter_continue();
	player_name = Get_Player_Name();
	enter_continue();
	std::string player_affinity;
	player_affinity = Initiate_Quiz(player_name, earth, water, fire, air);
	enter_continue();
	std::cout << Quiz_Results(player_affinity, earth, water, fire, air);
	return 0;
}


