#include "Room.h"
#include <iostream>

/**
	Default constructor for Room.
	Calls Entity's default constructor.
	Sets its own variables to NULL.
**/
Room::Room() : Locatable(), longDescription(NULL), 
	northExit(NULL), eastExit(NULL), southExit(NULL), westExit(NULL), water(NULL), lighting(NULL), contents(NULL), nonPlayableCharacters(NULL) { }

/**
	Constructor for Room.
	@param roomName the name of the Room
	@param roomShortDescription the short description of the Room
	@param roomLongDescription the long description of the Room
	@param roomNorthExit True if North is an exit
	@param roomEastExit True if East is an exit
	@param roomSouthExit True if South is an exit
	@param roomWestExit True if West is an exit
**/
Room::Room(string roomName, string roomDescription, string roomLongDescription, 
		   bool roomNorthExit, bool roomEastExit, bool roomSouthExit, bool roomWestExit, int roomXPosition, int roomYPosition, bool roomWater) 
		   : Locatable(roomName, roomDescription, roomXPosition, roomYPosition), longDescription(roomLongDescription), 
		   northExit(roomNorthExit), eastExit(roomEastExit), southExit(roomSouthExit), westExit(roomWestExit), water(roomWater), contents(NULL), 
		   nonPlayableCharacters(NULL), lighting(true) { }

/*
	Destructor for Room.
	Deletes the contents vector in Room.
*/
Room::~Room()
{
	for (int i = 0; i < contents.size(); ++i)
	{
		if (contents.at(i) != NULL)
		{
			delete contents.at(i);
			contents.at(i) = NULL;
		}
	}

	for (int i = 0; i < nonPlayableCharacters.size(); ++i)
	{
		if (nonPlayableCharacters.at(i) != NULL)
		{
			delete nonPlayableCharacters.at(i);
			nonPlayableCharacters.at(i) = NULL;
		}
	}
}

/**
	Returns longDescription.
**/
string Room::getLongDescription() const { return longDescription; }

/**
	Returns true if the direction is an exit.
	@param roomDirection the direction to check
	@return true or false depending on input direction
**/
bool Room::isValidExit(direction roomDirection) const
{
	if(roomDirection == North)
		return northExit;
	else if(roomDirection == East)
		return eastExit;
	else if(roomDirection == South)
		return southExit;
	else if (roomDirection == West)
		return westExit;
	else
		return false;
}

/**
	Adds an Item to the Room contents.
	@param roomItem the item to add
**/
void Room::addItem(Item* roomItem) 
{ 
	contents.push_back(roomItem); 
}

/*
	Adds a NonPlayableCharacter to a room.
	@param roomNPC the NPC to add to nonPlayableCharacters vector
*/
void Room::addNonPlayableCharacter(NonPlayableCharacter* roomNPC) 
{ 
	nonPlayableCharacters.push_back(roomNPC); 
}

/*
	Removes a NonPlayableCharacter from a room.
	@param roomNPC the NPC to erase from nonPlayableCharacters vector
*/
void Room::removeNonPlayableCharacter(NonPlayableCharacter* roomNPC)
{
	int indexOfNPC = indexOfNonPlayableCharacter(roomNPC->getName());
	nonPlayableCharacters.erase(nonPlayableCharacters.begin() + indexOfNPC);
}

/*
	Deletes an item from a room.
	@param roomItem the item to be erased from contents vector
	(Note: If item is a money pouch, then add the value in money pouch
	to player's money pouch and delete room money pouch.)
*/
void Room::deleteItem(Item* roomItem)
{
	for(int i = 0; i < contents.size(); ++i)
	{
		if(roomItem->getName() == contents.at(i)->getName())
		{
			MoneyPouch* moneyPouch = dynamic_cast<MoneyPouch*>(roomItem);

			if (moneyPouch != NULL)
			{
				delete roomItem;
			}

			contents.erase(contents.begin()+i);
			break;
		}
	}
}

/*
	Returns a point to the room's contents vector.
	@return &contents reference to contents vector
*/
vector<Item*>* Room::getContents()
{
	return &contents;
}

/*
	Returns a pointer to the room's nonPlayableCharacter vector.
	@return &nonPlayableCharacters reference to nonPlayableCharacters vector
*/
const vector<NonPlayableCharacter*>* Room::getNonPlayableCharacters() const
{
	return &nonPlayableCharacters;
}

/*
	Returns the index of an item based on a string.
	@param noun the name of the item to look for
	@return i the index of the item if found
	@return -1 if the item was not found
*/
int Room::indexOfItem(string noun)
{
	for(int i = 0; i < contents.size(); ++i)
	{
		if(toLowercase(noun) == toLowercase(contents.at(i)->getName()))
		{
			return i;
		}
	}

	return -1;
}

/*
	Returns the index of a non playable character based on string.
	@param noun the name of the NPC to look for
	@return i the index of the NPC if found
	@return -1 if the NPC was not found
*/
int Room::indexOfNonPlayableCharacter(string noun)
{
	for(int i = 0; i < nonPlayableCharacters.size(); ++i)
	{
		if(noun == toLowercase(nonPlayableCharacters.at(i)->getName()))
		{
			return i;
		}
	}

	return -1;
}

/*
	Returns if the room is lit.
	@return lighting bool value for if lit or not
*/
bool Room::getLighting() const
{
	return lighting;
}

/*
	Returns if ther Room is a water room.
	@return water the bool value for if water or not
*/
bool Room::isWater() const
{
	return water;
}

/*
	Sets the lighting for the room.
	@param lightOrDark the value to set lighting to
*/
void Room::setLighting(bool lightOrDark)
{
	lighting = lightOrDark;
}

/*
	Sets an exit to true.
	@param dir the direction of the exit
*/
void Room::setExitToTrue(direction dir)
{
	if (dir == North)
		northExit = true;
	else if (dir == East)
		eastExit = true;
	else if (dir == South)
		southExit = true;
	else if (dir == West)
		westExit = true;
}

/*
A non-member ostream operator overloader for a vector of Item pointers.
@param out the ostream reference to write to
@param contents pointer to a vector of Item pointers
@return out the modified ostream reference
*/
ostream& operator<<(ostream& out, const vector<Item*>* contents)
{
	for (int i = 0; i < contents->size(); ++i)
	{
		Item* item = contents->at(i);
		out << item->getName() << "\n";
	}

	return out;
}

/*
A non-member ostream operator overloader for a vector of NonPlayableCharacter pointers.
@param out the ostream reference to write to
@param npcs pointer to a vector of NonPlayableCharacter pointers
@return out the modified ostream reference
*/
ostream& operator<<(ostream& out, const vector<NonPlayableCharacter*>* npcs)
{
	for (int i = 0; i < npcs->size(); ++i)
		out << npcs->at(i)->getName() << "\n";

	return out;
}