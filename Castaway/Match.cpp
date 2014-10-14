#include "Match.h"

/*
	Constructor for Match.
	@param matchName the name for the match
	@param matchDescription the description for the match
	@param matchMoveable if match is moveable or not
*/
Match::Match(string matchName, string matchDescription, bool matchMoveable) : Usable(matchName, matchDescription, matchMoveable)
{
}

/*
	Uses the match on an item.
	@param player the player to be using the match
	@param indexOfPlayerItem the index of the item in players inventory to be using the match on
	@param room the room to be using the match in
	@param indexOfRoomItem the index of the item in room contents to be using the match on
*/
void Match::use(Player& player, int indexOfPlayerItem, Room& room, int indexOfRoomItem)
{
	Torch* torch = dynamic_cast<Torch*>(player.getInventory()->at(indexOfPlayerItem));
	if (torch != NULL)
	{
		int indexOfMatch = player.indexOfItem("match");
		player.getInventory()->erase(player.getInventory()->begin() + indexOfMatch);
		torch->light();
		cout << "You used the match on the torch, it is now lit!\n";
		/*
		int indexOfMatch = player.indexOfItem("match");

		// deleting memory location of match used
		//delete player.getInventory()->at(indexOfMatch);
		player.getInventory()->erase(player.getInventory()->begin() + indexOfMatch);
		torch->light();
		cout << "You used the match on the torch, it is now lit!\n";
		*/
	}
	else
		cout << "Match cannot be used in that way.\n";
}