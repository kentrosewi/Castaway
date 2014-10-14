#include "Hatchet.h"

/*
	Constructor for Hatchet.
	@param hatchetName the hatchet's name
	@param hatchetDescription the description for hatchet
	@param hatchetMoveable bool value for if hatchet is moveable
*/
Hatchet::Hatchet(string hatchetName, string hatchetDescription, bool hatchetMoveable) : Usable(hatchetName, hatchetDescription, hatchetMoveable)
{
}

/*
	Uses the hatchet.
	@param player the player to be using the hatchet
	@param indexOfPlayerItem the index of the item in player inventory to use hatchet on
	@param room the room to be using the hatchet in
	@param indexOfRoomItemthe index of the item in room contents to use hatchet on
*/
void Hatchet::use(Player& player, int indexOfPlayerItem, Room& room, int indexOfRoomItem)
{
	vector<Item*>* contents = room.getContents();

	if ((indexOfRoomItem != -1) && contents->at(indexOfRoomItem)->getName() == "tree")
	{
		Item* item = contents->at(indexOfRoomItem);
		item->setMoveable(true);
		item->setName("logs");
		item->setDescription("These got chopped down good. I wonder if they float.");
		cout << "hatchet used on tree.\nYou've created logs.\n";
	}
	else
		cout << "Cannot use hatchet in this way.\n";

}
