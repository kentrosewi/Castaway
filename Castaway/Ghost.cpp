#include "Ghost.h"

/*
	Constructor for Ghost.
	@param ghostName the ghost's name
	@param ghostDescription the description for ghost
	@param ghostXPosition the x position for ghost
	@param ghostYPosition the y position for ghost
	@param ghostHappy if the ghost is happy or not
*/
Ghost::Ghost(string ghostName, string ghostDescription, int ghostXPosition, int ghostYPosition, bool ghostHappy) : NonPlayableCharacter(ghostName, ghostDescription, ghostXPosition, ghostYPosition, ghostHappy)
{
	helloString = "Hello, I am the ghost of the lost adventurer. You have taken something that belongs to me which is why I have stolen something from you.";
	dialogString = "What do you have to say for yourself?\n(Enter a number) \n1. \"I did't know that it belonged to you.\"\n2. \"You're a ghost?! What are you doing here?\"\n";
	dialogCompleteString = "I hope you complete your adventures.\n";
	alreadyTalkedTo = false;
	stoleItem = false;
	
}

/*
	Moves the ghost.
	@param d the direction to move the ghost in
	@param g the gameboard to be moving the ghost on
*/
void Ghost::moveGhost(direction d, Gameboard& g)
{
	g.getRoom(getXPosition(), getYPosition())->removeNonPlayableCharacter(this);
	move(d);
	g.getRoom(getXPosition(), getYPosition())->addNonPlayableCharacter(this);
}
/*
	Lets the ghost follow the player depening on player position.
	@param p the player to follow
	@param g the gameboard to move on
*/
void Ghost::follow(Player& p, Gameboard& g)
{
	

	int xPosDifferenceValue = p.getXPosition() - getXPosition();
	if (xPosDifferenceValue < 0)
		xPosDifferenceValue += (-2 * xPosDifferenceValue);
	int yPosDifferenceValue = p.getYPosition() - getYPosition();
	if (yPosDifferenceValue < 0)
		yPosDifferenceValue += (-2 * yPosDifferenceValue);

	if (p.getXPosition() != getXPosition() || p.getYPosition() != getYPosition())//if not in same sector
	{
		if (xPosDifferenceValue >= yPosDifferenceValue)//if the ghost is closer up and down than left and right
		{
			if (p.getXPosition() < getXPosition())
			{
				moveGhost(West, g);
			}
			else if (getXPosition() < p.getXPosition())
			{
				moveGhost(East, g);
			}
		}
		else if (xPosDifferenceValue < yPosDifferenceValue)
		{
			if (p.getYPosition() < getYPosition())
			{
				moveGhost(North, g);
			}
			else if (getYPosition() < p.getYPosition())
			{
				moveGhost(South, g);
			}
		}
	}
	if (p.getXPosition() == getXPosition() && p.getYPosition() == getYPosition())
	{
		cout << "You have been caught by a ghost and he has stolen an item from your inventory! You should try to get it back from where the ghost came from.\n" << endl;
		int randomItemIndex;
		do
		{
			randomItemIndex = rand() % (p.getInventory()->size());
		} while (p.getInventory()->at(randomItemIndex)->getName() == "raft");
		//saves item-to-steal's moveable value for when player gets it back from ghost
		if (p.getInventory()->at(randomItemIndex)->isMoveable())
		{
			oldMoveableState = true;
		}
		else
			oldMoveableState = false;

		//assigns stolen item to ghosts inventory
		p.give(p.getInventory()->at(randomItemIndex), this);
		//sets that items moveable value to false 
		getInventory()->at(0)->setMoveable(false);

		stoleItem = true;
		g.getRoom(getXPosition(), getYPosition())->removeNonPlayableCharacter(this);
		setPosition(8, 6);

		g.getRoom(getXPosition(), getYPosition())->addNonPlayableCharacter(this);
	}
	//warning of ghost when it comes within 2 sectors of player
	if (xPosDifferenceValue < 3 && yPosDifferenceValue < 3 && stoleItem == false)
	{
		cout << "You feel like something is following you, but you can't see anything whenever you look for it." << endl << endl;;
	}
}
/*
	Returns if the ghost has stolen something or not.
	@param stoleItem bool value for if an item has been stolen or not
*/
bool Ghost::getStolenValue()
{
	return stoleItem;
}
/*
	Starts the dialog sequence of Ghost.
	@param player the player to talk to
*/
void Ghost::startDialog(Player& player)
{
	int choice;

	if (alreadyTalkedTo == false)
	{
		cout << helloString;

		int indexOfStolenItemNPC = 0;
		cout << dialogString;
		cin >> choice;
		cout << endl;

		if (cin.fail())
		{
			cin.clear();
			cin.ignore(100, '\n');
			cout << getName() + " clears his throat. What?\n";
		}
		else
		{
			if (choice == 2) //freaking out over seeing a ghost
			{
				cout << "Yes, I am a ghost. I was abandoned here when I was looking for a new life for my family by a ruthless smuggler. I died on this island waiting for someone to save me but you came too late.\n";
				choice = 1;
			}
			if (choice == 1) // didn't know item belonged to ghost
			{

				cout << "Some things you had taken are very valuable to me and I did not appreciate you stealing it from my body so I have stolen something from you.\n";
				cout << "(Enter a number)\n1. \"I'm sorry but I really need that item to help me get back to where I came from.\"\n2. \"I don't care who you are give it back to me you creepy ghost!\"\n";
				cin >> choice;
				cout << endl;
				if (choice == 1) //apologize for taking item
				{
					cout << "It is ok, I forgive you. You could probably use this on your adventures more than I can and since you were nice to me I will give it back to you.\n";
					give(getInventory()->at(indexOfStolenItemNPC), &player);
					player.getInventory()->at(player.getInventory()->size() - 1)->setMoveable(oldMoveableState);
					cout << "You received " << player.getInventory()->at(player.getInventory()->size() - 1)->getName() << " .\n" << dialogCompleteString << "\n";
					setHappy(true);
					player.incrementPeopleMadeHappy();
				}
				else if (choice == 2) //mean response to ghost
				{
					string itemName = getInventory()->at(indexOfStolenItemNPC)->getName();
					cout << "Insulting a ghost is never a good idea, however I will still give this back to you. I hope you don't regret it later...\n";
					give(getInventory()->at(indexOfStolenItemNPC), &player);
					player.getInventory()->at(player.getInventory()->size() - 1)->setMoveable(oldMoveableState);
					cout << "You received " << player.getInventory()->at(player.getInventory()->size() - 1)->getName() << " .\n" << dialogCompleteString << "\n";
					setHappy(false);
				}
			}
		}
		alreadyTalkedTo = true;
		string remainder;
		getline(cin, remainder);
	}
	else if (alreadyTalkedTo == true)
	{
		cout << "We have nothing more to talk about. I wish you the best on your adventures.\n";
	}
}
