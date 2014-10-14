#include "NonPlayableCharacter.h"

/*
	Default constructor for NonPlayableCharacter.
*/
NonPlayableCharacter::NonPlayableCharacter() : Character(), happy(NULL)
{
}

/*
	Constructor for NonPlayableCharacter.
	@param npcName the name of the NonPlayableCharacter
	@param npcDescription the description of the NonPlayableCharacter
	@param npcXPosition the x position of the NonPlayableCharacter
	@param npcYPosition the y position of the NonPlayableCharacter
	@param npcHappy bool value for if NonPlayableCharacter is happy or not
*/
NonPlayableCharacter::NonPlayableCharacter(string npcName, string npcDescription, int npcXPosition, int npcYPosition, bool npcHappy) 
	: Character(npcName, npcDescription, npcXPosition, npcYPosition), happy(npcHappy)
{ 
}

/*
	Sets the NonPlayableCharacter's happy value.
	@param happyOrNot if the NonPlayableCharacter is happy or not
*/
void NonPlayableCharacter::setHappy(bool happyOrNot)
{
	happy = happyOrNot;
}

/*
	Returns if the NonPlayableCharacter is happy.
	@return happy bool for if NonPlayableCharacter is happy
*/
bool NonPlayableCharacter::getHappy() const
{
	return happy;
}