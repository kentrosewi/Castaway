#ifndef ACHIEVEMENTS_H
#define ACHIEVEMENTS_H

#include "Player.h"
#include <iostream>

class Achievements
{
public:
	Achievements(Player&);
	int checkForAchievements();

private:
	Player& player;
	bool leftMainIsland;
	bool foundSecretIsland;
	bool fixedHyperDrive;
	bool numberOfCommandsIssued50;
	bool numberOfCommandsIssued100;
	bool hungWithShopkeeper;
	bool boughtSomething;
	bool peopleMadeHappy2;
	static int const LEFT_MAIN_ISLAND_POINTS = 5;
	static int const FOUND_SECRET_ISLAND_POINTS = 10;
	static int const FIXED_HYPER_DRIVE_POINTS = 15;
	static int const NUMBER_OF_COMMANDS_ISSUED_50_POINTS = 5;
	static int const NUMBER_OF_COMMANDS_ISSUED_100_POINTS = 10;
	static int const HUNG_WITH_SHOPKEEPER_POINTS = - 5;
	static int const BOUGHT_SOMETHING_POINTS = 5;
	static int const PEOPLE_MADE_HAPPY_2_POINTS = 10;

};
#endif
