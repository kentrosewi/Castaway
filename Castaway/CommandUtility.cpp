#include "CommandUtility.h"

/*
	Default constructor for CommandUtility.
*/
CommandUtility::CommandUtility()
{
}

/*
	Attempts to move the player.
	@param dir the direction to move
	@param room the room the Player is in
	@param player the Player to move
	@param gameboard the gameboard to move around
*/
void CommandUtility::move(direction dir, Room* room, Player* player, Gameboard* gameboard)
{
	if (dir == UnknownDirection)
	{
		cout << "Move where? Try again." << endl << endl;
	}
	
	if(player->isConfused())
	{
		int confusedTurns = player->getConfusedTurnsLeft();
		if(confusedTurns <= 0)
		{
			player->setConfused(false);
			confusedTurns = 0;
			cout << "You're starting to feel a bit better now, but man what happened?\n";
		}
		else
		{
			int randomNum;

			do
			{
				randomNum = rand() % 4;
			}
			while(randomNum == (int)dir);
			
			if(randomNum == 0)
			{
				dir = North;
				cout << "You stumble North.\n";
			}
			else if(randomNum == 1)
			{
				dir = South;
				cout << "You stumble South.\n";
			}
			else if(randomNum == 2)
			{
				dir = East;
				cout << "You stumble East.\n";
			}
			else if(randomNum == 3)
			{
				dir = West;
				cout << "You stumble West.\n";
			}
			
			player->decrementConfusedTurns();
		}

	}

	int playerX = player->getXPosition();
	int playerY = player->getYPosition();
	
	if (player->indexOfItem("raft") != -1)
	{
		int toRoomX = -1;
		int toRoomY = -1;
		bool validDirection = true;
		
		if (dir == North && playerY > 0)
		{
			toRoomY = playerY - 1;
			toRoomX = playerX;
		}
		else if (dir == East && playerX < 10)
		{
			toRoomX = playerX + 1;
			toRoomY = playerY;
		}
		else if (dir == South && playerY < 9)
		{
			toRoomY = playerY + 1;
			toRoomX = playerX;
		}
		else if (dir == West && playerX > 0)
		{
			toRoomX = playerX - 1;
			toRoomY = playerY;
		}
		else
			validDirection = false;

		if (toRoomY != -1 && toRoomX != -1 && gameboard->getRoom(toRoomX, toRoomY)->isWater())//outofbounds fix
		{
			direction oppositeDirection;
			if (dir == North)
				oppositeDirection = South;
			else if (dir == East)
				oppositeDirection = West;
			else if (dir == South)
				oppositeDirection = North;
			else if (dir == West)
				oppositeDirection = East;

			if (validDirection == true && gameboard->getRoom(toRoomX, toRoomY)->isValidExit(oppositeDirection))
			{
				room->setExitToTrue(dir);
				cout << "You are using your raft!\n";
			}
		}
	}
	if(room->isValidExit(dir))
	{
		player->move(dir);
		room = gameboard->getRoom(player->getXPosition(), player->getYPosition());
		cout << room->getDescription() << endl;
	}
	else
	{
		cout << "Cannot go that way.\n";
	}

	static bool hasNotLeftMainIsland = true;
	static Ghost* ghost = NULL;

	if (player->hasLeftMainIsland() && hasNotLeftMainIsland == true)
	{
		hasNotLeftMainIsland = false;
		ghost = new Ghost("ghost", "I am a ghost. You should be scared.", 8, 6, false);
		gameboard->getRoom(8, 6)->addNonPlayableCharacter(ghost);
	}

	if (ghost != NULL && ghost->getStolenValue() != true)
	{
		ghost->follow(*player, *gameboard);
	}

}

