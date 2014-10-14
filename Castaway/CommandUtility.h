#ifndef COMMANDUTILITY_H
#define COMMANDUTILITY_H

#include "Room.h"
#include "Player.h"
#include "NonPlayableCharacter.h"
#include "Gameboard.h"
#include "Command.h"
#include "Ghost.h"
#include "HyperDrive.h"
#include <iostream>

class CommandUtility
{
public:
	CommandUtility();
	static void move(direction, Room*, Player*, Gameboard*);
	static void look(Command&, Room&, Player&);
	static void talk(Command&, Room&, Player&);
	static void take(Command&, Room&, Player&);
	static void drop(Command&, Room&, Player&);
	static void inventory(Player&);
	static void use(Command&, Room&, Player&);
	static void say(Command&, Room&, Player&);
	static void give(Command&, Room&, Player&);
	static void open(Command&, Room&, Player&);
	static void push(Command&, Room&, Player&);
	static void help(Player&, Gameboard&);
	static void sleep(Command&, Player&);
};
#endif
