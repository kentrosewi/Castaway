#include "Shopkeeper.h"

/*
	Constructor for Shopkeeper.
	@param skName the name for shopkeeper
	@param skDescription the description of the shopkeeper
	@param skXPosition the x position for the shopkeeper
	@param skYPosition the y position for the shopkeeper
	@param skHappy if the shopkeeper is happy
*/
Shopkeeper::Shopkeeper(string skName, string skDescription, int skXPosition, int skYPosition, bool skHappy) : NonPlayableCharacter(skName, skDescription, skXPosition, skYPosition, skHappy)
{
	helloString = "Hello, welcome to my shop."; 
	menuString = "What would you like to do? (Enter a number)\n1. Buy a container (2 finiki)\n2. Buy a torch(3 finiki)\n"
		 "3. Buy a match (2 finiki)\n4. Buy information (5 finiki)\n5. Go to the back room (No charge)\n6. Exit";
	transactionCompleteString = "Thank you for your purchase. Business hasn't been so great ever since that space ship fell out of the sky.";
	byeString = "Thanks. I'll cya later.";
	funnyString = "You may start feeling a little funny now mon.";
	infoString = "If you're looking for a little treasure, I think I saw a small island to the South-West with a shiny chest on it.";
	infoGiven = false;
	itemPurchased = false;
	moneyReceived = 0;
}

/*
	Starts the dialog sequence of the shopkeeper.
	@param player to be talking to shopkeeper
*/
void Shopkeeper::startDialog(Player& player)
{
	cout << helloString;

	int choice;

	int containerPrice = 2;
	int torchPrice = 3;
	int matchPrice = 2;
	int infoPrice = 5;
	int moneyToMakeHappy = 14;
	
	do
	{
		int indexOfMoneyPouch = player.indexOfItem("money pouch");
		MoneyPouch* moneyPouch = static_cast<MoneyPouch*>(player.getInventory()->at(indexOfMoneyPouch));
		
	    int indexOfTorchNPC = indexOfItem("torch");
		int indexOfMatchNPC = indexOfItem("match");

		string yourMoney = to_string(moneyPouch->getNumberOfCoins());
		cout << "You have " << yourMoney << " " << moneyPouch->getNameOfCoin() << ".\n";
		cout << menuString; 
		cout << endl;
		cin >> choice;
		cout << endl;

		if(cin.fail())
		{
			cin.clear();
			cin.ignore(100, '\n');
			cout << getName() + " clears his throat. What?\n";
		}
		else
		{
			if(choice == 1) // wants container
			{
				int indexOfContainerNPC = indexOfItem("container");
				if(indexOfContainerNPC != -1)
				{
					if(moneyPouch->getNumberOfCoins() >= containerPrice)
					{
						moneyPouch->removeFromPouch(containerPrice);
						give(getInventory()->at(indexOfContainerNPC), &player);
						moneyReceived += containerPrice;
						itemPurchased = true;
						cout << "You received a container.\n" << transactionCompleteString << "\n";
					}
					else
					{
						cout << "Sorry you do not have enough money for that.\n";
					}
				}
				else
				{
					cout << "Sorry we are all out of containers.\n";
				}

			}
			else if(choice == 2) // wants torch
			{
				int indexOfTorchNPC = indexOfItem("torch");
				if(indexOfTorchNPC != -1)
				{
					if(moneyPouch->getNumberOfCoins() >= torchPrice)
					{
						moneyPouch->removeFromPouch(torchPrice);
						give(getInventory()->at(indexOfTorchNPC), &player);
						moneyReceived += torchPrice;
						itemPurchased = true;
						cout << "You received a torch.\n" << transactionCompleteString << "\n";
					}
					else
					{
						cout << "Sorry you do not have enough money for that.\n";
					}
				}
				else
				{
					cout << "Sorry we are all out of torches.\n";
				}
			}
			else if(choice == 3) // wants a match
			{			
				if(indexOfMatchNPC != -1)
				{
					if(moneyPouch->getNumberOfCoins() >= matchPrice)
					{
						moneyPouch->removeFromPouch(matchPrice);
						give(getInventory()->at(indexOfMatchNPC), &player);
						moneyReceived += matchPrice;
						itemPurchased = true;
						cout << "You received a match.\n" << transactionCompleteString << "\n";
					}
					else
					{
						cout << "Sorry you do not have enough money for that.\n";
					}
				}
				else
				{
					cout << "Sorry we are all out of matches.\n";
				}
			}
			else if(choice == 4) // wants information
			{
				if(infoGiven)
				{
					cout << "I have no more information for you.\n";
				}
				else if(moneyPouch->getNumberOfCoins() >= infoPrice)
				{
					moneyPouch->removeFromPouch(infoPrice);
					infoGiven = true;
					moneyReceived += infoPrice;
					itemPurchased = true;
					cout << infoString;
				}
				else
					cout << "Sorry you do not have enough money for that.\n";
			}
			else if(choice == 5) // wants to go to back room
			{
				cout << "Alright mon, follow me to the back room mon.\n";
				cout << funnyString;
				cout << endl;
				cout << "You enter a smokey room. You can barely see anything.\n";
				cout << endl;
				player.setConfused(true);

				if (!getHappy())
				{
					setHappy(true);
					player.incrementPeopleMadeHappy();
				}

				cout << "A short while later you emerge.\n";
				cout << "\"You may want to sleep that off, mon.\" he says.\n";
			}
			else if(choice == 6)
			{
				cout << byeString;
			}

			if (moneyReceived >= moneyToMakeHappy)
			{
				if (!getHappy())
				{
					setHappy(true);
					player.incrementPeopleMadeHappy();
				}
			}

			if (itemPurchased)
				player.setHasBoughtSomething();

		}

		cout << endl;

	}while(choice != 6);
	
	string remainder;
	getline(cin, remainder);
}
