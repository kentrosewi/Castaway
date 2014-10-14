#ifndef CHARACTER_H
#define CHARACTER_H

#include "Locatable.h"
#include "Command.h"
#include "stringapps.h"
#include "Item.h"
#include <vector>
#include <iostream> //delete after testing
class Character : public Locatable
{
public:
	Character();
	Character(string, string, int, int);
	~Character();
	void move(direction);
	void addToInventory(Item*);
	void deleteItem(Item*);
	vector<Item*>* getInventory();
	int indexOfItem(string);
	void give(Item*, Character*);
	int numberInInventory(string) const;

public:
	vector<Item*> inventory;
};
#endif