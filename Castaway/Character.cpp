#include "Character.h"

/**
	Default constructor for Character.
	Calls Locatable's default constructor
	and sets inventory to NULL.
**/
Character::Character() : Locatable(), inventory(NULL) { }

/**
	Constructor for Character that calls 
	Locatable's constructor with a name,
	x position, and y position. Sets its 
	own variables to NULL.
	@param characterName the Character's name
	@param characterDescription the Character's description
	@param xPosition the x position of Character
	@param yPosition the y position of Character
**/
Character::Character(string characterName, string characterDescription, int xPosition, int yPosition) 
	: Locatable(characterName, characterDescription, xPosition, yPosition), inventory(NULL) { }

/*
	Destructor for Character.
	Deletes everything in the Character's inventory.
*/
Character::~Character()
{
	for (int i = 0; i < inventory.size(); ++i)
	{
		if (inventory.at(i) != NULL)
		{
			delete inventory.at(i);
			inventory.at(i) = NULL;
		}
	}
}

/**
	Moves the Character in the direction passed in.
	@param direction the direction to move the Character
**/
void Character::move(direction direction)
{
	if(direction == North)
		updatePosition( 0, -1);
	else if(direction == East)
		updatePosition( 1, 0);
	else if(direction == South)
		updatePosition( 0, 1);
	else if(direction == West)
		updatePosition( -1, 0);
}

/**
	Adds an Item to the Character's inventory.
	@param item the item to add
**/
void Character::addToInventory(Item* item)
{
	inventory.push_back(item);
}

/**
	Returns a pointer to the Character's inventory.
	@return &inventory
**/
vector<Item*>* Character::getInventory()
{
	return &inventory;
}

/**
	Deletes an item from the Character's inventory.
	@param item the Item to delete
**/
void Character::deleteItem(Item* item)
{
	for (int i = 0; i < inventory.size(); ++i)
	{
		if (item->getName() == inventory.at(i)->getName())
		{
			inventory.erase(inventory.begin() + i);
			break;
		}
	}
}

/*
	Checks the index of Character for a specified Item.
	@param noun the string to check the Character's inventory for
	@return i the index of the Item if found
	@return -1 if not found
*/
int Character::indexOfItem(string noun)
{
	
	for(int i = 0; i < inventory.size(); ++i)
	{
		if(toLowercase(noun) == toLowercase(inventory.at(i)->getName()))
		{
			return i;
		}
	}
	
	return -1;
}

/*
	Gives an item from one Character to another.
	@param item the item to give to npc
	@param npc the Character to give the item too
*/
void Character::give(Item* item, Character* npc)
{
	npc->addToInventory(item);
	deleteItem(item);
}

/*
	Counts the number of items in Character's inventory
	with specified name.
	@param name the name of the Item to check for
	@return timesFound how many times the Item was found
*/
int Character::numberInInventory(string name) const
{
	int timesFound = 0;

	for(int i = 0; i < inventory.size(); ++i)
	{
		if(toLowercase(name) == toLowercase(inventory.at(i)->getName()))
			timesFound++;
	}

	return timesFound;
}