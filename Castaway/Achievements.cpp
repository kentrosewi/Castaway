#include "Achievements.h"

/*
	Constructor for Achievements.
	@param player the Player reference to keep track of
*/
Achievements::Achievements(Player& player) : player(player), leftMainIsland(false), foundSecretIsland(false), 
	fixedHyperDrive(false), numberOfCommandsIssued50(false), numberOfCommandsIssued100(false), hungWithShopkeeper(false), 
	boughtSomething(false), peopleMadeHappy2(false)
{
}

/*
	Checks to see if any achievements have been completed.
	Meant to be checked every turn.
	Only awards each achievement once.
	@return points the amount of points awarded
*/
int Achievements::checkForAchievements()
{
	int points = 0;

	// if player has left main island
	if (player.hasLeftMainIsland() && leftMainIsland == false)
	{
		leftMainIsland = true;
		points += LEFT_MAIN_ISLAND_POINTS;
		cout << "Points received for leaving main island: ";
		cout << LEFT_MAIN_ISLAND_POINTS;
		cout << endl;
	}

	// if player has found the secret island
	if (player.foundSecretIsland() && foundSecretIsland == false)
	{
		foundSecretIsland = true;
		points += FOUND_SECRET_ISLAND_POINTS;
		cout << "Points received for finding secret island: ";
		cout << FOUND_SECRET_ISLAND_POINTS;
		cout << endl;
	}

	// if the player has fixed the hyper drive
	if (player.fixedHyperDrive() && fixedHyperDrive == false)
	{
		fixedHyperDrive = true;
		points += FIXED_HYPER_DRIVE_POINTS;
		cout << "Points received for fixing hyper drive: ";
		cout << FIXED_HYPER_DRIVE_POINTS;
		cout << endl;
	}

	// if the player has issued 50 commands
	if (player.getNumberOfCommandsIssued() >= 50 && numberOfCommandsIssued50 == false)
	{
		numberOfCommandsIssued50 = true;
		points += NUMBER_OF_COMMANDS_ISSUED_50_POINTS;
		cout << "Points received for issuing 50 commands: ";
		cout << NUMBER_OF_COMMANDS_ISSUED_50_POINTS;
		cout << endl;
	}

	// if the player has issued 100 commands
	if (player.getNumberOfCommandsIssued() >= 100 && numberOfCommandsIssued100 == false)
	{
		numberOfCommandsIssued100 = true;
		points += NUMBER_OF_COMMANDS_ISSUED_100_POINTS;
		cout << "Points received for issuing 100 commands: ";
		cout << NUMBER_OF_COMMANDS_ISSUED_100_POINTS;
		cout << endl;
	}

	// if the player has went into the back room of the shop with the shopkeeper
	if (player.isConfused() && hungWithShopkeeper == false)
	{
		hungWithShopkeeper = true;
		points += HUNG_WITH_SHOPKEEPER_POINTS;
		cout << "Points received for hanging with the shopkeeper: ";
		cout << HUNG_WITH_SHOPKEEPER_POINTS;
		cout << endl;
		cout << "You lost points because you should know better." << endl;
	}

	// if the player has bought something from the shopkeeper
	if (player.hasBoughtSomething() && boughtSomething == false)
	{
		boughtSomething = true;
		points += BOUGHT_SOMETHING_POINTS;
		cout << "Points received for buying something: ";
		cout << BOUGHT_SOMETHING_POINTS;
		cout << endl;
	}
	
	// if the player has pleased at least 2 people
	if (player.getPeopleMadeHappy() >= 2 && peopleMadeHappy2 == false)
	{
		peopleMadeHappy2 = true;
		points += PEOPLE_MADE_HAPPY_2_POINTS;
		cout << "Points received for making two people happy: ";
		cout << PEOPLE_MADE_HAPPY_2_POINTS;
		cout << endl;
	}

	return points;
}