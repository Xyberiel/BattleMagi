#include <iostream>
#include "Intro.h"

int main()
{
	std::string player_name;

	Print_Intro();
	enter_continue();
	player_name = Get_Player_Name();
	enter_continue();
	std::string player_affinity;
	player_affinity = Initiate_Quiz(player_name);
	enter_continue();
	std::cout << Quiz_Results(player_affinity);
	return 0;
}


