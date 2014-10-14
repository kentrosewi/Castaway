#include "Chest.h"

/*
	Constructor for Chest.
	@param name the name of Chest
	@param description the description of Chest
	@param moveable if the Chest is moveable
*/
Chest::Chest(string name, string description, bool moveable) : Item(name, description, moveable), opened(false)
{
}

/*
	Opens the Chest.
	@param room the Room to add the new items to
*/
void Chest::open(Room& room)
{
	if (!opened)
	{
		room.addItem(new MoneyPouch("big money pouch", "THAT IS A FREAKN HUGE MONEY POUCH I WONDER HOW MUCH IS IN IT.", true, 100));
		room.addItem(new Paper("letter", "I'm writing this letter in hopes that one day you will find it.\nI've grown weary of the daily walks to the beach in hopes of finding a rescue ship sailing towards me from the horizon. They've given up... You've given up... I will place this letter in a chest to keep it safe. Shall anyone ever find this, please tell Merrill to swing away.", true));
		cout << "chest was opened.\n";
		opened = true;
	}
	else
		cout << "chest was already opened.\n";

}
