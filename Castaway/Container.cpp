#include "Container.h"

/*
	Constructor for container.
	@param cName the name of the container
	@param cDescription the description of the container
	@param cMoveable if the container is moveable
*/
Container::Container(string cName, string cDescription, bool cMoveable) : Usable(cName, cDescription, cMoveable), full(false)
{
}

/*
	Fills up the container.
	Sets full bool to true.
*/
void Container::fillUp()
{
	full = true;
}

/*
	Empties out the container.
	Sets full bool to false.
*/
void Container::emptyOut()
{
	full = false;
}

/*
	Returns if container is full or not.
	@return full the bool to return
*/
bool Container::isFull() const
{
	return full;
}

/*
	Uses the container.
	@param player the player who is using it
	@param indexOfPlayerItem the index of the item in player's inventory to be using the container on
	@param room the room the container is being used it
	@param indexOfRoomItem the index of the item in the room's contents to be using the container on
*/
void Container::use(Player& player, int indexOfPlayerItem, Room& room, int indexOfRoomItem)
{
	if (indexOfRoomItem == -1)
	{
		if (room.isWater())
		{
			fillUp();
			cout << "You filled up your container with water!\n";
		}
		else
		{
			cout << "I think you need to be on water to fill up the container.\n";
		}
	}
	else
	{
		HyperDrive* hyperDrive = dynamic_cast<HyperDrive*>(room.getContents()->at(indexOfRoomItem));
		if (hyperDrive != NULL)
		{
			if (hyperDrive->isPushedIn())
			{
				if (!isFull())
				{
					cout << "Your container is empty.\n";
				}
				else
				{
					//container full and use on hyper drive that is pushed in
					if (hyperDrive->isCool() == true)
					{
						cout << "That is already cooled off.\n";
					}
					else
					{
						hyperDrive->setCool(true);
						emptyOut();
						cout << "The hyper drive is cooled off.\n";
						hyperDrive->startPuzzle();
					}
				}
			}
			else
			{
				cout << "The hyper drive is not pushed in.\n";
			}
		}
		else
			cout << "I am not sure what you wanted to do with the container.\n";
	}
}