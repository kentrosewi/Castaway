#include "Player.h"

/*
	Constructor for Player.
	@param playerName the player's name
	@param playerDescription description for the player
	@param playerXPosition the x position to start player at
	@param playerYPosition the y position to start player at
*/
Player::Player(string playerName, string playerDescription, int playerXPosition, int playerYPosition) : 
	Character(playerName, playerDescription, playerXPosition, playerYPosition), peopleMadeHappy(0), 
	confused(false), commandsIssued(0), points(0), hyperDriveFixed(false), boughtSomething(false)
{
}

/*
	Returns how many confused turns are left 
	until player is not confused.
	@return confusedTurns the number of confused turns left
*/
int Player::getConfusedTurnsLeft() const
{
	return confusedTurns;
}

/*
	Decrements the confused turns left for the player by 1.
*/
void Player::decrementConfusedTurns()
{
	confusedTurns--;
}

/*
	Sets the player's confused value.
	@param confused if the player is confused
*/
void Player::setConfused(bool confused)
{
	confusedTurns = 5;
	this->confused = confused;
}

/*
	Returns if the player is confused.
	@preturn confusd value for if player is confused
*/
bool Player::isConfused() const
{
	return confused;
}

/*
	Increments the commands issued by player by 1.
*/
void Player::incrementCommandsIssued()
{
	commandsIssued++;
}

/*
	Returns the number of commands issued by player.
	@param commandsIssued the number of commands issued by player
*/
int Player::getNumberOfCommandsIssued() const
{
	return commandsIssued;
}

/*
	Returns if player has left the main island.
	@return true if player has left main island
	@return false if player has not left main island
*/
bool Player::hasLeftMainIsland() const
{
	int xMin = 6;
	int xMax = 9;
	int yMin = 5;
	int yMax = 8;

	if (getXPosition() > xMax || getXPosition() < xMin || getYPosition() > yMax || getYPosition() < yMin)
	{
		return true;
	}
	else
		return false;
}

/*
	Increments the number of people player has made happy by 1.
*/
void Player::incrementPeopleMadeHappy()
{
	peopleMadeHappy++;
}

/*
	Returns the number of people player has made happy.
	@return peopleMadeHappy the number of people made happy
*/
int Player::getPeopleMadeHappy() const
{
	return peopleMadeHappy;
}

/*
	Adds an amount to player's points.
	@param amount the amount to add to player's points
*/
void Player::addToPoints(int amount)
{
	points += amount;
}

/*
	Returns the points that player has.
	@return points the number of points player has
*/
int Player::getPoints() const
{
	return points;
}

/*
	Returns if the player has found the secret island.
	@return true if the player has found secret island
	@return false if the player has not found secret island
*/
bool Player::foundSecretIsland() const
{
	int islandX = 1;
	int islandY = 8;

	if (getXPosition() == 1 && getYPosition() == 8)
		return true;
	else
		return false;
}

/*
	Returns if the player has fixed the hyper drive.
	@return hyperDriveFixed bool for if the hyper drive has been fixed by player
*/
bool Player::fixedHyperDrive() const
{
	return hyperDriveFixed;
}

/*
	Returns if the player has bought an item.
	@return boughtSomething bool for if the player has bought something
*/
bool Player::hasBoughtSomething() const
{
	return boughtSomething;
}

/*
	Sets the hyperDriveFixed bool to true.
*/
void Player::setFixedHyperDrive()
{
	hyperDriveFixed = true;
}

/*
	Sets the boughtSomething bool to true.
*/
void Player::setHasBoughtSomething()
{
	boughtSomething = true;
}