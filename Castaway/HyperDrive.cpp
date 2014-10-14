#include "HyperDrive.h"
#include <time.h>

/*
	Constructor for HyperDrive.
	@param name the hyper drive's name
	@param description the description of the hyper drive
	@param moveable bool value for if hyperdrive is moveable
*/
HyperDrive::HyperDrive(string name, string description, bool moveable) : Item(name, description, moveable), fixed(false), pushedIn(false), cooledOff(false)
{
}

/*
	Pushes the hyper drive in.
	Sets pushedIn bool to true.
*/
void HyperDrive::pushIn()
{
	pushedIn = true;
	setDescription("The hyper drive is now hot! Try cooling it off!");
	cout << "You pushed " << getName() << " in.\n";
	cout << "The hyper drive is now hot. Maybe it can be cooled off." << endl;
}

/*
	Returns bool for if hyper drive is pushed in.
	@return pushedIn bool value for if hyper drive
	is pushed in or not
*/
bool HyperDrive::isPushedIn() const
{
	return pushedIn;
}

/*
	Sets the bool value cooledOff to true or false.
	@param coldOrHot the bool to set cooledOff to
*/
void HyperDrive::setCool(bool coldOrHot)
{
	cooledOff = coldOrHot;
}

/*
	Returns if the hyper drive is cool or not.
	@return cooledOff bool value for if hyper drive is cooled off
*/
bool HyperDrive::isCool() const
{
	return cooledOff;
}

/*
	Starts the hyper drive puzzle.
	Have to connect the correct wires together.
*/
void HyperDrive::startPuzzle()
{
	bool done = false;
	bool wire1Done = false;
	bool wire2Done = false;
	bool wire3Done = false;
	bool outOfTime = false;

	int wire1Connection = 4;
	int wire2Connection = 6;
	int wire3Connection = 5;

	std::cout << "The hyper drive needs to be fixed by connecting a series of 3 broken wires.\n";
	std::cout << "There are 6 connectors that are holding the wires. 3 on the left side, 3 on the right.\n";
	std::cout << "The connectors are holding the wires that should be connected to eachother.\n\n";
	
	cout << "WIRE 1 |----x     x----| WIRE 4" << endl;
	cout << "       |               |       " << endl;
	cout << "WIRE 2 |----x     x----| WIRE 5" << endl;
	cout << "       |               |       " << endl;
	cout << "WIRE 3 |----x     x----| WIRE 6" << endl;
	cout << "       |               |       " << endl;

	clock_t start, check;

	start = clock();

	int maxTime = 25000;
	do
	{
		int input;
		check = clock();
		int timeDif = check - start;

		if (timeDif > maxTime)
		{
			outOfTime = true;
		}

		if (outOfTime)
		{
			std::cout << "You ran out of time! The hyper drive got hot again!\n";
			setCool(false);
			done = true;
		}
		else
		{

			if (cin.fail())
			{
				cin.clear();
				cin.ignore(100, '\n');
			}

			if (!wire1Done)
			{
				std::cout << "What connector would you like to connect the 1st wire to?\n\n4\n5\n6\n\n";

				do
				{
					if (cin.fail())
					{

						cout << "Incorrect entry. Try again." << endl;
						cin.clear();
						cin.ignore(100, '\n');
					}
					cin >> input;
				} while (cin.fail());

				//cin >> input;
				if (input == wire1Connection)
				{
					std::cout << "You connected the left connector 1 to the right connector 4 and fixed the wire connection!\n";
					wire1Done = true;
				}
				else
				{
					cout << "Incorrect connection." << endl;
				}
			}

			if (!wire2Done)
			{
				std::cout << "What connector would you like to connect the 2nd wire to?\n\n4\n5\n6\n\n";

				do
				{
					if (cin.fail())
					{

						cout << "Incorrect entry. Try again." << endl;
						cin.clear();
						cin.ignore(100, '\n');
					}
					cin >> input;
				} while (cin.fail());

				if (input == wire2Connection)
				{
					std::cout << "You connected the left connector 2 to the right connector 6 and fixed the wire connection!\n";
					wire2Done = true;
				}
				else
				{
					cout << "Incorrect connection." << endl;
				}
			}

			if (!wire3Done)
			{
				std::cout << "What connector would you like to connect the 3rd wire to?\n\n4\n5\n6\n\n";

				do
				{
					if (cin.fail())
					{

						cout << "Incorrect entry. Try again." << endl;
						cin.clear();
						cin.ignore(100, '\n');
					}
					cin >> input;

				} while (cin.fail());

				if (input == wire3Connection)
				{
					std::cout << "You connected the left connector 3 to the right connector 5 and fixed the wire connection!\n";
					wire3Done = true;
				}
				else
				{
					cout << "Incorrect connection." << endl;
				}
			}

			if (wire1Done && wire2Done && wire3Done)
			{
				done = true;
				cout << "WIRE 1 |__________________| WIRE 4" << endl;
				cout << "       |                  |       " << endl;
				cout << "WIRE 2 |________  ________| WIRE 5" << endl;
				cout << "       |        \\/        |       " << endl;
				cout << "WIRE 3 |________/\\________| WIRE 6 " << endl;
				cout << "       |                  |       " << endl;
				cout << endl;
				std::cout << "You fixed the hyper drive!\n\n";
				setFixed(true);
			}
		}

	} while (!done);
	string remainder;
	std::getline(cin, remainder);
	std::cout << remainder;
	//std::cout << "exiting puzzle\n";
}

/*
	Returns if the hyper drive is fixed or not.
	@return fixed the bool value for if fixed or not
*/
bool HyperDrive::isFixed() const
{
	return fixed;
}

/*
	Sets the fixed bool of hyper drive.
	@param fixedOrNot if hyper drive is fixed or not
*/
void HyperDrive::setFixed(bool fixedOrNot)
{
	fixed = fixedOrNot;
}