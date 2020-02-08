#pragma once

void Print_Intro();
std::string Get_Player_Name();
std::string Initiate_Quiz(std::string player_name);
std::string Quiz_Results(const std::string& elemental_affinity);
char Quiz_Response(std::string& elemental_affinity);
void enter_continue();