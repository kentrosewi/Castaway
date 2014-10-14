#include "Rope.h"

/*
	Constructor for Rope.
	@param name the rope's name
	@param description the description for the rope
	@param moveable if the rope is moveable
*/
Rope::Rope(string name, string description, bool moveable) : Usable(name, description, moveable)
{
}

/*
	Uses the rope.
	@param player the player to be using the rope
	@param indexOfPlayerItem the index of the item in the players inventory to be using rope on
	@param room the room to be using the rope in
	@param indexOfRoomItem the index of the item in the room's contents to be using rope on
*/
void Rope::use(Player& player, int indexOfPlayerItem, Room& room, int indexOfRoomItem)
{
	vector<Item*>* inv = player.getInventory();
	if (inv->at(indexOfPlayerItem)->getName() == "logs")
	{
		inv->erase(inv->begin() + indexOfPlayerItem);
		int indexOfRope = player.indexOfItem(getName());
		inv->erase(inv->begin() + indexOfRope);
		inv->push_back(new Raft("raft", "This is a shoddy looking raft. At least now I should be able to go on water.", true));
		inv->at(inv->size() - 1)->setMoveable(false);
		cout << "rope used on logs.\nyou've created a raft.\n";
	}
	else
		cout << "rope is not usable in this way.\n";
}