/*
	Displays either info about the Room or info about an object.
	@param command the command to inspect
	@param room the room to look at
	@param player the player to use in the looking
*/
void CommandUtility::look(Command& command, Room& room, Player& player)
{
	
	int indexOfTorch = player.indexOfItem("torch");
	bool lightingChanged = false;

	if (indexOfTorch != -1)
	{
		Torch* torch = dynamic_cast<Torch*>(player.getInventory()->at(indexOfTorch));
		
		if (torch->isLit() && room.getLighting() == false)
		{
			room.setLighting(true);
			lightingChanged = true;
		}
	}

	if (room.getLighting() == false)
	{
		cout << "It is too dark to see anything. Why don't you figure out how to get some light on the situtation?\n";
		return;
	}
	

	if(command.getNoun() == "")
	{
		cout << room.getLongDescription() << "\n\n";
		cout << "Contents: \n" << room.getContents() << "\n";
		cout << "People: \n" << room.getNonPlayableCharacters() << "\n";
		cout << "Exits: \n";
		if(room.isValidExit(North))
			cout << "North\n";
		if(room.isValidExit(East))
			cout << "East\n";
		if(room.isValidExit(South))
			cout << "South\n";
		if(room.isValidExit(West))
			cout << "West\n";
	}
	else
	{
		string noun = command.getNoun();

		int indexOfNounPlayer = player.indexOfItem(noun);
		int indexOfNounRoom = room.indexOfItem(noun);
		int indexOfNounNPC = room.indexOfNonPlayableCharacter(noun);

		if(indexOfNounPlayer != -1)
		{
			MoneyPouch* moneyPouch = dynamic_cast<MoneyPouch*>(player.getInventory()->at(indexOfNounPlayer));
			if( moneyPouch != NULL)
			{
				cout << moneyPouch->getDescription() << "\n";
			}
			else
			{
			cout << player.getInventory()->at(indexOfNounPlayer)->getDescription() << "\n";
			}
		}
		else if(indexOfNounRoom != -1)
		{
			MoneyPouch* moneyPouch = dynamic_cast<MoneyPouch*>(room.getContents()->at(indexOfNounRoom));
			if( moneyPouch != NULL)
			{
				cout << moneyPouch->getDescription() << "\n";
			}
			else
			{
				cout << room.getContents()->at(indexOfNounRoom)->getDescription() << "\n";
			}
		}
		else if(indexOfNounNPC != -1)
			cout << room.getNonPlayableCharacters()->at(indexOfNounNPC)->getDescription() << "\n";
		else if(noun == "self")
			cout << player.getDescription() << "\n";
		else
			cout << "What did you want to look at? I do not understand.\n";
	} 

	if (lightingChanged)
		room.setLighting(false);
}

/*
	Allows the player to talk to someone.
	@param command the command to inspect
	@param room the room to be talking in
	@param player the player to be doing the talking
*/
void CommandUtility::talk(Command& command, Room& room, Player& player)
{
	
	string noun = command.getNoun();
	
	int indexOfNPC = room.indexOfNonPlayableCharacter(noun);

	if(indexOfNPC != -1)
	{
		NonPlayableCharacter* npc = room.getNonPlayableCharacters()->at(indexOfNPC);
		npc->startDialog(player);
	}
	else if (noun == "") //if user only entered "talk"
	{
		cout << "Who were you trying to talk to? Try the command again.\n";
	}
	else //if user entered incorrect noun
	{
		cout << "Who were you trying to talk to? Try the command again.\n";
	}
}

