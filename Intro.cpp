#include<iostream>
#include<string>
#include<iomanip>
#include <limits>


void Print_Intro()
{
	std::cout << "\nWelcome to Battle Magi!\n\n";
	std::cout << "__________        __    __  .__              _____                .__._.\n";
	std::cout << "\\______   \\____ _/  |__/  |_|  |   ____     /     \\ _____    ____ |__| |\n";
	std::cout << " |    |  _|__  \\\\   __\\   __\\  | _/ __ \\   /  \\ /  \\\\__  \\  / ___\\|  | |\n";
	std::cout << " |    |   \\/ __ \\|  |  |  | |  |_\\  ___/  /    Y    \\/ __ \\/ /_/  >  |\\|\n";
	std::cout << " |______  (____  /__|  |__| |____/\\___  > \\____|__  (____  |___  /|__|__\n";
	std::cout << "        \\/     \\/                     \\/          \\/     \\/_____/     \\/\n";
	std::cout << std::endl;

	std::cout << "Battle Magi is a world where people attuned to the four basic elements are called upon for great adventure!\n";
	std::cout << "Some Magi are destined to walk a path of virtue, while others have a predisposition of malevolence...\n";
	std::cout << "Ultimately, the path you walk is yours to choose!\n";
}


void enter_continue()
{
	std::cout << "Press Enter to Continue...\n\n\n\n\n";
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

std::string Get_Player_Name()
{
	std::string player_name;
	bool correct_name = false;
	std::string user_response;

	do
	{
		std::cout << "\nWhat is your Magi name?\n";
		std::getline(std::cin, player_name);
		if (islower(player_name[0]))
		{
			player_name[0] = toupper(player_name[0]);
		}
		std::cout << "\nNice to meet you... " << player_name << ". Is that correct? Type yes or no...\n";
		std::getline(std::cin, user_response);
		if (isupper(user_response[0]))
		{
			user_response = tolower(user_response[0]);
		}

		if (user_response[0] == 'y')
		{
			std::cout << "\nGreat! Let's carry on then, " << player_name << "!\n";
			correct_name = true;
		}
		else
		{
			std::cout << "I'm sorry, I can't translate fat fingers. Let's try again.\n";
			correct_name = false;
		}

	} while (correct_name == false);
	return player_name;
}

char Quiz_Response(std::string &elemental_affinity, int &earth, int &water, int &fire, int &air)
{
	bool response_good = false;
	char response[256];
	do
	{
		std::cin.getline(response, 256);
		if (islower(response[0]))
		{
			response[0] = toupper(response[0]);
		}
		switch (response[0])
		{
		case 'A':
			earth++;
			response_good = true;
			break;
		case'B':
			water++;
			response_good = true;
			break;
		case 'C':
			fire++;
			response_good = true;
			break;
		case 'D':
			air++;
			response_good = true;
			break;
		default:
			std::cout << "Sorry, that wasn't an option... Try entering either A, B, C, or D...\n";
			response_good = false;
			break;
		}
	} while (response_good == false);
	std::cout << "You chose " << response[0] << "...\n\n\n\n\n";
	elemental_affinity += response[0];
	return response[0];
}

std::string Quiz_Results(const std::string &elemental_affinity, int earth, int water, int fire, int air)
{
	std::string results = "";
	std::cout << elemental_affinity << "\n";
	std::cout << "You scored: " << earth << " points in EARTH!\n";
	std::cout << "You scored: " << water << " points in WATER!\n";
	std::cout << "You scored: " << fire << " points in FIRE!\n";
	std::cout << "You scored: " << air << " points in AIR!\n";

	if (earth > water && earth > fire && earth > air)
	{
		std::cout << "You scored highest with earth affinity!\n";
	}
	else if (water > earth && water > fire && water > air)
	{
		std::cout << "You scored highest with water affinity!\n";
	}
	else if (fire > earth && fire > water && fire > air)
	{
		std::cout << "You scored highest with fire affinity!\n";
	}
	else if (air > earth && air > water && air > fire)
	{
		std::cout << "You scored highest with air affinity!\n";
	}
	else if (earth == water && earth > fire && earth > air)
	{
		std::cout << "You are a good balance of earth and water and have an affinity for life magic!\n";
	}
	else if (earth > water && earth == fire && earth > air)
	{
		std::cout << "You are a good balance of earth and fire and have have the ability to manipulate metal and magma!\n";
	}
	else if (earth > water && earth > fire && earth == air)
	{
		std::cout << "You have a good balance of earth and air. Manipulating sand is second nature to you!\n";
	}
	else if (water > earth && water == fire && water > air)
	{
		std::cout << "You are balanced between water and fire and are able to manipulate them to make steam!\n";
	}
	else if (water > earth && water > fire&& water == air)
	{
		std::cout << "You are multitalented with water and air and can bring them together to make mist and ice!\n";
	}
	else if (air > earth&& air > water&& air == fire)
	{
		std::cout << "With your affinity for fire and air, you are able to manipulate lightning!\n";
	}
	else
	{
		std::cout << "Wow! You are likely well balanced between multiple elements! Unfortunately you didn't score high enough in any particular affinity...\n";
	}

	return results;
}

std::string Initiate_Quiz(std::string player_name, int &earth, int &water, int &fire, int &air)
{
	std::string elemental_affinity = "";

	std::cout << "\nAlright " << player_name << ", we are going to test your elemental affinity now!\n";
	std::cout << "\nWe're going to go through a series of questions to best determine your element.\n";
	std::cout << "\n\n!!!!!!!!!!FIRST A MANDATORY DISCLAIMER!!!!!!!!!!\n\n";

	std::cout << "People are too complex to be defined by such a limited questionaire,\n especially one with zero professional input or supervision.\n";
	std::cout << "This quiz is intended ONLY for fun and to demonstrate the programmers\n working knowledge of the C++ programming language.\n";
	std::cout << "The end results are not to be taken seriously and should not be understood\n to constitute any type of diagnosis or healthcare recommendation.\n";
	std::cout << "THESE STATEMENTS HAVE NOT BEEN EVALUATED BY THE FOOD AND DRUG ADMINISTRATION.\n";
	std::cout << "THIS PRODUCT IS NOT INTENDED TO DIAGNOSE, TREAT, CURE, OR PREVENT ANY DISEASE.\n";
	std::cout << "By proceeding you, " << player_name << ", acknowledge the author claims\n no responsibility or liability of damages.\n";
	std::cout << "Donations are welcome but never expected.\n";
	std::cout << "\nAlright, let's carry on!\n";
	enter_continue();


	std::cout << "QUESTION ONE:\n";
	std::cout << "You just witnessed something traumatic, how do you react?\n";
	std::cout << "A.) Remain stoic, you are unwaverable even in the worst of situations.\n";
	std::cout << "B.) Internalize your feelings as you don't want to burden others with them.\n";
	std::cout << "C.) You react passionately and are likely very expressive with your feelings.\n";
	std::cout << "D.) You are disjointed and may react in unpredictable ways. Who knows?\n";
	Quiz_Response(elemental_affinity, earth, water, fire, air);

	std::cout << "QUESTION TWO:\n";
	std::cout << "Someone close to you is suffering, what do you do?\n";
	std::cout << "A.) You provide a strong foundation for others to rebuild themselves.\n";
	std::cout << "B.) You are deeply empathetic and care greatly for their suffering.\n";
	std::cout << "C.) You are very compassionate and seek a means to end their suffering.\n";
	std::cout << "D.) Sympathy may be the best you can offer. Emotions are complicated.\n";
	Quiz_Response(elemental_affinity, earth, water, fire, air);

	std::cout << "QUESTION THREE:\n";
	std::cout << "How do you prefer to travel?\n";
	std::cout << "A.) You tend to travel alone, focused on your objective. You could survive easily in the wilderness if needed.\n";
	std::cout << "B.) Someone probably dragged you along, as you are typically reclusive. You would be a hermit if you could.\n";
	std::cout << "C.) You are a great travel companion and always bring enough energy for everyone!\n";
	std::cout << "D.) You are either leading a party or making friends all along the way. Your charisma is known far and wide!\n";
	Quiz_Response(elemental_affinity, earth, water, fire, air);

	std::cout << "QUESTION FOUR:\n";
	std::cout << "How would you take over the world if you were a villain?\n";
	std::cout << "A.) As a hardworking politician single mindedly focused on ruling from the top.\n Everything must obey my new world order.\n";
	std::cout << "B.) I would likely use religion to my advantage, painting the government to be the villains oppressing the people.\n Hope is power and I make sure to be the peoples only hope.\n";
	std::cout << "C.) I would conquer and destroy my enemies with brute force if necessary.\n None shall oppose me less they invoke my wrath!\n";
	std::cout << "D.) I am an expert at manipulating the hearts and minds of the people.\n I am a natural leader, and can easily play to the weaknesses of others.\n I will lead a revolution against the government and the people will appoint me their new leader!\n";
	Quiz_Response(elemental_affinity, earth, water, fire, air);

	std::cout << "QUESTION FIVE:\n";
	std::cout << "Which is a greater fear or weakness for you?\n";
	std::cout << "A.) Pure chaos. There is no sense of order anywhere. Nothing you do seems to be right and\n you can't seem to get a grasp of the situation.\n";
	std::cout << "B.) You are surrounded by people and you fear what they may think of you.\n You lack the self-confidence to be the person you wish everyone knew you as.\n";
	std::cout << "C.) People are holding you back and you don't get an opportunity to express yourself or achieve your goals.\n You are constantly being shut down by people or systems in place.\n";
	std::cout << "D.) You are completely isolated from the world around you, unable to reach out and connect with it.\n You feel like you are drowning in your own introspection.\n";
	Quiz_Response(elemental_affinity, earth, water, fire, air);

	std::cout << "QUESTION SIX:\n";
	std::cout << "What would be a more ideal power for you as a superhero?\n";
	std::cout << "A.) Super strength and toughness! Few things can actually challenge my physical limits!\n";
	std::cout << "B.) I prefer quirky abilities or powers that can support others.\n I prefer not to be directly in combat myself if I can help it.\n";
	std::cout << "C.) RAW POWER! I wish to obliterate my enemies in the most extreme and flashy method possible!\n My enemies will only be remembered by their utterly dramatic and devastating defeat!\n";
	std::cout << "D.) I need an ability with the most versatility and utility that really allows me to express my creativity.\n There is nothing I cannot accomplish with my own ability.\n";
	Quiz_Response(elemental_affinity, earth, water, fire, air);

	std::cout << "QUESTION SEVEN:\n";
	std::cout << "How do you prefer to dress?\n";
	std::cout << "A.) I prefer to dress practical. I'm ready for any situation at any time.\n Every article of clothing has a purpose.\n";
	std::cout << "B.) I prefer to blend in with the situation and environment.\n I don't want to draw any unwanted attention to myself.\n";
	std::cout << "C.) My clothes reflect my energy. I may also dress flashy or dramatic.\n It's not uncommon for me to dress up for the entertainment of it.\n";
	std::cout << "D.) If you are looking for me, you can find me setting the latest fashion trends.\n";
	Quiz_Response(elemental_affinity, earth, water, fire, air);

	std::cout << "QUESTION EIGHT:\n";
	std::cout << "Which do you prefer to keep around?\n";
	std::cout << "A.) Plants. They help me feel calm and connected to nature.\n";
	std::cout << "B.) Cats are a nice low maintenance pet that also provide emotional support when needed.\n Fish tanks can be cool too.\n";
	std::cout << "C.) Dogs are pretty much the only thing that can keep up with me!\n";
	std::cout << "D.) I'm cool with whatever as long as it will listen to me.\n";
	Quiz_Response(elemental_affinity, earth, water, fire, air);

	std::cout << "QUESTION NINE:\n";
	std::cout << "What do you bring to your group of friends?\n";
	std::cout << "A.) I do all the planning because no one else can be trusted to do it.\n Without me there would be nothing but disorder and chaos.\n";
	std::cout << "B.) People come to me when they need emotional support or advice.\n I nurture my friends, support them, and encourage them to grow.\n";
	std::cout << "C.) I'm the life of the party. The entertainer. The joker.\n Life would be completely boring without me!\n";
	std::cout << "D.) I am a charismatic extrovert. I am the one that comes up with all the good ideas,\n and I am always the first to volunteer.\n";
	Quiz_Response(elemental_affinity, earth, water, fire, air);

	std::cout << "QUESTION TEN:\n";
	std::cout << "Where might you prefer to live?\n";
	std::cout << "A.) In a log cabin out in the mountains or woods. Somewhere I can be close to nature.\n I could be happy just owning a farm or garden.\n";
	std::cout << "B.) Probably in a small town or community. I could be happy living in the suburbs as well.\n I try to keep life simple.\n";
	std::cout << "C.) I go where my passions take me and don't think much else about it.\n It's not uncommon for me to move from place to place.\n";
	std::cout << "D.) If I'm not traveling the world, I can be found thriving in the city.\n";
	Quiz_Response(elemental_affinity, earth, water, fire, air);

	std::cout << "BONUS QUESTION!\n";
	std::cout << "How would you come about your super natural abilities?\n";
	std::cout << "A.) I trained very hard to develop my abilities!\n";
	std::cout << "B.) They were bestowed upon me by forces outside my control!\n";
	std::cout << "C.) I sought after the power I wanted and took it for myself!\n";
	std::cout << "D.) I was born with natural talent and ability!\n";
	Quiz_Response(elemental_affinity, earth, water, fire, air);

	std::cout << "Hold on a minute " << player_name << " while I do some math or something...\n\n\n";

	return elemental_affinity;
}

