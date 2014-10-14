#ifndef MATCH_H
#define MATCH_H

#include "Usable.h"
#include "Torch.h"
#include "Room.h"

class Match :
	public Usable
{
public:
	Match(string, string, bool);
	virtual void use(Player&, int, Room&, int);
};
#endif