/*
	Takes something from either the Room or a person.
	(Note: Our game does not allow items to be taken
	from an NPC unless the item's moveable bool is 
	set to true, our game has NPC's items moveable 
	bool set to false.)
	@param command the command to inspect
	@param room the room to take an item from or that 
	holds NPC to take item from
	@param player the player to be doing the taking
*/
void CommandUtility::take(Command& command, Room& room, Player& player)
{
	//cout << command.getNoun() << endl;
	//cout << command.getNoun2() << endl;
	if(command.getNoun2() == "")
	{
		string noun = command.getNoun();
		int indexOfNoun = room.indexOfItem(noun);
		int haveMoneyPouch = true;

		if(indexOfNoun != -1)
		{
			if(room.getContents()->at(indexOfNoun)->isMoveable())
			{
				if(dynamic_cast<MoneyPouch*>(room.getContents()->at(indexOfNoun)) != NULL)
				{
					int indexOfPlayerMoneyPouch = player.indexOfItem("money pouch");
					if (indexOfPlayerMoneyPouch != -1)
					{
						MoneyPouch* playerMoneyPouch = static_cast<MoneyPouch*>(player.getInventory()->at(indexOfPlayerMoneyPouch));
						MoneyPouch* otherMoneyPouch = static_cast<MoneyPouch*>(room.getContents()->at(indexOfNoun));
						playerMoneyPouch->addToPouch(otherMoneyPouch->getNumberOfCoins());
					}
					else
					{
						haveMoneyPouch = false;
						cout << "You must have your money pouch to get more money!" << endl;
					}
				}
				else
				{
					player.addToInventory(room.getContents()->at(indexOfNoun));
				}

				if (haveMoneyPouch)
				{
					room.deleteItem(room.getContents()->at(indexOfNoun));
					cout << noun << " taken.\n";
				}
			}
			else
			{
				cout << noun << " is not moveable.\n";
			}
		}
		else
		{
			cout << "What did you want to take? I did not understand.\n";
		}
	}
	else
	{
		string item = command.getNoun();
		string character = command.getNoun2();

		Character* npc = NULL;

		int indexOfItem = -1;
		int indexOfNPC = room.indexOfNonPlayableCharacter(character);

		if(indexOfNPC != -1)
		{
			npc = room.getNonPlayableCharacters()->at(indexOfNPC);
			indexOfItem = npc->indexOfItem(item);
		}

		if(indexOfItem == -1 || indexOfNPC == -1)
		{
			if(indexOfNPC == -1)
				cout << character << " not found.\n";
			else
			{
				if(indexOfItem == -1)
					cout << item << " not found in " << character << "'s inventory.\n";
			}
		}
		else
		{
			if(!npc->getInventory()->at(indexOfItem)->isMoveable())
			{
				cout << "You cannot take that item.\n";
			}
			else
			{
				npc->give(npc->getInventory()->at(indexOfItem), &player);
				cout << "Took " << item << " from " << character << ".\n";
			}
		}
	}
}

/*
	Drops an item from the player's inventory into the room.
	@param command the command to inspect
	@param room the room to drop the item to
	@param player the player to do the dropping
*/
void CommandUtility::drop(Command& command, Room& room, Player& player)
{
	string noun = command.getNoun();
	int indexOfNoun = player.indexOfItem(noun);

	if(indexOfNoun != -1)
	{
		if(player.getInventory()->at(indexOfNoun)->isMoveable())
		{
			room.addItem(player.getInventory()->at(indexOfNoun));
			player.deleteItem(player.getInventory()->at(indexOfNoun));
			cout << noun << " dropped.\n";
		}
		else
		{
			cout << noun << " is not droppable.\n";
		}
	}
	else
		cout << "What did you want to drop? Try again.\n";
}

void CommandUtility::inventory(Player& player)
{
	cout << "Inventory: \n" << player.getInventory() << "\n";
	cout << "Points: ";
	cout << player.getPoints() << endl;
	cout << endl;
}

