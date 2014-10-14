#ifndef CHEST_H
#define CHEST_H

#include "Item.h"
#include "Paper.h"
#include "Room.h"
class Chest :
	public Item
{
public:
	Chest(string, string, bool);
	void open(Room&);

private:
	bool opened;
};
#endif
