#ifndef MONEYPOUCH_H
#define MONEYPOUCH_H

#include "item.h"
#include "sstream"

class MoneyPouch :
	public Item
{
public:
	MoneyPouch(string, string, bool);
	MoneyPouch(string, string, bool, int);
	void addToPouch(int);
	void removeFromPouch(int);
	string getNameOfCoin() const;
	int getNumberOfCoins() const;
	string getDescription() const;

private:
	string nameOfCoin;
	int numberOfCoins;
};
#endif