/*
	Uses an item.
	@param command the command to inspect
	@param room the room to use an item in
	@param player the player to be using an item
*/
void CommandUtility::use(Command& command, Room& room, Player& player)
{
	string noun1 = command.getNoun();
	string noun2 = command.getNoun2();
	int indexOfNoun1Player = player.indexOfItem(noun1);
	
	int indexOfNounRoom = room.indexOfItem(noun2);
	int indexOfNoun2Player = player.indexOfItem(noun2);
	if (noun1 == "")
		cout << "What would you like to use? Try the command again.\n";
	else if (indexOfNoun1Player == -1 && noun1 == "on")
	{
		cout << "What would you like to use that on? Try the command again.\n";
	}
	else if (indexOfNoun1Player == -1)
	{
		cout << "You don't have that in your inventory.\n";
	}
	else if (indexOfNoun1Player != -1 && noun1 == "on")
	{
		cout << "What would you like to use that on? Try the command again.\n";
	}
	
	else if(indexOfNoun1Player != -1 && indexOfNounRoom != -1)
	{
		Item* item = player.getInventory()->at(indexOfNoun1Player);
		Usable* usableItem = dynamic_cast<Usable*>(item);
		if (usableItem != NULL)
		{
			usableItem->use(player, indexOfNounRoom, room, indexOfNounRoom);
		}
		else
			cout << noun1 << " is not usable in that way.";
	}
	else if(indexOfNoun1Player != -1 && indexOfNoun2Player != -1)
	{
		Item* item = player.getInventory()->at(indexOfNoun1Player);
		Usable* usableItem = dynamic_cast<Usable*>(item);
		if (usableItem != NULL)
		{
			usableItem->use(player, indexOfNoun2Player, room, indexOfNounRoom);
		}
		else
			cout << noun1 << " is not usable in that way.";
	}
	else if (player.getInventory()->at(indexOfNoun1Player)->getName() == "container" && indexOfNoun2Player == -1 && indexOfNounRoom == -1)
	{
		Usable* usable = dynamic_cast<Usable*>(player.getInventory()->at(indexOfNoun1Player));
		if (usable != NULL && (noun2 == "" || noun2 == "water"))
		{
			usable->use(player, indexOfNoun1Player, room, indexOfNounRoom);
		}
		else
			cout << "Not usable in that way.\n";
	}
	else
	{
		cout << "I can tell you wanted to use something but your lack of simple keyboarding skills is preventing me from completing the task.\n";
	}	
}
/*
	Says a piece of dialog.
	@param command the command to inspect
	@param room the room to be talking in
	@param player the player to be talking
*/
void CommandUtility::say(Command& command, Room& room, Player& player)
{
	string noun = command.getNoun();

	int indexOfNPC = room.indexOfNonPlayableCharacter(noun);

	if(indexOfNPC == -1)
	{
		cout << "You say \"" << command.getDialog() << "\" to no one in particular.\n";
	}
	else
	{
		cout << "You say \"" << command.getDialog2() << "\" to " << command.getNoun() << "\n";
					
		if(command.getDialog2() == "hi" || command.getDialog2() == "hello")
		{	 
			NonPlayableCharacter* npc = room.getNonPlayableCharacters()->at(indexOfNPC);
			npc->startDialog(player);
		}
	}
}

/*
	Gives an item to someone.
	@param command the command to inspect
	@param room the room to inspect
	@param player the player to be doing the giving
*/
void CommandUtility::give(Command& command, Room& room, Player& player)
{
	string item = command.getNoun();
	string character = command.getNoun2();

	int indexOfItem = player.indexOfItem(item);
	int indexOfNPC = room.indexOfNonPlayableCharacter(character);
	if(indexOfItem == -1)
		cout << item << " not found.\n";
	else if(indexOfNPC == -1)
		cout << character << " not found.\n";
	else
	{
		
		if (player.getInventory()->at(indexOfItem)->getName() != "raft" && player.getInventory()->at(indexOfItem)->getName() != "money pouch")
		{
			player.give(player.getInventory()->at(indexOfItem), room.getNonPlayableCharacters()->at(indexOfNPC));
			cout << "Gave " << item << " to " << character << ".\n";
		}
		else cout << "Cannot give that away, you need that!" << endl;
	}
}

/*
	Opens an item if it is openable.
	@param command the command to be inspecting
	@param room the room to be opening something in
	@param player the player to be opening something
*/
void CommandUtility::open(Command& command, Room& room, Player& player)
{
	
	string noun = command.getNoun();

	int indexOfItemRoom = room.indexOfItem(noun);
	int indexOfItemPlayer = player.indexOfItem(noun);

	if (indexOfItemPlayer != -1)
	{
		Item* item = static_cast<Item*>(player.getInventory()->at(indexOfItemPlayer));
		MoneyPouch* moneyPouch = dynamic_cast<MoneyPouch*>(item);
		if (moneyPouch != NULL)
		{
			cout << moneyPouch->getDescription() << "\n";
		}
		else
		{
			cout << "I don't think " << noun << " is openable.\n";
		}
		
	}
	else if (indexOfItemRoom != -1)
	{
		Item* item = static_cast<Item*>(room.getContents()->at(indexOfItemRoom));
		MoneyPouch* moneyPouch = dynamic_cast<MoneyPouch*>(item);
		Chest* chest = dynamic_cast<Chest*>(item);
		if (moneyPouch != NULL)
		{
			cout << moneyPouch->getDescription() << "\n";
		}
		else if (chest != NULL)
		{
			chest->open(room);
		}
		else
		{
			cout << "I don't think " << noun << " is openable.\n";
		}
		
	}
	else
	{
		cout << "Not sure what you're trying to open.\n";
	}
	
}

