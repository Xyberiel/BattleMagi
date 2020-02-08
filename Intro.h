#pragma once

void Print_Intro();
std::string Get_Player_Name();
std::string Initiate_Quiz(std::string player_name, int& earth, int& water, int& fire, int& air);
std::string Quiz_Results(const std::string& elemental_affinity, int earth, int water, int fire, int air);
char Quiz_Response(std::string& elemental_affinity, int& earth, int& water, int& fire, int& air);
void enter_continue();