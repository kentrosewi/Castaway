#ifndef USABLE_H
#define USABLE_H

#include "Player.h"
#include "Room.h"

class Usable :
	public Item
{
public:
	Usable(string, string, bool);
	virtual void use(Player&, int, Room&, int) = 0;
	
};
#endif
