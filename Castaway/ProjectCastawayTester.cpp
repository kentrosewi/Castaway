#include "Entity.h"
#include "Character.h"
#include "Room.h"
#include "Gameboard.h"
#include "Command.h"
#include "CommandUtility.h"
#include "Player.h"
#include "Achievements.h"
#include <time.h>
#include <iostream>

using namespace std;

void endGame(Player&);
void displayTitle();

int main()
{
	Gameboard gameBoard;
	displayTitle();
	Player player("Drilner", "A handsome being.", 9, 8);
	player.addToInventory(new MoneyPouch("money pouch", "This is your money pouch. Don't lose it.", false, 0));
	player.addToInventory(new Paper("scratch paper", " 1 -> 4   2 -> 6     3 -> 5\n\nWhat do those numbers mean?", true));

	Achievements ach(player);

	bool done = false;

	clock_t startClock, endClock;

	startClock = clock();

	string input = "";

	string intro = "You wake up to water splashing over your head. You're laying on the shore and you are not sure where you are or how you got here. \n";
	cout << intro;

	int playerXPosition = player.getXPosition();
	int playerYPosition = player.getYPosition();
	Room* room = gameBoard.getRoom(playerXPosition, playerYPosition);
	cout << endl;
	cout << room->getDescription() << "\n";

	do{
		
		player.addToPoints(ach.checkForAchievements());

		playerXPosition = player.getXPosition();
		playerYPosition = player.getYPosition();
		room = gameBoard.getRoom(playerXPosition, playerYPosition);

		int indexOfHyperDrive = room->indexOfItem("hyper drive");
		if (indexOfHyperDrive != -1)
		{
			HyperDrive* hyperDrive = dynamic_cast<HyperDrive*>(room->getContents()->at(indexOfHyperDrive));
			if (hyperDrive->isFixed())
			{
				player.setFixedHyperDrive();
				player.addToPoints(ach.checkForAchievements());
				cout << "Points awarded for this game: " << player.getPoints() << endl;
				endClock = clock();
				int completeTime = endClock - startClock;
				cout << "Completion time: " << completeTime / CLOCKS_PER_SEC << " seconds." << endl << endl;
				endGame(player);
				return 0;
			}
		}
		cout << endl;
		getline(cin, input);
		Command command(input);
		cout << endl;
	
		CommandUtility commandUtility;

		if(command.getVerb() == Quit)
		{
			return(0);
		}
		else
		{
			int indexOfTorch = player.indexOfItem("torch");
			if (indexOfTorch != -1)
			{
				Torch* torch = static_cast<Torch*>(player.getInventory()->at(indexOfTorch));
				if (torch->isLit())
				{
					torch->decrementTimer();
				}
			}

			if(command.getVerb() == Move)
			{
				direction direction = command.getDirection();
				commandUtility.move(direction, room, &player, &gameBoard);
			}
			else if(command.getVerb() == Look)
			{
				commandUtility.look(command, *room, player);
			}
			else if(command.getVerb() == Take)
			{
				commandUtility.take(command, *room, player);
			}
			else if(command.getVerb() == Drop)
			{
				commandUtility.drop(command, *room, player);
			}
			else if(command.getVerb() == Inventory)
			{
				commandUtility.inventory(player);
			}
			else if(command.getVerb() == Use)
			{
				commandUtility.use(command, *room, player);
			}
			else if(command.getVerb() == Say)
			{
				commandUtility.say(command, *room, player);
			}
			else if(command.getVerb() == Give)
			{
				commandUtility.give(command, *room, player);
			}
			else if(command.getVerb() == Talk)
			{
				commandUtility.talk(command, *room, player);
			}
			else if (command.getVerb() == Open)
			{
				commandUtility.open(command, *room, player);
			}
			else if (command.getVerb() == Push)
			{
				commandUtility.push(command, *room, player);
			}
			else if (command.getVerb() == Help)
			{
				commandUtility.help(player, gameBoard);
			}
			else if (command.getVerb() == Sleep)
			{
				commandUtility.sleep(command, player);
			}
			else
			{
				cout << "You really have me confused. Try again.\n";
			}
			player.incrementCommandsIssued();
		}

	}while(!done);

	return 0;
}

void endGame(Player& player)
{
	int peopleMadeHappy = player.getPeopleMadeHappy();
	cout << "The engine starts to rumble...\n";
	cout << "You hear the ship AI speaking...\"The auto-pilot system has been activated and you will now ascend to an outer atmosphere location.\"\n";
	cout << "The ship takes off into the sky and after a minute you stop.\n";

	if (peopleMadeHappy == 1)
	{
		cout << "\"Preparing to jump to light-speed.\" the AI says.\n";
		cout << "Home planet found...please remained seated for the ride.\n";
		cout << "Your ship jumps to light speed.\n";
		cout << "You close your eyes and drift asleep.\n";
		cout << "Game Complete!\n";
	}
	else if (peopleMadeHappy == 2)
	{
		cout << "\"Preparing to jump to light-speed.\" the AI says.\n";
		cout << "Home planet found...please remaine seated for the ride.\n";
		cout << "Your ship jumps to light speed.\n\n";
		cout << "After a few days have passed you arrive on your home planet.\n";
		cout << "Your ship initiates the auto-landing sequence and you float into the dock.\n";
		cout << "You step out of your ship and there are just tons of babes waiting for you.\n";
		cout << "There's also Benjamin Geisler riding a hover-cycle. He has to clear a path through the babes to get to you.\n";
		cout << "\"Good job getting home. As a reward I've canceled all homework, projects, and exams in my classes for the rest of eternity.\" he says\n";
		cout << "\nGame Complete!\n";
	}
	else
	{
		cout << "\"to preparing ligh-speeee jump to error pla home foun error\" the AI says.\n";
		cout << "It seems the AI is malfunctioning. What is going on with the ship?\n";
		cout << "The rumble from the engine starts to die down and turns into a high-pitched squeel.\n";
		cout << "The engine shuts off and the ship begins to fall back down to the planet.\n";
		cout << "Game Complete!\n";
	}
	system("pause");
}

void displayTitle()
{
	cout << "  _____               _\n";
	cout << " / ____|             | |\n";
	cout << "| |       __ _   ___ | |_   __ _ __      __  __ _  _   _ \n";
	cout << "| |      / _` | / __|| __| / _` |\\ \\ /\\ / / / _` || | | |\n";
	cout << "| |____ | (_| | \\__ \\| |_ | (_| | \\ V  V / | (_| || |_| |\n";
	cout << " \\_____| \\__,_| |___/ \\__| \\__,_|  \\_/\\_/   \\__,_| \\__, |\n";
	cout << "                                                    __/ |\n";
	cout << "                                                   |___/ \n\n";

	cout << "---Welcome to Castaway by Kent Rose and Daniel Meighen.---" << endl << endl << endl;
	cout << "We hope you enjoy it. Let's get it started." << endl << endl;
}
