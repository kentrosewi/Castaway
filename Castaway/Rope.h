#ifndef ROPE_H
#define ROPE_H

#include "Usable.h"
#include "Player.h"
#include "Room.h"
#include "Raft.h"
#include <iostream>

class Rope :
	public Usable
{
public:
	Rope(string, string, bool);
	void use(Player&, int, Room&, int);

};
#endif