/*
	Pushes an item.
	@param command the command to inspect
	@param room the room to be pushing something in
	@param player the player to be pushing something
*/
void CommandUtility::push(Command& command, Room& room, Player& player)
{
	string noun = command.getNoun();

	int indexOfItemRoom = room.indexOfItem(noun);
	
	if (indexOfItemRoom != -1)
	{
		HyperDrive* hyperDrive = dynamic_cast<HyperDrive*>(room.getContents()->at(indexOfItemRoom));

		if (hyperDrive != NULL)
		{
			if (!hyperDrive->isPushedIn())
				hyperDrive->pushIn();
			else
				cout << "That is already pushed in.\n";
		}
		else
		{
			cout << "I don't think that is pushable.\n";
		}
	}
	else
	{
		cout << "Sorry, but that is not going to work.\n";
	}
}

/*
	Displays a help dialog and map.
	@param player the player to be helping
	@param gameboard the gameboard to display
*/
void CommandUtility::help(Player& player, Gameboard& gameboard)
{
	int playerXPos = player.getXPosition();
	int playerYPos = player.getYPosition();

	bool onIslandOne = (playerXPos > 5 && playerXPos < 10 && playerYPos > 4 && playerYPos < 9);
	bool onIslandTwo = (playerXPos > 6 && playerXPos < 9 && playerYPos > 0 && playerYPos < 3);
	bool onIslandThree = (playerXPos > 0 && playerXPos < 4 && playerYPos > 1 && playerYPos < 5);

	cout << "Commands" << endl;
	cout << "--------" << endl;
	cout << "move <direction>" << endl;
	cout << "inventory" << endl;
	cout << "use <something>" << endl;
	cout << "use <something> on <something else>" << endl;
	cout << "take <something>" << endl;
	cout << "drop <something>" << endl;
	cout << "look at <something>" << endl;
	cout << "open <something>" << endl;
	cout << "talk to <someone>" << endl;
	cout << "say \"something\"" << endl;
	cout << "say \"something\" to <someone>" << endl;
	cout << "push <something>" << endl;
	cout << "sleep" << endl;
	cout << "help" << endl;

	cout << endl;

	if (onIslandOne)
	{
		cout << "Have you tried creating a raft?" << endl << endl;
	}
	else if (onIslandTwo)
	{
		cout << "Have you bought anything from the shopkeeper yet?" << endl << endl;
	}
	else if (onIslandThree)
	{
		cout << "Have you tried going into the metallic structure?" << endl << endl;
	}
	else
	{
		cout << "Have you tried visiting the other islands yet?" << endl << endl;
	}

	int columns = gameboard.getColumns();
	int rows = gameboard.getRows();

	cout << "Player represented by \'P\'." << endl;
	cout << "Land is represented by \'#\'." << endl;
	cout << "Water is represented by an open [ ]." << endl << endl;

	for (int y = 0; y < rows; ++y)
	{
		for (int x = 0; x < columns; ++x)
		{
			cout << "[";
			if (x == playerXPos && y == playerYPos)
				cout << "P]";
			else if (gameboard.getRoom(x, y)->isWater())
				cout << " ]";
			else
				cout << "#]";
		}
		cout << endl;
	}
}

/*
	Allows the player to sleep and pass time.
	@param command the command to inspect
	@param player the player to be sleeping
*/
void CommandUtility::sleep(Command& command, Player& player)
{
	if (command.getNoun() == "")
	{
		cout << "You sleep." << endl;

		if (player.isConfused())
		{
			player.decrementConfusedTurns();

			int confusedTurns = player.getConfusedTurnsLeft();
			if (confusedTurns <= 0)
			{
				player.setConfused(false);
				confusedTurns = 0;
				cout << "You're starting to feel a bit better now, but man what happened?\n";
			}
		}
	}
	else
	{
		cout << "Not sure what you wanted to do with sleeping." << endl;
	}

}