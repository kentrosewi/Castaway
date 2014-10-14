#include "MoneyPouch.h"

/*
	Constructor for MoneyPouch
	@param name the name for the money pouch
	@pram description the description for the money pouch
	@param moveable if the money pouch is moveable or not
*/
MoneyPouch::MoneyPouch(string name, string description, bool moveable) : Item(name, description, moveable), nameOfCoin("finiki"), numberOfCoins(0)
{
}

/*
	Constructor for MoneyPouch that allows initial value of contents.
	@param name the name of the money pouch
	@param description the description of the MoneyPouch
	@param moveable if the money pouch is moveable or not
	@param numberOfCoins how much to start the moneypouch off with
*/
MoneyPouch::MoneyPouch(string name, string description, bool moveable, int numberOfCoins) : Item(name, description, moveable), nameOfCoin("finiki"), numberOfCoins(numberOfCoins)
{
}

/*
	Adds an amount to the money pouch.
	@param amount the amount to add
*/
void MoneyPouch::addToPouch(int amount)
{
	numberOfCoins += amount;
}

/*
	Removes an amount from the money pouch.
	@param amount the amount to remove
*/
void MoneyPouch::removeFromPouch(int amount)
{
	numberOfCoins -= amount;
}

/*
	Returns the name of the coin.
	@return nameOfCoin the name of the coin to be returned
*/
string MoneyPouch::getNameOfCoin() const
{
	return nameOfCoin;
}

/*
	Returns the number of coins in money pouch.
	@param numberOfCoins the number of coins in money pouch
*/
int MoneyPouch::getNumberOfCoins() const
{
	return numberOfCoins;
}

/*
	Gets the description of the money pouch.
	@return a string holding Item::getDescription & a string
	detailing name of coin and value in money pouch
*/
string MoneyPouch::getDescription() const
{
	ostringstream outstr;
	outstr << numberOfCoins;
	string numberOfCoinsString = outstr.str();
	return Item::getDescription() + "\n   It is holding " + numberOfCoinsString + " " + nameOfCoin + ".";
}
