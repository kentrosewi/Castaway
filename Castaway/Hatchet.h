#ifndef HATCHET_H
#define HATCHET_H

#include "Usable.h"
#include "Room.h"
#include <iostream>

class Hatchet : public Usable
{
public:
	Hatchet(string, string, bool);
	virtual void use(Player&, int, Room&, int);
};
#endif
