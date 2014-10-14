#ifndef SHOPKEEPER_H
#define SHOPKEEPER_H

#include "NonPlayableCharacter.h"
#include "Player.h"
#include <iostream>

class Shopkeeper :
	public NonPlayableCharacter
{
public:
	Shopkeeper(string, string, int, int, bool);
	virtual void startDialog(Player&);

private:
	string helloString;
	string menuString;
	string transactionCompleteString;
	string byeString;
	string funnyString;
	string infoString;
	int moneyReceived;
	bool infoGiven;
	bool itemPurchased;

};
#endif SHOPKEEPER_H
